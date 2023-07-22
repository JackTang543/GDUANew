#include <Arduino.h>
#include "key.h"

void ReadKeyStatus(void* parameter){
    pinMode(2,OUTPUT);
    
    digitalWrite(2,!digitalRead(2));
}
