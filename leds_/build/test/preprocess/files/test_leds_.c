#include "src/api_leds.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static uint16_t virtual_leds;



void setUp(void)

{

    init_leds(&virtual_leds);

}





void test_leds_apagados_al_inicializar()

{

    uint16_t virtual_leds = 0xffff;

    init_leds(&virtual_leds);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_unico_led()

{

    turn_on_led(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_unico_led()

{

    turn_on_led(5);

    turn_off_led(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_apagar_multiples_leds()

{

    turn_on_led(5);

    turn_on_led(5);

    turn_on_led(11);

    turn_off_led(11);

    turn_off_led(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);

}
