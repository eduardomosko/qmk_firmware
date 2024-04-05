/* Copyright (C) 2023 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// for use with keymap qwerty us intl. with dead keys

#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"

enum __layers { BASE, EXTRA };

#define MSK_Ç RALT(KC_COMM)
#define MSK_9 KC_9
#define MSK_TIL LSFT(KC_GRV) // ~
#define MSK_ACU KC_QUOT      // ´
#define MSK_GRV KC_GRV       // `

const custom_shift_key_t custom_shift_keys[] = {
  {KC_6 , LSFT(RALT(KC_6))}, // Shift 6 is ^ (inserted immediately)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_tkl_ansi(
      KC_ESC,        KC_F1,   KC_F2,  KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9,       KC_F10,        KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUS,
 RALT(KC_GRV),       KC_1,    KC_2,   KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    MSK_9,       KC_0,          KC_MINS, KC_EQL,  KC_BSLS, KC_INS,  KC_HOME, KC_PGUP,
      KC_TAB,        KC_Q,    KC_W,   KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,        KC_P,          KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,  KC_END,  KC_PGDN,
      KC_ESC, LSFT_T(KC_A),   KC_S,   KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L, RSFT_T(KC_SCLN), RALT(KC_QUOT),          KC_ENT,
      KC_LCTL,       KC_Z,    KC_X,   KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,      KC_SLSH,                         KC_RCTL,          KC_UP,
   MO(EXTRA),        KC_LGUI, KC_LALT,              KC_SPC,                    MO(EXTRA),      KC_RGUI,       XXXXXXX,          KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
),

[EXTRA] = LAYOUT_tkl_ansi(
 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
 KC_GRV , _______, _______, _______, _______, _______, LSFT(KC_6), _______, _______, _______, _______, DT_DOWN, DT_UP  , _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, DT_PRNT, MSK_ACU, MSK_GRV, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______,    _______, _______, _______, RGB_TOG, _______, MSK_TIL,          _______,
 _______, _______, _______, MSK_Ç  , _______, QK_BOOT,    _______, _______, _______, _______, _______,                   _______,          _______,
 _______, _______, _______,                   _______,                               _______, _______, _______,          _______, _______, _______, _______
),

//[EXAMPLE] = LAYOUT_tkl_ansi(
// _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
// _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
// _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,          _______,
// _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______, _______
//),

};
// clang-format on


/** custom shift keys https://getreuer.info/posts/keyboards/custom-shift-keys/index.html#implementation */
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  // Your macros ...

  return true;
}
