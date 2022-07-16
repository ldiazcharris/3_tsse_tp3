#ifndef _API_LEDS_H
#define _API_LEDS_H

#include <stdint.h>

// Valor que se debe restar a num_led para obtener el la posición correcta del led
#define RES_POSITION 1 

// Valor setear un bit
#define SET_BIT 1

// Apagar todos los leds
#define ALL_LEDS_OFF 0

/**
 * @brief inicializa el puerto de leds en 0, todos apagados
 * 
 * @param virtual_leds puntero al puerto GPIO de los leds
 */
void init_leds(uint16_t *virtual_leds);

/**
 * @brief enciende un led
 * 
 * @param num_led número del led a operar (no la posición)
 */
void turn_on_led(int num_led);

/**
 * @brief apaga un led
 * 
 * @param num_led  número del led a operar (no la posición)
 */
void turn_off_led(int num_led);


#endif 