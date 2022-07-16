#include "api_leds.h"
#include "errores.h"

// Función para enmascarar el puerto de leds
uint16_t led_to_mask(int num_led)
{
    return (SET_BIT << (num_led - RES_POSITION));
}

static uint16_t *port_leds;

void init_leds(uint16_t *virtual_leds)
{
    port_leds = virtual_leds;
    *port_leds = RESET_ALL_LEDS;
}

void turn_on_led(int num_led)
{
    if(num_led > 16 || num_led <= 0) 
    {
        Alerta("Invalid led number");
    }
    else
    {
        *port_leds |= led_to_mask(num_led);
    }
}

void turn_off_led(int num_led)
{
    if(num_led > 16 || num_led <= 0) 
    {
        Alerta("Invalid led number");
    }
    else
    {
        *port_leds &= ~led_to_mask(num_led);
    }
}

int read_led(int num_led)
{
    if(num_led > 16 || num_led <= 0) 
    {
        Alerta("Invalid led number");
    }
    else
    {
    uint8_t led_state = RESET;
    led_state = (led_to_mask(num_led)&*port_leds)>>(num_led - RES_POSITION);
    return led_state;
    }
}

void turn_on_all_leds(void)
{
    *port_leds = SET_ALL_LEDS;
}

void turn_off_all_leds(void)
{
    *port_leds = RESET_ALL_LEDS;
}