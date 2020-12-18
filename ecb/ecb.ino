#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

void setup()
{
  lcd.begin(16,2);
  
}

void loop()
{
  lcd.print("Manav Rachna");
  lcd.setCursor(0,1);
  lcd.print("Faridabad");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("9873804937");
  
  while(1);
  
  
}
