/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* Same UID as the vendor Vial firmware for the R3 hotswap PCB, so Vial
 * keeps recognising the keyboard and existing saved layouts apply. */
#define VIAL_KEYBOARD_UID {0x54, 0xF8, 0x27, 0x15, 0x2B, 0x66, 0x3A, 0xC0}

/* Secure mode: hold Esc and PgUp (top-left / bottom-right corners) to
 * unlock editing and firmware reflashing from the Vial app. */
#define VIAL_UNLOCK_COMBO_ROWS {0, 5}
#define VIAL_UNLOCK_COMBO_COLS {0, 15}

#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define DYNAMIC_KEYMAP_MACRO_COUNT 6
