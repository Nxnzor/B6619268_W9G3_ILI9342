#include "event.h"
#include <Arduino.h>

lv_chart_series_t *adc_chart_data33;
lv_chart_series_t *adc_chart_data34;

void event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);    
    lv_obj_t *obj = lv_event_get_target(e);
    int *pLED = (int *)lv_event_get_user_data(e);

    // lv_obj_t * adc33led  = lv_led_create(lv_scr_act());

    // int bar_val = lv_bar_get_value(objects.adc33val);
    // int pwmval = bar_val * 255 / 100;
    // lv_led_set_brightness(adc33led, pwmval);
    
    if(obj == objects.adc33bar && code == LV_EVENT_VALUE_CHANGED)
    {
        int bar_val = lv_bar_get_value(objects.adc33val);
        int pwmval = bar_val * 255 / 100;
        if(lv_obj_has_state(obj, LV_STATE_EDITED))
        {   
            lv_led_set_brightness(objects.adc33led,pwmval) ;   
        }
        else
        {
            lv_led_set_brightness(objects.adc33led,0);
        }
    }

}

void init_adc_33_34_chart()
{
    int pointcount = 50;
    int min_value = 0;
    int max_value = 1023;
// Set type of the chart
    lv_chart_set_type(objects.adc_chart, LV_CHART_TYPE_LINE);
// Set the number of points on the chart
    lv_chart_set_point_count(objects.adc_chart, pointcount);
// Set the range of the Y axis
    lv_chart_set_range(objects.adc_chart, LV_CHART_AXIS_PRIMARY_Y, min_value, max_value);
// Create a data series for the chart
    adc_chart_data33 = lv_chart_add_series(objects.adc_chart, lv_color_hex(0xffb400), LV_CHART_AXIS_PRIMARY_Y);
    adc_chart_data34 = lv_chart_add_series(objects.adc_chart, lv_color_hex(0x1b22e1), LV_CHART_AXIS_PRIMARY_Y);
}

void update_chart_adc_33_34(lv_timer_t * timer)
{
    LV_UNUSED(timer);
    analogReadResolution(10);
    lv_chart_set_next_value(objects.adc_chart, adc_chart_data33, analogRead(33));
    lv_bar_set_value(objects.adc33bar,analogRead(33),LV_ANIM_OFF);
    lv_label_set_text(objects.adc33val,String(analogRead(33)).c_str());
    
    lv_chart_set_next_value(objects.adc_chart, adc_chart_data34, analogRead(34));
    lv_bar_set_value(objects.adc34bar,analogRead(34),LV_ANIM_OFF);
    lv_label_set_text(objects.adc34val,String(analogRead(34)).c_str());
}

void control_page_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);    
    lv_obj_t *obj = lv_event_get_target(e);

    if(obj == objects.nextpage_bt && code == LV_EVENT_CLICKED)
    {
        lv_scr_load(objects.control_page);
    }
    else if(obj == objects.home_bt && code == LV_EVENT_CLICKED)
    {
        lv_scr_load(objects.main);
    }
}

void change_led_state(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);    
    lv_obj_t *obj = lv_event_get_target(e);
    int *pLED = (int *)lv_event_get_user_data(e);

    if(obj == objects.onmotor_bt && code == LV_EVENT_CLICKED)
    {
        gpio_set_level((gpio_num_t)*pLED,1);
    }
    else if(obj == objects.offmotor_bt && code == LV_EVENT_CLICKED)
    {
        gpio_set_level((gpio_num_t)*pLED,0);
    }
}

void pwm_spinbox_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);    
    lv_obj_t *obj = lv_event_get_target(e);

    if(obj == objects.incrementpwm && code == LV_EVENT_PRESSING)
    {
        int pwmval = lv_spinbox_get_value(objects.pwmval);
        if(pwmval < 255)
        {
            pwmval++;
            lv_spinbox_set_value(objects.pwmval,pwmval);
        }
    }
    else if(obj == objects.decrementpwm && code == LV_EVENT_PRESSING)
    {
        int pwmval = lv_spinbox_get_value(objects.pwmval);
        if(pwmval > 0)
        {
            pwmval--;
            lv_spinbox_set_value(objects.pwmval,pwmval);
        }
    }
}

void get_value(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (obj == objects.onpwm_sw)
    {
        if (lv_obj_has_state(objects.onpwm_sw, LV_STATE_CHECKED))
        {
            int val = lv_spinbox_get_value(objects.pwmval);
            analogWrite(22, val);
            Serial.println("PWMVAL:" + String(val));
        }
        else
        {
            analogWrite(22, 0);
        }
    }
}

void get_sw_state(lv_timer_t *timer)
{
    LV_UNUSED(timer);
    int *pSW = (int *)timer->user_data;
    // Serial.println(*pSW);

    if (digitalRead(*pSW) == 0)
    {

        lv_led_on(objects.fan_led);
    }
    else if (digitalRead(*pSW) == 1)
    {
        lv_led_off(objects.fan_led);
    }
}