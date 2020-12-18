#include <ESP8266HTTPClient.h>
// to make easy HTTP GET, POST and PUT request to web server
#include<ESP8266WiFi.h>
//used for connection between NodeMcu and your wifi
const char* ssid = "abcd"; //Enter Your Wifi Name
const char* password = "gaurigauri";
//Enter Your Wifi Password
WiFiServer server(80);  // open port 80 for server connection

String readData; // Variable to read data
String phpInput()
{
  WiFiClient client;
  client = server.available();
  HTTPClient http;
  //object of HTTPClient class for HTTP request
  String url = "http://nilanshkk.000webhostapp.com/receiveCurr.php";
  http.begin(url); //specify request address
  int httpCode = http.GET(); //Send GET Request
  String data1 = http.getString();
  //Get the request response payload
  Serial.println(data1);//Print the response payload
  http.end();//close the connection
  return data1;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial Communication is initialized at 9600 bps baud rate
  // Defining Pins
  pinMode(D0, OUTPUT);
  digitalWrite(D0, LOW);
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

void loop() {
  //   put your main code here, to run repeatedly:
  readData = phpInput();
  if (readData == "A")
  {
    // switch On fountain
    Serial.println("Fountain is switched ON");
    digitalWrite(D0, HIGH);
  }
  else if (readData == "B")
  {
    // switch OFF fountain
    Serial.println("Fountain is switched OFF");
    digitalWrite(D0, LOW);
  }
}


