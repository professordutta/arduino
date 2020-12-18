byte com = 0; //reply from voice recognition

void setup()
{
Serial.begin(9600);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);

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
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);

break;

case 0x12:
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);

break;

case 0x13:
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);

break;

case 0x14:
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);

break;

case 0x15:
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);

break;

}
}

}


