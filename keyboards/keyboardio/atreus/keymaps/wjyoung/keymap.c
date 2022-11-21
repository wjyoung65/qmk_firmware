// This is the personal keymap of Wayne Young implementing a variant
// of the Miryoku layout. I like the Miryoku layout, but want access
// to all 44 Atreus keys.

// to be exact, this is the Miryoku
//   * qwerty colemak-dh
//   * flip
//   * inverted T
//   * holding down SPACE does not shift layers b/c sometimes I want easy auto repeat
//   * backspace, enter, and escape in the corners
//   * thumb keys adjusted, still experimenting

#include QMK_KEYBOARD_H

//#define USE_MIRYOKU  // otherwise my map

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define QWE 0  // default base layer: qwerty
#define CMK 1  // alternate: colemak
#define NUM 2
#define SYM 3
#define FUN 4
#define NAV 5
#define MED 6
#define MOU 7  // mouse

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
#define QT_J    RCTL_T(KC_J)
#define QT_K    RSFT_T(KC_K)
#define QT_L    RALT_T(KC_L)
#define QT_SCLN RGUI_T(KC_SCLN)

// home row modifiers for qwerty: reduced set, lowered by one row
#define QT_Z    LSFT_T(KC_Z)
#define QT_X    LCTL_T(KC_X)
#define QT_SLSH RSFT_T(KC_SLSH)
#define QT_DOT  RCTL_T(KC_DOT)

#ifdef USE_MIRYOKU
// left-side thumb keys: hold for a layer shift, tap for normal key
#define LT_DEL  LT(FUN, KC_DEL)
#define LT_BSPC LT(NUM, KC_BSPC)
#define LT_ENT  LT(SYM, KC_ENT)

// right-side thumb keys: hold for a layer shift, tap for normal key
#define LT_TAB  LT(NAV, KC_TAB)
#define LT_SPC  KC_SPC
#define LT_ESC  LT(MOU, KC_ESC)

#else  // my thumb keys

// left-side thumb keys: hold for a layer shift, tap for normal key
#define LT_DEL  LT(FUN, KC_DEL)
//#define LT_QUOT LT(NUM, KC_QUOT)
#define LT_BSPC LT(NUM, KC_BSPC)
#define LT_TAB  LT(SYM, KC_TAB)

// right-side thumb keys
#define LT_MINS LT(NAV, KC_MINS)
//#define LT_BSPC LT(MOU, KC_BSPC)
#define LT_QUOT LT(MOU, KC_QUOT)
#define LT_SCLN LT(MOU, KC_SCLN)

#endif

// Left-side bottom corner key: hold for layer shift, tap for escape
//#define BT_ESC  LT(NUM, KC_ESC)
#define BT_ESC  LCTL_T(KC_ESC) // for one-hand ctl-c ctl-v
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
  [QWE] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
//  QT_A,    QT_S,    QT_D,    QT_F,    KC_G,                      KC_H,    QT_J,    QT_K,    QT_L,    QT_SCLN,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
//    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    QT_Z,    QT_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,    KC_M,    KC_COMM, QT_DOT,  QT_SLSH,
    BT_ESC,  KC_LALT, KC_LGUI, LT_DEL,  LT_BSPC, LT_TAB,  LT_MINS, KC_SPC,  LT_QUOT, DB2,     KC_EXLM, BT_ENT
  ),
  [CMK] = LAYOUT(
#ifdef USE_MIRYOKU
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    MT_A,    MT_R,    MT_S,    MT_T,    KC_G,                      KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_GRV,  KC_BSLS, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    BT_ESC,  KC_LALT, KC_LGUI, LT_DEL,  LT_BSPC, LT_ENT,  LT_TAB,  LT_SPC,  LT_ESC,  DB2,     KC_EXLM, BT_ENT
#else
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC,
    MT_A,    MT_R,    MT_S,    MT_T,    KC_G,                      KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_GRV,  KC_BSLS, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    BT_ESC,  KC_LALT, KC_LGUI, LT_DEL,  LT_BSPC, LT_TAB,  LT_MINS, KC_SPC,  LT_QUOT, DB2,     KC_EXLM, BT_ENT
#endif
  ),
  [NUM] = LAYOUT(
    _______, _______, _______, _______, _______,                   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,
    _______, _______, _______, _______, _______,                   KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN,
    _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,
#ifdef USE_MIRYOKU
    _______, _______, _______, _______, _______, _______, KC_MINS, KC_0,    KC_DOT,  _______, _______, _______
#else
    DF(QWE), _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, KC_UNDS, KC_0,    KC_DOT,  _______, _______, _______
#endif
  ),
  [SYM] = LAYOUT(
    _______, _______, _______, _______, _______,                   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
    _______, _______, _______, _______, _______,                   KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN,
    _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD,
    DF(QWE), _______, _______, _______, _______, _______, KC_EQL,  KC_LPRN, KC_RPRN, _______, _______, _______
  ),
  [FUN] = LAYOUT(
    _______, _______, _______, _______, _______,                   KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,
    _______, _______, _______, _______, _______,                   KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    _______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,
    DF(QWE), _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_APP,  _______, _______, _______
  ),
  [NAV] = LAYOUT(
    KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, CAPSWRD,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    _______, _______, _______, _______, KC_CAPS, _______, _______, XXXXXXX, KC_N,    XXXXXXX, XXXXXXX, XXXXXXX,
    DF(QWE), DF(CMK), DF(NUM), DF(MOU), _______, _______, _______, _______, _______, _______, _______, _______
    /* set default layer qwerty or colemak */
  ),
  [MOU] = LAYOUT( // mouse
    KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    DF(QWE), _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______, _______
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
            SEND_STRING("db2"); // when keycode DB2 is pressed
        } // else do nothing when keycode DB2 is released
        break;
  #ifdef USING_COLEMAK_BASELAYER
    case RCTL_T(KC_N): // src https://precondition.github.io/home-row-mods#rolled-modifiers-cancellation
        /*
        This piece of code nullifies the effect of Right Shift when tapping
        the RCTL_T(KC_N) key.
        This helps rolling over RSFT_T(KC_E) and RCTL_T(KC_N)
        to obtain the intended "en" instead of "N".
        Consequently, capital N can only be obtained by tapping RCTL_T(KC_N)
        and holding LSFT_T(KC_S) (which is the left Shift mod tap).
        */

        /*
        Detect the tap.
        We're only interested in overriding the tap behaviour
        in a certain circumstances. The hold behaviour can stay the same.
        */
        if (record->event.pressed && record->tap.count > 0) {
            // Detect right Shift
            if (get_mods() & MOD_BIT(KC_RSHIFT)) {
                // temporarily disable right Shift
                // so that we can send KC_E and KC_N
                // without Shift on.
                unregister_mods(MOD_BIT(KC_RSHIFT));
                tap_code(KC_E);
                tap_code(KC_N);
                // restore the mod state
                add_mods(MOD_BIT(KC_RSHIFT));
                // to prevent QMK from processing RCTL_T(KC_N) as usual in our special case
                return false;
            }
        }
         /*else process RCTL_T(KC_N) as usual.*/
        return true;

    case LCTL_T(KC_T):
        /*
        This piece of code nullifies the effect of Left Shift when
        tapping the LCTL_T(KC_T) key.
        This helps rolling over LSFT_T(KC_S) and LCTL_T(KC_T)
        to obtain the intended "st" instead of "T".
        Consequently, capital T can only be obtained by tapping LCTL_T(KC_T)
        and holding RSFT_T(KC_E) (which is the right Shift mod tap).
        */

        if (record->event.pressed && record->tap.count > 0) {
            if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                unregister_mods(MOD_BIT(KC_LSHIFT));
                tap_code(KC_S);
                tap_code(KC_T);
                add_mods(MOD_BIT(KC_LSHIFT));
                return false;
            }
        }
         /*else process LCTL_T(KC_T) as usual.*/
        return true;
  #endif
    } // end switch

    return true;
};

