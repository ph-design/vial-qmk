// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H



enum custom_layers {
    _BASE_WIN,
    _BASE_MAC,
    _FN1,
};


os_variant_t current_os = OS_UNSURE;

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) return false;

    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            current_os = OS_MACOS;
            set_single_persistent_default_layer(_BASE_MAC);
            break;
        default: // Windows/Linux/Uncertain
            current_os = OS_WINDOWS;
            set_single_persistent_default_layer(_BASE_WIN);
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Windows Base Layer
[_BASE_WIN] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          RSFT_T(KC_UP),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, LT(2,KC_LEFT),RGUI_T(KC_DOWN),RCTL_T(KC_RGHT)
),
// Mac Base Layer
[_BASE_MAC] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          RSFT_T(KC_UP),
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, LT(2,KC_LEFT),RALT_T(KC_DOWN),RCTL_T(KC_RGHT)
),
// Fn1 Layer
[_FN1] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, KC_INS,  _______, KC_PSCR, KC_SCRL, KC_PAUS, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP,          _______,
        _______,          RM_ON, RM_NEXT, RGB_HUI, RGB_HUD, RGB_SAI, RM_VALU, RM_VALD, _______, KC_END,  KC_PGDN,          _______,
        _______, GU_TOGG, _______,                            _______,                            _______, _______, _______, _______
),
};

led_config_t g_led_config = {
        {
                { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13 },
                         { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 },
                                  { 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, NO_LED, 40 },
                                           { 41, NO_LED, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, NO_LED, 52 },
                                                    { 53, 54, 55, NO_LED, NO_LED, NO_LED, 56, NO_LED, NO_LED, NO_LED, 57, 58, 59, 60 }
        },
        {
                // 行 0
                {9,0},   {27,0},  {45,0},  {63,0},  {81,0},  {99,0},  {117,0}, {135,0}, {153,0}, {171,0}, {189,0}, {207,0}, {225,0}, {252,0},

                // 行 1
                {243,16}, {225,16}, {207,16}, {189,16}, {171,16}, {153,16}, {135,16}, {117,16}, {99,16}, {81,16}, {63,16}, {45,16}, {27,16}, {13,16},

                // 行 2
                {15,32}, {33,32}, {51,32}, {69,32}, {87,32}, {105,32}, {123,32}, {141,32}, {159,32}, {177,32}, {195,32}, {213,32}, {234,32},

                // 行 3
                {240,48}, {213,48}, {195,48}, {177,48}, {159,48}, {141,48}, {123,48}, {105,48}, {87,48}, {69,48}, {51,48}, {18,48},

                // 行 4
                {9,64}, {36,64}, {55,64}, {120,64}, {189,64}, {216,64}, {243,64}, {255,64}
        },
        // LED标志（4表示每个按键LED）
        {
                4,4,4,4,4,4,4,4,4,4,4,4,4,4,
                4,4,4,4,4,4,4,4,4,4,4,4,4,4,
                4,4,4,4,4,4,4,4,4,4,4,4,   4,
                4,  4,4,4,4,4,4,4,4,4,4,   4,
                4,4,4,          4,       4,4,4,4
        }
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        if (current_os == OS_MACOS) {
            rgb_matrix_set_color(28, 0x00, 0xFF, 0x00); // MacOS下CapsLock亮绿色
        } else {
            rgb_matrix_set_color(28, 0xFF, 0x00, 0x00); // Windows下CapsLock亮红色
        }
    }

    if (get_highest_layer(layer_state) == _FN1) {
        // Row 0
        rgb_matrix_set_color(0, 0x7F, 0x7F, 0x7F);  // KC_GRV
        rgb_matrix_set_color(1, 0x7F, 0x7F, 0x7F);  // F1-F12
        rgb_matrix_set_color(2, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(3, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(4, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(5, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(6, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(7, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(8, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(9, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(10, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(11, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(12, 0x7F, 0x7F, 0x7F);
        rgb_matrix_set_color(13, 0x7F, 0x7F, 0x7F); // KC_DEL

// Row 1
        rgb_matrix_set_color(25, 0x7F, 0x7F, 0x7F); // KC_UP
        rgb_matrix_set_color(19, 0x7F, 0x7F, 0x7F); // KC_INS
        rgb_matrix_set_color(17, 0x7F, 0x7F, 0x7F); // KC_PSCR
        rgb_matrix_set_color(16, 0x7F, 0x7F, 0x7F); // KC_SCRL
        rgb_matrix_set_color(15, 0x7F, 0x7F, 0x7F); // KC_PAUS

// Row 2
        rgb_matrix_set_color(29, 0x7F, 0x7F, 0x7F); // KC_LEFT
        rgb_matrix_set_color(30, 0x7F, 0x7F, 0x7F); // KC_DOWN
        rgb_matrix_set_color(31, 0x7F, 0x7F, 0x7F); // KC_RGHT
        rgb_matrix_set_color(38, 0x7F, 0x7F, 0x7F); // KC_HOME
        rgb_matrix_set_color(39, 0x7F, 0x7F, 0x7F); // KC_PGUP

// Row 3
        rgb_matrix_set_color(51, 0x7F, 0x7F, 0x7F); // RM_ON
        rgb_matrix_set_color(50, 0x7F, 0x7F, 0x7F); // RM_NEXT
        rgb_matrix_set_color(49, 0x7F, 0x7F, 0x7F); // RGB_HUI
        rgb_matrix_set_color(48, 0x7F, 0x7F, 0x7F); // RGB_HUD
        rgb_matrix_set_color(47, 0x7F, 0x7F, 0x7F); // RGB_SAI
        rgb_matrix_set_color(46, 0x7F, 0x7F, 0x7F); // RM_VALU
        rgb_matrix_set_color(45, 0x7F, 0x7F, 0x7F); // RM_VALD
        rgb_matrix_set_color(43, 0x7F, 0x7F, 0x7F); // KC_END
        rgb_matrix_set_color(42, 0x7F, 0x7F, 0x7F); // KC_PGDN

// Row 4
        rgb_matrix_set_color(54, 0x7F, 0x7F, 0x7F); // GU_TOGG
    }

    return false;
}