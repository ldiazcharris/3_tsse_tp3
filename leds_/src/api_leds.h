#ifndef _API_LEDS_H
#define _API_LEDS_H

#include <stdint.h>


// Valor que se debe restar a num_led para obtener el la posición correcta del led
#define RES_POSITION 1 

// Valor setear un bit
#define SET_BIT 1

// Apagar todos los leds
#define RESET_ALL_LEDS 0x0000

// Prender todos los leds
#define  SET_ALL_LEDS 0xffff

// Estado de leds
typedef enum
{
    RESET = 0,
    SET
}led_state_t;

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

/**
 * @brief consulta el estado de un led
 * 
 * @param num_led número del led a leer (no la posición)
 */
int read_led(int num_led);

/**
 * @brief prende todos leds del puerto GPIO
 * 
 */
void turn_on_all_leds(void);

/**
 * @brief apaga todos leds del puerto GPIO
 * 
 */
void turn_off_all_leds(void);

#endif 