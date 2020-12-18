#include<avr/io.h>
#include <string.h>
#include <util/delay.h>
#include <SoftwareSerial.h>
#define USART_BAUDRATE 9600
int n;

char str[48] = "GET /GraphTest/plotgraph.php?temp=8";      
char temp1[5] = "\r\n\r\n";
        
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

char received_byte;

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


void receiver()
{   
  do
  {
  while(!(UCSR0A & (1<<RXC0)));
  // grab the byte from the serial port
  received_byte = UDR0;
  }while(received_byte!='!');
  
  while(!(UCSR0A & (1<<RXC0)));
  // grab the byte from the serial port
  received_byte = UDR0;
}



void esp()
{
   trans_str("AT+CIPSTART=\"TCP\",\"192.168.7.101\",80");
  _delay_ms(1000);
  String cmd;

  cmd=str;

  n= cmd.length();

  String x;
   char at_cmd[] = "AT+CIPSEND=39\r\n";
   trans_str(at_cmd);

   x=String(n);
   //Serial.print(x);
   //trans('\r');
   //trans('\n');

   trans_str(str);
  
   _delay_ms(1000);
  
   
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
  strcat(str,temp1);
 esp();
}


