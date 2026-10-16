# Winry 25tf

![Winry 25tf](https://raw.githubusercontent.com/pnetmon/winry25tf/master/readme.md)

> SpiderIsland 25-key RGB hotswap mini numpad (a.k.a. DEBROGLIE Lightning-25),
> sold on AliExpress/Taobao as "Winry 25-key".

25-key (5x5) ATmega32u4 board with per-key + under-glow WS2812 LEDs (33 total:
25 keys in a spiral ring + 8 underneath).

This port is based on [pnetmon/winry25tf](https://github.com/pnetmon/winry25tf)
(and the original [andrzejressel port](https://github.com/mgth/winry25tf)).

* Keyboard Maintainer: [pnetmon](https://github.com/pnetmon)
* Hardware Supported: Winry 25tf (ATmega32u4, atmel-dfu)
* Hardware Availability: [AliExpress](https://aliexpress.com/item/1005001523579896.html), [Taobao](https://world.taobao.com/item/599731303104.htm)

Make example for this keyboard (after setting up your build environment):

    make winry/winry25tf:default

Flashing example for this keyboard:

    make winry/winry25tf:default:flash

**Reset Key**: the reset button is on the PCB, accessible from the back of the keyboard.

## LED numbering

Top view; LEDs 0..24 spiral inward around the keys, LEDs 25..32 are on the
bottom side:

```
20 21 22 23 24
19  6  7  8  9
18  5  0  1 10
17  4  3  2 11
16 15 14 13 12
```

## Keymaps

* `default`: two-layer keymap, Num-pad digits with F-keys/media on the second layer.
* `num_kp`: eight-layer keymap with an extra utility column on the **left**
  (Esc/Backspace/Copy/Paste/RGB toggles), per-layer LED indicators and a Num
  Lock indicator LED; Num Lock is switched on at boot.
* `num_kp_a1`: same as `num_kp` but the number block occupies the **right**
  side (mirrored utility column, different indicator LEDs).

The original community repository ships VIA/Vial binaries for the `num_kp` and
`num_kp_a1` arrangements; in the vial-qmk fork use the `via` and `vial`
keymaps, which keep the community Vial keyboard UID so existing layouts apply.

## Rainbow wave

`WINRY_WAVE` (shown as *Winry Rainbow Wave* / `WAVE` in Vial, custom keycode in
VIA) cycles; the module is compile-gated behind `WINRY_WAVE_ENABLE` in the
keymap's `config.h` (set in the `vial`/`via` keymaps, absent elsewhere) the special effect: off -> top-to-bottom -> bottom-to-top ->
left-to-right -> right-to-left -> off.

The *Wave Offset +* / *Wave Offset -* keys (`WINRY_WAVE_UP` /
`WINRY_WAVE_DOWN`) shift each crossed row/column by one hue step, giving a
diagonal skew (range 0-64, default 0; also settable at compile time with
`#define WINRY_WAVE_OFFSET n`); *Wave Offset 0* (`WINRY_WAVE_ZERO`) resets
the skew. Wave speed is rgblight's standard speed
knob: the Vial app speed slider or `UG_SPDU`/`UG_SPDD`. Unlike rgblight's built-in swirl (which
follows the spiral LED chain), the wave ramps hue by physical grid position, so
it reads as a straight directional rainbow. While active it takes over the
strip; toggling rgblight back on (UG_TOGG) returns control to the normal
effects. Brightness/saturation/value settings apply. The Knight and Christmas
animations are disabled to make room for it on the 32K-flash part.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
