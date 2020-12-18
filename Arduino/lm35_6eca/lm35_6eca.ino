#include <LiquidCrystal.h>
LiquidCrystal  lcd(12, 11, 10, 9, 8, 7);
// rs - 12, en-11, 10 to 7 D4 to D7

int temp; // for storing the integer eq. value of analog voltage

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); // we are using 16x2 lcd
  Serial.begin(9600);
  // intialize serial communication at 9600bps baud rate
  lcd.print("Temp:");
}

void loop() {
  // put your main code here, to run repeatedly:

  temp = analogRead(A0);
  // convert analog voltage into digital and store integer value in temp

  Serial.println(temp); // print temp on serial port
  lcd.setCursor(6,0);
  lcd.print(temp/2);
  delay(50);
  



}
