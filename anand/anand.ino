
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int temp;

int value;
void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  
  Serial.begin(9600);
  lcd.begin(20,4);
  
}

void loop()
{
  
  value=analogRead(A0);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moisture:");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
  lcd.print(value);
  delay(300);
  
  
  if(value>900)
  {
    lcd.setCursor(0,1);
    lcd.print("LOW Moisture");
    Serial.println("Water Required in the fields");
    delay(300);
  }
  
  //while(!Serial.available());
  if(Serial.available()>0)
  {
    temp=Serial.read();
    
    if(temp=='1')
    {
     
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      
    }
    
    
    if(temp=='2')
    {
      
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      
    }
    
    
    if(temp=='3')
    {
      

      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      
    }
    
    if(temp=='4')
    {
      

      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      
    }
    
    if(temp=='5')
    {
      

      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      
    }
    
   if(temp=='6')
    {
      

      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      
      
    }
    
    
    if(temp=='7')
    {
      

      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      
      
    }
    
    
    
    
  }
  
}
