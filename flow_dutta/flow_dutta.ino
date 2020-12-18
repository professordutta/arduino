#include <ESP8266HTTPClient.h>
// to make easy HTTP GET, POST and PUT request to web server
#include<ESP8266WiFi.h>
//used for connection between NodeMcu and your wifi
volatile int flow_frequency; // Measures flow sensor pulses
unsigned int l_hour; // Calculated litres/hour
uint8_t flowsensor = D2; // Sensor Input
unsigned long currentTime;
unsigned long cloopTime;
const char* ssid = "UD"; //Enter Your Wifi Name
const char* password = "anitadutta";
//Enter Your Wifi Password
WiFiServer server(80);  // open port 80 for server connection
const char* conn = "api.thingspeak.com"; 
//thingspeak connection address

void flow () // Interrupt function
{
  flow_frequency++;
}
void setup()
{
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup Interrupt
  sei(); // Enable interrupts
  currentTime = millis();
  cloopTime = currentTime;
  WiFi.begin(ssid, password); //try to connect with your wifi
  while (WiFi.status() != WL_CONNECTED)
    //wait here till NodeMcu is connected with Wifi
  {
    delay(100); //wait for 100 milli seconds
    Serial.println("Connecting");
    //print "Connecting" on Serial Monitor
  }

  Serial.println("WiFi connection Successful");
  //will print "Wifi connection Successful" on Serial Monitor
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address

}

void thingspeak(char b)
{
  WiFiClient client;
  client.connect(conn, 80);
  //connect with Thingspeak at port 80
  client = server.available();
  // wait for a client (web browser) to connect
  String data = String(b); //convert char to String
  HTTPClient http;
  //object of HTTPClient class for HTTP request
  String url = "https://api.thingspeak.com/update?api_key=C29Z8ACYUOIECEX4&field1=" + data;
  //add your write channel API (GET request)

  Serial.println("I am hereeee.....");

  //enter your server web address or IP address
  http.begin(url); //specify request address

  int httpCode = http.GET(); //Send GET Request
  String data1 = http.getString();
  //Get the request response payload
  Serial.println(data1);//Print the response payload
  http.end();//close the connection
}

void loop ()
{
  currentTime = millis();
  // Every second, calculate and print litres/hour
  if (currentTime >= (cloopTime + 1000))
  {
    cloopTime = currentTime; // Updates cloopTime
    // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
    l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
    flow_frequency = 0; // Reset Counter
    Serial.print(l_hour, DEC); // Print litres/hour
    Serial.println(" L/hour");
    thingspeak(20);
    delay(1000);
  }
}
