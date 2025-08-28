#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *control_page;
    lv_obj_t *adc_chart;
    lv_obj_t *nextpage_bt;
    lv_obj_t *adc34bar;
    lv_obj_t *adc33bar;
    lv_obj_t *adc33val;
    lv_obj_t *adc34val;
    lv_obj_t *adc33led;
    lv_obj_t *home_bt;
    lv_obj_t *pwmval;
    lv_obj_t *incrementpwm;
    lv_obj_t *decrementpwm;
    lv_obj_t *onmotor_bt;
    lv_obj_t *offmotor_bt;
    lv_obj_t *fan_led;
    lv_obj_t *onpwm_sw;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_CONTROL_PAGE = 2,
};

void create_screen_main();
void tick_screen_main();

void create_screen_control_page();
void tick_screen_control_page();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/