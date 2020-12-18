#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);

void setup()
{
  pinMode(13,INPUT);
  digitalWrite(13,HIGH);
  lcd.begin(16,2);
  lcd.print("Manav Rachna");
  lcd.setCursor(3,1);
  lcd.print("Faridabad");
}

void loop()
{
  if(digitalRead(13)==LOW)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Umesh Dutta");
    while(digitalRead(13)==LOW);
    
  }
  
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Welcome");
    while(digitalRead(13)==HIGH);
  }
  
}
