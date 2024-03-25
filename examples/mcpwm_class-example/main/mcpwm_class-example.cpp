#include <stdio.h>
#include "COperatorComplementaryHigh.hpp"
#include "CTimer.hpp"
#include "driver/gpio.h"

#define GPIO_PWM0A_OUT 13 // Set GPIO 18 as PWM0A
#define GPIO_PWM0B_OUT 9  // Set GPIO 19 as PWM0B
#define GPIO_OUTPUT_IO_18 18

#define MCPWM_GROUP_ID 0
#define MCPWM_TIMER_0 0
#define MCPWM_TIMER_RESOLUTION 301318
#define MCPWM_TIMER_DEFAULT_PERIOD 100000



extern "C"
{
    void app_main(void)
    {
                // --- Timer configuration and instantiation --- //
        mcpwm_timer_config_t timer_config = {
            .group_id = MCPWM_GROUP_ID,
            .clk_src = MCPWM_TIMER_CLK_SRC_DEFAULT,
            .resolution_hz = MCPWM_TIMER_RESOLUTION,
            .count_mode = MCPWM_TIMER_COUNT_MODE_UP,
            .period_ticks = MCPWM_TIMER_DEFAULT_PERIOD,
            .intr_priority = 1,
            .flags = {
                .update_period_on_empty = true,
                .update_period_on_sync = false
            }
        };

        CTimer timer(timer_config);
        timer.set_frequency(5);
        ESP_ERROR_CHECK(timer.init());

        // --- Operator configuration and instantiation --- //
        COperatorComplementaryHigh mcpwm_operator(MCPWM_GROUP_ID, 1);
        mcpwm_operator.set_gpio_generator_pins(GPIO_NUM_13, GPIO_NUM_9);
        ESP_ERROR_CHECK(mcpwm_operator.connect_timer(timer.get_handle()));


        mcpwm_operator.init();
        ESP_ERROR_CHECK(mcpwm_operator.set_duty_cycle(0.5, timer.get_period_ticks()));
        
        

        timer.enable();
        timer.start();
    }
}
