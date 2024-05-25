#ifndef HUMANSENSOR_H
#define HUMANSENSOR_H

#include "gpio.h"

#define HUMAN_EXIST (3000)

typedef enum
{
    notHuman,
    isHuman,
} HumanState;

HumanState Get_HumanState(void);

#endif
