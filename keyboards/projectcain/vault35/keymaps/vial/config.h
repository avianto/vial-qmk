/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x48, 0x77, 0xFD, 0x92, 0x08, 0xA5, 0x3B, 0x19}

#define VIAL_UNLOCK_COMBO_ROWS { 2, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 9 }

#define ENCODERS_PAD_A { D7 }
#define ENCODERS_PAD_B { D6 }

/* WS2812 RGB LEDs */
#ifdef RGBLIGHT_ENABLE
  #define RGB_DI_PIN D5
    #ifdef RGB_DI_PIN
    #define RGBLED_NUM 6
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LIMIT_VAL 150 /* The maximum brightness level */
    // #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
    /*== all animations enable ==*/
    // #define RGBLIGHT_ANIMATIONS
    /*== or choose animations ==*/
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    //#define RGBLIGHT_EFFECT_SNAKE
    //#define RGBLIGHT_EFFECT_KNIGHT
    //#define RGBLIGHT_EFFECT_CHRISTMAS
    //#define RGBLIGHT_EFFECT_STATIC_GRADIENT
    //#define RGBLIGHT_EFFECT_RGB_TEST
    //#define RGBLIGHT_EFFECT_ALTERNATING
    #endif
#endif
