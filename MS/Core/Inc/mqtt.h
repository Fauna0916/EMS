#ifndef MQTT_H
#define MQTT_H

#include "usart.h"
#include "stdio.h"
#include "string.h"
#include "Delay.h"

#define MAX_String 100
#define WAIT_TIME 2

typedef struct {
    float gas;
    float humidity;
    float temperature;
    int humanState;
    int flameState;
    int MQ2State;
    int AHT20State;
    int HC_SRState;
    int FlameSensorState;
    int BeeperState;

}Profile;

void MQTT_Init(void);
void Publish(Profile *profile);

#endif
