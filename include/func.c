#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "func.h"

#include "key.c"

// 定时器句柄
TimerHandle_t timerKeyRead;

void TaskInit(void){
    
}
