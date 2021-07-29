#include QMK_KEYBOARD_H
#include <stdio.h>

extern uint8_t is_master;

#include "keycodes.h"

#include "features/functions.h"
#include "features/casemodes.h"

#ifdef OLED_DRIVER_ENABLE
#    include "style/oled.h"
#endif

#ifdef RGBLIGHT_ENABLE
#    include "style/rgb.h"
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_MINUS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
OSM(MOD_LSFT),  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN, UD_APO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
OSM(MOD_LCTL),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_EQL,\
  //|--------+--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------+--------|
                                                                                        // DEAD SOLDERING ATM
                                     OSM(MOD_LALT),  KC_SPC, NUM,   FUNCT, GUI_T(KC_ENT), KC_CIRC \
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,HOME_NUM_1,HOME_NUM_2,HOME_NUM_3,HOME_NUM_4,KC_5,                 KC_6,HOME_NUM_7,HOME_NUM_8,HOME_NUM_9,HOME_NUM_0,KC_COLON,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD,  KC_GRV, KC_QUOT,  KC_LBRC, KC_LCBR,                    KC_RCBR, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLASH,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  KC_TRNS, NUM,      ADJUST, KC_TRNS, KC_TRNS \
                                      //`--------------------------'  `--------------------------'
    ),

  [_FUNCTION] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_END, XXXXXXX, XXXXXXX, KC_PGUP,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_APP,  KC_F11, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_ESC, XXXXXXX, KC_COPY, KC_PASTE, KC_PGDN,                    KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_F12, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, ADJUST,     FUNCT, KC_TRNS, KC_TRNS \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      TO(_UTILS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX , XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_CAPS, G(KC_LEFT),G(KC_DOWN),G(KC_UP),G(KC_RIGHT), XXXXXXX,               C(KC_LEFT),S(KC_DOWN),S(KC_UP),C(KC_RIGHT), XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, XXXXXXX, RESET,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, ADJUST,     ADJUST,  XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),
  //TODO Tooling for debugging in Eclipse and Chrome
  [_UTILS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    BASE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX,  KC_F8,   KC_F10, KC_F11, SHIFT_F11, SHIFT_F8,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    } 
}

void oled_task_user(void) { render_status(); }
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    set_layer_color(state);
#endif

#ifdef AUTO_SHIFT_ENABLE
    switch (biton32(state)) {
        case _QWERTY:
            autoshift_enable();
            break;
        default:
            autoshift_disable();
            break;
    }
#endif

    return state;
}
