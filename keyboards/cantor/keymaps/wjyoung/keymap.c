// This is the personal keymap of Wayne Young for the Cantor keyboard
// SPDX-License-Identifier: GPL-2.0
//
// qmk flash -kb cantor -km wjyoung

#include QMK_KEYBOARD_H

////
// Macro enums
////
enum custom_keycodes {
    DB2 = SAFE_RANGE  // spit out "db2"
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define QWE 0  // default base layer: qwerty
#define NUM 1
#define FUN 2

// Some handy macros to keep the keymaps clean and easier to maintain

#define QT_ESC   LCTL_T(KC_ESC)

// Bottom row modifiers for qwerty
#define QT_Z     LGUI_T(KC_Z)
#define QT_X     LALT_T(KC_X)
#define QT_C     LSFT_T(KC_C)
#define QT_V     LCTL_T(KC_V)
#define QT_LBRC  LSFT_T(KC_LBRC)

#define QT_M     RCTL_T(KC_M)
#define QT_COMM  RSFT_T(KC_COMM)
#define QT_DOT   LALT_T(KC_DOT)
#define QT_RBRC  RSFT_T(KC_RBRC)

// Bottom row modifiers for numbers layer
#define NT_MINS  LALT_T(KC_MINS)
#define NT_EQL   LSFT_T(KC_EQL)
#define NT_GRV   LCTL_T(KC_GRV)

#define NT_BSLS  LCTL_T(KC_BSLS)
#define NT_LBRC  LSFT_T(KC_LBRC)
#define NT_RBRC  LALT_T(KC_RBRC)

// left-side thumb keys: hold for a layer shift, tap for normal key
#define LT_DEL  LT(FUN, KC_DEL)
//#define LT_ESC  LT(NUM, KC_ESC)
#define LT_SPC  LT(NUM, KC_SPC)
#define LT_TAB  KC_TAB

// right-side thumb keys
#define LT_ENT  KC_ENT
#define RT_SPC  LT(NUM, KC_SPC)
#define LT_BSPC LT(FUN, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │grv│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ \ │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │esc│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ [ │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │ ] │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Del├───┐           ┌───┤Bsp│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Tab│   │Ent├───┘
      *                       └───┘   └───┘
      */
    [QWE] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        QT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        QT_LBRC, QT_Z,    QT_X,    QT_C,    QT_V,    KC_B,                               KC_N,    QT_M,    QT_COMM, QT_DOT,  KC_SLSH, QT_RBRC,
                                            LT_DEL,  LT_SPC,  LT_TAB,           LT_ENT,  RT_SPC,  LT_BSPC
    ),
    [NUM] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        CAPSWRD, KC_EXLM, KC_LT,   KC_GT,   KC_TILD, CAPSWRD,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, KC_QUOT,
        QT_LBRC, KC_PLUS, NT_MINS, NT_EQL,  NT_GRV,  XXXXXXX,                            KC_UNDS, NT_BSLS, NT_LBRC, NT_RBRC, KC_SLSH, QT_RBRC,
                                            _______, _______, _______,          _______, KC_SPC,  KC_BSPC
    ),
    [FUN] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, KC_F12, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX,                            KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
                                            _______, _______, _______,          _______, KC_SPC,  KC_BSPC
    )
};

