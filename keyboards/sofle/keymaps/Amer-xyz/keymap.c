#include <quantum.h>

enum sofle_layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
};

#define LAYOUT_via( \
    LA1, LA2, LA3, LA4, LA5, LA6,           RA6, RA5, RA4, RA3, RA2, RA1, \
    LB1, LB2, LB3, LB4, LB5, LB6, LB7, RB7, RB6, RB5, RB4, RB3, RB2, RB1, \
    LC1, LC2, LC3, LC4, LC5, LC6, LE1, RE6, RC6, RC5, RC4, RC3, RC2, RC1, \
    LD1, LD2, LD3, LD4, LD5, LD6, LD7, RD7, RD6, RD5, RD4, RD3, RD2, RD1, \
              LE2, LE3, LE4, LE5, LE6, RE5, RE4, RE3, RE2, RE1 \
    ) \
    { \
        { LA1, LA2, LA3, LA4, LA5, LA6, KC_NO }, \
        { LB1, LB2, LB3, LB4, LB5, LB6, LB7   }, \
        { LC1, LC2, LC3, LC4, LC5, LC6, KC_NO }, \
        { LD1, LD2, LD3, LD4, LD5, LD6, LD7   }, \
        { LE1, LE2, LE3, LE4, LE5, LE6, KC_NO }, \
        { RA1, RA2, RA3, RA4, RA5, RA6, KC_NO }, \
        { RB1, RB2, RB3, RB4, RB5, RB6, RB7   }, \
        { RC1, RC2, RC3, RC4, RC5, RC6, KC_NO }, \
        { RD1, RD2, RD3, RD4, RD5, RD6, RD7   }, \
        { RE1, RE2, RE3, RE4, RE5, RE6, KC_NO } \
    }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// /*
//  * QWERTY
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
//  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
//  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */

// [_QWERTY] = LAYOUT(
//   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
//   KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
//   KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
//   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//                  KC_LGUI,KC_LALT,KC_LCTL, MO(_LOWER), KC_ENT,      KC_SPC,  MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
// ),
// /*
//  * COLEMAK
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
//  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
//  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */

// [_COLEMAK] = LAYOUT(
//   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
//   KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
//   KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
//   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,      XXXXXXX,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//                  KC_LGUI,KC_LALT,KC_LCTL,MO(_LOWER), KC_ENT,        KC_SPC,  MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
// ),
// /* LOWER
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
//  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
//  * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// [_LOWER] = LAYOUT(
//   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
//   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
//   _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
//   _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
//                        _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// ),
// /* RAISE
//  * ,----------------------------------------.                    ,-----------------------------------------.
//  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
//  * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
//  * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// [_RAISE] = LAYOUT(
//   _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
//   _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_BSPC,
//   _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
//   _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
//                          _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][2][2] = {
    // [_QWERTY] =     { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    // [_COLEMAK] =    { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    // [_LOWER] =      { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    // [_RAISE] =      { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
};
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

