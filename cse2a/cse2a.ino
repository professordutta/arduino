char temp;
char temp1[5];
int m;
int duration;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

do
{
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp=Serial.read();
  }
}while(temp!='*');

for(m=0;m<4;m++)
{
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp1[m]=Serial.read();
  }
}
duration=(1000*(temp1[0]-48))+(100*(temp1[1]-48))+(10*(temp1[2]-48))+(temp1[3]-48);
digitalWrite(13,HIGH);
delay(duration);
digitalWrite(13,LOW);

if(Serial.available()>0)
{
  temp=Serial.read();

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
