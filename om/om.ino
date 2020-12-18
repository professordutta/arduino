int temp;
void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  
}


void loop()
{
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp=Serial.read();
    if(temp=='1')
    {
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      
      
    }
    
    if(temp=='2')
    {
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      
      
    }
    
    if(temp=='3')
    {
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      
      
    }
    
    if(temp=='4')
    {
      digitalWrite(2,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      
      
    }
    
    if(temp=='5')
    {
      digitalWrite(2,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
    }
  
  
    
  }
  
 
}

