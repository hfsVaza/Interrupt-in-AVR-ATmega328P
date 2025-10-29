#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect) {
PINB = (1 << PINB5); // toggle PB5
}

int main(void) {
// LED pin as output
DDRB |= (1 << DDB5);

// Timer1: CTC, prescaler 1024, OCR1A for 1s
TCCR1A = 0;
TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
OCR1A = 15624;
TIFR1 |= (1 << OCF1A);
TIMSK1 = (1 << OCIE1A); // enable compare A interrupt

sei();
while (1) {}
}
