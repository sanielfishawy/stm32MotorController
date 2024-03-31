#include "src/phaseGen.h"
#include "/Users/sanielfishawy/dev/motorController/app/vendor/ceedling/vendor/unity/src/unity.h"


void sendTicks(int ticks) {

    for (int i = 0; i < ticks; i++) {

        PG_handlePwmTick();

    }

}



void setUp(void) {

    PG_init();

}



void tearDown(void) {

}



void testPGSetPeriod(void) {

    UnityAssertEqualNumber((UNITY_INT)((250000)), (UNITY_INT)((PG_period)), (((void*)0)), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT);

    PG_setPeriod(0);

    UnityAssertEqualNumber((UNITY_INT)((125)), (UNITY_INT)((PG_period)), (((void*)0)), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);

    PG_setPeriod(250000 + 1);

    UnityAssertEqualNumber((UNITY_INT)((250000)), (UNITY_INT)((PG_period)), (((void*)0)), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}



void testPGHandlePwmTick(void) {

    PG_setPeriod(400);

    sendTicks(1);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((PG_phaseFraction())), (((void*)0)), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

    sendTicks(100);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((0.25)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((0.25))), (UNITY_FLOAT)((UNITY_FLOAT)((PG_phaseFraction()))), ((((void*)0))), (UNITY_UINT)((UNITY_UINT)(32)));

    sendTicks(500);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((0.5)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((0.5))), (UNITY_FLOAT)((UNITY_FLOAT)((PG_phaseFraction()))), ((((void*)0))), (UNITY_UINT)((UNITY_UINT)(34)));



    PG_setPeriod(4000);

    sendTicks(1);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((0.5)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((0.5))), (UNITY_FLOAT)((UNITY_FLOAT)((PG_phaseFraction()))), ((((void*)0))), (UNITY_UINT)((UNITY_UINT)(38)));

    UnityAssertEqualNumber((UNITY_INT)((2000)), (UNITY_INT)((PG_phaseTickNum())), (((void*)0)), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2000)), (UNITY_INT)((PG_timestamp)), (((void*)0)), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_UINT64);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((0.5 * 2 * 3.14159265358979323846264338327950288)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((0.5 * 2 * 3.14159265358979323846264338327950288))), (UNITY_FLOAT)((UNITY_FLOAT)((PG_phaseRadians()))), ((((void*)0))), (UNITY_UINT)((UNITY_UINT)(41)));

}
