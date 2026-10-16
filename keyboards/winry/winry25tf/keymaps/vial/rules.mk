VIA_ENABLE = yes
VIAL_ENABLE = yes

LTO_ENABLE = yes

# 32KB-flash part: measured feature costs against 23296 all-off baseline (28672 limit):
# qmk_settings +4864, layer_lock +400 -> this set fits with ~100B spare;
# tap_dance/combo/key_override/repeat_key would overflow on top of qmk_settings
QMK_SETTINGS = yes
TAP_DANCE_ENABLE = no
COMBO_ENABLE = no
KEY_OVERRIDE_ENABLE = no
LAYER_LOCK_ENABLE = yes
REPEAT_KEY_ENABLE = no
