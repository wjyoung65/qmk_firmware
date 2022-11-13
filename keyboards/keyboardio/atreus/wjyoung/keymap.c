// This is the personal keymap of Wayne Young, initially copied
// from Jeremy Crowger (../jeremy), implementing a variant of the
// Miryoku layout. I like the Miryoku layout, but want access to
// all 44 Atreus keys.

// to be exact, this is the Miryoku
//   * colemak-dh
//   * flip
//   * inverted T
//   * no mouse layer (never needed it)
//   * holding down SPACE does not shift layers b/c sometimes I want easy auto repeat

#include QMK_KEYBOARD_H

#define USE_MIRYOKU  // otherwise my map

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define CMK 0  // default base: colemak
#define QWE 1  // alternate base: qwerty
#define VIM 2  // vim navigation layer. Yeah, I'm wasting an entire layer for hjkl
#define NUM 3
#define SYM 4
#define FUN 5
#define NAV 6
#define MED 7

// Some handy macros to keep the keymaps clean and easier to maintain

// Left-side home row keys: hold for a modifier, tap for normal key
#define MT_A  LGUI_T(KC_A)
#define MT_R  LALT_T(KC_R)
#define MT_S  LSFT_T(KC_S)
#define MT_T  LCTL_T(KC_T)

// .. for qwerty
#define QT_A  LGUI_T(KC_A)
#define QT_S  LALT_T(KC_S)
#define QT_D  LSFT_T(KC_D)
#define QT_F  LCTL_T(KC_F)

// Right-side home row keys: hold for a modifier, tap for normal key
#define MT_N  RCTL_T(KC_N)
#define MT_E  RSFT_T(KC_E)
#define MT_I  LALT_T(KC_I)
#define MT_O  RGUI_T(KC_O)

// .. for qwerty
#define QT_J  RCTL_T(KC_J)
#define QT_K  RSFT_T(KC_K)
#define QT_L  RALT_T(KC_L)
#define QT_P  RGUI_T(KC_P)

#ifdef USE_MIRYOKU
// left-side thumb keys: hold for a layer shift, tap for normal key
#define LT_DEL  LT(FUN, KC_DEL)
#define LT_BSPC LT(NUM, KC_BSPC)
#define LT_ENT  LT(SYM, KC_ENT)

// right-side thumb keys: hold for a layer shift, tap for normal key
#define LT_TAB  LT(NAV, KC_TAB)
#define LT_SPC  KC_SPC
#define LT_ESC  KC_ESC

#else  // my thumb keys

// left-side thumb keys: hold for a layer shift, tap for normal key
#define LT_LBRC LT(FUN, KC_LBRC)
#define LT_RBRC LT(NUM, KC_RBRC)
#define LT_TAB  LT(SYM, KC_TAB)

// right-side thumb keys: hold for a layer shift, tap for normal key
#define LT_QUOT LT(NAV, KC_QUOT)
#define LT_SPC  KC_SPC
#define LT_UNDS KC_UNDS // note that KC_UNDS cannot be used with a MT or LT

#endif

// Left-side bottom corner key: hold for shift, tap for escape
//#define BT_ESC  LSFT_T(KC_ESC)

// Left-side bottom corner key: hold for layer shift, tap for escape
#define BT_ESC  LT(VIM, KC_ESC)
#define QT_ESC  LSFT_T(KC_ESC)

// Right-side bottom corner key: hold for shift, tap for enter
#define BT_ENT  RSFT_T(KC_ENT)

////
// Macro enums
////
enum custom_keycodes {
    DB2 = SAFE_RANGE,  // spit out "db2"
};

////
// Keymap and layers
////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [CMK] = LAYOUT(
#ifdef USE_MIRYOKU
    KC_Q,    KC_W,     KC_F,     KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,     KC_Y,    KC_QUOT,
#else
    KC_Q,    KC_W,     KC_F,     KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,     KC_Y,    KC_BSPC,
#endif
    MT_A,    MT_R,     MT_S,     MT_T,    KC_G,                       KC_M,    MT_N,    MT_E,     MT_I,    MT_O,
    KC_Z,    KC_X,     KC_C,     KC_D,    KC_V,    KC_GRV,  KC_BSLS,  KC_K,    KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,
#ifdef USE_MIRYOKU
    BT_ESC,  KC_LALT,  KC_LGUI,  LT_DEL,  LT_BSPC, LT_ENT,  LT_TAB,   LT_SPC,  LT_ESC,  DB2,      KC_EXLM, BT_ENT
#else
    BT_ESC,  KC_LALT,  KC_LGUI,  LT_LBRC, LT_RBRC, LT_TAB,  LT_QUOT,  LT_SPC,  KC_UNDS, DB2,      KC_EXLM, BT_ENT
#endif
  ),
  [QWE] = LAYOUT(
    KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,     KC_O,    KC_BSPC,
    QT_A,    QT_S,     QT_D,     QT_F,    KC_G,                       KC_H,    QT_J,    QT_K,     QT_L,    QT_P,
    KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    KC_GRV,  KC_BSLS,  KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
    BT_ESC,  KC_LALT,  KC_LGUI,  LT_DEL,  LT_BSPC, LT_TAB,  LT_TAB,   LT_SPC,  KC_ESC,  DB2,      KC_EXLM, BT_ENT
  ),
  [VIM] = LAYOUT(
    _______, _______,  _______,  _______, _______,                    KC_B,    KC_0,    KC_DLR,   KC_E,    _______,
    _______, _______,  _______,  _______, _______,                    KC_H,    KC_J,    KC_K,     KC_L,    XXXXXXX,
    _______, _______,  _______,  _______, _______, _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______,  _______, _______
  ),
#ifdef USE_MIRYOKU
  [NUM] = LAYOUT(
    _______, _______,  _______,  _______, _______,                    KC_LBRC, KC_7,    KC_8,     KC_9,    KC_RBRC,
    _______, _______,  _______,  _______, _______,                    KC_EQL,  KC_4,    KC_5,     KC_6,    KC_SCLN,
    _______, _______,  _______,  _______, _______, _______, _______,  KC_BSLS, KC_1,    KC_2,     KC_3,    KC_GRV,
    _______, _______,  _______,  _______, _______, _______, KC_MINS,  KC_0,    KC_DOT,  _______,  _______, _______
  ),
#else
  [NUM] = LAYOUT(
    _______, _______,  _______,  _______, _______,                    KC_ASTR, KC_7,    KC_8,     KC_9,    KC_DEL,
    _______, _______,  _______,  _______, _______,                    KC_PLUS, KC_4,    KC_5,     KC_6,    KC_SCLN,
    _______, _______,  _______,  _______, _______, _______, _______,  KC_EQL,  KC_1,    KC_2,     KC_3,    KC_GRV,
    _______, _______,  _______,  _______, _______, _______, KC_MINS,  KC_0,    KC_DOT,  _______,  _______, _______
  ),
#endif
#ifdef USE_MIRYOKU
  [SYM] = LAYOUT(
    _______, _______,  _______,  _______, _______,                    KC_LCBR, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RCBR,
    _______, _______,  _______,  _______, _______,                    KC_PLUS, KC_DLR,  KC_PERC,  KC_CIRC, KC_COLN,
    _______, _______,  _______,  _______, _______, _______, _______,  KC_PIPE, KC_EXLM, KC_AT,    KC_HASH, KC_TILD,
    _______, _______,  _______,  _______, _______, _______, KC_UNDS,  KC_LPRN, KC_RPRN, _______,  _______, _______
  ),
#else
#error this needs fixing
  [SYM] = LAYOUT(
    _______, _______,  _______,  _______, _______,                    KC_LBRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RBRC,
    _______, _______,  _______,  _______, _______,                    _______, KC_DLR,  KC_PERC,  KC_LPRN, _______,
    _______, _______,  _______,  _______, _______, _______, _______,  _______, KC_DLR,  KC_PERC,  KC_CIRC, KC_COLN,
    _______, _______,  _______,  _______, _______, _______, KC_UNDS,  KC_LPRN, KC_RPRN, _______,  _______, _______
  ),
#endif
  [FUN] = LAYOUT(
    _______, _______,  _______,  _______, _______,                    KC_PSCR, KC_F7,   KC_F8,    KC_F9,   KC_F12,
    _______, _______,  _______,  _______, _______,                    KC_SCRL, KC_F4,   KC_F5,    KC_F6,   KC_F11,
    _______, _______,  _______,  _______, _______, _______, _______,  KC_PAUS, KC_F1,   KC_F2,    KC_F3,   KC_F10,
    _______, _______,  _______,  _______, _______, _______, KC_TAB,   KC_SPC,  KC_APP,  _______,  _______, _______
  ),
  [NAV] = LAYOUT(
    KC_PGUP, KC_HOME,  KC_UP,    KC_END,  KC_INS,                     _______, _______, _______,  _______, _______,
    KC_PGDN, KC_LEFT,  KC_DOWN,  KC_RGHT, CAPSWRD,                    _______, _______, _______,  _______, _______,
    _______, _______,  _______,  _______, KC_CAPS, _______, _______,  _______, _______, _______,  _______, _______,
    DF(QWE), DF(CMK),  _______,  _______, _______, _______, _______,  _______, _______, _______,  _______, _______
    /* set default layer qwerty or colemak */
  ),
};


////
// Macro implementations
////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // call Caps Word
    if (!process_caps_word(keycode, record)) { return false; }

    // macros
    switch (keycode) {
    case DB2:
        if (record->event.pressed) {
            // when keycode DB2 is pressed
            SEND_STRING("db2");
        } else {
            // when keycode DB2 is released
        }
        break;
    }
    return true;
};

