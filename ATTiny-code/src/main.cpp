/*
to do: when switch is held, light 1 light up after each second 
then after 3 or so seconds close power switch

use transistor to short the circuit
*/

#include <Arduino.h>

const int led_1 = 1; //check these later
const int led_2 = 2;
const int led_3 = 3; 

const int key_switch = 4; 

const int power_switch = 5;

int start_time;
int time_elapsed;

// bool switch_released = false;
// int switch_prev_state = 0;

void setup(){
    pinMode(led_1, OUTPUT);
    pinMode(led_2, OUTPUT);
    pinMode(led_3, OUTPUT);
    
    pinMode(key_switch, INPUT);

    pinMode(power_switch, OUTPUT);

    digitalWrite(power_switch, LOW);
}

void loop(){

    if (digitalRead(key_switch == HIGH)){
        start_time = millis();

        while (digitalRead(key_switch == HIGH)){
            time_elapsed = millis() - start_time;
            if (time_elapsed >= 1000){
                digitalWrite(led_1, HIGH);
            }
            if (time_elapsed >= 2000){
                digitalWrite(led_2, HIGH);
            }
            if (time_elapsed >= 3000){
                digitalWrite(led_3, HIGH);
                delay(250);
                digitalWrite(power_switch, HIGH);
                delay(50);
                digitalWrite(power_switch, LOW);
            }
        }
    }
}