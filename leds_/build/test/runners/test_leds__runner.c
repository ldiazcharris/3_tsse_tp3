/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include "mock_errores.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_leds_apagados_al_inicializar();
extern void test_prender_unico_led();
extern void test_apagar_unico_led();
extern void test_prender_apagar_multiples_leds();
extern void test_prender_todos_los_leds();
extern void test_apagar_todos_los_leds();
extern void test_valor_invalido_limite_superior_turn_on_led();
extern void test_valor_invalido_limite_superior_turn_off_led();


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_errores_Init();
}
static void CMock_Verify(void)
{
  mock_errores_Verify();
}
static void CMock_Destroy(void)
{
  mock_errores_Destroy();
}

/*=======Teardown (stub)=====*/
void tearDown(void) {}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds_.c");
  run_test(test_leds_apagados_al_inicializar, "test_leds_apagados_al_inicializar", 36);
  run_test(test_prender_unico_led, "test_prender_unico_led", 44);
  run_test(test_apagar_unico_led, "test_apagar_unico_led", 51);
  run_test(test_prender_apagar_multiples_leds, "test_prender_apagar_multiples_leds", 59);
  run_test(test_prender_todos_los_leds, "test_prender_todos_los_leds", 70);
  run_test(test_apagar_todos_los_leds, "test_apagar_todos_los_leds", 77);
  run_test(test_valor_invalido_limite_superior_turn_on_led, "test_valor_invalido_limite_superior_turn_on_led", 85);
  run_test(test_valor_invalido_limite_superior_turn_off_led, "test_valor_invalido_limite_superior_turn_off_led", 93);

  CMock_Guts_MemFreeFinal();
  return UnityEnd();
}
