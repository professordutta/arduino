#include "avr/io.h"
#include "avr/interrupt.h"


ISR (USART_UDRE_vect)
{
  UDR0 = 'M';
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    UBRR0 = 103;
    UCSR0B = (1<<TXEN0)| (1<<UDRIE0);
    sei();
    while(1);
    //delay(1000);
    //while(!(UCSR0A & (1<<UDRE0)));
    //UDR0 = '\r';
    //delay(1000);
    //while(1); //stop here


}
