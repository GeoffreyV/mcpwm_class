#include <stdio.h>
#include "COperatorComplementaryHigh.hpp"
#include "CTimer.hpp"

extern "C"
{
    void app_main(void)
    {
        COperatorComplementaryHigh mcpwm_operator;
        CTimer timer;

        mcpwm_operator.connect_timer(timer.getHandle());
        mcpwm_operator.init();
        timer.start();
    }
}
