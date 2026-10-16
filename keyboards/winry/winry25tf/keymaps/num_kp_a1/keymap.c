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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[layer0] = LAYOUT(KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, KC_ESC, KC_P7, KC_P8, KC_P9, KC_PPLS, UG_TOGG, KC_P4, KC_P5, KC_P6, KC_PENT, UG_NEXT, KC_P1, KC_P2, KC_P3, KC_UP, MO(layer1), KC_P0, KC_PDOT, KC_LEFT, KC_DOWN, KC_RGHT),
                                                              [layer1] = LAYOUT(UG_TOGG, UG_NEXT, UG_PREV, RGB_M_P, UG_HUEU, UG_VALU, UG_SATU, UG_HUEU, UG_SPDU, RGB_M_B, UG_VALD, UG_SATD, UG_HUED, UG_SPDD, KC_NO, TG(layer2), TG(layer3), TG(layer4), KC_NO, KC_NO, TG(layer5), TG(layer6), TG(layer7), KC_NO, KC_NO),
                                                              [layer2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer5] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P5, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer6] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [layer7] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(layer0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)};

/* LED ring order (top view), see the keyboard readme:
 * 20 21 22 23 24
 * 19  6  7  8  9
 * 18  5  0  1 10
 * 17  4  3  2 11
 * 16 15 14 13 12
 * plus bottom-side LEDs 25..32.
 */
const rgblight_segment_t PROGMEM my_layer_num[]    = RGBLIGHT_LAYER_SEGMENTS({20, 1, HSV_AZURE}, // Num Lock indicator
                                                                             {12, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({11, 1, HSV_AZURE});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({17, 1, HSV_AZURE}, {24, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({4, 1, HSV_AZURE}, {9, 1, HSV_GREEN}, {19, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS({3, 1, HSV_AZURE}, {10, 1, HSV_GREEN}, {18, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS({16, 1, HSV_AZURE});
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS({15, 1, HSV_AZURE});
const rgblight_segment_t PROGMEM my_layer7_layer[] = RGBLIGHT_LAYER_SEGMENTS({14, 1, HSV_AZURE});

enum rgb_layer_index {
    L_NUMLOCK,
    L_1,
    L_2,
    L_3,
    L_4,
    L_5,
    L_6,
    L_7,
};

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST([L_NUMLOCK] = my_layer_num, [L_1] = my_layer1_layer, [L_2] = my_layer2_layer, [L_3] = my_layer3_layer, [L_4] = my_layer4_layer, [L_5] = my_layer5_layer, [L_6] = my_layer6_layer, [L_7] = my_layer7_layer);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(L_NUMLOCK, host_keyboard_led_state().num_lock);
    rgblight_set_layer_state(L_1, layer_state_cmp(state, layer1));
    rgblight_set_layer_state(L_2, layer_state_cmp(state, layer2));
    rgblight_set_layer_state(L_3, layer_state_cmp(state, layer3));
    rgblight_set_layer_state(L_4, layer_state_cmp(state, layer4));
    rgblight_set_layer_state(L_5, layer_state_cmp(state, layer5));
    rgblight_set_layer_state(L_6, layer_state_cmp(state, layer6));
    rgblight_set_layer_state(L_7, layer_state_cmp(state, layer7));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(L_NUMLOCK, led_state.num_lock);
    return true;
}
