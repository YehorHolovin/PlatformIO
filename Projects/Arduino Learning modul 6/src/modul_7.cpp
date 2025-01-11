#include <Arduino.h>
#define BUTTON_PIN 2
#define LED_PIN 11

void setup() {
  Serial.begin(9600);      // Ініціалізація серійного порту
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN); // Читання стану кнопки
  digitalWrite(LED_PIN, buttonState);       // Керування світлодіодом

  // Вивід даних у форматі для плоттера
  Serial.println(buttonState*100); // Стан кнопки
  delay(100);                  // Затримка
}