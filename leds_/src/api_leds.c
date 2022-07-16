#include "api_leds.h"

// Valor que se debe restar a num_led para obtener el bit correcto
#define RES_POSITION 1 

static uint16_t *port_leds;

void init_leds(uint16_t *virtual_leds)
{
    port_leds = virtual_leds;
    *port_leds = 0;
}

void turn_on_led(int num_led)
{
    *port_leds |= (1 << (num_led - RES_POSITION));
}

void turn_off_led(int num_led)
{
    *port_leds &= ~(1 << (num_led - RES_POSITION));
}