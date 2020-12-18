#include<avr/io.h>
#include <string.h>
#include <util/delay.h>
#include <SoftwareSerial.h>

#define USART_BAUDRATE 9600

float temp;


String GET = "GET /GraphTest/plotgraph.php?";

char str2[20];

char str[100];      

char temp1[5] = "\r\n\r\n";
        
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

char received_byte;

int m;

void trans(char data) {
  while(! (UCSR0A & (1 << UDRE0)));
  UDR0 = data;
}

void trans_str(char* str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    trans(str[i]);
  }
  trans('\r');
  trans('\n');
}

void trans_str1(char* str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    trans(str[i]);
  }
}


void receiver()
{ 
  char u[8];  
  do
  {
  while(!(UCSR0A & (1<<RXC0)));
  // grab the byte from the serial port
  received_byte = UDR0;
  }while(received_byte!='!');

  digitalWrite(13,HIGH);
  while(1);

  while(!(UCSR0A & (1<<RXC0)));
  // grab the byte from the serial port
  received_byte = UDR0;
  
  if(received_byte=='Y')
  {
    digitalWrite(13,HIGH);
    while(1);
    delay(10000);
    digitalWrite(13,LOW);
    
  }
  
}



void update_mydata(String var)
{
  String cmd;
  trans_str("AT+CIPSTART=\"TCP\",\"192.168.7.101\",80");
  _delay_ms(1000);
   cmd = GET;
   cmd+=var;
   cmd+="\r\n\r\n";
   trans_str1("AT+CIPSEND=");


   Serial.println(cmd.length());
  
   Serial.print(cmd);
   
   receiver();
   
  
}

void setup()
{
 pinMode(13,OUTPUT);
 digitalWrite(13,LOW); 
 UCSR0B |= (1<<RXEN0)  | (1<<TXEN0);
 UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01);
 UBRR0H  = (BAUD_PRESCALE >> 8);
 UBRR0L  = BAUD_PRESCALE;
 
}


void loop()
{
  temp=analogRead(A0);

  temp = (temp*5.0)/(1023.0);

  temp = temp*10;

  dtostrf(temp, 2, 0, str2);

  strcpy(str,"temp=");

  strcat(str,str2);

  update_mydata(str);

  delay(2000);

  

 

        
}


