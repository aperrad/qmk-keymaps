#include QMK_KEYBOARD_H

#include "aperrad.h"

bool cmd_tab_active = false;
bool alt_tab_active = false;

uint8_t mod_state;
bool    process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&alt_tab_active, KC_LALT, KC_TAB, ALT_TAB, keycode, record);
    update_swapper(&cmd_tab_active, KC_LGUI, KC_TAB, CMD_TAB, keycode, record);

#ifdef CUSTOM_LEADER_ENABLE
    if (!process_leader(keycode, record)) {
        return false;
    }
#endif
// ------------------------------------------------------------------------call case modes----------------------------------------------------------------
#ifdef CASEMODES_ENABLE
    if (!process_case_modes(keycode, record)) {
        return false;
    }
#endif
// ------------------------------------------------------------------------------call custom one shots----------------------------------------------------------------
#ifdef CUSTOM_ONE_SHOT_ENABLE
    process_custom_one_shot(keycode, record);
#endif
    // ------------------------------------------------------------------------------process_eos_logic----------------------------------------------------------------
#ifdef EOS_ENABLE
    process_eos(keycode, record);
#endif
#ifdef CUSTOM_WORD_LINE_SELECTION_ENABLE
    if (!process_word_line_selection(keycode, record)) {
        return false;
    }
#endif
    uint16_t temp_keycode = keycode;
    mod_state             = get_mods();

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
        case EURO_SYM:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P2) SS_TAP(X_P8)));  // send euro symbol
            }
            return false;
            // ------------------------------------------------------------------------call leader ----------------------------------------------------------------
#ifdef CUSTOM_LEADER_ENABLE
        case LEADER:
            if (record->event.pressed) {
#    ifdef CUSTOM_LEADER_TO_DL
                if (IS_LAYER_ON(_NAV)) {
                    layer_off(_NAV);
                    layer_toggle_flag = false;
                }
                if (IS_LAYER_ON(_NUM)) {
                    layer_off(_NUM);
                    layer_toggle_flag = false;
                }
#    endif
                start_leading();
            }
            return false;
#endif
            // ------------------------------------------------------------------------ toggles case modes ----------------------------------------------------------------
#ifdef CASEMODES_ENABLE
        case CAPS_WORD:
            if (record->event.pressed) {
                toggle_caps_word();
            }
            return false;

        case SNAKE_CASE:
            if (record->event.pressed) {
                toggle_xcase();
            }
            return false;

        case NUM_WORD:
            if (record->event.pressed) {
                toggle_num_word();
            }
            return false;
#endif
        default:
            return true;
            break;
    }
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CUSTOM_ONE_SHOT_ENABLE
    release_custom_one_shot(keycode, record);
#endif
#ifdef EOS_ENABLE  //----------------------------------------------------------process_eos_logic----------------------------------------------------------------
    release_eos(keycode, record);
#endif
}
