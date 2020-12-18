#include <Arduino.h>
#include <Servo.h>
#include "BasicStepperDriver.h"

Servo servo1;

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 120

// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
#define MICROSTEPS 1

// All the wires needed for full functionality
#define DIR 8
#define STEP 9

char step_count[4];
//Uncomment line to use enable/disable functionality
//#define SLEEP 13

// 2-wire basic config, microstepping is hardwired on the driver
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

//Uncomment line to use enable/disable functionality
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, SLEEP);

void setup() {
    stepper.begin(RPM, MICROSTEPS);
    Serial.begin(9600);
    servo1.attach(12);
//    pinMode(5,INPUT);
    // if using enable/disable on ENABLE pin (active LOW) instead of SLEEP uncomment next line
    // stepper.setEnableActiveState(LOW);
}

void loop() 
{
  //if(digitalRead(5) == 1)
  //{
    
   // Serial.readBytesUntil('\0',step_count,4);
   // int step_value = atoi(step_count);
    //stepper.move(90);
   // Serial.println(step_value);
    servo1.write(40);
    delay(1000);
    //servo1.write(90);
   // delay(1000);
    //stepper.move(90);
    //delay(3000);

    servo1.write(10);
    
  //}
}


