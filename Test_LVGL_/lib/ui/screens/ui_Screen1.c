// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: Test

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel1, 100);
    lv_obj_set_height(ui_Panel1, 50);
    lv_obj_set_x(ui_Panel1, 0);
    lv_obj_set_y(ui_Panel1, -53);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_hour = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_hour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_hour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_hour, -25);
    lv_obj_set_y(ui_hour, -3);
    lv_obj_set_align(ui_hour, LV_ALIGN_CENTER);
    lv_label_set_text(ui_hour, "12");

    ui_min = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_min, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_min, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_min, -2);
    lv_obj_set_y(ui_min, 0);
    lv_obj_set_align(ui_min, LV_ALIGN_CENTER);
    lv_label_set_text(ui_min, "22");

    ui_sec = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_sec, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_sec, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_sec, 30);
    lv_obj_set_y(ui_sec, -2);
    lv_obj_set_align(ui_sec, LV_ALIGN_CENTER);
    lv_label_set_text(ui_sec, "59");

    ui_Sensor_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Sensor_Panel1, 63);
    lv_obj_set_height(ui_Sensor_Panel1, 28);
    lv_obj_set_x(ui_Sensor_Panel1, 28);
    lv_obj_set_y(ui_Sensor_Panel1, -8);
    lv_obj_set_align(ui_Sensor_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Sensor_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Sensor_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Sensor_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Sensor_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Sensor_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image2 = lv_img_create(ui_Sensor_Panel1);
    lv_img_set_src(ui_Image2, &ui_img_547817801);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image2, -19);
    lv_obj_set_y(ui_Image2, 0);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label1 = lv_label_create(ui_Sensor_Panel1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, 14);
    lv_obj_set_y(ui_Label1, 0);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "45 C");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0x4F42D7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Sensor_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Sensor_Panel2, 63);
    lv_obj_set_height(ui_Sensor_Panel2, 28);
    lv_obj_set_x(ui_Sensor_Panel2, 34);
    lv_obj_set_y(ui_Sensor_Panel2, 59);
    lv_obj_set_align(ui_Sensor_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Sensor_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Sensor_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Sensor_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Sensor_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Sensor_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image4 = lv_img_create(ui_Sensor_Panel2);
    lv_img_set_src(ui_Image4, &ui_img_tvoc_png);
    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image4, -19);
    lv_obj_set_y(ui_Image4, 0);
    lv_obj_set_align(ui_Image4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label3 = lv_label_create(ui_Sensor_Panel2);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 14);
    lv_obj_set_y(ui_Label3, 0);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "45 C");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0x4F42D7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Sensor_Panel3 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Sensor_Panel3, 63);
    lv_obj_set_height(ui_Sensor_Panel3, 28);
    lv_obj_set_x(ui_Sensor_Panel3, -32);
    lv_obj_set_y(ui_Sensor_Panel3, 24);
    lv_obj_set_align(ui_Sensor_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Sensor_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Sensor_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Sensor_Panel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Sensor_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Sensor_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image3 = lv_img_create(ui_Sensor_Panel3);
    lv_img_set_src(ui_Image3, &ui_img_394011210);
    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image3, -19);
    lv_obj_set_y(ui_Image3, 0);
    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label2 = lv_label_create(ui_Sensor_Panel3);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 14);
    lv_obj_set_y(ui_Label2, 0);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "45 C");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0x4F42D7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Sensor_Panel5 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Sensor_Panel5, 63);
    lv_obj_set_height(ui_Sensor_Panel5, 28);
    lv_obj_set_x(ui_Sensor_Panel5, -30);
    lv_obj_set_y(ui_Sensor_Panel5, 59);
    lv_obj_set_align(ui_Sensor_Panel5, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Sensor_Panel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Sensor_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Sensor_Panel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Sensor_Panel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Sensor_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image5 = lv_img_create(ui_Sensor_Panel5);
    lv_img_set_src(ui_Image5, &ui_img_1551580766);
    lv_obj_set_width(ui_Image5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image5, -19);
    lv_obj_set_y(ui_Image5, 0);
    lv_obj_set_align(ui_Image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label4 = lv_label_create(ui_Sensor_Panel5);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 14);
    lv_obj_set_y(ui_Label4, 0);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "45 C");
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0x4F42D7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}
