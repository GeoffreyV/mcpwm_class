#include "CGenerator.hpp"

extern "C" CGenerator::CGenerator()
{
}

extern "C" CGenerator::CGenerator(mcpwm_oper_handle_t x_operator)
{
}

extern "C" CGenerator::CGenerator(mcpwm_generator_config_t x_config,
                                  mcpwm_oper_handle_t x_operator) : m_config(x_config),
                                                                    m_operator_parent(x_operator)
{
}

CGenerator::~CGenerator()
{
}

extern "C" esp_err_t CGenerator::init(void)
{
    return mcpwm_new_generator(m_operator_parent, &m_config, &m_handle);

}


extern "C" esp_err_t CGenerator::init(mcpwm_oper_handle_t x_operator)
{
    m_operator_parent = x_operator;
    return init();
}

extern "C" esp_err_t CGenerator::set_gpio_num(int x_gpio_num)
{
    m_config.gen_gpio_num = x_gpio_num;
    return ESP_OK;
}