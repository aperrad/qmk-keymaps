#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers {
    _QWERTY = 0,
    _NUM,
    _FUNCTION,
    _ADJUST,
    _UTILS,
};

// ---- Simple keycodes ---- {{{
// QWERTY Home Row Mods
// QWERTY LAYER
// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// NUM LAYER
// Left-hand home row mods
#define HOME_NUM_1 LGUI_T(KC_1)
#define HOME_NUM_2 LALT_T(KC_2)
#define HOME_NUM_3 LSFT_T(KC_3)
#define HOME_NUM_4 LCTL_T(KC_4)

// Right-hand home row mods
#define HOME_NUM_7 RCTL_T(KC_7)
#define HOME_NUM_8 RSFT_T(KC_8)
#define HOME_NUM_9 LALT_T(KC_9)
#define HOME_NUM_0 RGUI_T(KC_0)

// FN LAYER
// Left-hand home row mods
#define HOME_FN_HOME LGUI_T(KC_HOME)
#define HOME_FN_END LALT_T(KC_END)
#define HOME_FN_SHFT KC_LSFT
#define HOME_FN_CTL KC_LCTL

// Layer keys
#define BASE TO(_QWERTY)
#define NUM LT(_NUM, KC_GRV)
#define FUNCT LT(_FUNCTION, KC_BSPC)
#define UTILS TO(_UTILS)
#define ADJUST MO(_ADJUST)

// Misc
#define KC_EURO S(A(KC_2))

// ---- END Simple Keycodes ---- }}}

// ---- Less simple keycodes ---- {{{
enum custom_keycodes {
    // Undead characters
    UD_APO = SAFE_RANGE,
    UD_GRV,
    UD_TLD,
    UD_CIRC,

    // Accented letters
    E_ACUTE,
    E_GRV,
    E_CIRC,
    A_GRV,
    U_GRV,
    A_CIRC,
    I_CIRC,
    O_CIRC,
    U_CIRC,
    C_CED,

    // Case modes
    CAPSWORD,
    CAMELCASE,
    SNAKECASE,
    KEBABCASE,

    // Chrome Dev Tools shortcuts
    SHIFT_F8,
    SHIFT_F11
};
