#include "aht20.h"
#include "i2c.h"
#include "Delay.h"

#define BUFF_BIT_1 (1)
#define BUFF_BIT_2 (2)
#define BUFF_BIT_3 (3)
#define BUFF_BIT_4 (4)
#define BUFF_BIT_5 (5)
#define BUFF_BIT_6 (6)

AhtSensonValue sensorValue={0};
uint8_t receiveBuf[BUFF_BIT_6]={0};
int test=0;

void Get_AHT20_value(AHT20State *aht20State){
    switch (*aht20State){
        case trigger:
            AHT20_Write();
            *aht20State=sending;
            break;
        case sendDone:
            Delay_ms(AHT_DELAY_75MS);
            AHT20_Get();
            *aht20State=receiving;
            break;
        case receiveDone:
            AHT20_Read();
            *aht20State=trigger;
            Delay_s(1);
            break;
        default :
            break;
    }
}

void AHT20_Init(void){
    uint8_t receiveBuf;
    Delay_ms(AHT_DELAY_40MS);
    HAL_I2C_Master_Receive(&hi2c1,AHT20_ADDRESS,&receiveBuf,BUFF_BIT_1,HAL_MAX_DELAY);
    if((receiveBuf&0x08)==0x00){
        uint8_t sendBuf[3]={AHT_INIT_CMD,AHT_PARAM_INIT_HIGH,AHT_PARAM_LOW_BYTE};
        HAL_I2C_Master_Transmit(&hi2c1,AHT20_ADDRESS,sendBuf,BUFF_BIT_3,HAL_MAX_DELAY);
    }
}

void AHT20_Write(void){
    static uint8_t sendBuf[BUFF_BIT_3]={AHT_TEST_CMD,AHT_PARAM_HIGH_BYTE,AHT_PARAM_LOW_BYTE};
    HAL_I2C_Master_Transmit_DMA(&hi2c1,AHT20_ADDRESS,sendBuf,BUFF_BIT_3);
}

void AHT20_Get(void){
    HAL_I2C_Master_Receive_DMA(&hi2c1,AHT20_ADDRESS,receiveBuf,BUFF_BIT_6);
}

void AHT20_Read(void){
    float Humidity,Temperature;
    if((receiveBuf[0]&0x80)==0x00){
    uint32_t data = 0;

    data = ((uint32_t)receiveBuf[BUFF_BIT_3] >> 4) + ((uint32_t)receiveBuf[BUFF_BIT_2] << 4) + ((uint32_t)receiveBuf[BUFF_BIT_1] << 12);  
    Humidity = data * 100.0f / (1 << 20);
    sensorValue.ahtHumi=Humidity;
    
    data = (((uint32_t)receiveBuf[BUFF_BIT_3] & 0x0f) << 16) + ((uint32_t)receiveBuf[BUFF_BIT_4] << 8) + (uint32_t)receiveBuf[BUFF_BIT_5];
    Temperature = data * 200.0f / (1 << 20) - 50;
    sensorValue.ahtTemper=Temperature;

    }
}
