/* Copyright 2018 Eucalyn
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
 *
 * Build
 * make mint60:custom:avrdude
 */
#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define TVD TOG_VDESKTOP
#define DR_SRT1 DYN_REC_START1
#define DR_SRT2 DYN_REC_START2
#define DR_STOP DYN_REC_STOP
#define _BL 0
#define _JL 1
#define _FL 2

enum custom_keycodes {
    RGBRST = SAFE_RANGE,
    ALT_TAB,
    TOG_VDESKTOP,
    DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

enum {
    TD_J_Cc = 0
};

/* Tap Dance Definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for J, twice for <C-c>
    [TD_J_Cc]  = ACTION_TAP_DANCE_DOUBLE(KC_J, LCTL(KC_C)),
    // Other declarations would go here, separated by commas, if you have them
};
// In Layer declaration, add tap dance item in place of a key code
// TD(TD_J_Cc)
/*                       */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* mint60
    * ,-----------------------------------+-.  .---------------------------------------------------------.
    * |  `  |  1  |  2  |  3  |  4  |  5  |  \  \  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    BACK   |
    * |======================================+\  \ +=====================================================|
    * |  Tab   |  Q  |  W  |  E  |  R  |  T  | \  \    |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \   |
    * |=======================================+ \  \ +===================================================|
    * |  Ctrl   |  A  |  S  |  D  |  F  |  G  |  \  \   |
    * |========================================+  |  |  +========================================
    * |  Shift   |  Z  |  X  |  C  |  V  |  B  |  |  |  |  Z  |  X  |  C  |  V  |  B  |
    * |========================================+  |  | +========================================
    * | ESC | Win  |  F4  |  L2  |    Space    |  |  | |      |
    * `----------------------------------------+--` `-+----------------------------------------
    */























    /* Keymap _BL: Base Layer (Default Layer) */
    [_BL] = LAYOUT( \
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    TVD,  \
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  \
        KC_LCTL,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_ENT,   \
        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,   KC_UP,  KC_DEL,\
        KC_ESC,    KC_LGUI,    KC_F4,    LT(_FL, KC_MHEN),    KC_SPC,    KC_BSPC, LT(_JL, KC_HENK),  KC_LALT,  KC_LEFT,  KC_DOWN,  KC_RGHT \
    ),
    /* Keymap _JL: J side Layer (Right hand function Layer) */
    [_JL] = LAYOUT( \
        SGUI(KC_S),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL, \
        ALT_TAB,   RALT(KC_F4),  LCTL(KC_W), XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,          _______, \
        _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_BTN2, \
        _______,   _______,    _______,    _______,    LWIN(KC_R),         _______, _______, _______,                    _______, _______, _______ \
    ),
    /* Keymap _FL: F side Layer (Left hand function Layer) */
    [_FL] = LAYOUT( \
        SGUI(KC_S),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL, \
        ALT_TAB,   RALT(KC_F4),  LCTL(KC_W), XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,          _______, \
        _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, \
        _______,   _______,    _______,    _______,    LWIN(KC_R),         _______, _______, _______,                    _______, _______, _______ \
    ),

};

const uint16_t PROGMEM fn_actions[] = {

};

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
// MACRODOWN only works in this function
    switch(id) {
        case 0:
        if (record->event.pressed) {
            register_code(KC_RSFT);
        } else {
            unregister_code(KC_RSFT);
        }
        break;
    }
    return MACRO_NONE;
};

bool is_alt_tab_active = false;  // ADD this near the begining of keymap.c
static uint16_t alt_tab_timer = 0;  // we will be using them soon.
bool tog_vdesktop_status = true;  // Toggle between left arrow and right arrow.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // dynamic macro.
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
    switch (keycode) {
    case RGBRST:
        #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
        }
        #endif

    /* super <Alt+TAB> */
    case ALT_TAB:
        if (record->event.pressed) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }

    /* Toggle virtual Desktop between no.1 and no.2. */
    case TOG_VDESKTOP:
        if (record->event.pressed) {
            if (tog_vdesktop_status) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_RGHT);
            } else {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_LEFT);
            }
        } else {
            if (tog_vdesktop_status) {
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_RGHT);
                tog_vdesktop_status = false;
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_LEFT);
                tog_vdesktop_status = true;
            }
        }
    break;
    }
    return true;
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {     // The very important timer.
    // if (is_alt_tab_active) {
    //     if (timer_elapsed(alt_tab_timer) > 500) {
    //         unregister_code(KC_LALT);
    //         unregister_code(KC_TAB);
    //         // unregister_code16(LALT(KC_TAB));
    //         is_alt_tab_active = false;
    //     }
    // }
}

void led_set_user(uint8_t usb_led) {

}
