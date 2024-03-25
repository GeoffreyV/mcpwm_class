#pragma once
#include "driver/mcpwm_gen.h"

#ifdef __cplusplus
extern "C"
{
#endif

class CDeadTime
{
public:
    CDeadTime();
    CDeadTime(uint32_t posedge_ticks, uint32_t negedge_ticks);
    ~CDeadTime();

    void apply_active_high_complementary_mode(mcpwm_gen_handle_t gena, mcpwm_gen_handle_t genb);

    void set_dead_time_ticks(uint32_t posedge_ticks, uint32_t negedge_ticks) const;
    

private:
    mcpwm_dead_time_config_t m_config = {
        .posedge_delay_ticks = 10,
        .negedge_delay_ticks = 10
    };
};

#ifdef __cplusplus
}
#endif