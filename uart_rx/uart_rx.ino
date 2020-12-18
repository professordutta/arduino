#include <avr/interrupt.h> 
#include <avr/io.h>
char temp='0';
char temp1;
 
void setup()
{
   pinMode(13, OUTPUT);  
   UBRR0 = 103;
   UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // Use 8-bit character sizes 
   UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);   // Turn on the transmission, reception, and Receive interrupt      
   sei();
}

void loop()
{
  
  switch(temp)
  {
    case '0':
    digitalWrite(13,LOW);
    break;

    case '1':
    digitalWrite(13,HIGH);
    break;

    case '2':
    digitalWrite(13,HIGH);
    delay(300);
    digitalWrite(13,LOW);
    delay(300);
    break;

    case '3':
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
    break;

    
  }
}

ISR(USART_RX_vect)
{  
  temp=UDR0;
  //digitalWrite(13, HIGH);   // set the LED on
  //delay(1000);              // wait for a second
}
