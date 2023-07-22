#include <Arduino.h>
#include "key.h"
#include "DEFINE.h"

//用于保存回调函数
KeyChangeCb callback;

//按键的结构体变量
typedef struct{
    CHANGE_FLAG_t m_ChangeFlag;     //按键的变化标志位
    bool m_b_key_curr_status;         //按键当前状态
    bool m_b_key_last_status;         //按键上一次的状态
}KEY_Structure_t;

void Key_KeyRead_Init(void){
    //初始化按键的引脚
    pinMode(GPIO_KEY1,      INPUT);
    pinMode(GPIO_KEY2,      INPUT);
    pinMode(GPIO_0,         INPUT);
    //按键读取定时器
    TimerHandle_t timerKeyRead = xTimerCreate("timerKeyRead",
                                              pdMS_TO_TICKS(20),    //20ms
                                              pdTRUE,   //自动重装
                                              NULL,
                                              Key_KeyCheck);
    xTimerStart(timerKeyRead, 0);       //启动定时器
}
//注册回调函数
void Key_setKeyCallback(KeyChangeCb cb){
    callback = cb;
}

void Key_KeyCheck(void* parameter){
    static KEY_Structure_t key_next,key_enter,key_0;
    //上一次的等于这一次的
    key_next.m_b_key_last_status  = key_next.m_b_key_curr_status;
    key_enter.m_b_key_last_status = key_enter.m_b_key_curr_status;
    key_0.m_b_key_last_status     = key_0.m_b_key_curr_status;
    //这一次的由读取到的电平决定
    key_next.m_b_key_curr_status   = (bool)digitalRead(GPIO_KEY1);
    key_enter.m_b_key_curr_status  = (bool)digitalRead(GPIO_KEY2);
    key_0.m_b_key_curr_status      = (bool)digitalRead(GPIO_0);
    //更新按键变化的状态(按键变化状态机)
    //key_next
    //如果上一次的状态等于这一次的状态,说明电平没有变化
    if(key_next.m_b_key_last_status == key_next.m_b_key_curr_status){
        key_next.m_ChangeFlag = key_non_change;     //没有变化
    }//如果上一次为高,这一次为低,说明是falling
    else if((key_next.m_b_key_last_status == HIGH) && (key_next.m_b_key_curr_status == LOW)){
        key_next.m_ChangeFlag = key_falling;        //状态为falling
    }//如果上一次为低,这一次为高,说明是rising
    else if((key_next.m_b_key_last_status == LOW) && (key_next.m_b_key_curr_status == HIGH)){
        key_next.m_ChangeFlag = key_rising;         //说明是rising
    }
    //key_enter
    //如果上一次的状态等于这一次的状态,说明电平没有变化
    if(key_enter.m_b_key_last_status == key_enter.m_b_key_curr_status){
        key_enter.m_ChangeFlag = key_non_change;     //没有变化
    }//如果上一次为高,这一次为低,说明是falling
    else if((key_enter.m_b_key_last_status == HIGH) && (key_enter.m_b_key_curr_status == LOW)){
        key_enter.m_ChangeFlag = key_falling;        //状态为falling
    }//如果上一次为低,这一次为高,说明是rising
    else if((key_enter.m_b_key_last_status == LOW) && (key_enter.m_b_key_curr_status == HIGH)){
        key_enter.m_ChangeFlag = key_rising;         //说明是rising
    }
    //key_0
    //如果上一次的状态等于这一次的状态,说明电平没有变化
    if(key_0.m_b_key_last_status == key_0.m_b_key_curr_status){
        key_0.m_ChangeFlag = key_non_change;     //没有变化
    }//如果上一次为高,这一次为低,说明是falling
    else if((key_0.m_b_key_last_status == HIGH) && (key_0.m_b_key_curr_status == LOW)){
        key_0.m_ChangeFlag = key_falling;        //状态为falling
    }//如果上一次为低,这一次为高,说明是rising
    else if((key_0.m_b_key_last_status == LOW) && (key_0.m_b_key_curr_status == HIGH)){
        key_0.m_ChangeFlag = key_rising;         //说明是rising
    }
    
    //如果key_next有变化
    if((key_next.m_ChangeFlag == key_rising) || (key_next.m_ChangeFlag == key_falling)){
        //调用用户的回调函数
        Key_KeyChangeCall(callback,1, key_next.m_ChangeFlag);
    }//如果key_enter有变化
    else if((key_enter.m_ChangeFlag == key_rising) || (key_enter.m_ChangeFlag == key_falling)){
        Key_KeyChangeCall(callback,2, key_enter.m_ChangeFlag);
    }//如果key_0有变化
    else if((key_0.m_ChangeFlag == key_rising) || (key_0.m_ChangeFlag == key_falling)){
        Key_KeyChangeCall(callback,3, key_0.m_ChangeFlag);
    }

}
//变化时由按键变化状态机执行
void Key_KeyChangeCall(KeyChangeCb cb,uint8_t key_val,CHANGE_FLAG_t change_flag){
    if(nullptr != cb){
        cb(key_val,change_flag);
    }
}