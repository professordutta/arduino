#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <String.h>
int i,len; 
char temp[50];
const char *ssid = "MyESP8266AP";
const char *password = "1234";
 
WiFiServer server(80);
 
 
void setup() {
 
  Serial.begin(115200);
  
  pinMode(D0,OUTPUT);
  
  digitalWrite(D0,HIGH);

  //WiFi.mode(WIFI_AP);
  //WiFi.begin(ssid, password);
  WiFi.softAP(ssid, password);
 
  Serial.println();
  Serial.print("Server IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.print("Server MAC address: ");
  Serial.println(WiFi.softAPmacAddress());
 
  //server.on("/", handleRoot);
  server.begin();
 
  Serial.println("Server listening");
}
 
void loop() {
 
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  len=req.length();
  req.toCharArray(temp, 50);
  for (i = 0; i <(len-1); i++)
    {
        if (temp[i] == '$')
        {
            digitalWrite(D0,LOW);
        }

        if (temp[i] == '#')
        {
            digitalWrite(D0,HIGH);
        }
    }
   
  client.flush();
 
}
