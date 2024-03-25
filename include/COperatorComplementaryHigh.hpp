
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


    esp_err_t set_duty_cycle(float duty_cycle, uint32_t timer_period_ticks);
    

private:

};

#ifdef __cplusplus
}
#endif