#include "avr/io.h"
#include "avr/interrupt.h"
char temp;

ISR(USART_RX_vect)
{
  temp=UDR0;
}


void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
UBRR0 = 103;
UCSR0B = (1<<RXEN0)|(1<<RXCIE0);
interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
    
    if(temp=='0')
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
      delay(300);
      digitalWrite(13,LOW);
      delay(300);
    }

    if(temp=='3')
    {
      digitalWrite(13,HIGH);
      delay(1000);
      digitalWrite(13,LOW);
      delay(1000);
    }
   
}
