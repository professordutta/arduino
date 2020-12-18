int s1;
int s2;
float duration;

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,INPUT);
  Serial.begin(9600);
  
}


void loop()
{
  s1=analogRead(A0);
  s2=analogRead(A1);
  Serial.println(s1);
  Serial.println(s2);
  
  
  
  
 digitalWrite(12, LOW);
 delayMicroseconds(2);
 digitalWrite(12, HIGH);
 delayMicroseconds(10);
 digitalWrite(12, LOW);
 
 duration = pulseIn(11, HIGH);
 
 duration=duration/58.6;
 
 Serial.println(duration);
 delay(400);

  
  
  
  if(s1>500)
  {
    digitalWrite(13,HIGH);
  }
  
  if(s2>500 || duration<15.0)
  {
    digitalWrite(13,LOW);
  }
  
  
  
}
