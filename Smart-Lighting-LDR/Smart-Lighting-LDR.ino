// LDR-based Smart Lighting Code
#include <Arduino.h>

// Pin definitions
const int ldrPin = A0;  // LDR connected to A0
const int ledPin = 9;   // LED connected to digital pin 9

void setup() {
    pinMode(ledPin, OUTPUT);  // Set LED pin as output
    Serial.begin(9600);       // Start serial communication
}

void loop() {
    int ldrValue = analogRead(ldrPin); // Read the LDR value
    Serial.println(ldrValue);          // Print the LDR value to serial monitor

    // Control LED based on LDR value
    if (ldrValue < 500) {   // Change the threshold value as needed
        digitalWrite(ledPin, HIGH); // Turn ON the LED
    } else {
        digitalWrite(ledPin, LOW);  // Turn OFF the LED
    }
    delay(1000); // Wait for 1 second before the next read
}