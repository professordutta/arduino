#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);
char temp;
int i;

void setup()
{
  pinMode(13,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void blink()
{
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}

void serialEvent()
{
  if(Serial.available())
  {
    i=i+1;
    if(i==17)
    {
      lcd.setCursor(0,1);
    }
    
    if(i==32)
    {
      lcd.clear();
      lcd.setCursor(0,0);
    }
    
    temp=Serial.read();
    lcd.print(temp);
   
  }
  
}


void loop()
{
  blink();
}

