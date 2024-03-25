
#pragma once
#include "driver/mcpwm_timer.h"

#ifdef __cplusplus
extern "C"
{
#endif

    class CTimer
    {
    public:
        CTimer();
        CTimer(mcpwm_timer_config_t x_config);
        ~CTimer();

        mcpwm_timer_handle_t get_handle() const { return m_handle; }
        uint32_t get_period_ticks() const {return m_config.period_ticks;}

        void set_frequency(uint32_t x_frequency);
        void set_period_ticks(uint32_t x_period_ticks);
        void set_timer_mode(mcpwm_timer_count_mode_t x_count_mode);
        void set_config(mcpwm_timer_config_t x_config);

        esp_err_t init();
        esp_err_t enable();
        esp_err_t disable();
        esp_err_t start();
        esp_err_t stop();

    private:
        mcpwm_timer_config_t m_config = {
            .group_id = 0,
            .clk_src = MCPWM_TIMER_CLK_SRC_DEFAULT,
            .resolution_hz = 300000,
            .count_mode = MCPWM_TIMER_COUNT_MODE_UP,
            .period_ticks = 100000,
            .intr_priority = 1,
            .flags = {
                .update_period_on_empty = 0,
                .update_period_on_sync = 0
            }
        };
        mcpwm_timer_handle_t m_handle;
    };

#ifdef __cplusplus
}
#endif