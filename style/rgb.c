#include "keycodes.h"
#include "features/casemodes.h"

const rgblight_segment_t PROGMEM layer_qwerty_lights[]   = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_AZURE});
const rgblight_segment_t PROGMEM layer_num_lights[]      = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_SPRINGGREEN});
const rgblight_segment_t PROGMEM layer_function_lights[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_BLUE});
const rgblight_segment_t PROGMEM layer_adjust_lights[]   = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_CORAL});
const rgblight_segment_t PROGMEM layer_utils_lights[]    = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_GOLD});
const rgblight_segment_t PROGMEM layer_capslock_lights[] = RGBLIGHT_LAYER_SEGMENTS({2, 5, HSV_RED});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(layer_qwerty_lights, layer_num_lights, layer_function_lights, layer_adjust_lights, layer_utils_lights, layer_capslock_lights);

void set_layer_color(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FUNCTION));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(4, layer_state_cmp(state, _UTILS));
    rgblight_set_layer_state(5, !caps_word_enabled() && IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK));
}

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_enable_noeeprom();
}
