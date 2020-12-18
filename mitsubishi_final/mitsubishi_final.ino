float duration;
int plc=12;
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
  pinMode(plc,OUTPUT);
  digitalWrite(plc,LOW);
  Serial.begin(9600);
  
}


void routine_1()
{
  
}

void loop()
{  
 //digitalWrite(plc,HIGH); 
 digitalWrite(10, LOW);
 delayMicroseconds(2);
 digitalWrite(10, HIGH);
 delayMicroseconds(10);
 digitalWrite(10, LOW);
 
 duration = pulseIn(11, HIGH);
 
 duration=duration/58.6;
 
 Serial.println(duration);
 delay(100);
  if(duration<25)
  {
    digitalWrite(13,HIGH);
    digitalWrite(plc,LOW);
    delay(2000);
    routine_1();
  }
  
  else
  {
    digitalWrite(13,LOW);
    digitalWrite(plc,HIGH);
    
   
  }
  
}
