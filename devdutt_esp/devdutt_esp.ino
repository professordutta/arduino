
char temp,temp1;
void setup()
{
 Serial.begin(115200);
 pinMode(13,OUTPUT);
 digitalWrite(13,LOW);
}
void loop()
{
  do
  {
    while(!Serial.available());
    temp=Serial.read();
  }while('$'!=temp);
  while(!Serial.available());
  temp1=Serial.read();
  
  if(temp1=='A')
  {
    digitalWrite(13,HIGH);
  }
  if(temp1=='B')
  {
    digitalWrite(13,LOW);
  }
    
}
