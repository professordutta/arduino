int temp; // variable to hold the analog voltage equiavlent value
int temp1; // variable to store temperature in degree celcius
const int LED = 13; // pin 13 referred by LED
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // initialize serial communication at 9600 bps baud rate
  pinMode(LED, OUTPUT); // configure pin 13 as output pin
  digitalWrite(LED, LOW); // make state of pin 13 LOW
}


void esp_initialize() // function routine for esp initialization
{
  Serial.print("AT\r\n"); // send at command
  delay(2000); // wait for the execution of command
  Serial.print("AT+CIPMUX=1\r\n");
  delay(2000);
  Serial.print("AT+CWMODE=3\r\n");
  delay(2000);
  Serial.print("AT+CIPSERVER=1,80\r\n"); // establising server
  delay(2000);
  delay(2000);
}

void send_data(int m)
{
  int sensorData;  
  sensorData = m; // store temperature data
  esp_initialize(); // initialize ESP8266 module
  char sensorString[] = "0000000000"; // Sensor data in string format
  //declare connection command and update link
  char connectionCommand[] = "AT+CIPSTART=0,\"TCP\",\"184.106.153.149\",80";
  char updateLink[] = "GET /update?key=C29Z8ACYUOIECEX4&field1=";
  itoa(sensorData, sensorString, 10); // convert integer to string
  //convert sensor o/p from intiger to string
  Serial.println(connectionCommand); // executing connection build command
  delay(2000); // waiting for the command to be executed
  strcpy(updateLink, "GET /update?key=C29Z8ACYUOIECEX4&field1=");
  //update link
  strcat(updateLink, sensorString); // adding sensor data to the link
  strcat(updateLink, "\r\n");
  //adding carriage return and newline to the link
  Serial.print("AT+CIPSEND=0,"); // sending data command execution start
  Serial.println(strlen(updateLink)); // calculating link length
  delay(1000);
  Serial.print(updateLink); // sending data to thingspeak
  for (int i = 0; i < 5; i++) // blinking led when data has been updated
  {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
  Serial.print("AT+CIPCLOSE=0\r\n"); // close the connection
  delay(16000); // wait for 16 sec
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(A0); 
  /* convert analog voltage on channel A0 to its equivalent decimal value
     and store in temp */
  // convert temp value on degree celcius scale
  temp1 = (temp * 500) / 1023;
  send_data(temp1); // call send_data function to push temperature data on cloud
}
