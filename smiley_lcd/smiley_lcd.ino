#include <LiquidCrystal.h>
int m;
LiquidCrystal lcd(13,12,11,10,9,8);
byte smile[8] = 
              {
                0b00000,
                0b00000,
                0b01010,
                0b00000,
                0b10001,
                0b01110,
                0b00000,
                0b00000
              };

void setup()
{
  lcd.begin(16,2);
  lcd.createChar(1, smile);

}


void loop()
{
  lcd.setCursor(0,0);
  for(m=0;m<8;m++)
  {
    lcd.write(1);
    delay(1000);
  }
  lcd.clear();
 
}
