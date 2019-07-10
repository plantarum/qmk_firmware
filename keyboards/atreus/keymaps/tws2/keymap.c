// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,    KC_TRNS,  KC_Y,    KC_U,     KC_I,    KC_O,     KC_P    },
  {MT(MOD_LALT, KC_A),    KC_S,    KC_D,    KC_F,          KC_G,    KC_TRNS,
   KC_H,    KC_J,     KC_K,    KC_L,     MT(MOD_RALT, KC_SCLN) },
  {MT(MOD_LSFT, KC_Z),    KC_X,    KC_C,    KC_V,          KC_B,    KC_TAB,  KC_N,    KC_M,     KC_COMM, KC_DOT,   MT(MOD_RSFT, KC_SLSH) },
  {MT(MOD_LCTL, KC_ESC),  OSL(_LW),  KC_LGUI, OSL(_RS), KC_BSPC, KC_ENT,  KC_SPC,  OSL(_RS), KC_QUOT, KC_MINS, MT(MOD_RCTL, KC_EQUAL)  }
},
/*
 *  !       @     #     $     %        ||     ^    &     *     (    )
 *  1       2     3     4     5        ||     6    7     8     9    0
 *  [       ]     {     }     `        ||     ~    '     "     \    |
 * lower  insert super shift del  ctrl || alt sp   fn    .     -    =
 */
[_RS] = { /* [> RAISE <] */
  {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
  {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0},
  {KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_GRV,  KC_TRNS, KC_TILD, KC_QUOT, KC_DQT,  KC_BSLS, KC_PIPE},
  {TG(_LW), KC_INS,  KC_LGUI, KC_TRNS, KC_DELT, KC_TRNS, KC_SPC,  KC_TRNS, KC_DOT, KC_TRNS, KC_TRNS}
},
/*
 * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
 *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
 *       volup             reset      ||             F1    F2    F3   F12
 *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
 */
[_LW] = { /* [> LOWER <] */
  {KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_END,  KC_TRNS, KC_PGUP, KC_F7,   KC_F8, KC_F9,   KC_F10},
  {KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_HOME, KC_TRNS, KC_DOWN, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT},
   // KC_F4,   KC_F5,   KC_F6,   KC_F11
  {KC_F1, KC_F2,   KC_F3,   KC_F4,   RESET,   KC_LCTL, KC_HOME, KC_F1,   KC_F2,   KC_F3,   KC_F12},
  {TO(_QW), OSL(_LW), KC_LGUI, KC_LSFT, KC_BSPC, KC_LALT, KC_SPC, TO(_QW), KC_PSCR, KC_SLCK, TO(_QW)}
}};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(_LW, KC_SPC), // to layer 1 while held, space when tapped
};

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
