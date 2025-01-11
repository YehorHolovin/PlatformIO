#include <Arduino.h>

#define LED_GREEN 13
int blinkRate = 500;

void setup()
{
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, LOW);
  Serial.begin(9600);
  Serial.setTimeout(500);
  Serial.println("ready to change the LED blink frequency?");
}

void loop()
{
  if (Serial.available() > 0)
  {
    int inputDaley = Serial.parseInt();
    if (inputDaley > 100 && inputDaley < 1000)
    {
      blinkRate = inputDaley;
      Serial.print("New delay set: ");
      Serial.print(blinkRate);
      Serial.println("ms");
    }
    else
    {
      Serial.println("Error: Delay should be between 100 and 1000ms.");
    }
  }

  digitalWrite(LED_GREEN, HIGH);
  delay(blinkRate);
  digitalWrite(LED_GREEN, LOW);
  delay(blinkRate);
}