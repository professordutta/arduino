#include<avr/io.h>
#include <string.h>
#include <util/delay.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#define USART_BAUDRATE 9600
int k;
int socket1=3;
int socket2=4;
int socket3=5;
int socket4=6;

char resp1[4]="YA1";
char resp2[4]="YA2";

char resp3[4]="YB1";
char resp4[4]="YB2";

char resp5[4]="YC1";
char resp6[4]="YC2";

char resp7[4]="YD1";
char resp8[4]="YD2";

char resp9[4]="YX1";

char resp10[4]="NNN";

int n;

char str[48] = "GET /karan/validation.php?rfid=";      
char temp1[5] = "\r\n\r\n";
char resp[4]; // reading the response from the webserver
        
LiquidCrystal lcd(12,11,10,9,8,7);
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)
char received_byte;
SoftwareSerial mySerial(2,3);
int m;
char temp[13];

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
  
  for(n=0;n<3;n++)
  {
  while(!(UCSR0A & (1<<RXC0)));
  // grab the byte from the serial port
  received_byte = UDR0;
  resp[n]=UDR0;
  }
  resp[3]='\0'; // null character
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print(resp);
}

void port1_on()
{
  digitalWrite(socket1,HIGH);
}

void port1_off()
{
  digitalWrite(socket1,LOW);
}


void port2_on()
{
  digitalWrite(socket2,HIGH);
}

void port2_off()
{
  digitalWrite(socket2,LOW);
}

void port3_on()
{
  digitalWrite(socket3,HIGH);
}

void port3_off()
{
  digitalWrite(socket3,LOW);
}

void port4_on()
{
  digitalWrite(socket4,HIGH);
}

void port4_off()
{
  digitalWrite(socket4,LOW);
}

void port_no()
{
  
}

void unregistered()
{
  
}


void action()
{
  if (strcmp(resp,resp1)==0)
  {
    port1_on();
  }
  if (strcmp(resp,resp2)==0)
  {
    port1_off();
  }
  if (strcmp(resp,resp3)==0)
  {
    port2_on();
  }
  if (strcmp(resp,resp4)==0)
  {
    port2_off();
  }
  
  if (strcmp(resp,resp5)==0)
  {
    port3_on();
  }
  if (strcmp(resp,resp6)==0)
  {
    port3_off();
  }
  
  if (strcmp(resp,resp7)==0)
  {
    port4_on();
  }
  if (strcmp(resp,resp8)==0)
  {
    port4_off();
  }
  
  if (strcmp(resp,resp9)==0)
  {
    port_no();
  }
  if (strcmp(resp,resp10)==0)
  {
    unregistered();
  }
  
  
}

void esp()
{
   trans_str("AT+CIPSTART=\"TCP\",\"192.168.7.106\",80");
  _delay_ms(1000);
   char at_cmd[] = "AT+CIPSEND=47\r\n";
   trans_str(at_cmd);
   _delay_ms(1000);
   trans_str(str);
   
}

void setup()
{
  lcd.begin(16,2);
  lcd.print("Welcome User");
 pinMode(13,OUTPUT);
 digitalWrite(13,LOW); 
 
 pinMode(socket1,OUTPUT);
 pinMode(socket2,OUTPUT);
 pinMode(socket3,OUTPUT);
 pinMode(socket4,OUTPUT);
 
 digitalWrite(socket1,LOW);
 digitalWrite(socket2,LOW);
 digitalWrite(socket3,LOW);
 digitalWrite(socket4,LOW);
 
 
 mySerial.begin(9600);
 UCSR0B |= (1<<RXEN0)  | (1<<TXEN0);
 UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01);
 UBRR0H  = (BAUD_PRESCALE >> 8);
 UBRR0L  = BAUD_PRESCALE;
 
}




void loop()
{
   for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  temp[m]=mySerial.read();
  }
  lcd.setCursor(0,1);
  lcd.print("ID:");
  
  for(m=0;m<12;m++)
  {
    lcd.print(temp[m]);
    
  }
  temp[12] = '\0';
  strcat(str,temp);
  strcat(str,temp1);
  delay(1000);
  esp();
  receiver();
  action();
  delay(1000);
 
}


