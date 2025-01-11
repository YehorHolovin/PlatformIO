#include <Arduino.h>
#define BUTTON1 2

#define LED_RED 11
#define LED_YELOW 12
#define LED_GREEN 13

#define LED_PIN_ARR_SIZE 3

byte LedPinArr[LED_PIN_ARR_SIZE] = {LED_RED, LED_YELOW, LED_GREEN};

int LEDBlinkState = 1;

void setLEDpinMode()
{
  for (int i = 0; i < LED_PIN_ARR_SIZE; i++)
  {
    pinMode(LedPinArr[i], OUTPUT);
  }
}

void turnLeddigitalWrite()
{
  for (int i = 0; i < LED_PIN_ARR_SIZE; i++)
  {
    digitalWrite(LedPinArr[i], LOW);
  }
}
void toggleLEDs()
{
  if (LEDBlinkState == 1)
  {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELOW, LOW);
    digitalWrite(LED_GREEN, HIGH);
    LEDBlinkState = 2;
  }
  else
  {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELOW, HIGH);
    digitalWrite(LED_GREEN, LOW);
    LEDBlinkState = 1;
  }
}
void setup()
{
  pinMode(BUTTON1, INPUT);
  setLEDpinMode();
  turnLeddigitalWrite();
}
void loop()
{
  if (digitalRead(BUTTON1) == LOW)
  {
    toggleLEDs();
    delay(300);
  }
}
