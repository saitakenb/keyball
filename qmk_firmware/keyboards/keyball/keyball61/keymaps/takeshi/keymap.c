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
#ifdef RGBLIGHT_ENABLE
    uint8_t count = rgblight_config.sat; // sat から個数を取得
    if (count > 37) count = 8;
    oled_write_char(' ', false);
    oled_write_char('L', false);
    oled_write_char(':', false);
    oled_write_char((count / 10) + '0', false);
    oled_write_char((count % 10) + '0', false);
#endif
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

#ifdef RGBLIGHT_ENABLE
// タイマー競合や誤判定のない、QMK標準の左右判定APIを使用
bool get_is_left_hand_latched(void) {
    return is_keyboard_left();
}

void update_led_state(void) {
    uint8_t current_layer = get_highest_layer(layer_state);

    // 彩度(sat)はレイヤー状態からローカルで自律決定する（L0=0, L1=160, 他=255）
    uint8_t sat_actual = 255;
    if (current_layer == 1) {
        sat_actual = 160; // 薄紫 (ラベンダー)
    } else if (current_layer == 0) {
        sat_actual = 0;   // レイヤー0は白
    }

    LED_TYPE color_led;
    // 明度(rgblight_config.val)と自律決定した彩度を使用して、全体の輝度調整が完全に機能する色を生成
    sethsv(rgblight_config.hue, sat_actual, rgblight_config.val, &color_led);

    // 左右合計71個の全バッファ（L=37, R=34）を消灯クリア
    for (uint8_t i = 0; i < 71; i++) {
        led[i] = (LED_TYPE){0, 0, 0};
    }

    // RGBが有効なときのみ、対象範囲にカラーを設定する
    if (rgblight_config.enable) {
        // 点灯制限数を sat 変数 (0〜37) から取得
        uint8_t limit = rgblight_config.sat;
        if (limit > 37) limit = 8; // デフォルト補正

        // 1. 左手側バッファの描画 (インデックス 0〜36)
        for (uint8_t cnt = 0; cnt < limit; cnt++) {
            uint8_t idx = cnt - 8;
            if (cnt < 8) {
                idx = cnt + 29;
            }
            if (idx < 37) {
                led[idx] = color_led;
            }
        }

        // 2. 右手側バッファの描画 (インデックス 37〜70)
        for (uint8_t cnt = 0; cnt < limit; cnt++) {
            uint8_t idx = cnt + 37; // 右手は37オフセットから開始
            if (idx < 71) {
                led[idx] = color_led;
            }
        }
    }

    // 描画する瞬間だけクリッピング範囲を全71個のLED全体に広げる
    rgblight_set_clipping_range(0, 71);
    rgblight_set_effect_range(0, 71);

    // 常に物理LEDに上書き書き出し
    rgblight_set();

    // 出力直後にクリッピング範囲を (0, 1) に設定し、同期パケットの送信経路を確保しつつ全点灯を防ぐ
    rgblight_set_clipping_range(0, 1);
    rgblight_set_effect_range(0, 1);
}
#endif

// 起動時にデフォルトの点灯個数を 8（親指全点灯）、モード1、白（レイヤー0）に設定する
void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    
    // 同期送信を維持しつつ描画を防ぐため、初期値としてクリッピングを(0, 1)にする
    rgblight_set_clipping_range(0, 1);
    rgblight_set_effect_range(0, 1);

    // レイヤー0(白)初期状態: hue=170, sat=8 (点灯数8をsatに格納), val=127 (初期輝度50%)
    rgblight_sethsv_noeeprom(170, 8, 127);
    
    update_led_state();
#endif
}

void matrix_scan_user(void) {
#ifdef RGBLIGHT_ENABLE
    static uint16_t last_state = 0xFFFF;
    uint8_t current_layer = get_highest_layer(layer_state);

    // レイヤーに応じて target_hue (色相) を自動決定
    uint8_t target_hue = 170;
    if (current_layer == 1) {
        target_hue = 200; // 薄紫 (ラベンダー)
    } else if (current_layer == 2) {
        target_hue = 128; // シアン (水色)
    }

    // 監視対象：レイヤー、ON/OFF状態、点灯個数(sat)、全体の明るさ(val)
    uint16_t current_state = (current_layer << 12) | (rgblight_config.sat << 6) | (rgblight_config.val << 1) | rgblight_config.enable;
    
    static uint8_t scan_div = 0;
    scan_div++;

    if (current_state != last_state || scan_div >= 10) {
        last_state = current_state;
        scan_div = 0;

        // マスター側でのみ、レイヤー変更を検知して同期を実行
        // クリッピング(0, 1)を維持したまま送信することで、同期させつつフラッシュを完全防止
        if (is_keyboard_master()) {
            if (rgblight_config.hue != target_hue) {
                rgblight_set_clipping_range(0, 1);
                rgblight_set_effect_range(0, 1);
                rgblight_sethsv_noeeprom(target_hue, rgblight_config.sat, rgblight_config.val);
            }
        }

        update_led_state();
    }
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_ENABLE
    if (keycode == RGB_MOD || keycode == RGB_RMOD) {
        if (record->event.pressed) {
            uint8_t count = rgblight_config.sat; // sat を点灯数として流用
            if (count > 37) count = 8; // デフォルト補正
            
            uint8_t new_count = count;
            if (keycode == RGB_MOD && count < 37) {
                new_count = count + 1;
            } else if (keycode == RGB_RMOD && count > 0) {
                new_count = count - 1;
            }

            // クリッピング(0, 1)で同期パケットを確実に送信しつつ、親指以外の全点灯フラッシュを完全防止する
            rgblight_set_clipping_range(0, 1);
            rgblight_set_effect_range(0, 1);
            rgblight_sethsv_noeeprom(rgblight_config.hue, new_count, rgblight_config.val);

            update_led_state();
        }
        return false;
    }
#endif
    return true;
}
