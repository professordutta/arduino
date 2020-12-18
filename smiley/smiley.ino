#include <LiquidCrystal.h>
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
//----------------- store the custom characters in arrays ---------------------//
byte heart[8] = 
              {
                0b00000,
                0b01010,
                0b11111,
                0b10101,
                0b10001,
                0b10001,
                0b01010,
                0b00100
              };
 
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
 
//----------------- store the custom characters in arrays ---------------------//
 
// give the LED pin a name:
int led = 6;
 
void setup()
{
  //---- create custom characters ----//
  lcd.createChar(1, heart);
  lcd.createChar(2, smile);
  //---- create custom characters ----//
  
  // initialize the led pin as an output.
  pinMode(led, OUTPUT);
  
  // set up the lcd's number of columns and rows: 
  lcd.begin(16, 2);
  
  lcd.print("MRIU");
  lcd.setCursor(0, 1);
  lcd.write(1);lcd.write(2);lcd.write(1);lcd.write(2);
  lcd.write(1);lcd.write(2);lcd.write(1);lcd.write(2);
  lcd.write(1);lcd.write(2);lcd.write(1);lcd.write(2);
  lcd.write(1);lcd.write(2);lcd.write(1);lcd.write(2);
}
 
void loop()
{
  //---- blink LED -----//
  digitalWrite(led, HIGH);       
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
   //---- blink LED -----//
}
 
