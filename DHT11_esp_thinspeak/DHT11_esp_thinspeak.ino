#include<SoftwareSerial.h>
#include "DHT.h"
SoftwareSerial esp(2,3);

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  esp.begin(115200);
  Serial.begin(9600);
  //DHT11.attach(8);
  dht.begin();
  
  Serial.println("setup");
  
//  int chk = DHT11.read();
//  
//  Serial.print("Read sensor: ");
//  switch (chk)
//  {
//    case 0: Serial.println("OK"); break;
//    case -1: Serial.println("Checksum error"); break;
//    case -2: Serial.println("Time out error"); break;
//    default: Serial.println("Unknown error"); break;
//  }

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
//  Serial.print("Humidity (%): ");
//  Serial.println((float)DHT11.humidity, DEC);
//
//  Serial.print("Temperature (°C): ");
//  Serial.println((float)DHT11.temperature, DEC);
  
  delay(1000);
  
  esp.println("AT+RST\r\n");
  delay(5000);

  esp.println("AT+CWMODE=3\r\n");
  delay(1000);

  esp.println("AT+CWJAP=\"mriic_IOT\",\"mriic_iot\"\r\n");
  delay(2000);

  esp.println("AT+CIPMUX=0\r\n");
  delay(1000);
}

void loop() {
  
  Serial.println("loop");
  
//  int chk = DHT11.read();
//
//  Serial.print("Read sensor: ");
//  switch (chk)
//  {
//    case 0: Serial.println("OK"); break;
//    case -1: Serial.println("Checksum error"); break;
//    case -2: Serial.println("Time out error"); break;
//    default: Serial.println("Unknown error"); break;
//  }

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  Serial.println(t);
  Serial.println(h);
  
//  Serial.print("Humidity (%): ");
//  Serial.println((float)DHT11.humidity, DEC);
//
//  Serial.print("Temperature (°C): ");
//  Serial.println((float)DHT11.temperature, DEC);
  
  Start:
  esp.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n");
  //delay(1000);
  if(esp.find("OK")){
    Serial.print("TCP CONNECT"); 
  }
  //else{
  //  goto Start;
  //}
  
//  int temp = (int)DHT11.temperature;
//  int hum = (int)DHT11.humidity;
  
  String sendStr = "GET /update?key=FL7JNN7R6V1X9KX6&field1=";
  sendStr += t;
  sendStr += "&field2=";
  sendStr += h;
  sendStr += "\r\n\r\n";
  
  String ATcmd = "AT+CIPSEND=";
  ATcmd += sendStr.length();
  ATcmd += "\r\n";
  
  delay(1000);
  
  esp.println(ATcmd);
  delay(100);
  if (esp.find(">")) {
    esp.println(sendStr);
    Serial.println("DATA SENT");
  }
  //else {
  // goto Start; 
  //}
  
  //esp.println("AT+CIPCLOSE");
  
  delay(16*1000);
}
