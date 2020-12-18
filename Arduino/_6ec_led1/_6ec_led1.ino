#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);
//12 rs 11 en 10 to 7 D4 to D7

void setup()
{
  lcd.begin(16,2);
  lcd.print("Ayush");
  lcd.setCursor(0,1);
  lcd.print("ECE FET MRIIRS");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gaurav");
  
}
void loop()
{
  
}

