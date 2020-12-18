// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
#include <SoftwareSerial.h>

//RTC_DS1307 RTC;

RTC_Millis RTC;

void setup () 
{
    Serial.begin(9600);
    Wire.begin();
    RTC.begin(DateTime(__DATE__, __TIME__));
}


void loop() 
{
    DateTime now = RTC.now();    
    Serial.print(now.hour(), DEC);
    Serial.print(":");
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    delay(1000); 
  }
        
}
