#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "gpio.h"

#include "stdio.h"
#include "oled.h"
#include "Delay.h"
#include "aht20.h"
#include "mq2.h"
#include "beeper.h"
#include "triled.h"
#include "humansensor.h"

#define ABNORMAL_GAS (25)
#define ABNORMAL_HUMIDITY (85)
#define ABNORMAL_TEMPERATURE (30)

uint16_t flame_Detect(void);
void environment_Detect(double gas, AhtSensonValue *aht, HumanState humanState);

#endif
