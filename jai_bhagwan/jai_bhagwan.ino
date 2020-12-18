int x;
int y;

void setup()
{
 Serial.begin(9600); 
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 
}


void loop()
{
  x=analogRead(A0);
  y=analogRead(A1);
  
  Serial.print("x:");
  Serial.println(x);
  digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  
  if(x>580)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    
  }
  
  if(y>580)
  {
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
  }
  
}
