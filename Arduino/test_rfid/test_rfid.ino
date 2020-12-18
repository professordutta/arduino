#include <SoftwareSerial.h>
SoftwareSerial mySerial(11,12);
int m;
int count;
char temp[12];
void setup()
{
  // put your setup code here, to run once:

  mySerial.begin(9600);
  Serial.begin(9600);
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if(mySerial.available()>0)
  {
    temp[m]=mySerial.read();
    Serial.print(temp[m]);
  }
  }
} 

  
  

