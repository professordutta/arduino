int temp, temp1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


void esp_initialize()
{
  Serial.print("AT\r\n");
  delay(2000);
  Serial.print("AT+CIPMUX=1\r\n");
  delay(2000);
  Serial.print("AT+CWMODE=3\r\n");
  delay(2000);
  Serial.print("AT+CIPSERVER=1,80\r\n");
  delay(2000);
}
void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(A0);
  temp1 = (temp * 500) / 1023;
  Serial.println(temp1);
  esp_initialize();

  /*
    Define the array to send the data via GET request
    Define the array for starting TCP connection
  */
  char connection_string[] = "";
  char data_string[] = "";
  delay(1000);
}
