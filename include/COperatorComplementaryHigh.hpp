
#pragma once
#include "COperator.hpp"


#ifdef __cplusplus
extern "C"
{
#endif
class COperatorComplementaryHigh : public COperator
{
public:
    COperatorComplementaryHigh();
    COperatorComplementaryHigh(int group_id, int intr_priority);
    ~COperatorComplementaryHigh();

    virtual void init();


    esp_err_t set_duty_cycle(unsigned int duty_cycle_percent, unsigned int timer_period_ticks);
    

private:

};

#ifdef __cplusplus
}
#endif