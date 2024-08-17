#include <Arduino.h>

const int ledPin1 = 4;
const int ledPin2 = 5;
const unsigned long interval = 1000;
unsigned long previousMillis = 0;
bool ledState1 = LOW;
bool ledState2 = LOW;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    ledState1 = !ledState1;
    ledState2 = !ledState2;

    digitalWrite(ledPin1, ledState1);
    digitalWrite(ledPin2, ledState2);
  }
}