
 #include <LiquidCrystal.h>
 LiquidCrystal lcd(6, 5, 13, 12, 11, 10);
int temp;
float temp1;
float temp2;
void setup()
{
   pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  
  
  Serial.begin(9600);
  lcd.begin(16,2);
  
  
}

void loop()
{
  while(!Serial.available())
  {
    temp1=analogRead(A0);
    
    
     Serial.print("temperature:");
  
    temp2=((temp1*5)/1023.0)*100;
  
    Serial.print(temp2);
    lcd.setCursor(0,0);
    lcd.print("temp:");
    lcd.print(temp2);
 
    Serial.print('\n');
    Serial.print('\r');
    delay(200);
  }
  
  if(Serial.available()>0)
  {
    temp=Serial.read();

    if(temp=='1')
    {
     
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      
    }
    
    
    if(temp=='2')
    {
      
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      
    }
    
    
    if(temp=='3')
    {
      

      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      
    }
    
    if(temp=='4')
    {
      

      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      
    }
    
    if(temp=='5')
    {
      

      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      
    }
    
   
    
    
    
  }
  
}
