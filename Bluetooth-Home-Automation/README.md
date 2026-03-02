# Bluetooth-Based Home Automation Project

## Introduction
This project demonstrates a Bluetooth-based home automation system that allows users to control various household appliances remotely using a mobile device. The system uses Bluetooth technology to communicate between a microcontroller and a smartphone application.

## Features
- Control multiple household appliances via Bluetooth.
- User-friendly mobile application interface.
- Real-time feedback and status monitoring.
- Energy-efficient operation.
- Scalable design for adding more devices.

## Components
1. Microcontroller (Arduino, ESP32, or similar)
2. Bluetooth Module (HC-05 or HC-06)
3. Relay Modules (for controlling appliances)
4. Power Supply
5. Connecting Wires
6. Resistors and Capacitors
7. Mobile Device with Bluetooth capability

## Circuit Diagram
![Circuit Diagram](link_to_circuit_diagram)

## Working Principle
- The Bluetooth module receives signals from a mobile application.
- The microcontroller processes these signals and controls the relay modules.
- The relay modules switch ON/OFF the connected appliances.
- Status feedback is sent back to the mobile application.

## Installation Steps

### Hardware Setup
1. Connect the Bluetooth module (HC-05/HC-06) to the microcontroller's serial pins.
2. Connect relay modules to digital output pins of the microcontroller.
3. Connect appliances to the relay modules.
4. Power up the system.

### Software Setup
1. Download and install the Arduino IDE.
2. Install required libraries for Bluetooth communication.
3. Upload the provided code to the microcontroller.
4. Download the mobile application (Android/iOS).
5. Pair your Bluetooth module with your mobile device.

## Code Example
```cpp
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int relay1 = 5;
const int relay2 = 6;
const int relay3 = 7;

void setup() {
    Serial.begin(115200);
    SerialBT.begin("ESP32_BT");
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
}

void loop() {
    if (SerialBT.available()) {
        String command = SerialBT.readStringUntil('\n');
        
        if (command == "1ON") {
            digitalWrite(relay1, HIGH);
            SerialBT.println("Relay 1 ON");
        } else if (command == "1OFF") {
            digitalWrite(relay1, LOW);
            SerialBT.println("Relay 1 OFF");
        }
    }
}
```

## Mobile Application
You can use the following mobile apps to control the system:
- MIT App Inventor
- Blynk
- RemoteXY

## Command Format
- `1ON` - Turn on Relay 1
- `1OFF` - Turn off Relay 1
- `2ON` - Turn on Relay 2
- `2OFF` - Turn off Relay 2

## Safety Precautions
- Always ensure proper insulation of electrical connections.
- Use appropriate relay ratings for the appliances.
- Keep the system away from moisture and extreme temperatures.

## Conclusion
This Bluetooth-based home automation project provides a foundation for building a smart home system.