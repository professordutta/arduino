#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
void setup()
{
  mySerial.begin(115200);
  Serial.begin(115200);
}

void loop()
{
  while(!mySerial.available());
  if(mySerial.available()>0)
  {
    Serial.print(mySerial.read());
  }
  
}
