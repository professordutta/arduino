#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);


int temp;
void setup()
{
 lcd.begin(16,2);
 pinMode(6,INPUT);
 digitalWrite(6,HIGH);
 
}

void loop()
{
  temp=digitalRead(6);
  
  if(temp==HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PAKISTAN");
    while(digitalRead(6)==HIGH);
    
  }
  else
  {
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("INDIA");
    while(digitalRead(6)==LOW);
    
  }
}
