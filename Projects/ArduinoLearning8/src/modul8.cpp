#include <Arduino.h>
#define POTENSIOMTR_PIN A1
#define LED_PIN A5
void setup()
{
   pinMode(LED_PIN, OUTPUT);
   Serial.begin(9600);
}

void loop()
{
   int postValue = analogRead(POTENSIOMTR_PIN);
   int ledValue = postValue / 4;
   analogWrite(LED_PIN, ledValue);
   Serial.println(analogRead(POTENSIOMTR_PIN));
   delay(100);
}