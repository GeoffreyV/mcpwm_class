#include "COperator.hpp"

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
    //ESP_ERROR_CHECK(mcpwm_del_operator(m_handle));
}

void COperator::set_gpio_generator_pins(int gpio1, int gpio2){
    m_gpio_numbers[0] = gpio1;
    m_gpio_numbers[1] = gpio2;
}

extern "C" esp_err_t COperator::connect_timer(mcpwm_timer_handle_t timer_handle)
{
    ESP_ERROR_CHECK(mcpwm_operator_connect_timer(m_handle, timer_handle));
    m_timer_connected_handle = timer_handle;
    return ESP_OK;
}

void COperator::init(){

}