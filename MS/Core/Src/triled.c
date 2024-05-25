#include "triled.h"

//control led
void TriLED_Control(LightStatus lightstatus, FlagStatus flag)
{
    switch (lightstatus)
    {
    case RED:
        HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, flag);
        break;
    case GREEN:
        HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, flag);
        break;
    case BLUE:
        HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, flag);
        break;
    default:
        break;
    }
}
