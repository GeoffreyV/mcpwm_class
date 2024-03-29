#include "COperatorComplementaryHigh.hpp"
#include "driver/mcpwm_prelude.h"
#include "esp_log.h"

static const char* TAG = "MyModule";

static void gen_action_config(mcpwm_gen_handle_t gena, mcpwm_gen_handle_t genb, mcpwm_cmpr_handle_t cmpa, mcpwm_cmpr_handle_t cmpb)
{
    ESP_ERROR_CHECK(mcpwm_generator_set_action_on_timer_event(gena,
                                                              MCPWM_GEN_TIMER_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, MCPWM_TIMER_EVENT_EMPTY, MCPWM_GEN_ACTION_HIGH)));
    ESP_ERROR_CHECK(mcpwm_generator_set_action_on_compare_event(gena,
                                                                MCPWM_GEN_COMPARE_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, cmpa, MCPWM_GEN_ACTION_LOW)));
}

COperatorComplementaryHigh::COperatorComplementaryHigh()
{
    ESP_ERROR_CHECK(mcpwm_new_operator(&this->m_config, &this->m_handle));
}

COperatorComplementaryHigh::~COperatorComplementaryHigh()
{
    //ESP_ERROR_CHECK(mcpwm_del_operator(m_handle));
}

COperatorComplementaryHigh::COperatorComplementaryHigh(int group_id, int intr_priority) : COperator(group_id, intr_priority)
{
    ESP_ERROR_CHECK(mcpwm_new_operator(&this->m_config, &this->m_handle));
}

esp_err_t COperatorComplementaryHigh::set_duty_cycle(unsigned int duty_cycle_percent, unsigned int timer_period_ticks){
    ESP_LOGD(TAG, "Setting duty cycle to %d \%", duty_cycle_percent);
    ESP_LOGD(TAG, "Got timer period %lu", timer_period_ticks);
    ESP_LOGD(TAG, "Setting compare value to %lu", (uint32_t) (duty_cycle_percent*timer_period_ticks));

    return m_comparators[0].set_comparator_value((uint32_t) (duty_cycle_percent*timer_period_ticks / 100));
}

void COperatorComplementaryHigh::init()
{
    

    mcpwm_generator_config_t generator_config = {
        .gen_gpio_num = m_gpio_numbers[0],
        .flags = {
            .invert_pwm = false,
            .io_loop_back = false,
            .io_od_mode = false,
            .pull_up = false,
            .pull_down = false}};
    

    // Create two generators attached to this operator
    for (int i = 0; i < 2; i++)
    {
        generator_config.gen_gpio_num = m_gpio_numbers[i];
        m_generators[i] = CGenerator(generator_config, this->m_handle);
        ESP_ERROR_CHECK(m_generators[i].init());
    }

    // Create one comparator
    m_comparators[0] = CComparator(this->m_handle);

    gen_action_config(m_generators[0].getHandle(), m_generators[1].getHandle(),
                      m_comparators[0].getHandle(), m_comparators[0].getHandle());

    m_deadtime = CDeadTime(10, 10);
    m_deadtime.apply_active_high_complementary_mode(m_generators[0].getHandle(), m_generators[1].getHandle());
}