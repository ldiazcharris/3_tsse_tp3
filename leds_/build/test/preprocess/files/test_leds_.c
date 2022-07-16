#include "build/test/mocks/mock_errores.h"
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

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_unico_led()

{

    turn_on_led(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_unico_led()

{

    turn_on_led(5);

    turn_off_led(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_HEX16);

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

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_todos_los_leds()

{

    turn_on_all_leds();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xffff)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_todos_los_leds()

{

    turn_off_all_leds();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_HEX16);

}





void test_consultar_estado_un_led_prendido()

{

    turn_off_all_leds();

    turn_on_led(5);

    turn_on_led(4);

    turn_on_led(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((SET)), (UNITY_INT)(UNITY_INT16)((read_led(3))), (

   ((void *)0)

   ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_HEX16);

}





void test_consultar_estado_un_led_apagado()

{

    turn_on_all_leds();

    turn_off_led(5);

    turn_off_led(4);

    turn_on_led(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((RESET)), (UNITY_INT)(UNITY_INT16)((read_led(4))), (

   ((void *)0)

   ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_HEX16);

}





void test_valor_invalido_limite_superior_turn_on_led()

{

    RegistrarMensaje_CMockExpect(100, ALERTA, "turn_on_led", 0, "Invalid led number");

    RegistrarMensaje_CMockIgnoreArg_linea(101);

    RegistrarMensaje_CMockIgnoreArg_funcion(102);

    turn_on_led(18);

}



void test_valor_invalido_limite_superior_turn_off_led()

{

    RegistrarMensaje_CMockExpect(108, ALERTA, "turn_off_led", 0, "Invalid led number");

    RegistrarMensaje_CMockIgnoreArg_linea(109);

    RegistrarMensaje_CMockIgnoreArg_funcion(110);

    turn_off_led(18);

}



void test_valor_invalido_limite_superior_read_led()

{

    RegistrarMensaje_CMockExpect(116, ALERTA, "read_led", 0, "Invalid led number");

    RegistrarMensaje_CMockIgnoreArg_linea(117);

    RegistrarMensaje_CMockIgnoreArg_funcion(118);

    read_led(18);

}



void test_valor_invalido_limite_inferior_turn_on_led()

{

    RegistrarMensaje_CMockExpect(124, ALERTA, "turn_on_led", 0, "Invalid led number");

    RegistrarMensaje_CMockIgnoreArg_linea(125);

    RegistrarMensaje_CMockIgnoreArg_funcion(126);

    turn_on_led(0);

}



void test_valor_invalido_limite_inferior_turn_off_led()

{

    RegistrarMensaje_CMockExpect(132, ALERTA, "turn_off_led", 0, "Invalid led number");

    RegistrarMensaje_CMockIgnoreArg_linea(133);

    RegistrarMensaje_CMockIgnoreArg_funcion(134);

    turn_off_led(0);

}



void test_valor_invalido_limite_inferior_read_led()

{

    RegistrarMensaje_CMockExpect(140, ALERTA, "read_led", 0, "Invalid led number");

    RegistrarMensaje_CMockIgnoreArg_linea(141);

    RegistrarMensaje_CMockIgnoreArg_funcion(142);

    read_led(0);

}
