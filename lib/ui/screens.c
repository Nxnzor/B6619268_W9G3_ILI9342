#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // adc_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.adc_chart = obj;
            lv_obj_set_pos(obj, 13, 94);
            lv_obj_set_size(obj, 201, 138);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1b22e1), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 118, 9);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "B6619268 Phonphimon W.");
        }
        {
            // nextpage_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.nextpage_bt = obj;
            lv_obj_set_pos(obj, 220, 209);
            lv_obj_set_size(obj, 90, 23);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Next Page");
                }
            }
        }
        {
            // adc34bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.adc34bar = obj;
            lv_obj_set_pos(obj, 70, 74);
            lv_obj_set_size(obj, 150, 10);
            lv_bar_set_range(obj, 0, 1023);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            // adc33bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.adc33bar = obj;
            lv_obj_set_pos(obj, 70, 52);
            lv_obj_set_size(obj, 150, 10);
            lv_bar_set_range(obj, 0, 1023);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 13, 49);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ADC33");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 12, 71);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ADC34");
        }
        {
            // adc33val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc33val = obj;
            lv_obj_set_pos(obj, 228, 52);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
        {
            // adc34val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc34val = obj;
            lv_obj_set_pos(obj, 228, 74);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
        {
            // adc33led
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.adc33led = obj;
            lv_obj_set_pos(obj, 249, 131);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(0xff45da39));
            lv_led_set_brightness(obj, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 241, 104);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ADC33");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_control_page() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.control_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // home_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_bt = obj;
            lv_obj_set_pos(obj, 16, 206);
            lv_obj_set_size(obj, 65, 24);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Home");
                }
            }
        }
        {
            // pwmval
            lv_obj_t *obj = lv_spinbox_create(parent_obj);
            objects.pwmval = obj;
            lv_obj_set_pos(obj, 41, 32);
            lv_obj_set_size(obj, 81, 33);
            lv_spinbox_set_digit_format(obj, 3, 0);
            lv_spinbox_set_range(obj, 0, 255);
            lv_spinbox_set_rollover(obj, false);
            lv_spinbox_set_step(obj, 1);
            lv_spinbox_set_value(obj, 0);
        }
        {
            // incrementpwm
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.incrementpwm = obj;
            lv_obj_set_pos(obj, 130, 36);
            lv_obj_set_size(obj, 27, 26);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3ccd42), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "+");
                }
            }
        }
        {
            // decrementpwm
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.decrementpwm = obj;
            lv_obj_set_pos(obj, 6, 35);
            lv_obj_set_size(obj, 27, 26);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffdf3a3a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "PWM Control");
        }
        {
            // onmotor_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.onmotor_bt = obj;
            lv_obj_set_pos(obj, 11, 112);
            lv_obj_set_size(obj, 111, 30);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff39cb40), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Open Motor");
                }
            }
        }
        {
            // offmotor_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.offmotor_bt = obj;
            lv_obj_set_pos(obj, 11, 151);
            lv_obj_set_size(obj, 111, 31);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd9a33b), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Closed Motor");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 85);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Pump Control");
        }
        {
            // fan_led
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.fan_led = obj;
            lv_obj_set_pos(obj, 234, 143);
            lv_obj_set_size(obj, 30, 24);
            lv_led_set_color(obj, lv_color_hex(0xff3a9366));
            lv_led_set_brightness(obj, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 234, 114);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FAN");
        }
        {
            // onpwm_sw
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.onpwm_sw = obj;
            lv_obj_set_pos(obj, 215, 37);
            lv_obj_set_size(obj, 50, 25);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 178, 40);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "OFF");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 273, 41);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ON");
        }
    }
    
    tick_screen_control_page();
}

void tick_screen_control_page() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_control_page,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_control_page();
}
