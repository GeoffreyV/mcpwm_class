#pragma once
#include "driver/mcpwm_oper.h"
#include "driver/gpio.h"

#include "CTimer.hpp"
#include "CGenerator.hpp"
#include "CComparator.hpp"
#include "CDeadtime.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

    class COperator
    {
    public:
        COperator();
        COperator(int group_id, int intr_priority = 0);
        ~COperator();

        void set_gpio_generator_pins(int gpio1, int gpio2 = GPIO_NUM_NC);

        virtual void init();

        esp_err_t connect_timer(mcpwm_timer_handle_t timer_handle);
        const mcpwm_oper_handle_t& getHandle() const { return m_handle; }

    protected:
        mcpwm_operator_config_t m_config = {
            .group_id = 0,
            .intr_priority = 0,
            .flags = {
                .update_gen_action_on_tez = true,
                .update_gen_action_on_tep = true, 
                .update_gen_action_on_sync = false,
                .update_dead_time_on_tez = true,
                .update_dead_time_on_tep = true,
                .update_dead_time_on_sync = true,                             
            }
        };

        mcpwm_oper_handle_t m_handle;
        mcpwm_timer_handle_t m_timer_connected_handle;
        CGenerator m_generators[2];
        CComparator m_comparators[2];
        CDeadTime m_deadtime;

        int m_gpio_numbers[2] = {GPIO_NUM_NC, GPIO_NUM_NC};


        
        
    };

#ifdef __cplusplus
}
#endif