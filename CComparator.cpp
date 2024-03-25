#include "CComparator.hpp"


extern "C" CComparator::CComparator()
{

}

extern "C" CComparator::CComparator(mcpwm_oper_handle_t mcpwm_operator_handle)
{
    ESP_ERROR_CHECK(mcpwm_new_comparator(mcpwm_operator_handle, &m_config,&m_handle));

}

extern "C" CComparator::~CComparator()
{

}

extern "C" esp_err_t CComparator::set_comparator_value(uint32_t cmp_ticks)
{
    return mcpwm_comparator_set_compare_value(m_handle,cmp_ticks);
}
