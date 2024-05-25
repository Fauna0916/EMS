#ifndef AHT20_H
#define AHT20_H

#define AHT20_ADDRESS 0x70  //device addr
#define AHT_INIT_CMD  (0xBE) // aht init cmd
#define AHT_TEST_CMD  (0xAC) // test cmd
#define AHT_PARAM_HIGH_BYTE  (0x33)
#define AHT_PARAM_LOW_BYTE   (0x00)
#define AHT_PARAM_INIT_HIGH  (0x08)
#define AHT_DELAY_40MS  (40) // 40ms
#define AHT_DELAY_75MS  (75) // 75ms

typedef enum{
  trigger,
  sending,
  sendDone,
  receiving,
  receiveDone,
} AHT20State;

typedef struct {
    float  ahtTemper;
    float  ahtHumi;
} AhtSensonValue;

extern AhtSensonValue sensorValue;

void Get_AHT20_value(AHT20State *aht20State);
void AHT20_Init(void);
void AHT20_Write(void);
void AHT20_Get(void);
void AHT20_Read(void);


#endif
