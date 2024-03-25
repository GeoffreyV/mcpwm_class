#pragma once
#ifdef __cplusplus
extern "C"
{
#endif
// Path: main/CMcpwm/CMcpwm.h
#include "driver/mcpwm_prelude.h"

    class CMcpwm
    {
    public:
        CMcpwm();
        ~CMcpwm();
        void init();
        void setDutyCycle(int dutyCycle);
        void setFrequency(int frequency);
        void setDutyCycleAndFrequency(int dutyCycle, int frequency);
        void setDutyCycleAndFrequencyAndStart(int dutyCycle, int frequency);
        void start();
        void stop();

    protected:
        mcpwm_timer_handle_t m_timer_handle;
        mcpwm_oper_handle_t m_oper_handle;
        mcpwm_gen_handle_t m_gen_handle;
        mcpwm_cmpr_handle_t m_cmpr_handle;

    };

#ifdef __cplusplus
}
#endif