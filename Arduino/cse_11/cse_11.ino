char temp; // global variable 
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600); // serial communication at 9600bps baud rate
pinMode(13,OUTPUT);// configure 13th pin as output pin
}

void loop() {
  // put your main code here, to run repeatedly:

  while(!Serial.available()); // stay here if there is no serial data

  if(Serial.available()>0)
  {
    temp = Serial.read(); // buffer the received data in temp

    if(temp=='A')
    {
      digitalWrite(13,HIGH);
    }

    if(temp=='B')
    {
      digitalWrite(13,LOW);
    }

  }

  
  

}
