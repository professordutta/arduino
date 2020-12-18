/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/


#include <Adafruit_Fingerprint.h>
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;
int temp;
int temp1;
int temp2;

#include <LiquidCrystal.h>
LiquidCrystal lcd (10,A0,8,7,6,5);

int getFingerprintIDez();

// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)

SoftwareSerial mySerial(2, 3);


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

int id;
int flag;


void setup()  
{
  pinMode(4,INPUT);
  digitalWrite(4,HIGH);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,HIGH);
  Serial.begin(9600);
  Serial.println("fingertest");
  lcd.begin(16,2);
  delay(5);
  lcd.print("MANAV RACHNA");
  
 
  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
  Serial.println("Waiting for valid finger...");
  

  
   if (!SD.begin(9)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
   Wire.begin();
    RTC.begin();
    delay(100);

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  
}

void loop()                     // run over and over again
{
   DateTime now = RTC.now();
  lcd.clear();
   while(digitalRead(4)==HIGH)
  {
    DateTime now = RTC.now();
    
    lcd.setCursor(0,1);
    lcd.print(now.hour(),DEC);
    lcd.print(":");
    temp2=now.hour();
    lcd.print(now.minute(),DEC);
    lcd.print(":");
    temp1=now.minute();
    lcd.print(now.second(),DEC);
    temp=now.second();
    delay(1000);
    if(temp==59)
    {
      lcd.setCursor(6,1);
      lcd.print("  ");
    }
    
    if(temp1==59 && temp==59)
    {
      lcd.setCursor(3,1);
      lcd.print("  ");
      lcd.setCursor(6,1);
      lcd.print("  ");
    }
    
    if(temp2==23 && temp1==59 && temp==59)
    {
      lcd.setCursor(0,1);
      lcd.print("  ");
    }
  }
  
  while(flag==0)
  {
  id = getFingerprintIDez();
  if(id>=0)
  break;
  
  }
  if(id>=0)
  {
   Serial.print("ID is:");
  Serial.println(id);
  
  Serial.print(now.hour(),DEC);
  Serial.print(":");
  Serial.print(now.minute(),DEC);
  Serial.print(":");
  Serial.println(now.second(),DEC);
    /*lcd.setCursor(0,1);
    lcd.print("               ");
    lcd.setCursor(0,1);
    lcd.print("USER ID:");
    lcd.print(id);
    delay(1000);
    */
    Serial.println("Present"); 
    
    File myFile = SD.open("temp1.csv", FILE_WRITE);
    if (myFile) 
    {
    myFile.print("ID");
    myFile.print(",");
    myFile.print(id);
    myFile.print(",");
    myFile.print(now.hour(),DEC);
    myFile.print(":");
    myFile.print(now.minute(),DEC);
    myFile.print(":");
    myFile.println(now.second(),DEC);
    // close the file:
    myFile.close();
    digitalWrite(A1,LOW);
    delay(1500);
    digitalWrite(A1,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ID:");
    lcd.print(id);
    delay(1000);
  
  
  }
}}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
