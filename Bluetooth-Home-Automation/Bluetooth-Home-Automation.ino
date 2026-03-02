#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Bluetooth"); // Name of your Bluetooth device
  Serial.println("The device started, now you can pair it");
}

void loop() {
  if (SerialBT.available()) {
    char incoming = SerialBT.read();
    if(incoming == '1') {
      // Code to turn on a device
      Serial.println("Device ON");
    } else if(incoming == '0') {
      // Code to turn off a device
      Serial.println("Device OFF");
    }
  }
}