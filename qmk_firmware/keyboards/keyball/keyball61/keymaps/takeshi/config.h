/*
This is the c configuration file for the keymap

Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU y

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_EFFECT_BREATHING
#endif

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE

#define TAP_CODE_DELAY 5
//#define TAPPING_TERM 200  // 全体のデフォルトは少し長めでもOK
//#define TAPPING_TERM_PER_KEY

//#define PRECISION_ENABLE // 有効化
//#define PRECISION_CPI 4  // 下げた時のCPI (1/100の値を指定。左記ならCPI 400)

//#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
//#define AUTO_MOUSE_DEFAULT_LAYER 2

#define COMBO_COUNT 6          // コンボの数
#define COMBO_TERM 200           // 同時押しとみなす時間（ms）
#define COMBO_MUST_KEY_PRESS

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD  // 両シフト同時押しでCaps Word

#define KEYBALL_SCROLLSNAP_ENABLE 2

#define SPLIT_LAYER_STATE_ENABLE
