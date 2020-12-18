#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char temp;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Value:");
}

void loop()
{
  
  //while(!Serial.available());
  if(Serial.available()>0)
  {
    temp=Serial.read();
    lcd.print(temp);
    
    
    delay(1000);
    lcd.clear();
    while(!Serial.available());
    
  }
}
