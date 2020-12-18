/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 This example code is in the public domain.
 */
 
 #include <SoftwareSerial.h>

SoftwareSerial mySerial(4, 5); // RX, TX

 int M11 = 6;
 int M12 = 7;
 int M21 = 10;
 int M22 = 11;
 char dev=0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  mySerial.begin(9600);
  pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if(mySerial.available()>0)
{
  dev = mySerial.read();
    delay(20);
  if(dev == '1')
  {
    digitalWrite(M11,HIGH);
    digitalWrite(M12,LOW);
    digitalWrite(M21,HIGH);
    digitalWrite(M22,LOW);
    
  }
  
  else if(dev == '2')
  {
    digitalWrite(M11,HIGH);
    digitalWrite(M12,LOW);
    digitalWrite(M21,LOW);
    digitalWrite(M22,LOW);
    
  }
  else if(dev == '3')
  {
    digitalWrite(M11,LOW);
    digitalWrite(M12,LOW);
    digitalWrite(M21,HIGH);
    digitalWrite(M22,LOW);
    
  }
  else if(dev == '4')
  {
    digitalWrite(M11,LOW);
    digitalWrite(M12,HIGH);
    digitalWrite(M21,LOW);
    digitalWrite(M22,HIGH);
    
  }
  else if(dev == '5')
  {
    digitalWrite(M11,LOW);
    digitalWrite(M12,LOW);
    digitalWrite(M21,LOW);
    digitalWrite(M22,LOW);
    
  }
  
}
  
  
}
