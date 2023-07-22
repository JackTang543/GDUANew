#ifndef __KEY_H__
#define __KEY_H__

//变化标志
typedef enum{
    key_rising = 0,
    key_falling,
    key_non_change
}CHANGE_FLAG_t;
//回调函数,一旦有按键变化,就调用用户的函数
typedef void (*KeyChangeCb)(uint8_t key_val,CHANGE_FLAG_t change_flag);

void Key_KeyRead_Init(void);
void Key_setKeyCallback(KeyChangeCb cb);
void Key_KeyCheck(void* parameter);
void Key_KeyChangeCall(KeyChangeCb cb,uint8_t key_val,CHANGE_FLAG_t change_flag);

#endif