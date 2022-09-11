#include QMK_KEYBOARD_H
#include "aperrad.h"

// include the gboards helpers for combos defined in userspace combos.def
#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [CLM] = LAYOUT(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    UD_APO,
  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                             LA_EXT,  KC_SPC,                    SHFT_BSPC, LA_SYM
  ),
  [SYM] = LAYOUT(
  KC_EXLM, KC_AT,   KC_HASH, KC_COLN, KC_SCLN,                   KC_EQL,  KC_7,    KC_8,    KC_9,   KC_PLUS,
  KC_BSLS, KC_PIPE, KC_LCBR, KC_LPRN, KC_LBRC,                   KC_ASTR, KC_4,    KC_5,    KC_6,   KC_MINS,
  KC_MINS, KC_UNDS, KC_RCBR, KC_RPRN, KC_RBRC,                   KC_0   , KC_1,    KC_2,    KC_3,   KC_DOT,
                             LA_FUN,  LA_SYM2,                   _______, XXXXXXX
  ),

  [SYM2] = LAYOUT(
  XXXXXXX, KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN3,                   DEG, KC_AMPR, KC_GRV,  KC_TILD, KC_QUOT,
  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,                   EURO, KC_DLR,  KC_PERC, KC_CIRC, KC_UNDS,
  XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,                   SECT, KC_EXLM, KC_AT,   KC_HASH, KC_BSLS,
                             _______, XXXXXXX,                   _______, XXXXXXX
  ),
    [EXT] = LAYOUT(
  //CMD_TAB, ALT_TAB, KC_WBAK, KC_WFWD, RESET,                    KC_HOME, KC_PGDN,  KC_PGUP, KC_END, _______ ,
  KC_ESC,  KC_WBAK, KC_WFWD, PRINT,   RESET,                      KC_HOME, KC_PGDN,  KC_PGUP, KC_END, _______ ,
  OS_CMD,  OS_ALT,  OS_SFT,  OS_CTL,  OSM_MEH,                    KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT,KC_DEL,
  KC_UNDO, KC_CUT,  KC_COPY,  KC_TAB, KC_PSTE,                   _______, KC_BSPC,   KC_LSFT, KC_APP, KC_ENT,
  //XXXXXXX, S_TAB,   KC_TAB,  OS_CMD,  _______,                  _______, KC_BSPC,  KC_F5,  KC_F12, KC_ENT,
                             XXXXXXX, _______,                    KC_ENT,  LA_FUN
  ),
   [FUN] = LAYOUT(
  KC_MUTE, KC_VOLD, KC_MPLY, KC_VOLU, XXXXXXX,                   KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,
  OS_CMD,  OS_ALT,  OS_SFT,  OS_CTL,  OSM_MEH,                   KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
  XXXXXXX, KC_MPRV, KC_MSTP, KC_MNXT, XXXXXXX,                   KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX,
                             XXXXXXX, _______,                   KC_ENT, XXXXXXX
  )
};
// clang-format on
