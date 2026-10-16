/* Copyright 2022 Nikolay N
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

#if defined(RGBLIGHT_ENABLE) && defined(WINRY_WAVE_ENABLE)
#    include "winry25tf.h"
#    include "color.h"
#    include "rgblight.h"
#    include "ws2812.h"

extern rgblight_config_t rgblight_config;

/* ---- Rainbow wave ----
 * Stock rgblight "rainbow swirl" flows along the LED chain, and this board
 * is wired in a spiral, so it visually swirls. The wave below ignores the
 * chain order and ramps the hue by physical grid position instead, giving
 * a directional rainbow: top->bottom, bottom->top, left->right, right->left.
 *
 * Whole module is gated behind WINRY_WAVE_ENABLE (keymap config.h); with it
 * unset the keyboard builds without any wave code.
 *
 * WINRY_WAVE cycles: off -> down -> up -> right -> left -> off.
 * WINRY_WAVE_UP / WINRY_WAVE_DOWN nudge the cross-axis skew offset;
 * WINRY_WAVE_ZERO resets it to 0 (straight bands).
 * While the wave runs it takes over the strip (rgblight is toggled off
 * without eeprom writes); turning the wave off restores the previous
 * rgblight state. If rgblight is enabled manually the wave steps aside.
 *
 * LED numbering (see readme):
 * 20 21 22 23 24
 * 19  6  7  8  9
 * 18  5  0  1 10
 * 17  4  3  2 11
 * 16 15 14 13 12
 * LEDs 25..32 are the bottom-side ring; they follow the grid as an extra
 * row / wider column so they blend with whichever direction is active.
 */

#    define WAVE_OFFSET_MAX 64

static uint8_t wave_offset =
#    ifdef WINRY_WAVE_OFFSET
    WINRY_WAVE_OFFSET;
#    else
    0;
#    endif

enum wave_dir {
    WAVE_OFF,
    WAVE_DOWN,
    WAVE_UP,
    WAVE_RIGHT,
    WAVE_LEFT,
    WAVE_COUNT,
};

#    define WAVE_LEDS RGBLIGHT_LED_COUNT

static const uint8_t PROGMEM wave_row[WAVE_LEDS] = {2, 2, 3, 3, 3, 2, 1, 1, 1, 1, 2, 3, 4, 4, 4, 4, 4, 3, 2, 1, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5};
static const uint8_t PROGMEM wave_col[WAVE_LEDS] = {2, 3, 3, 2, 1, 1, 1, 2, 3, 4, 4, 4, 4, 3, 2, 1, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 6, 7};

static uint8_t  wave_dir  = WAVE_OFF;
static uint8_t  wave_hue  = 0;
static uint16_t wave_last = 0;

static void wave_render(void) {
    bool vertical = (wave_dir == WAVE_DOWN || wave_dir == WAVE_UP);
    bool reverse  = (wave_dir == WAVE_UP || wave_dir == WAVE_LEFT);
    for (uint8_t i = 0; i < WAVE_LEDS; i++) {
        uint8_t pos   = pgm_read_byte(vertical ? &wave_row[i] : &wave_col[i]);
        uint8_t cross = pgm_read_byte(vertical ? &wave_col[i] : &wave_row[i]);
        // this era's hsv_t.h is 0-255, the same units as the rgblight hue knob
        uint8_t hue = wave_hue + (uint8_t)((reverse ? -pos : pos) * (256 / 6) + cross * wave_offset);
        rgb_t   rgb = hsv_to_rgb((hsv_t){hue, rgblight_config.sat, rgblight_config.val});
        ws2812_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    ws2812_flush();
}

void matrix_scan_user(void) {
    if (wave_dir == WAVE_OFF || rgblight_config.enable) return;
    // rgblight's speed knob (Vial slider / UG_SPDU / UG_SPDD) maps to 6-50 ms per tick
    uint16_t interval = 50 - ((uint16_t)rgblight_config.speed * 44 / 255);
    if (timer_elapsed(wave_last) < interval) return;
    wave_last = timer_read();
    wave_hue += 2;
    wave_render();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WINRY_WAVE:
            if (record->event.pressed) {
                wave_dir = (wave_dir + 1) % WAVE_COUNT;
                if (wave_dir == WAVE_OFF) {
                    if (!rgblight_config.enable) rgblight_toggle_noeeprom(); // give the strip back
                } else {
                    if (rgblight_config.enable) rgblight_toggle_noeeprom(); // take it over
                    wave_render();
                }
            }
            return false;
        case WINRY_WAVE_UP:
            if (record->event.pressed && wave_offset < WAVE_OFFSET_MAX) {
                wave_offset++;
                if (wave_dir != WAVE_OFF) wave_render();
            }
            return false;
        case WINRY_WAVE_DOWN:
            if (record->event.pressed && wave_offset > 0) {
                wave_offset--;
                if (wave_dir != WAVE_OFF) wave_render();
            }
            return false;
        case WINRY_WAVE_ZERO:
            if (record->event.pressed) {
                wave_offset = 0;
                if (wave_dir != WAVE_OFF) wave_render();
            }
            return false;
    }
    return true;
}
#endif

#ifdef NUMLOCK_ON_STARTUP
void suspend_wakeup_init_user(void) {
    // This is a numpad: make sure the digits type numbers by default.
    if (!host_keyboard_led_state().num_lock) {
        wait_ms(100);
        tap_code(KC_NUM_LOCK);
    }
}
#endif
