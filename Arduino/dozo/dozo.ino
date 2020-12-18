#include <string.h>    // Library to use string functions
int LED = 13;  // On Board Green LED on pin 14
char updateLink[] = "GET /nilansh/pot.php?a=25 HTTP/1.1\r\nHost: dozo.co.in\r\n\r\n";
char connectionCommand[] = "AT+CIPSTART=2,\"TCP\",\"dozo.co.in\",80";
char sensorString[] = "0000000000"; // Sensor data in string format

void setup()
{
  pinMode(LED, OUTPUT);   // Initialize LED as an OUTPUT
  digitalWrite(LED, LOW); // Initially LED OFF
  Serial.begin(9600);   // start serial with 9600 baud rate
}
// the loop routine runs over and over again forever:

void loop()
{
  esp_initialize();  //  Call esp initialize function
  int sensorData = analogRead(A0); //storing sensor data in intiger format
  itoa(sensorData, sensorString, 10);
  //convert sensor o/p from intiger to string
  Serial.println(connectionCommand); // executing connection build command
  delay(2000);  // waiting for the command to be executed
  strcpy(updateLink, "GET /nilansh/pot.php?a=");
  //update link
  strcat(updateLink, sensorString); // adding sensor data to the link
  strcat(updateLink, " HTTP/1.1\r\nHost: dozo.co.in\r\n\r\n");
  //adding carriage return and newline to the link
  Serial.print( "AT+CIPSEND=2," ); // sending data command execution start
  Serial.println(strlen(updateLink));  // calculating link length
  delay(2000);
  Serial.print(updateLink);  // sending data to thingspeak
  for (int i = 0; i < 5; i++) // blinking led when data has been updated
  {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
  Serial.print("AT+CIPCLOSE=2\r\n");
  delay(10000);  // wait before sending next data
  Serial.flush();
  delay(100);
}

void esp_initialize()   // function routine for esp initialization
{
  Serial.println("AT");
  delay(2000);
  Serial.println("AT+CIPMUX=1");
  delay(2000);
  Serial.println("AT+CWMODE=3");
  delay(2000);
}
