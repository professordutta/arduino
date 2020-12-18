#include <SoftwareSerial.h>
char temp;
int duration1, duration2;
SoftwareSerial mySerial(10,11);


void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  digitalWrite(9,LOW);
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
  pinMode(5,INPUT);
  digitalWrite(13,LOW);
}

void loop()
{
  if(mySerial.available()>0)
  {
    temp = mySerial.read();
    
    if(temp=='1')
    {
      digitalWrite(9,HIGH);
    }
    
    if(temp=='2')
    {
      digitalWrite(9,LOW);
    }
  }
  
 mySerial.println('A'); 
 digitalWrite(8, LOW);
 delayMicroseconds(2);
 digitalWrite(8, HIGH);
 delayMicroseconds(10);
 digitalWrite(8, LOW);
 
 duration1 = pulseIn(7, HIGH);
 
 
 digitalWrite(6, LOW);
 delayMicroseconds(2);
 digitalWrite(6, HIGH);
 delayMicroseconds(10);
 digitalWrite(6, LOW);
 
 duration2 = pulseIn(5, HIGH);
 

 duration1=duration1/58.6;
 duration2=duration2/58.6;
 
 if(duration1 < 30 || duration2 < 30)
 {
   digitalWrite(13,HIGH);
 }
 
 else
 {
   digitalWrite(13,LOW);
 }
 
}
