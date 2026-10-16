/* Copyright 2022 Nikolay N
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include "quantum.h"

#if defined(RGBLIGHT_ENABLE) && defined(WINRY_WAVE_ENABLE)
#    define WINRY_WAVE_OFFSET_KEY QK_KB_1   /* wave offset +1 (clamped) */
#    define WINRY_WAVE_UNOFFSET_KEY QK_KB_2 /* wave offset -1           */
#    define WINRY_WAVE_ZERO_KEY QK_KB_3     /* wave offset -> 0         */

enum winry_keycodes {
    WINRY_WAVE      = QK_KB_0,
    WINRY_WAVE_UP   = WINRY_WAVE_OFFSET_KEY,
    WINRY_WAVE_DOWN = WINRY_WAVE_UNOFFSET_KEY,
    WINRY_WAVE_ZERO = WINRY_WAVE_ZERO_KEY,
};
#endif
