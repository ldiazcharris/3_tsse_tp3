#include "build/test/mocks/mock_errores.h"
#include "src/api_leds.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




static uint16_t virtual_leds;



void registrar_error(gravedad_t gravedad, const char * funcion, int linea, const char * mensaje, ...)

{



}



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

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_unico_led()

{

    turn_on_led(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_unico_led()

{

    turn_on_led(5);

    turn_off_led(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX16);

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

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_todos_los_leds()

{

    turn_on_all_leds();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xffff)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_todos_los_leds()

{

    turn_off_all_leds();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_leds)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_HEX16);

}





void test_consultar_estado_un_led_prendido()

{

    turn_off_all_leds();

    turn_on_led(5);

    turn_on_led(4);

    turn_on_led(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((SET)), (UNITY_INT)(UNITY_INT16)((read_led(3))), (

   ((void *)0)

   ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_HEX16);

}





void test_consultar_estado_un_led_apagado()

{

    turn_on_all_leds();

    turn_off_led(5);

    turn_off_led(4);

    turn_on_led(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((RESET)), (UNITY_INT)(UNITY_INT16)((read_led(4))), (

   ((void *)0)

   ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_HEX16);

}











void test_valor_invalido_limite_superior_turn_on_led()

{

    RegistrarMensaje_CMockExpect(109, ALERTA, "turn_on_led", 0, "Invalid led number");

    RegistrarMensaje_CMockIgnoreArg_linea(110);

    RegistrarMensaje_CMockIgnoreArg_funcion(111);

    turn_on_led(18);

}



void test_valor_invalido_limite_superior_turn_off_led()

{

    RegistrarMensaje_CMockExpect(117, ALERTA, "turn_off_led", 0, "Invalid led number");

    RegistrarMensaje_CMockIgnoreArg_linea(118);

    RegistrarMensaje_CMockIgnoreArg_funcion(119);

    turn_off_led(18);

}
