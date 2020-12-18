char temp;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

while(!Serial.available());

if(Serial.available()>0)
{
  temp = Serial.read();

  if(temp=='A')
  {
    digitalWrite(13,HIGH);
  }
  if(temp=='B')
  {
    digitalWrite(13,LOW);
  }
}
}
