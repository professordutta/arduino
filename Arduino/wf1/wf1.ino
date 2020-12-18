
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#include <LiquidCrystal.h>
#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12,11,10,9,8,7);

int h,z,temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
}



void loop() {
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  z = dht.readTemperature();

  // read the MQ2 sensor

  temp = analogRead(A0);

 // Serial.print("*");
  Serial.print(z);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.print(temp);
  delay(1000);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(z)) 
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(z);
  lcd.print (" MQ:");
  lcd.print(temp);

  if(temp>320)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" High CO conc.");
  }
}
