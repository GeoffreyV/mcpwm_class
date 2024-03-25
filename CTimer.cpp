#include "CTimer.hpp"

CTimer::CTimer()
{

}

CTimer::~CTimer()
{

}

CTimer::CTimer(mcpwm_timer_config_t x_config)
{
    m_config = x_config;
}

void CTimer::set_frequency(uint32_t x_frequency)
{
    m_config.period_ticks = m_config.resolution_hz / x_frequency;
}

void CTimer::set_period_ticks(uint32_t x_period_ticks)
{
    m_config.period_ticks = x_period_ticks;
}

void CTimer::set_timer_mode(mcpwm_timer_count_mode_t x_count_mode)
{
    m_config.count_mode = x_count_mode;
}

void CTimer::set_config(mcpwm_timer_config_t x_config)
{
    m_config = x_config;
}

esp_err_t CTimer::init()
{
    return mcpwm_new_timer(&m_config, &m_handle);
}

esp_err_t CTimer::enable()
{
    return mcpwm_timer_enable(m_handle);
}

esp_err_t CTimer::disable()
{
    return mcpwm_timer_disable(m_handle);
}

esp_err_t CTimer::start()
{
        return mcpwm_timer_start_stop(m_handle, MCPWM_TIMER_START_NO_STOP);
}

esp_err_t CTimer::stop()
{
    return mcpwm_timer_start_stop(m_handle, MCPWM_TIMER_STOP_FULL);
}