#ifndef _API_LEDS_H
#define _API_LEDS_H

#include <stdint.h>

void init_leds(uint16_t *virtual_leds);

void turn_on_led(int num_led);

void turn_off_led(int num_led);


#endif 