char temp;
void setup()
{
Serial.begin(9600);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
}

void loop() // run over and over again
{

while(!Serial.available());
temp = Serial.read();
if(temp=='1')
{
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
}

if(temp=='2')
{
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
}

if(temp=='3')
{
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
}

if(temp=='4')
{
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
}

if(temp=='5')
{
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
}


}


