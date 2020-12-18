int s1;
int s2;
char temp;
void setup()
{
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  
}


void loop()
{
  s1=analogRead(A0);
  s2=analogRead(A1);
  
  
  if(s1> 200 && s2>200)
  {
    Serial.println("Hi");
    delay(500);
  }
  
 if(Serial.available()>0)
 {
   temp=Serial.read();
   
   if(temp=='1')
   {
     digitalWrite(3,HIGH);
     delay(1000);
     digitalWrite(3,LOW);
     digitalWrite(4,HIGH);
     delay(1000);
     digitalWrite(4,LOW);
     
     
   }
 }
  
  
  
}
