
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
    ~COperatorComplementaryHigh();

    virtual void init();
private:

};

#ifdef __cplusplus
}
#endif