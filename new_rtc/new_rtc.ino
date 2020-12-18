#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <String.h>
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(11,10,9,8,7,6);


RTC_DS1307 RTC;

char temp[11];
int selected_hour = 0;
int selected_minute = 0;
int selected_off_hour = 0;
int selected_off_minute = 0;

int now_time;

int eeprom_hour_addr = 1;
int eeprom_minute_addr = 2;
int eeprom_off_hour_addr = 3;
int eeprom_off_minute_addr = 4;



void setup() {

  //EEPROM.write(0, 0); ///////////////////////change it.

  Serial.begin(9600);
  lcd.begin(16,2);

  RTC.begin();
  Wire.begin();
  
 // Serial.print("UMESH DUTTA");

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  DateTime now = RTC.now();
  ////////////////////////////////////////////////////////
  if (EEPROM.read(7)==0) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    
  }
  if (EEPROM.read(7)==1) {
    digitalWrite(13,HIGH);
     digitalWrite(12,HIGH);
    
  }
  /////////////////////////////////////////////////////////
  now_time = now.hour()*100 + now.minute();
  if ((EEPROM.read(eeprom_hour_addr)*100 + EEPROM.read(eeprom_minute_addr)) < now_time && now_time < (EEPROM.read(eeprom_off_hour_addr)*100 + EEPROM.read(eeprom_off_minute_addr))) {
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    EEPROM.write(0, 1);
  }
  else {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    EEPROM.write(0, 0);
  }  
      delay(200);
  
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(now.hour(),DEC);
      lcd.print(':');
      lcd.print(now.minute(),DEC);

  

  
}

void loop() {
  //RTC.adjust(DateTime(__DATE__, __TIME__));
  DateTime now = RTC.now();
  

  if (EEPROM.read(0) == 1) {
    DateTime now = RTC.now();
     lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print(now.hour(),DEC);
    lcd.print(':');
    lcd.print(now.minute(),DEC);    

     delay(1000);
    Serial.println("eeprom 1");
    
    
    
    if(now.second()==0)
    {
      lcd.clear();
      delay(300);

    Serial.print(now.hour(), DEC);
    lcd.setCursor(0,0);
    lcd.print(now.hour(),DEC);
    lcd.print(':');
    Serial.print(':');
    lcd.print(now.minute(),DEC);
    }
    if(now.minute()==0)
    {
      delay(400);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(now.hour(),DEC);
      lcd.print(':');
      lcd.print(now.minute(),DEC);
    
    }
    Serial.print(now.minute(), DEC);
    Serial.println();

    if ((now.hour() == EEPROM.read(eeprom_hour_addr)) && (now.minute() == EEPROM.read(eeprom_minute_addr))) {
      
      
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      EEPROM.write(7,1);

      //EEPROM.write(0, 0); //allowing to again set time.
      EEPROM.write(5,0);
      selected_hour = 0;
      selected_minute = 0;
      EEPROM.write(eeprom_hour_addr, 0);
      EEPROM.write(eeprom_minute_addr, 0);
      
      while((now.hour() == EEPROM.read(eeprom_hour_addr)) && (now.minute() == EEPROM.read(eeprom_minute_addr)));
    //  lcd.clear();
      //lcd.setCursor(0,0);
      //lcd.print("Device on");
      //delay(300);
      //lcd.print(now.hour(),DEC);
      //lcd.print(':');
      //lcd.print(now.minute(),DEC);

    }
    
    if ((now.hour() == EEPROM.read(eeprom_off_hour_addr)) && (now.minute() == EEPROM.read(eeprom_off_minute_addr))) {

      Serial.print("low.");

      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      delay(200);
      EEPROM.write(7,0);

      //EEPROM.write(0, 0); //allowing to again set time.
      EEPROM.write(6,0);
      selected_off_hour = 0;
      selected_off_minute = 0;
      EEPROM.write(eeprom_off_hour_addr, 0);
      EEPROM.write(eeprom_off_minute_addr, 0);
      delay(400);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(now.hour(),DEC);
      lcd.print(':');
      lcd.print(now.minute(),DEC);
      delay(400);
      while((now.hour() == EEPROM.read(eeprom_off_hour_addr)) && (now.minute() == EEPROM.read(eeprom_off_minute_addr)));

    }
    

    if ((EEPROM.read(5)==0) && (EEPROM.read(6)==0)) {
      
      Serial.print("5 6");
      
      EEPROM.write(0, 0);
      delay(200);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(now.hour(),DEC);
      lcd.print(':');
      lcd.print(now.minute(),DEC);
      delay(200);
    }
    
    delay(1000);
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if (EEPROM.read(0) == 0) {

    if(now.second()==0)
    {
    Serial.print("eeprom 0");
    delay(400);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(now.hour(),DEC);
    lcd.print(':');
    lcd.print(now.minute(),DEC);
    }
    if(now.minute()==0)
    {
      delay(400);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(now.hour(),DEC);
      lcd.print(':');
      lcd.print(now.minute(),DEC);
      delay(200);
    
    }    
    
    while (!Serial.available())   ///
    {
      DateTime now = RTC.now();
      delay(200);
      lcd.setCursor(0,0);
      lcd.print(now.hour(),DEC);
      lcd.print(':');
      lcd.print(now.minute(),DEC);
      if(now.minute()==0)
      {
      lcd.clear();
    
      }    
    }

    if (Serial.available()) {      ////

      digitalWrite(13, LOW);
      digitalWrite(12, LOW);

      //read data
      for (int i = 0 ; i <= 10 ; i++) {
        temp[i] = Serial.read();     ////
        delay(10);
      }
    }
    
   
    //print data
    for (int i = 0 ; i <= 10 ; i++) {
      Serial.print(temp[i]);
    }


    //on hour
    for (int i = 0 ; i <= 1 ; i++) {
      selected_hour = (selected_hour * 10) + temp[i] - '0';  //convert temp to int.
    }
    Serial.println(selected_hour);
    EEPROM.write(eeprom_hour_addr, selected_hour);


    //on minute
    for (int i = 3 ; i <= 4 ; i++) {
      selected_minute = (selected_minute * 10) + temp[i] - '0';  //convert temp to int.
    }
    Serial.println(selected_minute);
    EEPROM.write(eeprom_minute_addr, selected_minute);
    
    EEPROM.write(5,1);
    
    
    //off hour
    for (int i = 6 ; i <= 7 ; i++) {
      selected_off_hour = (selected_off_hour * 10) + temp[i] - '0';  //convert temp to int.
    }
    Serial.println(selected_off_hour);
    EEPROM.write(eeprom_off_hour_addr, selected_off_hour); 
 
 
    //off minute
    for (int i = 9 ; i <= 10 ; i++) {
      selected_off_minute = (selected_off_minute * 10) + temp[i] - '0';  //convert temp to int.
    }
    Serial.println(selected_off_minute);
    EEPROM.write(eeprom_off_minute_addr, selected_off_minute);   

    EEPROM.write(6,1);
    
    

    selected_hour = 0;
    selected_minute = 0;
    selected_off_hour = 0;
    selected_off_minute = 0;
    
    EEPROM.write(0, 1); //time setted.
    
    lcd.clear();
    delay(400);
    lcd.setCursor(0,0);
    lcd.print(now.hour(),DEC);
    lcd.print(':');
    lcd.print(now.minute(),DEC);    
    
    if(now.second()==0)
    {
    lcd.clear();
    delay(200);
    lcd.setCursor(0,0);
    lcd.print(now.hour(),DEC);
    lcd.print(':');
    lcd.print(now.minute(),DEC);    
    }

    delay(100);

  }
}
