#ifndef EVENT_H
#define EVENT_H
#include <lvgl.h>
#include "ui.h"
#if defined(EEZ_FOR_LVGL)
#include <eez/flow/lvgl_api.h>
#endif
#if !defined(EEZ_FOR_LVGL)
#include "screens.h"
#endif
#ifdef __cplusplus
extern "C"
{
#endif
    void event_handler(lv_event_t *e);
    void init_adc_33_34_chart();
    void update_chart_adc_33_34(lv_timer_t * timer);

    void control_page_event_cb(lv_event_t * e);
    void change_led_state(lv_event_t * e);
    void pwm_spinbox_event_cb(lv_event_t * e);
    void get_value(lv_event_t *e);
    void get_sw_state(lv_timer_t *timer);


#ifdef __cplusplus
}
#endif
#endif