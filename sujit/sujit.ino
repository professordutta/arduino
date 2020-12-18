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
 digitalWrite(12, LOW);
 delayMicroseconds(2);
 digitalWrite(12, HIGH);
 delayMicroseconds(10);
 digitalWrite(12, LOW);
 
 duration = pulseIn(11, HIGH);
 
 duration=duration/58.6;
 
 Serial.println(duration);
 delay(500); 
}
