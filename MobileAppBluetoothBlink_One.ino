#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
const int LED_PIN = 2;  // Built-in LED pin on ESP32

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32_LED_Control"); // Bluetooth device name
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  if (SerialBT.available()) {

    char command = SerialBT.read();
    if (command == '1') {
      digitalWrite(LED_PIN, HIGH);
      SerialBT.println("LED is ON");


    } else if (command == '0') {
      digitalWrite(LED_PIN, LOW);
      SerialBT.println("LED is OFF");

    }
  }

  delay(20);
  
}