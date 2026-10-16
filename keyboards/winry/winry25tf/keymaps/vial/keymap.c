/* Copyright 2022 Nikolay N
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

enum {
    layer0,
    layer1,
    layer2,
    layer3,
    layer4,
    layer5,
    layer6,
    layer7,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[layer0] = LAYOUT(KC_ESC, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC, KC_P7, KC_P8, KC_P9, KC_PPLS, UG_TOGG, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_P1, KC_P2, KC_P3, MO(layer1), KC_COPY, KC_PASTE, KC_P0, KC_PDOT, KC_PENT),
                                                              [layer1] = LAYOUT(UG_TOGG, UG_NEXT, UG_PREV, RGB_M_P, UG_HUEU, UG_VALU, UG_SATU, UG_HUEU, UG_SPDU, RGB_M_B, UG_VALD, UG_SATD, UG_HUED, UG_SPDD, KC_NO, TG(layer2), TG(layer3), TG(layer4), KC_NO, KC_NO, TG(layer5), TG(layer6), TG(layer7), WINRY_WAVE, KC_NO),
                                                              [layer2] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer3] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer4] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer5] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P5, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer6] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer7] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)};
