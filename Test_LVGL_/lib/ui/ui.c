// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: Test

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_hour;
lv_obj_t * ui_min;
lv_obj_t * ui_sec;
lv_obj_t * ui_Sensor_Panel1;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Sensor_Panel2;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Sensor_Panel3;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Sensor_Panel5;
lv_obj_t * ui_Image5;
lv_obj_t * ui_Label4;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_128x[1] = {&ui_img_128x130_png};
const lv_img_dsc_t * ui_imgset_arrow_right_x[1] = {&ui_img_arrow_right_16x16_png};
const lv_img_dsc_t * ui_imgset_bg[1] = {&ui_img_bg300_png};
const lv_img_dsc_t * ui_imgset_btn_main_off_80x[1] = {&ui_img_btn_main_off_80x32_png};
const lv_img_dsc_t * ui_imgset_btn_main_on_80x[1] = {&ui_img_btn_main_on_80x32_png};
const lv_img_dsc_t * ui_imgset_buttonx[1] = {&ui_img_button32x32_png};
const lv_img_dsc_t * ui_imgset_wifi_16x16_[1] = {&ui_img_wifi_16x16_001_png};
const lv_img_dsc_t * ui_imgset_wifi_128x[1] = {&ui_img_wifi_128x160_png};
const lv_img_dsc_t * ui_imgset_1187750366[1] = {&ui_img_144205808};
const lv_img_dsc_t * ui_imgset_1993094331[1] = {&ui_img_1199486407};
const lv_img_dsc_t * ui_imgset_264462334[1] = {&ui_img_162118600};
const lv_img_dsc_t * ui_imgset_1181847013[2] = {&ui_img_1208893048, &ui_img_1530590678};
const lv_img_dsc_t * ui_imgset_429246764[1] = {&ui_img_1574887283};
const lv_img_dsc_t * ui_imgset_655074089[1] = {&ui_img_964567643};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
