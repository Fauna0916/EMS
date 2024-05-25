#ifndef TRILED_H
#define TRILED_H

#include "gpio.h"

typedef enum
{
    RED,
    GREEN,
    BLUE,
} LightStatus;

void TriLED_Control(LightStatus lightstatus, FlagStatus flag);

#endif
