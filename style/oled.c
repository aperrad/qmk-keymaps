#include "keycodes.h"
#include "features/casemodes.h"
#include <stdio.h>
#include <version.h>
#include <string.h>

void render_build_info(void) {
    oled_write_P(PSTR("v"), false);
    oled_write_P(PSTR(QMK_VERSION), false);
    oled_write_P(PSTR("\nb:"), false);
    oled_write_P(PSTR(QMK_BUILDDATE), false);
}

// void render_wpm(void) {
//     static char wpm_str[10];
//     sprintf(wpm_str, "WPM: %03d", get_current_wpm());
//     oled_write_ln(wpm_str, false);
// }

void render_layers(void) {
    oled_write_P(PSTR("Layer\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMBR"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("FUNCT"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJST"), false);
            break;
        case _UTILS:
            oled_write_P(PSTR("UTILS"), false);
            break;
        default:
            oled_write_P(PSTR("?????"), false);
    }
    oled_write_P(PSTR("\n"), false);
}

void render_mod(uint8_t mods, uint8_t os_mods, uint8_t mask, char mod, char os) {
    if (mods & mask) {
        oled_write_char(mod, false);
        oled_write_char('\n', false);
    } else if (os_mods & mask) {
        oled_write_char(os, false);
        oled_write_char('\n', false);
    } else {
        oled_write_P(PSTR(""), false);
    }
}

void render_mods(void) {
    uint8_t mods    = get_mods();
    uint8_t os_mods = get_oneshot_mods();

    oled_write_P(PSTR("Mods: \n"), false);
    render_mod(mods, os_mods, MOD_MASK_SHIFT, 'S', 's');
    render_mod(mods, os_mods, MOD_MASK_ALT, 'A', 'a');
    render_mod(mods, os_mods, MOD_MASK_CTRL, 'C', 'c');
    render_mod(mods, os_mods, MOD_MASK_GUI, 'G', 'g');
    oled_write_ln("", false);
}

void render_caps(void) {
    bool    caps_word     = caps_word_enabled();
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR(" CAPS") : PSTR("\n"), false);

    bool xcase = get_xcase_state() != XCASE_OFF;
    if (caps_word && xcase) {
        oled_write_P(PSTR("XCASE"), false);
        oled_write_P(PSTR("CAPS WORD"), false);

    } else if (xcase) {
        oled_write_P(PSTR("XCASE"), false);
    } else if (caps_word) {
        oled_write_P(PSTR("CAPS WORD"), false);
    } else if (host_keyboard_led_state().caps_lock && !caps_word) {
        oled_write_P(PSTR(" CAPS"), false);
    }
    oled_write_ln("", false);
}

void render_master_status(void) {
    render_layers();
    oled_write_ln("", false);
    render_mods();
    oled_write_ln("", false);
    render_caps();
    oled_write_ln("", false);
}

void render_slave_status(void) {
    render_build_info();
    //oled_write_ln("\n", false);
    // render_wpm();
}

void render_status(void) {
    if (is_keyboard_master()) {
        render_master_status();
    } else {
        render_slave_status();
    }
}
