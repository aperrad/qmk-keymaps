#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "features/casemodes.h"
#include "features/functions.h"

#ifdef COMBO_ENABLE
// clang-format off
enum combo_events {
    WER_E_CIRC,
    ER_E_ACUTE,
    WE_E_GRV,
    ASD_A_CIRC,
    AS_A_GRV,
    YUI_U_CIRC,
    UI_U_GRV,
    UIO_I_CIRC,
    IOP_O_CIRC,
    XC_C_CED,
    RT_OPEN_PRN,
    YU_CLOSE_PRN,
    TY_CAPSWORD,
    BN_XCASE,
    GH_SEARCH_XCASE,
};
// clang-format on

// Accented
const uint16_t PROGMEM er_combo[]  = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM we_combo[]  = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wer_combo[] = {KC_W, KC_E, KC_R, COMBO_END};

const uint16_t PROGMEM as_combo[]  = {HOME_A, HOME_S, COMBO_END};
const uint16_t PROGMEM asd_combo[] = {HOME_A, HOME_S, HOME_D, COMBO_END};

const uint16_t PROGMEM ui_combo[]  = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM yui_combo[] = {KC_Y, KC_U, KC_I, COMBO_END};

const uint16_t PROGMEM uio_combo[] = {KC_U, KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM iop_combo[] = {KC_I, KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};

// Parenthesis, curly & square brackets
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};

// Features
const uint16_t PROGMEM ty_combo[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM bn_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    // Accented E combos
    [WER_E_CIRC] = COMBO_ACTION(wer_combo),
    [ER_E_ACUTE] = COMBO_ACTION(er_combo),
    [WE_E_GRV]   = COMBO_ACTION(we_combo),
    // Accented A combos
    [ASD_A_CIRC] = COMBO_ACTION(asd_combo),
    [AS_A_GRV]   = COMBO_ACTION(as_combo),

    // Accented U combos
    [YUI_U_CIRC] = COMBO_ACTION(yui_combo),
    [UI_U_GRV]   = COMBO_ACTION(ui_combo),

    // Accented I combos
    [UIO_I_CIRC] = COMBO_ACTION(uio_combo),

    // Accented O combos
    [IOP_O_CIRC] = COMBO_ACTION(iop_combo),

    // Accented C combos
    [XC_C_CED] = COMBO_ACTION(xc_combo),

    // Dev combos
    [RT_OPEN_PRN]  = COMBO_ACTION(rt_combo),
    [YU_CLOSE_PRN] = COMBO_ACTION(yu_combo),

    // Feature combos
    [TY_CAPSWORD] = COMBO_ACTION(ty_combo),
    [BN_XCASE]    = COMBO_ACTION(bn_combo),
    [GH_SEARCH_XCASE]    = COMBO_ACTION(gh_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    uint8_t mod_state = get_mods();
    switch (combo_index) {
        case WER_E_CIRC:
            accented_letter(KC_CIRC, KC_E, pressed);
            break;
        case YUI_U_CIRC:
            accented_letter(KC_CIRC, KC_U, pressed);
            break;
        case ASD_A_CIRC:
            accented_letter(KC_CIRC, KC_A, pressed);
            break;
        case UIO_I_CIRC:
            accented_letter(KC_CIRC, KC_I, pressed);
            break;
        case IOP_O_CIRC:
            accented_letter(KC_CIRC, KC_O, pressed);
            break;
        case WE_E_GRV:
            accented_letter(KC_GRV, KC_E, pressed);
            break;
        case AS_A_GRV:
            accented_letter(KC_GRV, KC_A, pressed);
            break;
        case UI_U_GRV:
            accented_letter(KC_GRV, KC_U, pressed);
            break;
        case ER_E_ACUTE:
            accented_letter(KC_QUOT, KC_E, pressed);
            break;
        case XC_C_CED:
            accented_letter(KC_QUOT, KC_C, pressed);
            break;
        case RT_OPEN_PRN:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    // First canceling both shifts so that shift isn't applied
                    // to the KC_LBRC keycode since that would result in
                    // a "{" instead of a "[".
                    del_mods(MOD_MASK_SHIFT);
                    send_string("[");
                    // "resuming" *the* shift so that you can hold shift
                    // and the square brackets combo still works without
                    // having to re-press shift every time.
                    set_mods(mod_state);
                } else if (mod_state & MOD_MASK_ALT) {
                    del_mods(MOD_MASK_ALT);
                    del_mods(MOD_MASK_SHIFT);
                    send_string("{");
                    set_mods(mod_state);
                } else {
                    send_string("(");
                }
            }
            break;
        case YU_CLOSE_PRN:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("]");
                    set_mods(mod_state);
                } else if (mod_state & MOD_MASK_ALT) {
                    del_mods(MOD_MASK_ALT);
                    del_mods(MOD_MASK_SHIFT);
                    send_string("}");
                    set_mods(mod_state);
                } else {
                    send_string(")");
                }
            }
            break;
        case TY_CAPSWORD:
            if (pressed) {
                enable_caps_word();
            }
            break;
        case BN_XCASE:
            if (pressed) {
                // SCREAMING_SNAKE_CASE
                if (mod_state & MOD_MASK_SHIFT) {
                    enable_caps_word();
                    enable_xcase_with(KC_UNDERSCORE);
                }
                // kebab-case
                else if (mod_state & MOD_MASK_ALT) {
                    enable_xcase_with(KC_MINS);
                }
                // camelCase
                else {
                    enable_xcase_with(OSM(MOD_LSFT));
                }
            }
            break;
              case GH_SEARCH_XCASE:
            if (pressed) {
                // search*xcase
                enable_xcase_with(KC_ASTR);
            }
            break;
    }
}

// Combo terms
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case WER_E_CIRC:
        case UIO_I_CIRC:
        case YUI_U_CIRC:
        case ASD_A_CIRC:
        case IOP_O_CIRC:
            return 40;
        default:
            return COMBO_TERM;
    }
    return COMBO_TERM;
}
#endif
