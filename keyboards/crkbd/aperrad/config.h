/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#define MASTER_LEFT
#ifdef OLED_DRIVER_ENABLE
#undef SSD1306OLED
#define OLED_TIMEOUT 30000
#endif

#undef USE_I2C
#define USE_SERIAL_PD2

// Customized by markstos
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define TAP_CODE_DELAY 100

// used for key // Layer switch
#define TAPPING_TERM_BSPC 125
#define TAPPING_TERM_LAYER 200

// HOME ROW MODS
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
//#define TAPPING_FORCE_HOLD

// markstos: prevent keydown and keyup from firing on different layers
#define PREVENT_STUCK_MODIFERS

// When enabled, typing a mod-tap plus second within term will register as the mod-combo
// Ref: https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#permissive-hold
#define PERMISSIVE_HOLD

#ifdef AUTO_SHIFT_ENABLE
#define AUTO_SHIFT_TIMEOUT 150
#endif

// Combo settings
#define COMBO_COUNT 15
#define COMBO_TERM_PER_COMBO
// Set the COMBO_TERM so low that I won't type the keys one after each other during normal typing.
// They would have be held together intentionally to trigger this.
#define COMBO_TERM 25

#ifdef RGBLIGHT_ENABLE
#undef RGBLED_NUM
#define RGBLED_NUM 27
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#endif
