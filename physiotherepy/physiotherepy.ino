/*
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
 
 
 
int sensor1Pin = A0;
int sensor2Pin = A1;
int sensor3Pin = A2;
int sensor4Pin = A3;
int sensor5Pin = A4;
int sensor6Pin = A5;
int sensorValue = 0;  // variable to store the value coming from the sensor

int caliberate=0;
 
 
 #include <LiquidCrystal.h>
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
 void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
  lcd.setCursor(0, 0);
  lcd.print("  MANAV RACHNA");
  lcd.setCursor(0,1);
  lcd.print(" INT.UNIVERSITY ");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("INJURY RECOVERY");
  lcd.setCursor(0,1);
  lcd.print("ANALYSIS SYSTEM");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("A:");
  lcd.setCursor(6,0);
  lcd.print("B:");
  
  lcd.setCursor(12,0);
  lcd.print("C:");
  lcd.setCursor(0, 1);
  lcd.print("D:");
  lcd.setCursor(6,1);
  lcd.print("E:");
  lcd.setCursor(12,1);
  lcd.print("F:");
  
  Serial.begin(9600); 
 }
 
 void loop()
 {
   
  sensorValue = analogRead(sensor1Pin); 
  caliberate = sensorValue;
  lcd.setCursor(3, 0);
  lcd.print(caliberate);
  
  Serial.print("S1:");
  
  //delay(1000);
  Serial.print(caliberate);
  //delay(1000);
  //Serial.print('\r');
  //Serial.print('\n');
  //delay(1000);
  sensorValue = analogRead(sensor2Pin); 
  caliberate = sensorValue;
  lcd.setCursor(9, 0);
  // print the number of seconds since reset:
  lcd.print(caliberate);
  
  //Serial.print("S2-");
  //Serial.print(':');
 // delay(1000);
  Serial.print(caliberate);
  //delay(1000);
 // Serial.print('\r');
  //Serial.print('\n');
  //delay(1000);
  
  
  
  sensorValue = analogRead(sensor3Pin); 
  caliberate = sensorValue;
  lcd.setCursor(14, 0);
  // print the number of seconds since reset:
  lcd.print(caliberate);
  
  
  //Serial.print("S3-");
  //Serial.print(':');
  //delay(1000);
  Serial.print(caliberate);
  //delay(1000);
 // Serial.print('\r');
  //erial.print('\n');
  //delay(1000);
  
  
  
  sensorValue = analogRead(sensor4Pin);
  
  caliberate = sensorValue;
  lcd.setCursor(3, 1);
  // print the number of seconds since reset:
  lcd.print(caliberate);
  
  
  
 // Serial.print("S4-");
  //Serial.print(':');
  //delay(1000);
  Serial.print(caliberate);
 // delay(1000);
 // Serial.print('\r');
  //Serial.print('\n');
  
  sensorValue = analogRead(sensor5Pin); 
  caliberate = sensorValue;
  lcd.setCursor(9, 1);
  // print the number of seconds since reset:
  lcd.print(caliberate);
  
  //Serial.print("S2-");
  //Serial.print(':');
 // delay(1000);
  Serial.print(caliberate);
  
   sensorValue = analogRead(sensor6Pin); 
  caliberate = sensorValue;
  lcd.setCursor(14, 1);
  // print the number of seconds since reset:
  lcd.print(caliberate);
  
  //Serial.print("S2-");
  //Serial.print(':');
 // delay(1000);
  Serial.print(caliberate);
  delay(2000);
  
  
 }
