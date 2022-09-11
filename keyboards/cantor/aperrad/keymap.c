#include QMK_KEYBOARD_H
#include "aperrad.h"
#include "features/features.h"

// include the gboards helpers for combos defined in userspace combos.def
#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[CLM] = LAYOUT_split_3x6_3(
  KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    UD_APO,  _______,
  KC_LSFT,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
  KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                              KC_LALT, KC_SPC,  LA_EXT,                    LA_SYM, KC_BSPC, _______
),

[QWR] = LAYOUT_split_3x6_3(
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    _______,
  KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_QUOT, _______,
  KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, _______,
                              KC_LALT, KC_SPC,  LA_EXT,                    LA_SYM, KC_BSPC, _______
),

[SYM] = LAYOUT_split_3x6_3(
  _______,  KC_EXLM, KC_AT,    KC_HASH, KC_COLN, KC_SCLN,                   KC_EQL, KC_7,    KC_8,    KC_9,    KC_PLUS,  _______,
  _______,  KC_BSLS, KC_PIPE,  KC_LCBR, KC_LPRN, KC_LBRC,                   KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
  _______,  KC_MINS, KC_UNDS,  KC_RCBR, KC_RPRN, KC_RBRC,                   KC_0   , KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
                               _______, LA_SYM2, _______,                   XXXXXXX, _______, _______
),
 
[SYM2] = LAYOUT_split_3x6_3(
  _______,  _______, KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN3,                   _______, KC_AMPR, KC_GRV,  KC_TILD, KC_QUOT, _______,
  _______,  _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,                   EURO_SYM, KC_DLR,  KC_PERC, KC_CIRC, KC_UNDS,_______,
  _______,  _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,                   _______, KC_EXLM, KC_AT,   KC_HASH, KC_BSLS, _______,
                              _______, XXXXXXX, _______,                   XXXXXXX, _______, _______
),         

[EXT] = LAYOUT_split_3x6_3(
  _______,  CMD_TAB, ALT_TAB, KC_WBAK, KC_WFWD, RESET,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______ , _______,
  _______,  KC_ESC,  ML_alt,  ML_sft,  ML_ctl,  OSM_MEH,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_BSPC, _______,
  _______,  XXXXXXX, S_TAB,   KC_TAB,  OS_CMD,  _______,                   LEADER, KC_ENT,  KC_F5,   KC_F12, KC_DEL,  _______,
                              _______, _______, XXXXXXX,                   _______,LA_FUN,  _______
),

[FUN] = LAYOUT_split_3x6_3(
  _______,  KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE,                   KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX, _______,
  _______,  _______, _______, _______, _______, _______,                   KC_F11,  KC_F4,   KC_F5,   KC_F6,   DF(CLM), _______,  
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_F10,  KC_F1,   KC_F2,   KC_F3,   DF(QWR), _______,
                             _______, _______, XXXXXXX,                    _______, XXXXXXX, _______
)
};
// clang-format on
