#include "DHT.h"
#define DHTPIN 2  
#include<stdlib.h>
#define SSID "mriic_IOT"
#define PASS "mriic_iot"
#define IP "184.106.153.149" // thingspeak.com
String GET = "GET /update?key=QO3C8RHO1D743WBD&";
//8X7EJE0ZEOLMLVFZ
#define DHTTYPE DHT11
int delaycount=2000;
char str[100];
DHT dht(DHTPIN, DHTTYPE);
char str2[20];
// the setup routine runs once when you press reset:
void setup() {
   dht.begin();
  Serial.begin(9600);
    Serial.println("AT");
  delay(1000);
 // if(Serial.find("OK")){
    connectWiFi();
  }
  //}

void loop() {
   dtostrf(dht.readHumidity(), 2, 0, str2);
  strcpy(str,"field2=");
  strcat(str,str2);
  updateThings(str);
  delay(delaycount);
  dtostrf(dht.readTemperature(), 2, 0, str2);
  strcpy(str,"field1=");
  strcat(str,str2);
  updateThings(str);
  delay(delaycount);  
}

void updateThings(String tenmpF){

  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  Serial.println(cmd);
  delay(2000);
  if(Serial.find("Error")){
    return;
  }
  cmd = GET;
  cmd += tenmpF;
  cmd += "\r\n\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  if(Serial.find(">")){
    Serial.print(cmd);
  }
  else{
    Serial.println("AT+CIPCLOSE=4");
  }
  delay(700);
}

boolean connectWiFi(){
  Serial.println("AT+CWMODE=1");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  Serial.println(cmd);
  delay(2000);
  if(Serial.find("OK")){
    return true;
  }
  else{
    return false;
  }
}
