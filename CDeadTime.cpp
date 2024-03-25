#include "CDeadTime.hpp"

CDeadTime::CDeadTime()
{

}

CDeadTime::CDeadTime(uint32_t posedge_ticks, uint32_t negedge_ticks)
{
    m_config.posedge_delay_ticks = posedge_ticks;
    m_config.negedge_delay_ticks = negedge_ticks;
}

CDeadTime::~CDeadTime()
{

}

void CDeadTime::apply_active_high_complementary_mode(mcpwm_gen_handle_t gena, mcpwm_gen_handle_t genb)
{
    mcpwm_dead_time_config_t dead_time_config = {
        .posedge_delay_ticks = m_config.posedge_delay_ticks,
        .negedge_delay_ticks = 0
    };

    ESP_ERROR_CHECK(mcpwm_generator_set_dead_time(gena, gena, &dead_time_config));

    dead_time_config.posedge_delay_ticks = 0;
    dead_time_config.negedge_delay_ticks = m_config.negedge_delay_ticks;
    dead_time_config.flags.invert_output = true;
    ESP_ERROR_CHECK(mcpwm_generator_set_dead_time(gena, genb, &dead_time_config));
}