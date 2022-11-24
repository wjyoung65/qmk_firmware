#pragma once

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

//#include "../../config.h"

// Recommended when using Mod-Tap on alphanumeric keys to
// avoid hold function taking precendence when the next key
// is pressed quickly
#ifdef IGNORE_MOD_TAP_INTERRUPT
  #undef IGNORE_MOD_TAP_INTERRUPT
#endif
#define IGNORE_MOD_TAP_INTERRUPT

// How long key need to be held down to be considered a hold vs tap
#ifdef TAPPING_TERM
  #undef TAPPING_TERM
#endif
#define TAPPING_TERM 230  // in milliseconds, default is 200

// Turns on caps word by pressing both shift keys.
// Not using: pressing any other modifier turns it off,
// so does not play well with home row modifiers
//#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Affects repeating. One tap followed by hold makes the key repeat.
// Useful for hjkl. Configure which keys in keymap.c
//#define TAPPING_FORCE_HOLD_PER_KEY

#endif
