#include <LiquidCrystal.h>
int m;
LiquidCrystal lcd(13,12,11,10,9,8);

char temp[12] = {'U', 'M', 'E', 'S', 'H', ' ', 'D', 'U', 'T', 'T', 'A'};
void setup()
{
  lcd.begin(16,2);

}


void loop()
{
  lcd.setCursor(11,0);
  lcd.autoscroll();
  for(m=0;m<11;m++)
  {
    lcd.print(temp[m]);
    delay(300);
  }
  lcd.noAutoscroll();
  lcd.clear();
  delay(300);
  
 
}
