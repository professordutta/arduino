#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11); // Rx-10, Tx-11
char temp;
int REL1A = 22;
int REL2A = 23;
int REL3A = 24;
int REL4A = 25;
int REL5A = 26;
int REL6A = 27;
int REL7A = 28;
int REL8A = 29;


int REL1B = 30;
int REL2B = 31;
int REL3B = 32;
int REL4B = 33;
int REL5B = 34;
int REL6B = 35;
int REL7B = 36;
int REL8B = 37;

int REL1C = 38;
int REL2C = 39;
int REL3C = 40;
int REL4C = 41;
int REL5C = 42;
int REL6C = 43;




void setup()
{
  // configure software serial and hardware serial baud rate as 9600bps
  
  Serial.begin(9600);
  delay(100);
  mySerial.begin(9600);
  
  //configure relay pins as o/p pins
  
  pinMode(REL1A,OUTPUT);
  pinMode(REL2A,OUTPUT);
  pinMode(REL3A,OUTPUT);
  pinMode(REL4A,OUTPUT);
  pinMode(REL5A,OUTPUT);
  pinMode(REL6A,OUTPUT);
  pinMode(REL7A,OUTPUT);
  pinMode(REL8A,OUTPUT);
  
  pinMode(REL1B,OUTPUT);
  pinMode(REL2B,OUTPUT);
  pinMode(REL3B,OUTPUT);
  pinMode(REL4B,OUTPUT);
  pinMode(REL5B,OUTPUT);
  pinMode(REL6B,OUTPUT);
  pinMode(REL7B,OUTPUT);
  pinMode(REL8B,OUTPUT);
  
  pinMode(REL1C,OUTPUT);
  pinMode(REL2C,OUTPUT);
  pinMode(REL3C,OUTPUT);
  pinMode(REL4C,OUTPUT);
  pinMode(REL5C,OUTPUT);
  pinMode(REL6C,OUTPUT);
  
  
  //make all the relay pins low initially
  digitalWrite(REL1A,LOW);
  digitalWrite(REL2A,LOW);
  digitalWrite(REL3A,LOW);
  digitalWrite(REL4A,LOW);
  digitalWrite(REL5A,LOW);
  digitalWrite(REL6A,LOW);
  digitalWrite(REL7A,LOW);
  digitalWrite(REL8A,LOW);
  
  digitalWrite(REL1B,LOW);
  digitalWrite(REL2B,LOW);
  digitalWrite(REL3B,LOW);
  digitalWrite(REL4B,LOW);
  digitalWrite(REL5B,LOW);
  digitalWrite(REL6B,LOW);
  digitalWrite(REL7B,LOW);
  digitalWrite(REL8B,LOW);
  
  digitalWrite(REL1C,LOW);
  digitalWrite(REL2C,LOW);
  digitalWrite(REL3C,LOW);
  digitalWrite(REL4C,LOW);
  digitalWrite(REL5C,LOW);
  digitalWrite(REL6C,LOW);
  
  
}

void loop()
{
  do
  {
    while(!mySerial.available());
    temp = mySerial.read();
  }while('$' != temp);
  
  while(!mySerial.available());
  temp = mySerial.read();
  
  //relay 1
  if(temp == 'A')
  {
    digitalWrite(REL1A,HIGH);
  }
  
  if(temp == 'a')
  {
    digitalWrite(REL1A,LOW);
  }
  
  //relay 2
  if(temp == 'B')
  {
    digitalWrite(REL2A,HIGH);
  }
  
  if(temp == 'b')
  {
    digitalWrite(REL2A,LOW);
  }
  
  //relay 3 
  
  if(temp == 'C')
  {
    digitalWrite(REL3A,HIGH);
  }
  
  if(temp == 'c')
  {
    digitalWrite(REL3A,LOW);
  }
  
  //relay 4
  
  if(temp == 'D')
  {
    digitalWrite(REL4A,HIGH);
  }
  
  if(temp == 'd')
  {
    digitalWrite(REL4A,LOW);
  }
  
  //relay 5 
  
  if(temp == 'E')
  {
    digitalWrite(REL5A,HIGH);
  }
  
  if(temp == 'e')
  {
    digitalWrite(REL5A,LOW);
  }
  
  //relay 6
  
  if(temp == 'F')
  {
    digitalWrite(REL6A,HIGH);
  }
  
  if(temp == 'f')
  {
    digitalWrite(REL6A,LOW);
  }
  
  //relay 7
  
  if(temp == 'G')
  {
    digitalWrite(REL7A,HIGH);
  }
  
  if(temp == 'g')
  {
    digitalWrite(REL7A,LOW);
  }
  
  //relay 8
  
  if(temp == 'H')
  {
    digitalWrite(REL8A,HIGH);
  }
  
  if(temp == 'h')
  {
    digitalWrite(REL8A,LOW);
  }
  
 // codes for relay board second
 
  //relay 1
  if(temp == 'I')
  {
    digitalWrite(REL1B,HIGH);
  }
  
  if(temp == 'i')
  {
    digitalWrite(REL1B,LOW);
  }
  
  //relay 2
  if(temp == 'J')
  {
    digitalWrite(REL2B,HIGH);
  }
  
  if(temp == 'j')
  {
    digitalWrite(REL2B,LOW);
  }
  
  //relay 3 
  
  if(temp == 'K')
  {
    digitalWrite(REL3B,HIGH);
  }
  
  if(temp == 'k')
  {
    digitalWrite(REL3B,LOW);
  }
  
  //relay 4
  
  if(temp == 'L')
  {
    digitalWrite(REL4B,HIGH);
  }
  
  if(temp == 'l')
  {
    digitalWrite(REL4B,LOW);
  }
  
  //relay 5 
  
  if(temp == 'M')
  {
    digitalWrite(REL5B,HIGH);
  }
  
  if(temp == 'm')
  {
    digitalWrite(REL5B,LOW);
  }
  
  //relay 6
  
  if(temp == 'N')
  {
    digitalWrite(REL6B,HIGH);
  }
  
  if(temp == 'n')
  {
    digitalWrite(REL6B,LOW);
  }
  
  //relay 7
  
  if(temp == 'O')
  {
    digitalWrite(REL7B,HIGH);
  }
  
  if(temp == 'o')
  {
    digitalWrite(REL7B,LOW);
  }
  
  //relay 8
  
  if(temp == 'P')
  {
    digitalWrite(REL8B,HIGH);
  }
  
  if(temp == 'p')
  {
    digitalWrite(REL8B,LOW);
  }
  
  
  // codes for third relay board
  
  
  //relay 1
  if(temp == 'Q')
  {
    digitalWrite(REL1C,HIGH);
  }
  
  if(temp == 'q')
  {
    digitalWrite(REL1C,LOW);
  }
  
  //relay 2
  if(temp == 'R')
  {
    digitalWrite(REL2C,HIGH);
  }
  
  if(temp == 'r')
  {
    digitalWrite(REL2C,LOW);
  }
  
  //relay 3 
  
  if(temp == 'S')
  {
    digitalWrite(REL3C,HIGH);
  }
  
  if(temp == 's')
  {
    digitalWrite(REL3C,LOW);
  }
  
  //relay 4
  
  if(temp == 'T')
  {
    digitalWrite(REL4C,HIGH);
  }
  
  if(temp == 't')
  {
    digitalWrite(REL4C,LOW);
  }
  
  //relay 5 
  
  if(temp == 'U')
  {
    digitalWrite(REL5C,HIGH);
  }
  
  if(temp == 'u')
  {
    digitalWrite(REL5C,LOW);
  }
  
  //relay 6
  
  if(temp == 'V')
  {
    digitalWrite(REL6C,HIGH);
  }
  
  if(temp == 'v')
  {
    digitalWrite(REL6C,LOW);
  }
  
  
  if(temp == 'W')
  {
    
  digitalWrite(REL1A,HIGH);
  digitalWrite(REL2A,HIGH);
  digitalWrite(REL3A,HIGH);
  digitalWrite(REL4A,HIGH);
  digitalWrite(REL5A,HIGH);
  digitalWrite(REL6A,HIGH);
  digitalWrite(REL7A,HIGH);
  digitalWrite(REL8A,HIGH);
  
  digitalWrite(REL1B,HIGH);
  digitalWrite(REL2B,HIGH);
  digitalWrite(REL3B,HIGH);
  digitalWrite(REL4B,HIGH);
  digitalWrite(REL5B,HIGH);
  digitalWrite(REL6B,HIGH);
  digitalWrite(REL7B,HIGH);
  digitalWrite(REL8B,HIGH);
  
  digitalWrite(REL1C,HIGH);
  digitalWrite(REL2C,HIGH);
  digitalWrite(REL3C,HIGH);
  digitalWrite(REL4C,HIGH);
  digitalWrite(REL5C,HIGH);
  digitalWrite(REL6C,HIGH);
 
    
  }
  
  if(temp == 'w')
  {
  digitalWrite(REL1A,LOW);
  digitalWrite(REL2A,LOW);
  digitalWrite(REL3A,LOW);
  digitalWrite(REL4A,LOW);
  digitalWrite(REL5A,LOW);
  digitalWrite(REL6A,LOW);
  digitalWrite(REL7A,LOW);
  digitalWrite(REL8A,LOW);
  
  digitalWrite(REL1B,LOW);
  digitalWrite(REL2B,LOW);
  digitalWrite(REL3B,LOW);
  digitalWrite(REL4B,LOW);
  digitalWrite(REL5B,LOW);
  digitalWrite(REL6B,LOW);
  digitalWrite(REL7B,LOW);
  digitalWrite(REL8B,LOW);
  
  digitalWrite(REL1C,LOW);
  digitalWrite(REL2C,LOW);
  digitalWrite(REL3C,LOW);
  digitalWrite(REL4C,LOW);
  digitalWrite(REL5C,LOW);
  digitalWrite(REL6C,LOW);

    
  }
  
  
   
}

