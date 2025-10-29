const uint8_t SW_PIN = 2; // INT0
//onboard LED 

void syncLedToSwitch() {
//closed switch = LOW
bool closed = (digitalRead(SW_PIN) == LOW);
digitalWrite(LED_BUILTIN, closed ? HIGH : LOW);
}

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
pinMode(SW_PIN, INPUT_PULLUP);

syncLedToSwitch();

// Trigger on any change (open/closed)
attachInterrupt(digitalPinToInterrupt(SW_PIN), syncLedToSwitch, CHANGE);
}

void loop() { /* nothing */ }
