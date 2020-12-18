#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("UMESH DUTTA ECE");
}

void loop() 
{
  lcd.setCursor(4,1);
  lcd.print("Manal    Deep");
  lcd.setCursor(0,2);
  lcd.print("Rohit    Shrey");
  lcd.setCursor(0,3);
  lcd.print("Karan  Deewakar");
  
  while(1);
  
}

