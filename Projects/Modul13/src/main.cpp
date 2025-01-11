#include <Arduino.h>
#define LED_PIN 13
#define BUTTON_PIN 2

void toggleLed();
void buttonPressedInterrupt();

byte LedState = LOW;
byte ButtonState = LOW;
volatile bool buttonReleased = false;

volatile unsigned long lastTimeButtonInterapt = 0;
const unsigned long bounceDelay = 50;

int count = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonPressedInterrupt, RISING);
}

void loop()
{
  if (buttonReleased)
  {
    buttonReleased = false;
    toggleLed();
    Serial.print("You have turned on the ");
    Serial.print(++count);
    Serial.println(" button");
  }
}

// Change LED
void toggleLed()
{
  if (LedState == LOW)
  {
    LedState = HIGH;
  }
  else
  {
    LedState = LOW;
  }

  digitalWrite(LED_PIN, LedState);
}

// Function interart
void buttonPressedInterrupt()
{
  unsigned long timeNow = millis();
  if (timeNow - lastTimeButtonInterapt > bounceDelay)
  {
    lastTimeButtonInterapt = timeNow;
    buttonReleased = true;
  }
}