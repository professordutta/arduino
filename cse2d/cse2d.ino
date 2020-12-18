void setup() {
  // put your setup code here, to run once:

pinMode(13,OUTPUT);
pinMode(2,INPUT);
digitalWrite(2,HIGH);
digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(2)==LOW)
{
digitalWrite(13,HIGH);
}

if(digitalRead(2)==HIGH)
{
digitalWrite(13,LOW);
}

}
