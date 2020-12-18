
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
  }while(temp!='$');
  while(!Serial.available());
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
