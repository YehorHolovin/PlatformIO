#include <Arduino.h>
unsigned long startTime = millis();
unsigned long intrevalTime = 500;
void setup()
{
  Serial.begin(115200);
}

void loop()
{
  unsigned long timeNow = millis();
  if (timeNow - startTime > intrevalTime)
  {
    Serial.println("Hello");
    Serial.println(millis());
    startTime += intrevalTime;
  }
}