#include <Arduino.h>
#define LED_R_1 11
#define LED_Y_2 12
#define LED_G_3 13
#define BUTTON_1 2
#define ARRSIZELED 3

void blinkLED();
void buttonPressed();

int LedArr[ARRSIZELED] = {LED_R_1, LED_Y_2, LED_G_3};

unsigned long blinkTimeLED_Y_2 = 400;
unsigned long lasctStatusBlinkLED_Y_2 = millis();

int ledStart_Y_2 = LOW;

unsigned long timeStatusButton = 50;
unsigned long timeBounceButton = 0;

int statusButton_1 = LOW;
int previousButtonState = LOW;
void setup()
{
  for (int i = 0; i < ARRSIZELED; i++)
  {
    pinMode(LedArr[i], OUTPUT);
  }

  for (int i = 0; i < ARRSIZELED; i++)
  {
    digitalWrite(LedArr[i], LOW);
  }
  pinMode(BUTTON_1, INPUT);
}

void loop()
{
  blinkLED();
  buttonPressed();
}
void blinkLED()
{
  unsigned long newBlinkTime_Y_2 = millis();
  if (newBlinkTime_Y_2 - lasctStatusBlinkLED_Y_2 > blinkTimeLED_Y_2)
  {
    ledStart_Y_2 = (ledStart_Y_2 == LOW) ? HIGH : LOW;
    digitalWrite(LED_Y_2, ledStart_Y_2);
    lasctStatusBlinkLED_Y_2 = newBlinkTime_Y_2;
  }
}
void buttonPressed()
{
  unsigned long newChangeButton = millis();
  statusButton_1 = digitalRead(BUTTON_1);
  if (newChangeButton - timeBounceButton > timeStatusButton)
  {
    timeBounceButton = newChangeButton;

    if (statusButton_1 != LOW)
    {
      digitalWrite(LED_R_1, HIGH);
      digitalWrite(LED_G_3, LOW);
    }
    else
    {
      digitalWrite(LED_G_3, HIGH);
      digitalWrite(LED_R_1, LOW);
    }
  }
}