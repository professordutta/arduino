
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX


char temp[12];
int m;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  delay(100);
}


void loop()
{
  for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if(mySerial.available()>0)
  {
    temp[m]=mySerial.read();
   }
  }
  
  for(m=0;m<12;m++)
  {
    Serial.print(temp[m]);
  }
  
  
  if(temp[0]=='6' && temp[1]=='5')
  {
    Serial.println("match found");
  }
  
  else
  {
    Serial.println("match not found");
  }
  
}
