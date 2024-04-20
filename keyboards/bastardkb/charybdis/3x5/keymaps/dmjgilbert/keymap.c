#include QMK_KEYBOARD_H

// Thumb keymaps
#define LY1_ETR LT(1, KC_ENTER)       // Layer one when held, enter when tapped
#define LY2_ESC LT(2, KC_ESCAPE)      // Layer two when held, esc when tapped
#define LT_BSPC MT(MOD_RSFT, KC_BSPC) // Right shift when held, backspace when tapped
#define LCT_DOT MT(MOD_RCTL, KC_DOT)  // Right control when held, dot when tapped

#define WIN_MOV HYPR(KC_M) //
#define WIN_RSZ HYPR(KC_R) //
#define WIN_SWI HYPR(KC_C) //

#define DSP_LFT HYPR(KC_Q) //
#define DSP_RHT HYPR(KC_W) //

#define WRK_LFT HYPR(KC_A) //
#define WRK_RHT HYPR(KC_S) //

#define WIN_FUL HYPR(KC_F) //

enum charybdis_keymap_layers { _DAZMAK = 0, _SYMBOL, _NAVIG };

enum combo_events {
    LEFT_MOUSE_CLICK,
    RIGHT_MOUSE_CLICK,
};

const uint16_t PROGMEM left_mouse_click_combo[]  = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM right_mouse_click_combo[] = {KC_E, KC_I, COMBO_END};

combo_t key_combos[] = {
    [LEFT_MOUSE_CLICK]  = COMBO_ACTION(left_mouse_click_combo),
    [RIGHT_MOUSE_CLICK] = COMBO_ACTION(right_mouse_click_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case LEFT_MOUSE_CLICK:
            if (pressed) {
                tap_code16(KC_BTN1);
            }
            break;
        case RIGHT_MOUSE_CLICK:
            if (pressed) {
                tap_code16(KC_BTN2);
            }
            break;
    }
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DAZMAK] = LAYOUT(
        //,--------------------------------------------.                    ,--------------------------------------------.
            XXXXXXX,    KC_Q,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, XXXXXXX,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
               KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
               KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M,    KC_W, KC_COMM, LCT_DOT,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       KC_LGUI, LY1_ETR,  KC_SPC,    LT_BSPC, LY2_ESC
                                   //`--------------------------'  `--------------------------'
    ),

    [_SYMBOL] = LAYOUT(
        //,--------------------------------------------.                    ,--------------------------------------------.
            XXXXXXX, KC_DQUO,KC_QUOTE,  KC_GRV,  KC_DLR,                      KC_CIRC, KC_LBRC,  KC_EQL, KC_RBRC, XXXXXXX,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_EXLM, KC_QUES, KC_PERC, KC_SCLN,   KC_AT,                      KC_ASTR, KC_LPRN, KC_COLN, KC_RPRN, KC_PLUS,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_BSLS, KC_TILD, KC_PIPE, KC_HASH, KC_AMPR,                      KC_SLSH, KC_LCBR, KC_UNDS, KC_RCBR, KC_MINS,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       KC_LGUI, _______,  KC_SPC,     KC_DEL, _______
                                   //`--------------------------'  `--------------------------'
    ),

    [_NAVIG] = LAYOUT(
        //,--------------------------------------------.                    ,--------------------------------------------.
            XXXXXXX, KC_MPLY,  KC_DOT, KC_VOLD, KC_VOLU,                      WIN_MOV, WRK_LFT,   KC_UP, WRK_RHT, XXXXXXX,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
              KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                      WIN_SWI, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGUP,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
              KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,                      WIN_RSZ, DSP_LFT, WIN_FUL, DSP_RHT, KC_PGDN,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       KC_LALT, _______,  KC_TAB,    LT_BSPC, _______
                                   //`--------------------------'  `--------------------------'
    ),
};

// clang-format on
