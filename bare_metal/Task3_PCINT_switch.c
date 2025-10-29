#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT0_vect) {
// LOW = LED on and / HIGH = LED off
if (PINB & (1 << PB0)) PORTB &= ~(1 << PORTB5);
else PORTB |= (1 << PORTB5);
}

int main(void) {
// LED PB5 out; switch PB0 in with pull-up
DDRB |= (1 << DDB5);
DDRB &= ~(1 << DDB0);
  //INPUT_PULLUP
PORTB |= (1 << PORTB0); 

if (PINB & (1 << PB0)) PORTB &= ~(1 << PORTB5);
else PORTB |= (1 << PORTB5);

// Enable pin-change interrupt on PB0
PCICR |= (1 << PCIE0);
PCMSK0 |= (1 << PCINT0);
PCIFR |= (1 << PCIF0);
sei();

while (1) {}
}
