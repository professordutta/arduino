int i,r1,r2;

void setup()
{
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  Serial.begin(9600);
}

void loop()
{
  r1=digitalRead(10);
  r2=digitalRead(11);
 
 /* if(x==HIGH)
  {
  digitalWrite(13,HIGH);
  Serial.println("led on...");
  }
  //delay(1000);
  */
  
  while(r1==HIGH && r2==HIGH);
  {
 // digitalWrite(13,LOW);
  Serial.println("start...");
 //digitalWrite(13,LOW);
  i=i+1;
  Serial.println(i);
  delay(1000);
  }
  if(r2==LOW);
  
    Serial.println("out...");
  
} 
 

//Serial.println("OUT");
 


