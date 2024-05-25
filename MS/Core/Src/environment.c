#include "environment.h"

void environment_Detect(double gas, AhtSensonValue *aht, HumanState humanState)
{
    uint16_t flameFlag = flame_Detect();

    // the most dangerous situation
    if (gas >= ABNORMAL_GAS || flameFlag || humanState)
    {
        Beeper(SET);
        TriLED_Control(RED, SET);
        TriLED_Control(BLUE, RESET);
        TriLED_Control(GREEN, RESET);
        Delay_ms(200);
        Beeper(RESET);
    }
    // temp or humi abnormal
    else if ((aht->ahtHumi) >= ABNORMAL_HUMIDITY || (aht->ahtTemper) >= ABNORMAL_TEMPERATURE)
    {
        Beeper(RESET);
        TriLED_Control(RED, RESET);
        TriLED_Control(BLUE, SET);
        TriLED_Control(GREEN, RESET);
    }
    // noraml
    else
    {
        Beeper(RESET);
        TriLED_Control(RED, RESET);
        TriLED_Control(BLUE, RESET);
        TriLED_Control(GREEN, SET);
    }
}

// whether flame happen
uint16_t flame_Detect(void)
{
    uint16_t flameFlag = RESET;
    flameFlag = !HAL_GPIO_ReadPin(FLAME_GPIO_Port, FLAME_Pin);
    return flameFlag;
}
