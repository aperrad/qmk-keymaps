#include "swapper.h"

void update_swapper(bool *active, uint16_t cmdish, uint16_t tabish, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (!is_swapper_ignored_key(keycode) && *active) {
        // On non-ignored keyup, disable swapper
        unregister_code(cmdish);
        *active = false;
    }
}

bool is_swapper_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case KC_LEFT:
        case KC_RIGHT:
        case KC_UP:
        case KC_DOWN:
        case KC_SPC:
        case KC_LSFT:
        case KC_ESC:
            return true;
        default:
            return false;
    }
}
