// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int led = A3;
//int led1 = 2;
//int led2 = 7;
////////////////////////////////////////////////////////
int led1 = A2;
//int led4 = 3;
//int led5 = 4;
/////////////////////////////////////////////////////////////
int led2 = A1;
//int led7 = 11;
//int led8 = 12;
////////////////////////////////////////////////////////////
//int led9 = 5;
//int led10 = 6;
int led3 = A0;
int buzzor=6;
//int vibrator=A2;
//int buzzor = A3;
//int s1=7;
//int s2=A0;
//int a;
RTC_DS1307 RTC;
int z=0;
int addr=0;
int a = 0;
int a1 = 1;
int a2 = 2;
int a3 = 3;
int a4 = 4;
int a5 = 5;
int a6 = 6;
int a7 = 7;
int a8 = 8;
//String inputString="$18$37$18$38$18$39$18$40$5$";    ////////////////////////////////////($id$date$month$hour$minute)
//String splitString(String s, char parser,int index);
int value;
int value1;
int value2;
int value3;
int value4;
int value5;
int value6;
int value7;
int value8;
int a0;
/*const int button1=2;
const int button2=3;
int button1state =0;
int button2state =0;
*/
String inputString = "";         // a string to hold incoming data
String splitString(String s, char parser,int index);
boolean stringComplete = false;  // whether the string is complete

void setup () {
  
  lcd.begin(16, 2);
//  digitalWrite(s1,HIGH);
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3, OUTPUT);
//pinMode(led4, OUTPUT);
 //pinMode(led5, OUTPUT);  
 //pinMode(led6, OUTPUT);  
 //pinMode(led7, OUTPUT);  
 //pinMode(led8, OUTPUT);
 //pinMode(led9, OUTPUT);  
 //pinMode(led10, OUTPUT);
 //pinMode(led11, OUTPUT);
 pinMode(buzzor, OUTPUT);
 //pinMode(vibrator, OUTPUT);
 //pinMode(s1, OUTPUT);
// pinMode(s2, OUTPUT);

  Serial.begin(9600);
    Wire.begin();
    RTC.begin();
    
    inputString.reserve(200);
    
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
 
//  pinMode(button1,INPUT);
  //pinMode(button2,INPUT);
 
 
  }
}

void loop () {
  lcd.setCursor(0, 1);

  //button1state =digitalRead(button1);
  //button2state =digitalRead(button2);
    DateTime now = RTC.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
   
/*if((now.minute()==36)&&(now.hour()==2))
 {
      digitalWrite(led,HIGH);
 // delay(5000);
  //digitalWrite(ledpin,LOW);
 }*/
 //a0=digitalRead(A3);
  if (stringComplete) 
  {
     Serial.println(inputString);
   int c=0;
  String b1h1=splitString(inputString,'.',1);
  String b1m1 = splitString(inputString,'.',2);
  String b2h2 = splitString(inputString,'.',3);
  String b2m2=splitString(inputString,'.',4);
  String b3h3 = splitString(inputString,'.',5);
  String b3m3 = splitString(inputString,'.',6);
  String b4h4 = splitString(inputString,'.',7);
  String b4m4 = splitString(inputString,'.',8);
  String b5m5 = splitString(inputString,'.',9);
  
  ////////////////////////////////////////////////////////////////////////////////////////////////
  int b1 = stringToNumber(b1h1);
  int z = stringToNumber(b1m1);
  int b2 = stringToNumber(b2h2);
  int B2 = stringToNumber(b2m2);
  int b3 = stringToNumber(b3h3);
  int B3 = stringToNumber(b3m3);
  int b4 = stringToNumber(b4h4);
  int B4 = stringToNumber(b4m4);
  int B5 = stringToNumber(b5m5);


  
    Serial.print("Box1:");
    Serial.println(b1h1);
 delay(1000);
     Serial.print("Box1:");
     Serial.println(b1m1);
 delay(1000);
     Serial.print("Box2:");
     Serial.println(b2h2);
 delay(1000);
  Serial.print("Box2:");
     Serial.println(b2m2);
 delay(1000);
  Serial.print("Box3:");
     Serial.println(b3h3);
 delay(1000);

Serial.print("Box3:");
     Serial.println(b3m3);
 delay(1000);

Serial.print("Box4:");
     Serial.println(b4h4);
 delay(1000);

Serial.print("Box4:");
     Serial.println(b4m4);
 delay(1000);

  
   EEPROM.write(addr, b1);
  Serial.print("address:");
  Serial.print(addr);
  Serial.print("\t");
   Serial.print("b1h1:");
  Serial.print(b1);
  Serial.println();
  
  addr++;
  EEPROM.write(addr, z);
   Serial.print("address:");
    Serial.print(addr);
   Serial.print("\t");
   Serial.print("b1m1:");
  Serial.print(z);
  Serial.println();
  
  addr++;
  EEPROM.write(addr, b2);
   Serial.print("address:");
    Serial.print(addr);
   Serial.print("\t");
   Serial.print("b2h2:");
  Serial.print(b2);
  Serial.println();
  
  addr++;
  EEPROM.write(addr, B2);
   Serial.print("address:");
    Serial.print(addr);
   Serial.print("\t");
   Serial.print("b2m2:");
  Serial.print(B2);
  Serial.println();
  
  addr++;
  EEPROM.write(addr, b3);
   Serial.print("address:");
    Serial.print(addr);
   Serial.print("\t");
   Serial.print("b3h3:");
  Serial.print(b3);
  Serial.println();
 
  addr++;
  EEPROM.write(addr, B3);
   Serial.print("address:");
    Serial.print(addr);
   Serial.print("\t");
   Serial.print("b3m3:");
  Serial.print(B3);
  Serial.println();
 
 addr++;
  EEPROM.write(addr, b4);
   Serial.print("address:");
    Serial.print(addr);
   Serial.print("\t");
   Serial.print("b4h4:");
  Serial.print(b4);
  Serial.println();
 
 addr++;
  EEPROM.write(addr, B4);
   Serial.print("address:");
    Serial.print(addr);
   Serial.print("\t");
   Serial.print("b4m4:");
  Serial.print(B4);
  Serial.println();
 
 addr++;
 
 
  EEPROM.write(addr, B5);
   /*Serial.print("address:");
    Serial.print(addr);
   Serial.print("\t");
   Serial.print("b5m5:");
  Serial.print(B5);
  Serial.println();
 */
 delay(3000);
// readComplete=false;

  }
 value = EEPROM.read(a);
    value1 = EEPROM.read(a1);
      value2 = EEPROM.read(a2);
 value3 = EEPROM.read(a3);
      value4 = EEPROM.read(a4);
 value5 = EEPROM.read(a5);
value6 = EEPROM.read(a6);
value7 = EEPROM.read(a7);
value8 = EEPROM.read(a8);
  
  Serial.print(a);
  Serial.print("\t");
  Serial.print(value);
  Serial.println();

  Serial.print(a1);
  Serial.print("\t");
  Serial.print(value1);
  Serial.println();
  
  Serial.print(a2);
  Serial.print("\t");
  Serial.print(value2);
  Serial.println();
  
  Serial.print(a3);
  Serial.print("\t");
  Serial.print(value3);
  Serial.println();
  
  Serial.print(a4);
  Serial.print("\t");
  Serial.print(value4);
  Serial.println();

  Serial.print(a5);
  Serial.print("\t");
  Serial.print(value5);
  Serial.println();


Serial.print(a6);
  Serial.print("\t");
  Serial.print(value6);
  Serial.println();

Serial.print(a7);
  Serial.print("\t");
  Serial.print(value7);
  Serial.println();

Serial.print(a8);
  Serial.print("\t");
  Serial.print(value8);
  Serial.println();


  delay(1000);
 inputString = "";
    stringComplete = false;
  
  


  if((now.hour()==value)&&now.minute()==value1)
  {
    A0001();
   /* digitalWrite(s1,LOW);
    delay(1500);
    digitalWrite(s1,HIGH);*/
    //delay(60000);
    
  }
   else if((now.hour()==value2)&&now.minute()==value3)
  {
    //digitalWrite(s1,LOW);
     A0010();

  }
    else if((now.hour()==value4)&&now.minute()==value5)
  {
     A0011();

  }
   else if((now.hour()==value6)&&now.minute()==value7)
  {
     A0100();

  }
  
 
  else
  {
    AllOff();
  }
}
//int value4 =now.minute()==z;
//int x=now.hour()==value4;
 int stringToNumber(String thisString) {
  int i, value, length;
  length = thisString.length();
  char blah[(length+1)];
  for(i=0; i<length; i++) {
    blah[i] = thisString.charAt(i);
  }
  blah[i]=0;
  value = atoi(blah);
  return value;
}
////////////////////////////////////////////////////////////////////
String splitString(String s, char parser,int index){
  String rs='\0';
  int parserIndex = index;
  int parserCnt=0;
  int rFromIndex=0, rToIndex=-1;

  while(index>=parserCnt){
    rFromIndex = rToIndex+1;
    rToIndex = s.indexOf(parser,rFromIndex);

    if(index == parserCnt){
      if(rToIndex == 0 || rToIndex == -1){
        return '\0';
      }
      return s.substring(rFromIndex,rToIndex);
    }
    else{
      parserCnt++;
    }

  }
  return rs;
}


/////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void A0001 ()
{
  digitalWrite(led,HIGH);
  //digitalWrite(led1,HIGH);
  //digitalWrite(led2,HIGH);
  digitalWrite(buzzor,LOW);
  //digitalWrite(vibrator,HIGH);
  
  //analogWrite(s2,HIGH);
  lcd.print("Take Your Pills");
  delay(3000);
  digitalWrite(led,LOW);
//  digitalWrite(led1,LOW);
 // digitalWrite(led2,LOW);
  
  
  //digitalWrite(led3,LOW);
  //digitalWrite(led4,LOW);
  //digitalWrite(led5,LOW);
  digitalWrite(buzzor,HIGH);
//digitalWrite(vibrator,LOW);  
  delay(1000); 
}
void A0010 ()
{
  digitalWrite(led1,HIGH);
  //digitalWrite(led4,HIGH);
  //digitalWrite(led5,HIGH);
  digitalWrite(buzzor,LOW);
  // digitalWrite(vibrator,HIGH);
   lcd.print("Take Your Pills");
   //analogWrite(s1,LOW);
//    analogWrite(s2,HIGH);
  delay(3000);
  digitalWrite(led1,LOW);
  //digitalWrite(led4,LOW);
  //digitalWrite(led5,LOW);
  //digitalWrite(led8,LOW);
  digitalWrite(buzzor,HIGH);
   // digitalWrite(vibrator,LOW);
  delay(1000);
}
void A0011 ()
{
  //digitalWrite(led5,HIGH);
  digitalWrite(led2,HIGH);
  //digitalWrite(led7,HIGH);
  //digitalWrite(led8,HIGH);
  digitalWrite(buzzor,LOW);
  //  digitalWrite(vibrator,HIGH);
    //analogWrite(s1,LOW);
//    analogWrite(s2,HIGH);
    lcd.print("Take Your Pills");
  delay(3000);
  //digitalWrite(led5,LOW);
  digitalWrite(led2,LOW);
  //digitalWrite(led7,LOW);
  //digitalWrite(led8,LOW);
  digitalWrite(buzzor,HIGH);
   // digitalWrite(vibrator,LOW);
  delay(1000);
}

void A0100 ()
{
  digitalWrite(led3,HIGH);
 // digitalWrite(led10,HIGH);
 // digitalWrite(led11,HIGH);
  digitalWrite(buzzor,LOW);
    //digitalWrite(vibrator,HIGH);
    //analogWrite(s1,LOW);
//    analogWrite(s2,HIGH);
    lcd.print("Take Your Pills");
  delay(3000);
  digitalWrite(led3,LOW);
 // digitalWrite(led10,LOW);
 // digitalWrite(led11,LOW);
  digitalWrite(buzzor,HIGH);
    //digitalWrite(vibrator,LOW);
  delay(1000);
}

void AllOff()
{
  digitalWrite(led, LOW);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
    // digitalWrite(led4, LOW);
    // digitalWrite(led5, LOW);
     //digitalWrite(led6, LOW);
     //digitalWrite(led7, LOW);
    // digitalWrite(led8, LOW);
    // digitalWrite(led9, LOW);
    // digitalWrite(led10, LOW);
     //digitalWrite(led11,LOW);
     digitalWrite(buzzor,LOW);
     //digitalWrite(vibrator,LOW);
       //analogWrite(s1,HIGH);
//    analogWrite(s2,HIGH);
}


void serialEvent() 
{
  while (Serial.available()) 
  {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
//    Serial.println(inputString);
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}



