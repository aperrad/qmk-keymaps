/* Copyright 2022 @vvhg1
 * Original author: @andrewjrae
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "leaderfuncs.h"
#include "casemodes.h"
#include "aperrad.h"

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        /*case Sq_Br:
            if (get_mods() & MOD_MASK_SHIFT) {  // single brackets
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_RBRC);
            } else {
                tap_code(KC_LBRC);
            }
            return bracket_repeat;
        case Cr_Br:
            if (get_mods() & MOD_MASK_SHIFT) {  // single brackets
                tap_code16((LSFT(KC_RBRC)));
            } else {
                tap_code16((LSFT(KC_LBRC)));
            }
            return bracket_repeat;
        case Op_Br:
            if (get_mods() & MOD_MASK_SHIFT) {  // single brackets
                tap_code16(S(KC_0));
            } else {
                tap_code16(S(KC_9));
            }
            return bracket_repeat;*/
        case KC_Q:
            tap_code16(C(KC_F4));  // here WQ closes window
            return windows_stuff;
        // case KC_Q:
        //     return reset_keyboard1;  // here LDR QRK will reset the keyboard
        case KC_W:
            return windows_stuff;  // here W is the start for Win related actions
        case KC_V:
            return vscode_stuff;  // here V is the start for VSCode related actions
        case KC_U:
            return umlaut_stuff;  // here U is the start for Umlaut related actions
#ifdef CASEMODES_ENABLE
        case KC_C:
            toggle_caps_word();
            break;
        case KC_S:
            toggle_xcase();
            break;
        case KC_X:
            toggle_xcase();
            toggle_caps_word();
            break;
        case KC_N:
            toggle_num_word();
            break;
#endif
        case KC_LSHIFT:
        case KC_RSHIFT:
            // case ML_sft:
            // case MR_sft:
            return leader_start_func;
        default:
            return NULL;
    }
    return NULL;
}

void *bracket_repeat(uint16_t keycode) { return NULL; }
void *umlaut_stuff(uint16_t keycode) { return NULL; }

void *windows_stuff(uint16_t keycode) {
    switch (keycode) {  // here WS is Start menu, WM is context menu
        case KC_S:
            tap_code(KC_LGUI);  // here WS is Start menu, WM is context menu
            return NULL;
        case KC_M:
            tap_code(KC_APP);  // here WS is Start menu, WM is context menu
            return NULL;
        case KC_Q:
            tap_code16(C(KC_F4));  // here WQ closes window
            return windows_stuff;
        default:
            return NULL;
    }
}
void *vscode_stuff(uint16_t keycode) {
    switch (keycode) {
        case KC_N:
            tap_code16(C(KC_PGUP));  //  vi left
            return vscode_stuff_ne;
        case KC_I:
            tap_code16(C(KC_PGDN));  // vn select editor right
            return vscode_stuff_ne;
        case KC_M:
            return vscode_stuff_m;
        case KC_F:
            return vscode_stuff_f;
        case KC_U:
            tap_code16(LALT(KC_UP));  //  vu move line up
            return vscode_stuff_ml;
        case KC_E:
            tap_code16(LALT(KC_DOWN));  //  ve move ln down
            return vscode_stuff_ml;
        case KC_C:
            return vscode_stuff_cl;
        case KC_A:
            return vscode_stuff_a;
        case KC_P:
            tap_code16(LCTL(KC_K));  // format selection
            tap_code16(LCTL(KC_F));  // format selection
            return vscode_stuff_p;
        case KC_O:
            tap_code16(LCTL(KC_F2));  //  vo relect all occurrences
            return NULL;
        case KC_Z:
            tap_code16(LCTL(KC_K));  //  vo relect all occurrences
            tap_code16(KC_Z);        //  vo relect all occurrences
            return NULL;
        case KC_ENTER:
            tap_code16(LCTL(LSFT(KC_P)));  //  vo relect all occurrences
            tap_code16(KC_F1);             //  vo relect all occurrences
            return NULL;

        default:
            return NULL;
    }
}
void *vscode_stuff_ne(uint16_t keycode) {
    switch (keycode) {
        case KC_N:
            tap_code16(C(KC_PGUP));  //  vi left
            return vscode_stuff_ne;
        case KC_I:
            tap_code16(C(KC_PGDN));  // vn select editor right
            return vscode_stuff_ne;

        default:
            return NULL;
    }
}
void *vscode_stuff_a(uint16_t keycode) {
    switch (keycode) {
        case KC_P:
            tap_code16(LSA(KC_A));  // format document
            return NULL;
        default:
            return NULL;
    }
}
void *vscode_stuff_p(uint16_t keycode) {
    switch (keycode) {
        case KC_P:
            tap_code16(LCTL(KC_K));  // format selection
            tap_code16(LCTL(KC_F));  // format selection
            return vscode_stuff_p;
        default:
            return NULL;
    }
}
void *vscode_stuff_m(uint16_t keycode) {
    switch (keycode) {
        case KC_N:
            tap_code16(LCA(KC_LEFT));  // vmn editor left
            return vscode_stuff_m;
        case KC_I:
            tap_code16(LCA(KC_RIGHT));  //  vmi right
            return vscode_stuff_m;
        default:
            return NULL;
    }
}
void *vscode_stuff_cl(uint16_t keycode) {
    switch (keycode) {
        case KC_U:
            tap_code16(LSA(KC_UP));  //  vcu copy line up
            return vscode_stuff_cl;
        case KC_E:
            tap_code16(LSA(KC_DOWN));  //  vce copy ln down
            return vscode_stuff_cl;
        default:
            return NULL;
    }
}
void *vscode_stuff_ml(uint16_t keycode) {
    switch (keycode) {
        case KC_U:
            tap_code16(LALT(KC_UP));  //  vu move line up
            return vscode_stuff_ml;
        case KC_E:
            tap_code16(LALT(KC_DOWN));  //  ve move ln down
            return vscode_stuff_ml;
        default:
            return NULL;
    }
}
void *vscode_stuff_f(uint16_t keycode) {
    switch (keycode) {
        case KC_N:
            tap_code16(LCTL(KC_K));  // vfn focus left
            tap_code16(LCTL(KC_LEFT));
            return vscode_stuff_f;
        case KC_I:
            tap_code16(LCTL(KC_K));  //  vfi focus right
            tap_code16(LCTL(KC_RIGHT));
            return vscode_stuff_f;
        default:
            return NULL;
    }
}
