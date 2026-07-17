/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include <string.h>

extern rgblight_config_t rgblight_config;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC,          KC_1,    KC_2,    KC_3,          KC_4,          KC_5,                                  KC_6,    KC_7,       KC_8,       KC_9,       KC_0,            KC_MINS,
    KC_TAB,          KC_Q,    KC_W,    KC_E,          KC_R,          KC_T,                                  KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,            KC_INT3,
    LSFT_T(KC_GRV),  KC_A,    KC_S,    KC_D,          KC_F,          KC_G,                                  KC_H,    KC_J,       LT(3, KC_K),KC_L,       LGUI_T(KC_SCLN), RSFT_T(KC_QUOT),
    LCTL_T(KC_ESC),  KC_Z,    KC_X,    KC_C,          KC_V,          KC_B,    KC_DEL,              KC_BSPC, KC_N,    KC_M,       KC_COMM,    KC_DOT,     LALT_T(KC_SLSH), RCTL_T(KC_LBRC),
    KC_BTN1,         TO(2),   KC_LGUI, KC_LALT,       LT(3, KC_INT4),LT(2, KC_SPC),LT(1, KC_INT2), LT(2, KC_TAB), LT(1, KC_ENT), KC_TRNS, KC_TRNS, KC_TRNS, TO(1),        KC_ENT
  ),

  [1] = LAYOUT_universal(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_COMM, KC_RBRC,
    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                  KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, LGUI_T(KC_MINS), RSFT_T(KC_BSLS),
    KC_TRNS, KC_MINS, KC_PPLS, KC_PAST, KC_SLSH, KC_DOT,  KC_TRNS,             KC_TRNS, S(KC_F10), KC_BTN1, KC_BTN3, KC_BTN2, LALT_T(KC_EQL), RCTL_T(KC_INT3),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),   KC_TRNS
  ),

  [2] = LAYOUT_universal(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_PSCR,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                 LCTL(KC_HOME), LCTL(KC_PGUP), LCTL(KC_UP),   LCTL(KC_PGDN), C(S(KC_TAB)),  S(KC_CAPS),
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                                LCTL(KC_END),  LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RGHT), LCTL(KC_TAB),  KC_TRNS,
    KC_TRNS, KC_BTN2, KC_BTN3, OSL(3),  KC_F12,  KC_F11,  KC_TRNS,             KC_INS,  KC_TRNS,       KC_BTN4,       OSL(3),        KC_BTN5,       KC_LALT,       KC_PAUS,
    KC_TRNS, TO(0),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [3] = LAYOUT_universal(
    RGB_TOG, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT,                               RGB_M_P, RGB_M_B, RGB_M_R, KC_TRNS, KC_TRNS, KC_TRNS,
    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_VOLD, KC_VOLU,                               AML_I50, AML_D50, SSNP_VRT, SSNP_HOR, KC_TRNS, KC_TRNS,
    RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID, KC_BRIU,                               CPI_D1K, CPI_D100, CPI_I100, CPI_I1K,  SSNP_FRE, KC_TRNS,
    KC_TRNS, AML_TO,  SCRL_DVD, SCRL_DVI, SCRL_MO, SCRL_TO, KC_TRNS,             KC_TRNS, KC_F13,  KC_F14,  KC_F15,  KC_TRNS,  EE_CLR,   QK_RBT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    // keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

#ifdef COMBO_ENABLE
const uint16_t PROGMEM my_F2[] = {LT(2, KC_SPC), KC_W, COMBO_END};
const uint16_t PROGMEM combo_df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {KC_J, LT(3, KC_K), COMBO_END};
const uint16_t PROGMEM combo_zxc[] = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_sd[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_kl[] = {LT(3, KC_K), KC_L, COMBO_END};

combo_t key_combos[] = {
    COMBO(my_F2, KC_F2),
    COMBO(combo_df, KC_ESC),
    COMBO(combo_jk, KC_ENT),
    COMBO(combo_zxc, KC_MUTE),
    COMBO(combo_sd, KC_TAB),
    COMBO(combo_kl, KC_BSPC),
};
#endif

static uint16_t last_state = 0xFFFF;

void matrix_scan_user(void) {
#ifdef RGBLIGHT_ENABLE
    uint8_t current_layer = get_highest_layer(layer_state);
    uint8_t current_mode = rgblight_config.mode;
    bool current_enabled = rgblight_config.enable;

    bool need_update = false;

    uint16_t current_state = (current_layer << 8) | (current_mode << 1) | current_enabled;
    if (current_state != last_state) {
        last_state = current_state;
        need_update = true;
    }

    if (need_update && current_enabled && current_mode == RGBLIGHT_MODE_STATIC_LIGHT) {
        uint8_t start = rgblight_ranges.clipping_start_pos;
        uint8_t num = rgblight_ranges.clipping_num_leds;

        LED_TYPE color_led;
        sethsv(170, current_layer * 85, rgblight_config.val, &color_led);

        for (uint8_t i = 0; i < num; i++) {
            led[start + i] = (i >= 29) ? color_led : (LED_TYPE){0, 0, 0};
        }
        rgblight_set();
    }
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_ENABLE
    if (keycode == RGB_SAI || keycode == RGB_SAD) return false;
    if (keycode == RGB_MOD || keycode == RGB_RMOD) {
        if (record->event.pressed) {
            rgblight_toggle_noeeprom();
        }
        return false;
    }
#endif
    return true;
}
