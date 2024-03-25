#include "COperator.hpp"

static void gen_action_config(mcpwm_gen_handle_t gena, mcpwm_gen_handle_t genb, mcpwm_cmpr_handle_t cmpa, mcpwm_cmpr_handle_t cmpb)
{
    ESP_ERROR_CHECK(mcpwm_generator_set_action_on_timer_event(gena,
                    MCPWM_GEN_TIMER_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, MCPWM_TIMER_EVENT_EMPTY, MCPWM_GEN_ACTION_HIGH)));
    ESP_ERROR_CHECK(mcpwm_generator_set_action_on_compare_event(gena,
                    MCPWM_GEN_COMPARE_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, cmpa, MCPWM_GEN_ACTION_LOW)));
}

static void dead_time_config(mcpwm_gen_handle_t gena, mcpwm_gen_handle_t genb)
{
    mcpwm_dead_time_config_t dead_time_config = {
        .posedge_delay_ticks = 10,
        .negedge_delay_ticks = 0
    };
    ESP_ERROR_CHECK(mcpwm_generator_set_dead_time(gena, gena, &dead_time_config));
    dead_time_config.posedge_delay_ticks = 0;
    dead_time_config.negedge_delay_ticks = 10;
    dead_time_config.flags.invert_output = true;
    ESP_ERROR_CHECK(mcpwm_generator_set_dead_time(gena, genb, &dead_time_config));
}   



extern "C" COperator::COperator()
{
    ESP_ERROR_CHECK(mcpwm_new_operator(&m_config, &m_handle));
}

extern "C" COperator::COperator(int group_id, int intr_priority) {
    m_config.group_id = group_id;
    m_config.intr_priority = intr_priority;
}

extern "C" COperator::~COperator()
{
    ESP_ERROR_CHECK(mcpwm_del_operator(m_handle));
}

extern "C" esp_err_t COperator::connect_timer(mcpwm_timer_handle_t timer_handle)
{
    ESP_ERROR_CHECK(mcpwm_operator_connect_timer(m_handle, timer_handle));
    m_timer_connected = timer_handle;
    return ESP_OK;
}

void COperator::init(){

}