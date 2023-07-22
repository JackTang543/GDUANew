#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "func.h"
#include "key.h"
#include "DEFINE.h"

void SysInit(void){
    //所有GPIO初始化
    pinMode(GPIO_LED,       OUTPUT);
    pinMode(GPIO_0,         INPUT);
    pinMode(GPIO_KEY1,      INPUT);
    pinMode(GPIO_KEY2,      INPUT);
    pinMode(GPIO_BAT,       INPUT);
    pinMode(GPIO_5V,        INPUT);
    pinMode(GPIO_CHRG,      INPUT_PULLUP);
    pinMode(GPIO_STDBY,     INPUT_PULLUP);
    pinMode(GPIO_LCD_CS,    OUTPUT);
    pinMode(GPIO_BUZZ,      OUTPUT);
    pinMode(GPIO_5V_EN,     OUTPUT);
    pinMode(GPIO_LCDRS,     OUTPUT);
    pinMode(GPIO_LCDBLK,    OUTPUT);
    pinMode(GPIO_LIGHT,     INPUT);
    pinMode(GPIO_LCD_D4,    OUTPUT);
    pinMode(GPIO_LCD_D5,    OUTPUT);
    pinMode(GPIO_LCD_D6,    OUTPUT);
    pinMode(GPIO_LCD_D7,    OUTPUT);


}

// 定时器句柄
TimerHandle_t timerKeyRead;
TimerHandle_t timerKeyStateMechine;

void TaskInit(void){
    //按键读取定时器
    // TimerHandle_t timerKeyRead = xTimerCreate("timerKeyRead",
    //                                           pdMS_TO_TICKS(20),    //20ms
    //                                           pdTRUE,   //自动重装
    //                                           NULL,
    //                                          ReadKeyStatus);
    //状态机状态切换定时器
    //TimerHandle_t timerKeyStateMechine = xTimerCreate("timerKeyStateMechine",
    //                                          pdMS_TO_TICKS(30),    //20ms
    //                                          pdTRUE,   //自动重装
    //                                          NULL,
     //                                         KeyStateMachineHandle);
    

    //xTimerStart(timerKeyRead, 0);
    //xTimerStart(timerKeyStateMechine, 0);
}
