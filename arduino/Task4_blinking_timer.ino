#include <avr/interrupt.h>

void setup() {
pinMode(LED_BUILTIN, OUTPUT);

// Timer1 CTC, F_CPU = 16 MHz, prescaler = 1024. 16000000 / 1024 = 15625 ticks per second. 
TCCR1A = 0;
TCCR1B = _BV(WGM12) | _BV(CS12) | _BV(CS10); // CTC + prescale 1024
OCR1A = 15625;
TIFR1 |= _BV(OCF1A); // clear pending flags
TIMSK1 = _BV(OCIE1A); // enable compare A interrupt
sei();
}

ISR(TIMER1_COMPA_vect) {
//writing 1 to PINB5 on PB5 for built in LED
PINB = _BV(PINB5);
}

void loop() {}
