#include "api_leds.h"

static uint16_t *port_leds;

void init_leds(uint16_t *virtual_leds)
{
    port_leds = virtual_leds;
    *port_leds = 0;
}

void turn_on_led(int num_led)
{
    *port_leds = 1 << 5;
}

void turn_off_led(int num_led)
{
    *port_leds = 0 << 5;
}