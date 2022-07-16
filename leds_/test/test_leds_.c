/*
// Todos los leds apagados después de inicializar el puerto
// Prender un único led
// Apagar un único led 
// Apagar y encender múltiples leds
// Pender todos los leds de una vez

// Apagar todos los leds de una vez
// Consultar el estado de un único led
// Revisar límites de los parámetros
// Revisar parámetros fuera de los limites

*puerto |= (1 << (led - 1));
    *puerto &= ~(1 << (led - 1));

*/


#include "unity.h"
#include "api_leds.h"

// Todos los leds apagados después de inicializar el puerto
void test_leds_apagados_al_inicializar()
{
    uint16_t virtual_leds = 0xffff; 
    init_leds(&virtual_leds);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}

// Prender un único led
void test_prender_unico_led()
{
    uint16_t virtual_leds = 0xffff; 
    init_leds(&virtual_leds);
    turn_on_led(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 5, virtual_leds);
}

// Apagar un único led 
void test_apagar_unico_led()
{
    uint16_t virtual_leds = 0xffff; 
    init_leds(&virtual_leds);
    turn_on_led(5);
    turn_off_led(5);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}
