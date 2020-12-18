#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX



void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


while(!mySerial.available());

if(mySerial.available()>0)
{
  Serial.print(mySerial.read());
}
}

