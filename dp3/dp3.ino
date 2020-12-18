#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);
int m;
char temp[12];
void setup()  
{
 
  Serial.begin(9600);
  mySerial.begin(9600);
 }
 
 void loop() // run over and over
{
  
  for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if (mySerial.available())
  {
  temp[m]=mySerial.read();
  Serial.write(temp[m]);
  }
  }
}
