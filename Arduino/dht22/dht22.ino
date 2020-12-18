
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#include "SoftwareSerial.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial mySerial(10,11);

int h,z;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("Data Logger");
  dht.begin();
}

void esp_init()
{
  mySerial.println("AT");  // send at command
  delay(2000);     // wait for the execution of command
  mySerial.println("AT+CIPMUX=1");  
  delay(2000);
  mySerial.println("AT+CWMODE=3");   // establising server
  delay(2000);
}


void loop() {
  // Wait a few seconds between measurements.
  esp_init();
  char connectionCommand[]="AT+CIPSTART=2,\"TCP\",\"api.thingspeak.com\",80";
  // command for connecting to thingspeak server
  char updateLink[] = "GET /update?api_key=CHPUI7JRJTF4MG8N&field1=";
  // link to be updated once the connection established

  char sensorString1[]="0000000000";   // temperature Sensor data in string format
  char sensorString2[]="0000000000";   // humidity Sensor data in string format

  delay(2000);
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  z = dht.readTemperature();

  
  itoa(h,sensorString2,10);
  delay(100);
  itoa(z,sensorString1,10);
  delay(100);

  Serial.println(sensorString2);
  delay(2000);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(z)) 
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Humidity:");
  Serial.println(h);
  Serial.print("Temperature:");
  Serial.println(z);
  
  
  
//convert sensor o/p from integer to string 
  mySerial.println(connectionCommand); // executing connection build command

  Serial.println(connectionCommand);
  delay(2000);  // waiting for the command to be executed
  strcpy(updateLink,"GET /update?api_key=CHPUI7JRJTF4MG8N&field1=");
  //update link
  delay(1000); 
  strcat(updateLink,sensorString1); // adding temperature sensor data to the link

  strcat(updateLink,"&field2="); // adding temperature sensor data to the link

  strcat(updateLink,sensorString2); // adding humidity sensor data to the link

  strcat(updateLink,"\r\n");
//adding carriage return and newline to the link
  mySerial.print( "AT+CIPSEND=2," ); // sending data command execution start
  mySerial.println(strlen(updateLink));  // calculating link length

  Serial.print( "AT+CIPSEND=2," ); // sending data command execution start
  Serial.println(strlen(updateLink));  // calculating link length
  delay(20);
  if(mySerial.find( ">" ) )   // waiting to enter into the send mode
  {
    mySerial.print(updateLink);  // sending data to thingspeak
    Serial.print(updateLink);
    delay(10000);  // wait before sending next data
  } 

}
