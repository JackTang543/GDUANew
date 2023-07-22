#include <Arduino.h>

#include "driver/key.h"
#include "driver/func.h"

void key_callback(uint8_t key_val,CHANGE_FLAG_t change_flag){
	if(key_val == 1){
		Serial.print("key_val = 1,");
		Serial.print("change_flag = ");
		if(change_flag == key_rising){
			Serial.println("rising");
		}
		if(change_flag == key_falling){
			Serial.println("falling");
		}
		Serial.println(" ");
	}
	if(key_val == 2){
		Serial.print("key_val = 2,");
		Serial.print("change_flag = ");
		if(change_flag == key_rising){
			Serial.println("rising");
		}
		if(change_flag == key_falling){
			Serial.println("falling");
		}
		Serial.println(" ");
	}
	if(key_val == 3){
		Serial.print("key_val = 3,");
		Serial.print("change_flag = ");
		if(change_flag == key_rising){
			Serial.println("rising");
		}
		if(change_flag == key_falling){
			Serial.println("falling");
		}
		Serial.println(" ");
	}
	
}

void setup(){
	SysInit();
	TaskInit();
	
	Serial.begin(115200);

	Key_KeyRead_Init();
	Key_setKeyCallback(key_callback);

}

void loop(){

}
