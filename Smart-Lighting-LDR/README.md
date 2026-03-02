# LDR-based Smart Lighting Project

## Introduction
This project implements a smart lighting system using Light Dependent Resistors (LDRs). The system automatically turns on or off based on ambient light levels, aiming to conserve energy and improve convenience.

## Features
- Automatic light control based on surrounding light levels.
- Energy-efficient operation.
- Easy to set up and use.

## Components
1. Light Dependent Resistor (LDR)
2. Microcontroller (Arduino or similar)
3. Relay module or smart bulbs
4. Power supply
5. Connecting wires
6. independent lighting zones
7. Adjustable light threshold using onboard potentiometer
8. Energy-saving concept
9. Designed for school STEM demonstration



## Working Principle
- The LDR senses the ambient light intensity. 
- When the light intensity falls below a certain threshold, the microcontroller activates the relay, turning on the lights.
- Conversely, when the light intensity exceeds the threshold, the lights are turned off.

## Installation Steps
1. Connect the LDR to the microcontroller.
2. Set up the relay module to control the light.
3. Upload the code to the microcontroller.
4. Test the functionality.

## Components
- Arduino UNO
- 4 LDR Modules
- 4 LEDs
- 4 × 220Ω Resistors
- Jumper wires

## Pin Configuration

| LDR | Arduino Pin |
|------|------------|
| LDR1 D0 | 2 |
| LDR2 D0 | 3 |
| LDR3 D0 | 4 |
| LDR4 D0 | 5 |

| LED | Arduino Pin |
|------|------------|
| LED1 | 8 |
| LED2 | 9 |
| LED3 | 10 |
| LED4 | 11 |

## Conclusion
The LDR-based smart lighting project can greatly improve energy efficiency in homes and other environments. By automatically controlling lighting based on the time of day and occupancy, users can achieve convenience and reduce unnecessary electricity usage.

## Further Developments
- Integration with smart home systems.
- Addition of mobile APP control.
- Remote monitoring using IoT.

## References
- [Arduino Website](https://www.arduino.cc)
- Various electronics project resources.
