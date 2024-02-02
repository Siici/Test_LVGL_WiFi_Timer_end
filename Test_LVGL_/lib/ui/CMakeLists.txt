SET(SOURCES components/ui_comp_light.c
    components/ui_comp_navigation_bar.c
    components/ui_comp_panel1.c
    components/ui_comp_sensor_panel.c
    components/ui_comp_user_panel.c
    components/ui_comp.c
    screens/ui_Screen1.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_547817801.c
    images/ui_img_tvoc_png.c
    images/ui_img_394011210.c
    images/ui_img_1551580766.c
    images/ui_img_128x130_png.c
    images/ui_img_arrow_right_16x16_png.c
    images/ui_img_bg300_png.c
    images/ui_img_btn_main_off_80x32_png.c
    images/ui_img_btn_main_on_80x32_png.c
    images/ui_img_button32x32_png.c
    images/ui_img_wifi_16x16_001_png.c
    images/ui_img_wifi_128x160_png.c
    images/ui_img_144205808.c
    images/ui_img_1199486407.c
    images/ui_img_162118600.c
    images/ui_img_1208893048.c
    images/ui_img_1530590678.c
    images/ui_img_1574887283.c
    images/ui_img_964567643.c)

add_library(ui ${SOURCES})
