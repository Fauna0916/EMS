#include "mq2.h"
#include "math.h"
#include "adc.h"
#include "beeper.h"
#include "string.h"
#include "oled.h"


#define VOLTAGE_5V     (5.0)

//convert adc value to voltage
static double ConvertToVoltage(unsigned short data)
{
    return (double)data * 1.8 * 4 / 4096;
}

double Mq2GetData(void)
{
    double gasSensorResistance = 0.0f;

    uint32_t data = middleValueFilter(4);       //filtering algorithm
    
    double Vx = ConvertToVoltage(data);
    // Vx / 5 == 1kom / (1kom + Rx)
    //   => Rx + 1 == 5/Vx
    //   =>  Rx = 5/Vx - 1
    if (fabs(Vx) > (1e-7)) {
        gasSensorResistance = VOLTAGE_5V / Vx - 1;
    }
    return gasSensorResistance;
}
