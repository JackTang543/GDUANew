#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "func.h"
#include "key.h"

// 定时器句柄
TimerHandle_t timerKeyRead;

void TaskInit(void){
    TimerHandle_t timerKeyRead = xTimerCreate("timerKeyRead", pdMS_TO_TICKS(200), pdTRUE, NULL, ReadKeyStatus);
    

    xTimerStart(timerKeyRead, 0);
}
