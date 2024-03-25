#include "COperatorComplementaryHigh.hpp"
#include "driver/mcpwm_prelude.h"

COperatorComplementaryHigh::COperatorComplementaryHigh()
{

}

COperatorComplementaryHigh::~COperatorComplementaryHigh()
{

}

void COperatorComplementaryHigh::init()
{
    ESP_ERROR_CHECK(mcpwm_new_operator(&this->m_config, &this->m_handle));
    for (int i=0; i<2; i++){
        m_generators[i] = CGenerator(this->m_handle);
    }
    m_comparators[0] = CComparator(this->m_handle);
    m_deadtime = CDeadTime(10,10);
    m_deadtime.apply_active_high_complementary_mode(m_generators[0].getHandle(), m_generators[1].getHandle());


}