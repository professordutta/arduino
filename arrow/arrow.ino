#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte aa[8] =
            {
              0b00100,
              0b00100,
              0b01010,
              0b10101,
              0b00100,
              0b00100,
              0b00100,
              0b00100,
              
            };


void setup()
{
  lcd.createChar(5,aa);
  lcd.begin(16,2);
 
  lcd.print("UMESH");
   lcd.setCursor(0,1);
  
  lcd.write(5);
  delay(300);
}
void loop()
{
  
}

