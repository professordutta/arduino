#include<SoftwareSerial.h>
#include<dht11.h>
SoftwareSerial mySerial(2,3);

dht11 DHT11;

void setup() {
  
  mySerial.begin(9600);
  Serial.begin(9600);
  DHT11.attach(8);
  
  Serial.println("setup");
  
    int chk = DHT11.read();

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case 0: Serial.println("OK"); break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, DEC);

  Serial.print("Temperature (°C): ");
  Serial.println((float)DHT11.temperature, DEC);
  
  delay(2000);
  
  AT:
  mySerial.print("AT\r\n");
  delay(100);
  if(mySerial.find("OK")) {
    Serial.println("1  AT OK");
  }
  else{
  goto AT;
  }
  
  mySerial.print("AT+CPIN?\r\n");
  delay(100);
  if(mySerial.find("+CPIN: READY")) {
    Serial.println("2  SIM UNLOCKED");
  }
  else{
  goto AT;
  }
  
  mySerial.print("AT+CREG?\r\n");
  delay(100);
  if(mySerial.find("+CREG: 0,1")) {
    Serial.println("3  SIM REGISTERED");
  }
  else{
  goto AT;
  }
  
  mySerial.print("AT+CGATT?\r\n");
  delay(100);
  if(mySerial.find("+CGATT: 1")) {
    Serial.println("4  GPRS ATTACHED");
  }
  else{
  goto AT;
  }
  
  mySerial.print("AT+CIPSHUT\r\n");
  delay(100);
  if(mySerial.find("SHUT OK")) {
    Serial.println("5  CIP SHUT");
  }
  else{
  goto AT;
  }
  
  mySerial.print("AT+CIPSTATUS\r\n");
  delay(100);
  if(mySerial.find("STATE: IP INITIAL")) {
    Serial.println("6  IP INITIALIZED");
  }
  else{
  goto AT;
  }
  
  mySerial.print("AT+CIPMUX=0\r\n");
  delay(100);
  if(mySerial.find("OK")) {
    Serial.println("7  SINGLE CONNECTION");
  }
  else{
  goto AT;
  }
  
  mySerial.print("AT+CSTT=\"airtelgprs.com\",\"\",\"\"\r\n");
  delay(100);
  if(mySerial.find("OK")) {
    Serial.println("8  APN");
  }
  else{
  goto AT;
  }
  
  CIICR:
  mySerial.print("AT+CIICR\r\n");
  delay(3000);
  if(mySerial.find("OK")) {
    Serial.println("9  WIRELESS CONN.");
  }
  else{
    goto CIICR; 
  }
  
  //AT+CIFSR
  mySerial.print("AT+CIFSR\r\n");
  delay(100);
  
  Serial.println("!!!!!!!!!!!!!9!!!!!!!!!!!!!!");
  
}

void loop() {
  
  Serial.println("loop");
  
      int chk = DHT11.read();

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case 0: Serial.println("OK"); break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, DEC);

  Serial.print("Temperature (°C): ");
  Serial.println((float)DHT11.temperature, DEC);
  
  Start:
  mySerial.print("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n");
  delay(2000);
  if(mySerial.find("CONNECT OK")){
    Serial.print("TCP CONNECT"); 
  }
  else{
    goto Start;
  }
  
  
  mySerial.print("AT+CIPSEND\r\n");
  //delay(1000);
  if(mySerial.find(">")){
    Serial.println("!! DATA SENT !!");
    String cmd = "GET https://api.thingspeak.com/update?key=FL7JNN7R6V1X9KX6&field1=";
    cmd += DHT11.temperature;
    cmd += "&field2=";
    cmd += DHT11.humidity;
    cmd += "\r\n\r\n\x1A";
    mySerial.print(cmd);
  }
  if(mySerial.find("ERROR")){
    Serial.println("!! error !!");
    goto Start;
  }  
  
  
  delay(16*1000);
}
