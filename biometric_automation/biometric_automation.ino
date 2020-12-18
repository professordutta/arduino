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
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);

int getFingerprintIDez();

// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)

SoftwareSerial mySerial(2, 3);


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

int id;

char key;

int fan = 7;
int light1 = 6;
int light2 = 5;


int r1=A0;
int r2=A1;
int r3=A2;

int c1=A3;
int c2=A4;
int c3=A5;
int flag;

void check_col1()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  
  if(digitalRead(c1)==LOW)
  {
    key='1';
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  
  
  if(digitalRead(c1)==LOW)
  {
    key='4';
  }
  
  
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  
  if(digitalRead(c1)==LOW)
  {
    key='7';
  }
  
  digitalWrite(r3,HIGH);
  
  delay(400);
}

void check_col2()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  
  if(digitalRead(c2)==LOW)
  {
    key='2';
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  
  
  if(digitalRead(c2)==LOW)
  {
    key='5';
  }
  
  
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  
  if(digitalRead(c2)==LOW)
  {
    key='8';
  }
  digitalWrite(r3,HIGH);
  
  delay(400);
  
}


void check_col3()
{
  
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  
  if(digitalRead(c3)==LOW)
  {
    key='3';
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  
  
  if(digitalRead(c3)==LOW)
  {
    key='6';
  }
  
  
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  
  if(digitalRead(c3)==LOW)
  {
    key='9';
  }
  digitalWrite(r3,HIGH);
  
  delay(400);

  
  
}


void scan_key()
{
  
  if(digitalRead(c1)==LOW)
  {
    check_col1();
  }
  
  if(digitalRead(c2)==LOW)
  {
    check_col2();
  }
  
  if(digitalRead(c3)==LOW)
  {
    check_col3();
  }
  
}

void refkeypad()
{
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
}

void setup()  
{
  lcd.begin(16,2);
  Serial.begin(9600);
  Serial.println("fingertest");
  
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  
  pinMode(fan,OUTPUT);
  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  digitalWrite(fan,LOW);
  digitalWrite(light1,LOW);
  digitalWrite(light2,LOW);

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
  Serial.println("Waiting for valid finger...");
}

void loop()                     // run over and over again
{
  
  while(1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("Welcome");
  lcd.setCursor(0,1);
  lcd.print("Press any button");  
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  while(digitalRead(c1)==HIGH && digitalRead(c2)==HIGH && digitalRead(c3)==HIGH);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Put Finger...");
  
  while(flag==0)
  {
  id = getFingerprintIDez();
  if(id>=0)
  break;
  
  }
  if(id>=0)
  {
  Serial.print("ID is:");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ID is:");
  Serial.println(id);
  lcd.setCursor(0,1);
  lcd.print(id);
  delay(1500);
  if(id == 1 || id==2 || id==3 || id==4 || id==5 || id==6 || id==7 ||id==8)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Access Granted");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Press");
    lcd.setCursor(0,1);
    lcd.print("1: ON   2:OFF");
    while(digitalRead(c1)==HIGH && digitalRead(c2)==HIGH && digitalRead(c3)==HIGH);
    lcd.clear();
    scan_key();
    if(key == '1')
    {
      lcd.setCursor(0,0);
      lcd.print("1:FAN 2:LIGHT ON");
      lcd.setCursor(0,1);
      lcd.print("3:ALL ON");
      delay(100);
      refkeypad();
      while(digitalRead(c1)==HIGH && digitalRead(c2)==HIGH && digitalRead(c3)==HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      scan_key();
      if (key=='1')
      {
        digitalWrite(fan,HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Fan On");
        delay(1000);
      }
      
      if(key=='2')
      {
        digitalWrite(light1,HIGH);
        digitalWrite(light2,HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Light On");
        delay(1000);
        
      }
      
      if(key=='3')
      {
        digitalWrite(light1,HIGH);
        digitalWrite(light2,HIGH);
        digitalWrite(fan,HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("All Devices On");
        delay(1000);
        
      }
      
    }
    
    
    if(key == '2')
    {
      
      lcd.setCursor(0,0);
      lcd.print("1:FAN 2:TUBE OFF");
      lcd.setCursor(0,1);
      lcd.print("3:ALL OFF");
      delay(100);
      refkeypad();
      while(digitalRead(c1)==HIGH && digitalRead(c2)==HIGH && digitalRead(c3)==HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      scan_key();
      if (key=='1')
      {
        digitalWrite(fan,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Fan Off");
        delay(1000);
      }
      
      if(key=='2')
      {
        digitalWrite(light1,LOW);
        digitalWrite(light2,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Light Off");
        delay(1000);
        
      }
      
      if(key=='3')
      {
        digitalWrite(light1,LOW);
        digitalWrite(light2,LOW);
        digitalWrite(fan,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("All Devices Off");
        delay(1000);
        
      }
      
      
    }
    
    
  }
  
  }
  delay(50);            //don't ned to run this at full speed.
}
}

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
