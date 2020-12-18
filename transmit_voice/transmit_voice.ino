#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX


byte com = 0; //reply from voice recognition

void setup()
{
Serial.begin(9600);
mySerial.begin(9600);
Serial.write(0xAA);
Serial.write(0x37);
delay(1000);
Serial.write(0xAA);
Serial.write(0x21);
}

void loop() // run over and over again
{

while(Serial.available())
{
com = Serial.read();
switch(com)
{
case 0x11:
mySerial.write('1');
break;

case 0x12:
mySerial.write('2');
break;

case 0x13:
mySerial.write('3');
break;

case 0x14:
mySerial.write('4');
break;

case 0x15:
mySerial.write('5');
break;

}
}

}


