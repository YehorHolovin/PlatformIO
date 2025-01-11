#include <Arduino.h>

#define LED_1_PIN 13
#define LED_2_PIN 12
#define LED_3_PIN 11

#define POTENSIOMTR_1 A1
#define BUTTON_1 2

#define SIZE_PIN 3

int ArrLed[SIZE_PIN] = {LED_1_PIN, LED_2_PIN, LED_3_PIN};

unsigned long previousTimeLed1 = millis();
unsigned long timeIntervalLed1 = 100;

int LedStart1 = LOW;
int potencialLed = LOW;
int buttonState = LOW;
void setup()
{
    Serial.begin(115200);
    for (int i = 0; i < SIZE_PIN; i++)
    {
        pinMode(ArrLed[i], OUTPUT);
    }
    for (int i = 0; i < SIZE_PIN; i++)
    {
        digitalWrite(ArrLed[i], LOW);
    }
    pinMode(BUTTON_1, INPUT);
}

void loop()
{ // interval blink LED.
    unsigned long timeNow = millis();
    if (Serial.available() > 0)
    {
        int inputTimeInterval = Serial.parseInt();
        if (inputTimeInterval > 100 && inputTimeInterval < 1000)
        {
            timeIntervalLed1 = inputTimeInterval;
            Serial.print("New flashing interval time: ");
            Serial.print(timeIntervalLed1);
            Serial.println("ms");
        }
        else if (inputTimeInterval == 0)
        {
            Serial.println("Error: Invalid input. Please enter a number.");
        }
        else
        {
            Serial.println("Error: Delay should be between 100 and 1000ms.");
        }
    }

    if (timeNow - previousTimeLed1 > timeIntervalLed1)
    {
        LedStart1 = (LedStart1 == LOW) ? HIGH : LOW;
        digitalWrite(LED_1_PIN, LedStart1);
        previousTimeLed1 = timeNow;
    }

    // potensiomtr + LED
    potencialLed = analogRead(POTENSIOMTR_1);
    int brightnessLed = map(potencialLed, 0, 1023, 0, 255);
    analogWrite(LED_2_PIN, brightnessLed);

    // button + LED
    buttonState = digitalRead(BUTTON_1);
    digitalWrite(LED_3_PIN, buttonState);
}