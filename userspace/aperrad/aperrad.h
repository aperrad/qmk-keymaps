#pragma once

#include QMK_KEYBOARD_H

#include "features/features.h"

uint16_t startup_timer;
uint16_t one_shot_timer;

enum layers { CLM, QWR, SYM, SYM2, EXT, FUN };

enum keycodes {
    OS_SFT = SAFE_RANGE,
    OS_CTL,
    OS_ALT,
    OS_CMD,
    OSM_MEH,

    ML_sft,
    MR_sft,
    ML_alt,
    ML_ctl,

    CMD_TAB,
    ALT_TAB,
    UD_APO,
    UD_GRV,
    UD_TLD,
    UD_CIRC,

    LEADER,
    EURO_SYM,

    // Accented letters
    E_ACUTE,
    E_GRV,
    E_CIRC,
    A_GRV,
    U_GRV,
    A_CIRC,
    I_CIRC,
    O_CIRC,
    U_CIRC,
    C_CED,

    // Case modes
    //CAPS_WORD,
    SNAKE_CASE,
    // KEBABCASE,
    // CAMELCASE,
    NUM_WORD,

    SelWrdL,
    SelWrdR,
    SelLn,
    SelLnUp,
    SelLnDn,
};

// layer toggles
#define LA_EXT MO(EXT)
#define LA_SYM MO(SYM)
#define LA_SYM2 MO(SYM2)
#define LA_FUN MO(FUN)

// nav keys
#define S_TAB S(KC_TAB)
