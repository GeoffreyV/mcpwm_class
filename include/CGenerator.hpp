#pragma once
#include "driver/mcpwm_gen.h"

#ifdef __cplusplus
extern "C"
{
#endif

class CGenerator
{
public:
    CGenerator();
    CGenerator(mcpwm_oper_handle_t x_operator);
    CGenerator(mcpwm_generator_config_t x_config,mcpwm_oper_handle_t x_operator);
    ~CGenerator();

    esp_err_t init(mcpwm_oper_handle_t x_operator);
    esp_err_t set_gpio_num(int x_gpio_num);

    const mcpwm_gen_handle_t& getHandle() const { return m_handle; }

private:
    mcpwm_generator_config_t m_config = {
        .gen_gpio_num = 0,
        .flags = {
            .invert_pwm = false,
            .io_loop_back = false,
            .io_od_mode = false, 
            .pull_up = false, 
            .pull_down = false
        }
    };

    mcpwm_gen_handle_t m_handle;





};
#ifdef __cplusplus
}
#endif