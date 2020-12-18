// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX


//RTC_DS1307 RTC;

RTC_Millis RTC;


int temp1;
int temp2;
int temp3;
char temp;

LiquidCrystal lcd(2,3,4,5,6,7);

void setup () 
{
    pinMode(13,OUTPUT);
    Serial.begin(9600);
    mySerial.begin(9600);
    Wire.begin();
    RTC.begin(DateTime(__DATE__, __TIME__));
    lcd.begin(16,2);
  }


void loop () {
    DateTime now = RTC.now();
    
    
    // lcd hours
    
    
    while(!mySerial.available())
    {
    lcd.setCursor(0,0);
    lcd.print(now.hour());
    Serial.print(now.hour(), DEC);
    temp1 = now.hour();
    lcd.print(":");
    Serial.print(":");
    
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    temp2 = now.minute();
    
    //lcd minutes
    
    lcd.print(now.minute());
    lcd.print(":");
    
    Serial.print(now.second(), DEC);
    Serial.println();
    
    temp3 = now.second();
    
    lcd.print(now.second());
    
    temp3 = now.second();
    
    delay(1000);
    if(temp3 == 59)
    {
      delay(1000);
      lcd.setCursor(7,0);
      lcd.print(" ");
      temp3 = now.second();
    }
    
    
    if (temp1==13 && temp2==52 && temp3==0)
    {
      digitalWrite(13,HIGH);
    }
    
  }
  
  
  /*if(mySerial.available()>0)
  {
    do
    {
      temp = mySerial.read();
    }while('A'!=temp);
    
    if(temp=='A')
    {
      digitalWrite(13,HIGH);
      
    }
    
  }
  */
  
        
}
