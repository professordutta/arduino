
// o/ps are connected to 5th and 6th pin through relay
// i/ps from rf module are connected to pin no. 5 and 6

int s1=0;
int s2=0;
void setup()
{
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop()
{
  s1=digitalRead(2);
  s2=digitalRead(3);
  
  if(s1==HIGH && s2==HIGH)
  {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
  
  if(s1==LOW && s2==HIGH)
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    
  }
  
  if(s1==HIGH && s2==LOW)
  {
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
  }
  
  if(s1==LOW && s2==LOW)
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    
  }
}

