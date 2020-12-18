
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX







char temp[12];
int m;






void setup()
{
  
   mySerial.begin(9600);
   Serial.begin(9600);
   pinMode(13,OUTPUT);
   digitalWrite(13,LOW);
 
   
}

void loop()
{
  
  
   for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if (mySerial.available()>0)
  {
  temp[m]=mySerial.read();
  Serial.write(temp[m]);
  }
  }
  
  if(temp[10]=='8' && temp[11]=='2')
  {
    digitalWrite(13,LOW);
    
  }
  
  
  
    
  
  else
  {
    digitalWrite(13,HIGH);
  }
  
  
  
  
  
}
