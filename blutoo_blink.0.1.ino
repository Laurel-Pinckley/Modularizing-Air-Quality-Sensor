/*
Source Code:
https://www.youtube.com/watch?v=w5LgLsCumFI
*/

//include bluetooth library and set it to SerialBT name
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

//builtin led is pin 2
const int ledPin = 2;

void setup() {
  //bluetooth device name
  SerialBT.begin("ESP32-Bluetooth");
  pinMode(ledPin, OUTPUT);
}

void loop() {

  //read character
  if (SerialBT.available()) {
    char c = SerialBT.read();

    //check for on_button
    if (c == "1") {
      digitalWrite(ledPin, HIGH);
    }
    //check for off_button
    else if (c == "0") {
      digitalWrite(ledPin, LOW);
    }
  }
}
