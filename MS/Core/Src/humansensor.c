#include "humansensor.h"


//detect is there is human exists
HumanState Get_HumanState(void)
{
    HumanState humanstate = notHuman;
    

    if (HAL_GPIO_ReadPin(HUMAN_GPIO_Port,HUMAN_Pin)==SET)
    {
        humanstate = isHuman;
    }
    else
    {
        humanstate = notHuman;
    }

    return humanstate;
}
