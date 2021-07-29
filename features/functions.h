
#pragma once

#include QMK_KEYBOARD_H

#include "keycodes.h"

bool undead(uint16_t character, bool pressed);
void unmod(uint16_t letter);
bool accented_letter(uint16_t accent, uint16_t letter, bool pressed);