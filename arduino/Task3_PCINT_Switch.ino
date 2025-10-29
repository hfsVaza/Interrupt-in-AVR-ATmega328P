#include <avr/interrupt.h>

const uint8_t SW_PIN = 8; // PB0 / PCINT0

ISR(PCINT0_vect) {
// Mirror the switch to the built-in LED
if ((PINB & _BV(PB0)) == 0) PORTB |= _BV(PORTB5); // LED on
else PORTB &= ~_BV(PORTB5); // LED off
}

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
pinMode(SW_PIN, INPUT_PULLUP);

// Sync LED state individually 
if ((PINB & _BV(PB0)) == 0) PORTB |= _BV(PORTB5);
else PORTB &= ~_BV(PORTB5);

// turn on pin-change interruption for PB0 (PCINT0)
PCICR |= _BV(PCIE0); // enable PORTB group
PCMSK0 |= _BV(PCINT0); // unmask PB0
PCIFR |= _BV(PCIF0); //clears pending flags 
sei();
}

void loop() {} //loops
