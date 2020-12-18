
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
const int LED = 13; // pin 13 referred by LED
const size_t MAX_CONTENT_SIZE = 512;       // max size of the HTTP response

SoftwareSerial mySerial(2,3);
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(115200);
  Serial.begin(115200); // initialize serial communication at 9600 bps baud rate
  pinMode(LED, OUTPUT); // configure pin 13 as output pin
  digitalWrite(LED, LOW); // make state of pin 13 LOW
}


void esp_initialize() // function routine for esp initialization
{
  Serial.print("AT\r\n"); // send at command
  delay(2000); // wait for the execution of command
  mySerial.println("AT Sent");
  Serial.print("AT+CIPMUX=1\r\n");
  delay(2000);
  mySerial.println("AT+CIPMUX=1 sent");
  Serial.print("AT+CWMODE=3\r\n");
  delay(2000);
  mySerial.println("AT+CWMODE=3 sent");
  Serial.print("AT+CIPSERVER=1,80\r\n"); // establising server
  delay(2000);
  mySerial.println("AT+CIPSERVER=1,80 sent");
  delay(2000);
}

void receive()
{
  char temp[300];
  char marker;
  int i=0;
  while(!Serial.available());
  if(Serial.available()>0)
  {
    Serial.find("+IPD");
    do
    {
      marker = Serial.read();
    }while(marker !=':'); 
      Serial.readBytesUntil('\0',temp,300);
     const size_t BUFFER_SIZE =
      JSON_OBJECT_SIZE(8)    // the root object has 8 elements
      + JSON_OBJECT_SIZE(5)  // the "address" object has 5 elements
      + JSON_OBJECT_SIZE(2)  // the "geo" object has 2 elements
      + JSON_OBJECT_SIZE(3)  // the "company" object has 3 elements
      + MAX_CONTENT_SIZE;    // additional space for strings

  // Allocate a temporary memory pool
  DynamicJsonBuffer jsonBuffer(BUFFER_SIZE);

  JsonObject& root = jsonBuffer.parseObject(temp);

String field=root["feeds"][0]["field1"];

  mySerial.println(field);

    
  }

//while(!mySerial.available())
//{
//if(mySerial.available()>0)
//{
//Serial.println(mySerial.readStringUntil('CLOSED'));
//delay(2000);
//}
//}
}

void rec_data()
{
  esp_initialize(); // initialize ESP8266 module
  char updateLink[] ="GET /channels/227622/fields/1.json?results=1";
  //declare connection command and update link
  char connectionCommand[] = "AT+CIPSTART=0,\"TCP\",\"184.106.153.149\",80";
  Serial.println(connectionCommand); // executing connection build command
  mySerial.println("Connection command executed");
  delay(2000); // waiting for the command to be executed
  strcpy(updateLink, "GET /channels/227622/fields/1.json?results=1");
  //update link
  strcat(updateLink, "\r\n");
  //adding carriage return and newline to the link
  Serial.print("AT+CIPSEND=0,"); // sending data command execution start
  Serial.println(strlen(updateLink)); // calculating link length
  delay(1000);
  mySerial.println("AT+CIPSEND executed successfully");
  Serial.print(updateLink); // sending data to thingspeak
  mySerial.println("Send GET command to read last data byte");
  
  receive();
  
  mySerial.println();
  delay(7000);
  Serial.print("AT+CIPCLOSE=0\r\n"); // close the connection
  delay(2000); // wait for 16 sec
}
void data_frame()
{
  int i = 0;
}
void loop() {
  // put your main code here, to run repeatedly:
  rec_data();
  delay(2000);
}

