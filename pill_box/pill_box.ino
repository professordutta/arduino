// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
#include <SoftwareSerial.h>

//RTC_DS1307 RTC;

RTC_Millis RTC;

SoftwareSerial mySerial(10,11); ///10-rx 11-tx

int m;

int temp[17];
char temp1;

void setup () 
{
    Serial.begin(9600);
    mySerial.begin(9600);
    Wire.begin();
    RTC.begin(DateTime(__DATE__, __TIME__));
    pinMode(2,INPUT);
    digitalWrite(2,HIGH);
}


void loop() 
{
  // pin 2 is made low for setting the time 
  if(digitalRead(2)==LOW)
  {
    do
    {
      while(!mySerial.available());
      temp1=mySerial.read();
    }while(temp1!='*');
    Serial.print("start of timing frame");

    for(m=0;m<16;m++)
    {
      while(!mySerial.available());
      temp[m]=mySerial.read();
    }

    for(m=0;m<16;m++)
    {
      Serial.print(temp[m]);
    }
    
    
  }

  if(digitalRead(2)==HIGH)
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
