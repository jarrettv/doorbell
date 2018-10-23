#include <Arduino.h>

#define PIN_BTN D3
#define PIN_LED D1

bool on = true;

void setup() {
    
  Serial.begin(9600);

  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BTN, INPUT_PULLUP);

  digitalWrite(PIN_LED, on ? HIGH : LOW);

  uint8_t btn = digitalRead(PIN_BTN);
  Serial.println(btn == HIGH ? "Button high" : "Button low");
}

void loop() {

  uint8_t btn = digitalRead(PIN_BTN);

  if (btn == LOW) {
    Serial.println("Button pushed");
    on = !on;
  }

  digitalWrite(PIN_LED, on ? HIGH : LOW);

  delay(80);
}