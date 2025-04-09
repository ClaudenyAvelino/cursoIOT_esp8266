#include <Arduino.h>

const byte LED = 2;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  Serial.println("Low Voltage");
  digitalWrite(LED, LOW);
  delay(1000);
  Serial.println("High Voltage");
  digitalWrite(LED, HIGH);
  delay(1000);
}
