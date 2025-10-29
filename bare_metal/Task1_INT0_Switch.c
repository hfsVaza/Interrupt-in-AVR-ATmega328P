#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect) {
// PD2 HIGH (open) -> LED OFF; PD2 LOW (closed) -> LED ON
if (PIND & (1 << PD2)) {
PORTB &= ~(1 << PORTB5); // LED off
} else {
PORTB |= (1 << PORTB5); // LED on
}
}

int main(void) {
DDRB |= (1 << DDB5);

// Switch on PD2 using internal pull-up
DDRD &= ~(1 << DDD2);
PORTD |= (1 << PORTD2);

EICRA |= (1 << ISC00);
EICRA &= ~(1 << ISC01);

EIFR |= (1 << INTF0);
EIMSK |= (1 << INT0);

// Sync initial LED state
if (PIND & (1 << PD2)) PORTB &= ~(1 << PORTB5);
else PORTB |= (1 << PORTB5);

sei();
while (1) {}
}
