#include "avr/io.h"
#include "avr/interrupt.h"

//#define USART_BAUDRATE 9600
//#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
char temp='0';

ISR(USART_RXC)
{
  digitalWrite(13,HIGH);
   char ReceivedByte;
   ReceivedByte = UDR0; // Fetch the received byte value into the variable "ByteReceived"
   temp=ReceivedByte;
   UDR0 = ReceivedByte; // Echo back the received byte back to the computer
}
void setup() {
  // put your setup code here, to run once:
   pinMode(13,OUTPUT);
   digitalWrite(13,LOW);
   UBRR0=103;
   UCSR0B = (1 << RXEN0) | (1 << TXEN0);   // Turn on the transmission and reception circuitry
   //UCSR0C = (1 << URSEL) | (1 << UCSZ01) | (1 << UCSZ00); // Use 8-bit character sizes
UCSR0C =
        /* no parity bit */
        (0 << UPM01) |
        (0 << UPM00) |
        /* asyncrounous USART */
        (0 << UMSEL01) |
        (0 << UMSEL00) |
        /* one stop bit */
        (0 << USBS0) |
        /* 8-bits of data */
        (1 << UCSZ01) |
        (1 << UCSZ00);
  // UBRR0H = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
   //UBRR0L = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register

    
   UCSR0B |= (1 << RXCIE0); // Enable the USART Recieve Complete interrupt (USART_RXC)
   sei(); // Enable the Global Interrupt Enable flag so that interrupts can be processed

}

void loop() {
  // put your main code here, to run repeatedly:

/*if(temp=='0')
  {
    digitalWrite(13,LOW);
  }
  if(temp=='1')
  {
    digitalWrite(13,HIGH);
  }
  if(temp=='2')
  {
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
  }

  if(temp=='3')
  {
    digitalWrite(13,HIGH);
    delay(300);
    digitalWrite(13,LOW);
    delay(300);
  }
  */
}
