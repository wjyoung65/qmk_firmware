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

// qmk compile -kb keyboardio/atreus -km wjyoung
// sudo avrdude -p atmega32u4 -c avr109 -U flash:w:keyboardio_atreus_wjyoung.hex -P /dev/ttyACM0

#include QMK_KEYBOARD_H

#ifdef USING_BSDI
////
// Insert key state definition (Insert/Overwrite Mode)
////
static bool ins_state = true;
#endif

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
  , CK_BSDI  // Backspace/Delete/Insert from lms_ace01
  , MY_ENT   // return to base layer when enter is pressed
  , MY_ESC   // return to base layer when escape is pressed
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define QWE 0  // default base layer: qwerty
#define NUM 1
#define FUN 2

// Some handy macros to keep the keymaps clean and easier to maintain

// Bottom row modifiers for qwerty
#define QT_X     LALT_T(KC_X)
#define QT_C     LSFT_T(KC_C)
#define QT_V     LCTL_T(KC_V)

#define QT_M     RCTL_T(KC_M)
#define QT_COMM  RSFT_T(KC_COMM)
#define QT_DOT   LALT_T(KC_DOT)

// Bottom row modifiers for numbers layer
#define QT_MINS  LALT_T(KC_MINS)
#define QT_EQL   LSFT_T(KC_EQL)
#define QT_GRV   LCTL_T(KC_GRV)

#define QT_BSLS  LCTL_T(KC_BSLS)
#define QT_LBRC  LSFT_T(KC_LBRC)
#define QT_RBRC  LALT_T(KC_RBRC)

// left-side thumb keys: hold for a layer shift, tap for normal key
#define LT_DEL  LT(FUN, KC_DEL)
#define LT_ESC  LT(NUM, KC_ESC)
#define LT_TAB  KC_TAB

// right-side thumb keys
#define LT_ENT  KC_ENT
#define LT_SPC  LT(NUM, KC_SPC)
#define LT_BSPC LT(FUN, KC_BSPC)

////
// Keymap and layers
////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWE] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    QT_X,    QT_C,    QT_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,    QT_M,    QT_COMM, QT_DOT,  KC_SLSH,
    KC_LCTL, KC_LGUI, KC_LALT, LT_DEL,  LT_ESC,  LT_TAB,  LT_ENT,  LT_SPC,  LT_BSPC, KC_MINS, DB2,     KC_RSFT
  ),
  [NUM] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   
    KC_EXLM, KC_LT,   KC_GT,   KC_TILD, CAPSWRD,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    KC_PLUS, QT_MINS, QT_EQL,  QT_GRV,  XXXXXXX, _______, _______, KC_UNDS, QT_BSLS, QT_LBRC, QT_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_SPC,  KC_BSPC, _______, _______, _______
  ),
  [FUN] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_CAPS, XXXXXXX, XXXXXXX, KC_PGUP, CAPSWRD,                   KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, _______, _______, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};


////
// Macro implementations
////
///
void return_to_base_layer(void)
{
//  layer_off(SYM);
  layer_off(NUM);
//  layer_off(MOU);
  layer_off(FUN);
  layer_on(QWE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // call Caps Word
    if (!process_caps_word(keycode, record)) { return false; }

    // Get current mod and one-shot mod states.
    const uint8_t mod_state = get_mods();
    const uint8_t osm_state = get_oneshot_mods();

    // macros
    switch (keycode) {
    case DB2:
        if (record->event.pressed) {
          if ((mod_state | osm_state) & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            SEND_STRING("DB2"); // when keycode DB2 is pressed
            // if (mod_state & MOD_MASK_SHIFT)
            //   set_mods(MOD_MASK_SHIFT);
          }
          else {
            SEND_STRING("db2"); // when keycode DB2 is pressed
          }
          return false; // end further processing of this key
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
      return false;  // end further processing of this key
      break;
    case TAB_PRV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_TAB))));
      }
      return false;  // end further processing of this key
      break;
#ifdef USING_BSDI
// Not using this b/c if I want to fix typos when CAPSWRD is on
    case CK_BSDI: {  // Backspace/Delete/Insert
      static bool delkey_registered = false;

      if (record->event.pressed) {
        // Ctrl   -> Insert/Overwrite Mode
        // Shift  -> Delete
        // Normal -> Backspace
        if ((mod_state | osm_state) & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
          del_oneshot_mods(MOD_MASK_CTRL);

          tap_code(KC_INS);

          set_mods(mod_state);
          set_oneshot_mods(osm_state);

          ins_state = !ins_state;
        } else if ((mod_state | osm_state) & MOD_MASK_SHIFT) {
          delkey_registered = true;

          del_mods(MOD_MASK_SHIFT);
          del_oneshot_mods(MOD_MASK_SHIFT);

          register_code(KC_DEL);

          set_mods(mod_state);
          set_oneshot_mods(osm_state);
        } else {
          register_code(KC_BSPC);
        }
      } else {
        // Unregister keycode sent after the release of CK_BSDI
        if (delkey_registered) {
          unregister_code(KC_DEL);
          delkey_registered = false;
        } else {
          unregister_code(KC_BSPC);
        }
      }
      return false;  // end further processing of this key
      break;
    } // end case CK_BSDI
#endif
    case MY_ENT: {
      if (record->event.pressed) {
        return_to_base_layer();
        tap_code(KC_ENT);
      }
      return false;
      break;
    }
    case MY_ESC: {
      if (record->event.pressed) {
        return_to_base_layer();
        tap_code(KC_ESC);
      }
      return false;
      break;
    }
    }  // end switch

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
