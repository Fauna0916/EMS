#include "beeper.h"
#include "tim.h"

void Beeper(char flag)
{
	if(flag==SET)   //open beeper
	{
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	}
  else 
  {
    HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
  }
}

