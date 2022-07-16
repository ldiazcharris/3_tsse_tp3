#include "api_leds.h"


// Función para enmascarar el puerto de leds
uint16_t led_to_mask(int num_led)
{
    return (SET_BIT << (num_led - RES_POSITION));
}

static uint16_t *port_leds;

void init_leds(uint16_t *virtual_leds)
{
    port_leds = virtual_leds;
    *port_leds = ALL_LEDS_OFF;
}

void turn_on_led(int num_led)
{
    *port_leds |= led_to_mask(num_led);
}

void turn_off_led(int num_led)
{
    *port_leds &= ~led_to_mask(num_led);
}