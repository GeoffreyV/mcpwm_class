
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

        mcpwm_timer_handle_t getHandle() const { return m_handle; }

        void set_frequency(uint32_t x_frequency);
        void set_period_ticks(uint32_t x_period_ticks);
        void set_timer_mode(mcpwm_timer_count_mode_t x_count_mode);
        void set_config(mcpwm_timer_config_t x_config);

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
        };
        mcpwm_timer_handle_t m_handle;
    };

#ifdef __cplusplus
}
#endif