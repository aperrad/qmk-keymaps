#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "features/casemodes.h"
#include "features/functions.h"

// Tapping terms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FUNCT:
            // return TAPPING_TERM_BSPC;
        case NUM:
            return TAPPING_TERM_LAYER;
        default:
            return TAPPING_TERM;
    }
}
// END Tapping terms

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

uint8_t mod_state;
bool    process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t temp_keycode = keycode;
    mod_state             = get_mods();

    if (!process_case_modes(keycode, record)) {
        return false;
    }

    // Filter out the actual keycode from MT and LT keys.
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        temp_keycode &= 0xFF;
    }

    switch (temp_keycode) {
        // Undead characters
        case UD_APO:
            return undead(KC_QUOT, record->event.pressed);
        case UD_GRV:
            return undead(KC_GRV, record->event.pressed);
        case UD_TLD:
            return undead(S(KC_GRV), record->event.pressed);
        case UD_CIRC:
            return undead(S(KC_6), record->event.pressed);
        // Accented letters
        case E_ACUTE:
            return accented_letter(KC_QUOT, KC_E, record->event.pressed);
        case E_GRV:
            return accented_letter(KC_GRV, KC_E, record->event.pressed);
        case E_CIRC:
            return accented_letter(KC_CIRC, KC_E, record->event.pressed);
        case A_GRV:
            return accented_letter(KC_GRV, KC_A, record->event.pressed);
        case A_CIRC:
            return accented_letter(KC_CIRC, KC_A, record->event.pressed);
        case U_GRV:
            return accented_letter(KC_GRV, KC_U, record->event.pressed);
        case U_CIRC:
            return accented_letter(KC_CIRC, KC_U, record->event.pressed);
        case I_CIRC:
            return accented_letter(KC_CIRC, KC_I, record->event.pressed);
        case O_CIRC:
            return accented_letter(KC_CIRC, KC_O, record->event.pressed);
        case C_CED:
            return accented_letter(KC_QUOT, KC_C, record->event.pressed);

        // Case modes
        case CAPSWORD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
        case SNAKECASE:
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            return false;
        case KEBABCASE:
            if (record->event.pressed) {
                enable_xcase_with(KC_MINS);
            }
            return false;
        case CAMELCASE:
            if (record->event.pressed) {
                enable_xcase_with(OSM(MOD_LSFT));
            }
            return false;

        // Custom behavior : DEL on Shift + Bckspc
        case KC_BSPC: {
            static bool delkey_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else {
                // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
        }
            return true;
        case KC_DLR: {
            static bool eurkey_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_ALT) {
                    // Euro on international keyboard
                    add_mods(MOD_MASK_SHIFT);
                    register_code(KC_2);
                    eurkey_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else if (eurkey_registered) {
                    unregister_code(KC_2);
                    eurkey_registered = false;
                    return false;
            }
        }
        return true;
        // Chrome Dev Tools debugging
        case SHIFT_F8:
            if (record->event.pressed) {
                add_mods(MOD_MASK_SHIFT);
                register_code(KC_F8);
                set_mods(mod_state);
            } else {
                unregister_code(KC_F8);
            }
            return false;
        case SHIFT_F11:
            if (record->event.pressed) {
                add_mods(MOD_MASK_SHIFT);
                register_code(KC_F11);
                set_mods(mod_state);
            } else {
                unregister_code(KC_F11);
            }
            return false;
        default:
            return true;
            break;
    }
}


// ---- END Less simple keycodes ---- }}}

#ifdef AUTO_SHIFT_ENABLE
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MINUS ... KC_SLASH:
        case UD_CIRC:
        case KC_NONUS_BSLASH:
            return true;
    }
    return false;
}
#endif
