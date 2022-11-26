// This is the personal keymap of Wayne Young implementing a variant
// of the Ben Valleck layout, that uses
//   - layer locks via thumb keys
//   - right-left thumb combo that returns to layer 0, always
//   - one shot modifiers on shift and control
// Rationale for switching from Miryoku to this layout:
//   - avoid holding down layer shift or shift key to reduce thumb strain
//     by using one-shot modifiers and layer lock rather than shift
//   - put more symbols on a single layer to avoid having to switch back and forth
//     when coding
//     - for example, ("\n"); is slow in Miryoku
//     - todo: add arrow keys to the symbols layer because modern IDEs often auto-pair quotes, braces, etc.
//   - less reliance on home row modifiers

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define QWE 0  // default base layer: qwerty
#define SYM 1
#define NUM 2
#define FUN 3
#define NAV 4
#define MED 5
#define MOU 6  // mouse

// Some handy macros to keep the keymaps clean and easier to maintain

// Left-side home row keys: hold for a modifier, tap for normal key
// #define MT_A  LGUI_T(KC_A)
// #define MT_R  LALT_T(KC_R)
// #define MT_S  LSFT_T(KC_S)
// #define MT_T  LCTL_T(KC_T)

// .. for qwerty
// #define QT_A  LCTL_T(KC_A)
// #define QT_A  LGUI_T(KC_A)
// #define QT_S  LALT_T(KC_S)
// #define QT_D  LSFT_T(KC_D)
// #define QT_F  LCTL_T(KC_F)
//
// Right-side home row keys: hold for a modifier, tap for normal key
// #define MT_N  RCTL_T(KC_N)
// #define MT_E  RSFT_T(KC_E)
// #define MT_I  LALT_T(KC_I)
// #define MT_O  RGUI_T(KC_O)

// .. for qwerty
// #define QT_J    RCTL_T(KC_J)
// #define QT_K    RSFT_T(KC_K)
// #define QT_L    RALT_T(KC_L)
// #define QT_SCLN RGUI_T(KC_SCLN)
// #define QT_SCLN RCTL_T(KC_SCLN)

// left-side thumb keys: hold for a layer shift, tap for normal key
// #define LT_DEL  LT(FUN, KC_DEL)
// #define LT_QUOT LT(NUM, KC_QUOT)
#define LT_BSPC LT(MOU, KC_BSPC)
// #define LT_TAB  LT(SYM, KC_TAB)

// right-side thumb keys
// #define LT_MINS LT(NAV, KC_MINS)
// #define LT_SPC  LT(NAV, KC_SPC)
// #define LT_QUOT LT(MOU, KC_QUOT)
// #define LT_SCLN LT(MOU, KC_SCLN)

// Left-side bottom corner key: hold for layer shift, tap for escape
// #define BT_ESC  LCTL_T(KC_ESC) // for one-hand ctl-c ctl-v

// Right-side bottom corner key: hold for shift, tap for enter
// #define BT_ENT  RCTL_T(KC_ENT)

#define BV_CTRL  OSM(MOD_LCTL)
#define BV_SFT   OSM(MOD_LSFT)
#define BV_SPC   KC_SPC  // OSM(MOD_LCTL)


////
// Macro enums
////
enum custom_keycodes {
    DB2 = SAFE_RANGE  // spit out "db2"
  , CTL_Z
  , CTL_X
  , CTL_C
  , CTL_V
  , TAB_PRV
  , TAB_NXT
};

////
// Keymap and layers
////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWE] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_ESC,  KC_LALT, KC_LGUI, BV_SFT,  TO(SYM), LT_BSPC, BV_CTRL, BV_SPC,  KC_MINS, KC_QUOT, DB2,     KC_ENT
  ),
  [SYM] = LAYOUT(
    KC_ESC,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_TAB,  KC_SCLN, KC_COLN, KC_PLUS, KC_CIRC,                   KC_PIPE, KC_DQUO, KC_LCBR, KC_RCBR, KC_ENT,
    KC_GRV,  KC_EXLM, KC_EQL,  KC_MINS, KC_BSLS, _______, _______, KC_N,    KC_UNDS, KC_LBRC, KC_RBRC, KC_TILD,
    _______, _______, _______, _______, TO(NUM), _______, KC_LALT, TO(QWE), _______, _______, DB2,     _______
  ),
  [NUM] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_ASTR, KC_7,    KC_8,    KC_9,    KC_BSPC,
    KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PLUS, KC_4,    KC_5,    KC_6,    KC_ENT,
    TO(FUN), TO(MOU), XXXXXXX, XXXXXXX, CAPSWRD, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_SLSH,
    _______, _______, _______, _______, TO(NUM), _______, KC_LALT, TO(QWE), KC_0,    KC_0,    KC_DOT,  _______
  ),
  [FUN] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,
    KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    XXXXXXX, TO(MOU), XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,
    _______, _______, _______, _______, TO(NUM), _______, KC_LALT, TO(QWE), XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),
  [MOU] = LAYOUT( // mouse navigation
    KC_ESC,  KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                   XXXXXXX, TAB_PRV, TAB_NXT, XXXXXXX, XXXXXXX,
    KC_TAB,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    TO(FUN), KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, TO(NUM), _______, KC_LALT, TO(QWE), XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),
#ifdef UNUSED
  [NAV] = LAYOUT(
    KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, CAPSWRD,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    _______, _______, _______, _______, KC_CAPS, _______, _______, XXXXXXX, KC_N,    XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, TO(NUM), _______, _______, TO(QWE), _______, _______, _______, _______
    /* set default layer qwerty or colemak */
  ),
#endif
};


////
// Macro implementations
////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // call Caps Word
    if (!process_caps_word(keycode, record)) { return false; }

    // Get current mod and one-shot mod states.
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    // macros
    switch (keycode) {
    case DB2:
        if (record->event.pressed) {
          if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            SEND_STRING("DB2"); // when keycode DB2 is pressed
            // if (mods & MOD_MASK_SHIFT)
            //   set_mods(MOD_MASK_SHIFT);
          }
          else {
            SEND_STRING("db2"); // when keycode DB2 is pressed
          }
        } // else do nothing when keycode DB2 is released
        break;
    case CTL_Z: if (record->event.pressed) { SEND_STRING(SS_LCTL(SS_TAP(X_Z))); } break;
    case CTL_X: if (record->event.pressed) { SEND_STRING(SS_LCTL(SS_TAP(X_X))); } break;
    case CTL_C: if (record->event.pressed) { SEND_STRING(SS_LCTL(SS_TAP(X_C))); } break;
    case CTL_V: if (record->event.pressed) { SEND_STRING(SS_LCTL(SS_TAP(X_V))); } break;
    case TAB_NXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
      }
      break;
    case TAB_PRV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_TAB))));
      }
      break;
    } // end switch

    return true;
}

#ifdef DID_NOT_WORK_AS_EXPECTED
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Keys where I want "tap, then hold" to repeat the tap action.
    // Key repeating is useful on hjkl in Vim for navigation.
    case KC_H:
    case KC_J:
    case KC_K:
    case KC_L:
      return false;
    // Keys where I don't want key repeating.
    default:
      return true;
  }
}
#endif
