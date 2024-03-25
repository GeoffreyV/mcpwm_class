#include "CGenerator.hpp"

extern "C" CGenerator::CGenerator(){

}

extern "C" CGenerator::CGenerator(mcpwm_oper_handle_t x_operator)
{
    ESP_ERROR_CHECK(mcpwm_new_generator(x_operator, &m_config, &m_handle));
}

extern "C" CGenerator::CGenerator(mcpwm_generator_config_t x_config,mcpwm_oper_handle_t x_operator)
{
    m_config = x_config;
    ESP_ERROR_CHECK(mcpwm_new_generator(x_operator, &m_config, &m_handle));
}

CGenerator::~CGenerator()
{

}

extern "C" esp_err_t CGenerator::init(mcpwm_oper_handle_t x_operator) {
        ESP_ERROR_CHECK(mcpwm_new_generator(x_operator, &m_config, &m_handle));
        return ESP_OK;
}

extern "C" esp_err_t CGenerator::set_gpio_num(int x_gpio_num){
    m_config.gen_gpio_num = x_gpio_num;
    return ESP_OK;
}