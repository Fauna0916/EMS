#include "mqtt.h"

char mes[MAX_String]; // store string

void MQTT_Init(void)
{
    // connect Internet
    sprintf(mes, "AT+CWMODE=1\r\n");
    HAL_UART_Transmit(&huart1, mes, strlen(mes), HAL_MAX_DELAY);
    sprintf(mes, "AT+CWJAP=\"Fauna\",\"12345678\"\r\n");
    HAL_UART_Transmit(&huart1, mes, strlen(mes), HAL_MAX_DELAY);
    Delay_s(WAIT_TIME);

    // connect MQTT server
    sprintf(mes, "AT+MQTTUSERCFG=0,1,\"esp01s_id\",\"esp01s\",\"esp01s\",0,0,\"/mqtt\"\r\n");
    HAL_UART_Transmit(&huart1, mes, strlen(mes), HAL_MAX_DELAY);
    Delay_s(WAIT_TIME);
    sprintf(mes, "AT+MQTTCONN=0,\"192.168.98.146\",1883,0\r\n");
    HAL_UART_Transmit(&huart1, mes, strlen(mes), HAL_MAX_DELAY);
    Delay_s(WAIT_TIME);
}

// publish message
void Publish(Profile *profile)
{
    sprintf(mes, "AT+MQTTPUB=0,\"envir\",\"G:%.1fHD:%.1fT:%.1fF:%dHS:%d\",0,0\r\n", profile->gas, profile->humidity, profile->temperature, profile->flameState, profile->humanState);
    HAL_UART_Transmit(&huart1, mes, strlen(mes), HAL_MAX_DELAY);
    Delay_s(WAIT_TIME);
}

void MsgRcvCallBack(int qos, const char *topic, const char *payload)
{
}
