#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_ESCAPE, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE, LCTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_ENTER, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, MO(2), KC_LCTRL, KC_LGUI, KC_LALT, LT(1, KC_ENTER), KC_SPACE, KC_RGUI, KC_RALT, MO(3)),
	[1] = LAYOUT(KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_BSLASH, KC_QUOTE, KC_MINUS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET, KC_4, KC_5, KC_6, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(LSFT(KC_GRAVE), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_DELETE, KC_CAPSLOCK, LSFT(KC_BSLASH), LSFT(KC_QUOTE), LSFT(KC_MINUS), LSFT(KC_EQUAL), LSFT(KC_LBRACKET), LSFT(KC_RBRACKET), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT(RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_DELETE, KC_MUTE, KC_VOLU, RGB_SAI, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_TRNS, KC_VOLD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    // Set up RGB effects for 2nd and 3rd led.
    rgblight_set_effect_range(0, 2);
    rgblight_sethsv_noeeprom(185, 255, 255);
    rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);

    // Init the last LED to a static color
    setrgb(0, 0, 0, (LED_TYPE *)&led[2]);
    rgblight_set();
  #endif //RGBLIGHT_ENABLE
}

layer_state_t layer_state_set_user(layer_state_t state){
  #ifdef RGBLIGHT_ENABLE
    uint8_t led1r = 0; uint8_t led1g = 0; uint8_t led1b = 0;
    uint8_t led2r = 0; uint8_t led2g = 0; uint8_t led2b = 0;

    if (layer_state_cmp(state, 1)) {
      led1r = 255;
      led1g = 255;
      led2r = 255;
      led2g = 255;
    }
    if (layer_state_cmp(state, 2)) {
      led1g = 255;
      led1b = 255;
      led2g = 255;
      led2b = 255;
    }
    if (layer_state_cmp(state, 3)) {
      led1b = 255;
      led1r = 255;
      led2b = 255;
      led2r = 255;
    }

    setrgb(led1r, led1g, led1b, (LED_TYPE *)&led[1]);
    setrgb(led2r, led2g, led2b, (LED_TYPE *)&led[2]);

    rgblight_set();
  #endif //RGBLIGHT_ENABLE
  return state;
}
