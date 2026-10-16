/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* Same UID as the pnetmon/winry25tf community Vial firmware, so Vial keeps
 * recognising the keyboard and existing saved layouts apply. */
#define VIAL_KEYBOARD_UID {0xBF, 0x74, 0xE7, 0xE4, 0x65, 0xBB, 0xAD, 0x72}

/* Secure mode: hold top-left (Esc) and bottom-right (Enter) for a few
 * seconds to unlock editing and firmware reflashing from the Vial app. */
#define VIAL_UNLOCK_COMBO_ROWS {0, 4}
#define VIAL_UNLOCK_COMBO_COLS {0, 4}

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define NUMLOCK_ON_STARTUP

#define WINRY_WAVE_ENABLE
