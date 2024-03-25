#pragma once
#include "driver/mcpwm_cmpr.h"


#ifdef __cplusplus
extern "C"
{
#endif

    class CComparator
    {
    public:
        CComparator();
        CComparator(mcpwm_oper_handle_t mcpwm_operator);
        ~CComparator();

        esp_err_t set_comparator_value(uint32_t cmp_ticks);

        const mcpwm_cmpr_handle_t &getHandle() const { return m_handle; };

    private:
        mcpwm_comparator_config_t m_config = {
            .intr_priority = 0,
            .flags = {
                .update_cmp_on_tez = true,
                .update_cmp_on_tep = true,
                .update_cmp_on_sync = true}};

        mcpwm_cmpr_handle_t m_handle;
        mcpwm_oper_handle_t* m_operator;
    };

#ifdef __cplusplus
}
#endif