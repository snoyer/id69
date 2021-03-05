#include "keymap.h"

enum { QWERTY = 0, DHm, Fn1, Fn2, Fn3 };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , /*    */  KC_BSPC ,
        KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_HOME , KC_DEL  ,
        KC_GRV  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_ENT  , KC_END  , KC_INS  ,
        KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_BSLS , /*    */  KC_UP   , KC_PSCR ,
        KC_LCTL , KC_LGUI , KC_LALT ,       LT(Fn1, KC_SPC)       ,       LT(Fn2, KC_SPC)       , KC_RALT , KC_RGUI , KC_RCTL , KC_LEFT , KC_DOWN , KC_RIGHT
    ),
    [DHm] = LAYOUT(
        KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , /*    */  KC_BSPC ,
        KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_LBRC , KC_RBRC , KC_HOME , KC_DEL  ,
        KC_GRV  , KC_A    , KC_R    , KC_S    , KC_T    , KC_G    , KC_M    , KC_N    , KC_E    , KC_I    , KC_O    , KC_QUOT , KC_ENT  , KC_END  , KC_INS  ,
        KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    , KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLSH , KC_BSLS , /*    */  KC_UP   , KC_PSCR ,
        KC_LCTL , KC_LGUI , KC_LALT ,       LT(Fn1, KC_SPC)       ,       LT(Fn2, KC_BSPC)      , KC_RALT , KC_RGUI , KC_RCTL , KC_LEFT , KC_DOWN , KC_RIGHT
    ),
    [Fn1] = LAYOUT(
        _______ ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,  KC_F12 , /*    */  KC_MUTE ,
        _______ ,S(KC_F1) ,S(KC_F2) ,S(KC_F3) ,S(KC_F4) ,S(KC_F5) ,S(KC_F6) ,S(KC_F7) ,S(KC_F8) ,S(KC_F9) ,S(KC_F10),S(KC_F11),S(KC_F12), KC_PGUP , _______ ,
        _______ ,A(KC_F1) ,A(KC_F2) ,A(KC_F3) ,A(KC_F4) ,A(KC_F5) ,A(KC_F6) ,A(KC_F7) ,A(KC_F8) ,A(KC_F9) ,A(KC_F10), _______ , KC_MPLY , KC_PGDN , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /*    */  KC_VOLU , _______ ,
        _______ , _______ , _______ ,           _______           ,       LT(Fn3, KC_BSPC)      , _______ , KC_APP  , _______ , KC_MPRV , KC_VOLD , KC_MNXT 
    ),
    [Fn2] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_7    , KC_8    , KC_9    , _______ , _______ , _______ , /*    */  _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_4    , KC_5    , KC_6    , _______ , _______ , _______ , KC_MYCM , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_1    , KC_2    , KC_3    , _______ , _______ , _______ , KC_CALC , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_0    , KC_0    , KC_DOT  , _______ , _______ , /*    */  _______ , _______ ,
        _______ , _______ , _______ ,       LT(Fn3, KC_SPC)       ,           _______           , _______ , KC_APP  , _______ , _______ , _______ , _______
    ),
    [Fn3] = LAYOUT(
        RESET   ,DF(QWERTY),DF(DHm) , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /*    */  _______ ,
        DEBUG   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        RGB_TOG , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /*    */  _______ , _______ ,
        _______ , _______ , _______ ,           _______           ,           _______           , _______ , _______ , _______ , _______ , _______ , _______ 
    ),
};


#ifdef RGBLIGHT_ENABLE

const uint16_t LEDS_OFF_TIMEOUT = 15*60; // in seconds
#define Fn_color HSV_BLUE

const rgblight_segment_t PROGMEM rgb_layer_Fn1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, Fn_color}, {12, 4, Fn_color} // left half
);
const rgblight_segment_t PROGMEM rgb_layer_Fn2[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 8, Fn_color} // right half
);
const rgblight_segment_t PROGMEM rgb_layer_Fn3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, Fn_color} // all
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [Fn1] = rgb_layer_Fn1,
    [Fn2] = rgb_layer_Fn2,
    [Fn3] = rgb_layer_Fn3
);


struct Longtimer idle_timer;
bool rgblight_disabled_by_timeout = false;

#endif //RGBLIGHT_ENABLE






void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_sethsv_noeeprom_white();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
    rgblight_layers = rgb_layers;

    longtimer_read(&idle_timer);
#endif
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_ENABLE
    if(rgblight_disabled_by_timeout && !rgblight_is_enabled()){
        rgblight_enable_noeeprom();
        rgblight_disabled_by_timeout = false;
    }
    longtimer_read(&idle_timer);
#endif
    return true;
}

void matrix_scan_user(void) {
#ifdef RGBLIGHT_ENABLE
    if(rgblight_is_enabled() && longtimer_elapsed(&idle_timer) > LEDS_OFF_TIMEOUT){
        rgblight_disable_noeeprom();
        rgblight_disabled_by_timeout = true;
    }
#endif
}


uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    switch(biton32(default_layer_state)) {
        case QWERTY: rgblight_sethsv_noeeprom_white  (); break;
        case DHm   : rgblight_sethsv_noeeprom_magenta(); break;
    }
    rgblight_set_layer_state(Fn1, layer_state_cmp(state, Fn1));
    rgblight_set_layer_state(Fn2, layer_state_cmp(state, Fn2));
    rgblight_set_layer_state(Fn3, layer_state_cmp(state, Fn3));
#endif
    return state;
}




