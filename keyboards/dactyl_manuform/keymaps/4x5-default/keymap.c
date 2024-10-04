#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _MOVE   1
#define _SYM    2
#define _FN     3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP_4x5(
  // left hand
   KC_T,    KC_R,   KC_E, KC_W,  KC_Q,
   KC_G,    KC_F,   KC_D, KC_S,  KC_A,
   KC_B,    KC_V,   KC_C, KC_X,  KC_Z,
            KC_TAB, KC_GRV,
                               SFT_T(KC_ENT), LT(_SYM, KC_DEL),
                               CTL_T(KC_ESC), LT(_MOVE, KC_SPC),
                               LT(_FN, KC_TAB), KC_BTN1,
        // right hand
                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
                     KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                       KC_MINS, KC_SCLN,
        LT(_MOVE, KC_SPC), LT(_SYM, KC_BSPC),
        CTL_T(KC_PGUP), GUI_T(KC_PGDN),
        KC_LALT, KC_DQT),
[_SYM] = KEYMAP_4x5(
  // left hand
   KC_PIPE, KC_RCBR, KC_LCBR, KC_EXLM, KC_PIPE,
   KC_DLR,  KC_RPRN, KC_LPRN, KC_HASH, KC_AMPR,
   KC_BSLS, KC_RBRC, KC_LBRC, KC_PERC, KC_SCLN,
            KC_TAB, KC_GRV,
                               SFT_T(KC_ENT), LT(_SYM, KC_DEL),
                               CTL_T(KC_ESC), LT(_MOVE, KC_SPC),
                               LT(_FN, KC_TAB), KC_BTN1,
        // right hand
                     KC_PLUS, KC_7, KC_8, KC_9, KC_CIRC,
                     KC_EQL,  KC_4, KC_5, KC_6, KC_ASTR,
                     KC_MINS, KC_1, KC_2, KC_3, KC_SLSH,
                                       KC_0, KC_DOT,
        LT(_MOVE, KC_SPC), LT(_SYM, KC_BSPC),
        CTL_T(KC_PGUP), GUI_T(KC_PGDN),
        KC_LALT, KC_DQT),
[_MOVE] = KEYMAP_4x5(
  // left hand
   KC_WH_U, KC_WH_D, KC_MS_U, KC_WH_U,  QK_REBOOT,
   KC_LGUI, KC_MS_R, KC_MS_D, KC_MS_L,  KC_BTN3,
   KC_WH_D, KC_BTN3, KC_BTN2, KC_BTN5,  KC_BTN1,
            KC_TAB, KC_GRV,
                               SFT_T(KC_ENT), LT(_SYM, KC_DEL),
                               CTL_T(KC_ESC), LT(_MOVE, KC_SPC),
                               LT(_FN, KC_TAB), KC_BTN1,
        // right hand
                     KC_HOME, KC_PGUP, KC_PGDN, KC_END, _______,
                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, LALT(KC_TAB),
                     KC_CAPS, KC_DEL,  KC_DEL,  _______,  QK_REBOOT,
                                       KC_MINS, KC_SCLN,
        LT(_MOVE, KC_SPC), LT(_SYM, KC_BSPC),
        CTL_T(KC_PGUP), GUI_T(KC_PGDN),
        KC_LALT, KC_DQT),
[_FN] = KEYMAP_4x5(
  // left hand
   KC_WH_U,  KC_F4,  KC_F3,  KC_F2,  KC_F1,
   KC_LGUI,  KC_F8,  KC_F7,  KC_F6,  KC_F5,
   KC_WH_D,  KC_F12, KC_F11, KC_F10, KC_F9,
            KC_TAB, KC_GRV,
                               SFT_T(KC_ENT), LT(_SYM, KC_DEL),
                               CTL_T(KC_ESC), LT(_MOVE, KC_SPC),
                               LT(_FN, KC_TAB), KC_BTN1,
        // right hand
                     _______, _______, _______, _______, _______,
                     KC_CALC, KC_MAIL, KC_MYCM, KC_WHOM, _______,
                     _______, _______, _______, _______, _______,
                                       KC_MINS, KC_SCLN,
        LT(_MOVE, KC_SPC), LT(_SYM, KC_BSPC),
        CTL_T(KC_PGUP), GUI_T(KC_PGDN),
        KC_LALT, KC_DQT),
};



void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
