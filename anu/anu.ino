
 #include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(10, 11, 6, 7, 8, 9);
int temp;
void setup()
{
   pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  
  lcd.begin(20,4);
  Serial.begin(9600);
}

void loop()
{
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp=Serial.read();
    
    if(temp=='1')
    {
      lcd.setCursor(0,0);
      lcd.print("device 1 on");
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      
    }
    
    
    if(temp=='2')
    {
      lcd.setCursor(0,0);
      lcd.print("device 2 on");
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      
    }
    
    
    if(temp=='3')
    {
      lcd.setCursor(0,0);
      lcd.print("device 3 on");

      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      
    }
    
    if(temp=='4')
    {
      lcd.setCursor(0,0);
      lcd.print("device 4 on");

      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      
    }
    
    if(temp=='5')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("All on");

      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      
    }
    
    if(temp=='6')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("All off");

      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      
    }
    
    
    
  }
  
}
