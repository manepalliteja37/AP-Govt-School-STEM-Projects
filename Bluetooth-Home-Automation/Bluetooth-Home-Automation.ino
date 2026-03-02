#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define LED1 7
#define LED2 8
#define BT_STATE 2

SoftwareSerial bluetooth(10, 11);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool led1State = false;
bool led2State = false;
bool btConnected = false;

void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.println(btConnected ? "Bluetooth: Connected" : "Bluetooth: Connecting");

  display.setCursor(0, 20);
  display.print("LED1: ");
  display.println(led1State ? "ON" : "OFF");

  display.setCursor(0, 35);
  display.print("LED2: ");
  display.println(led2State ? "ON" : "OFF");

  display.display();
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BT_STATE, INPUT);

  bluetooth.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  updateDisplay();
}

void loop() {

  bool currentState = digitalRead(BT_STATE);
  if (currentState != btConnected) {
    btConnected = currentState;
    updateDisplay();
  }

  if (bluetooth.available()) {
    char cmd = bluetooth.read();

    if (cmd == '1') led1State = true;
    if (cmd == '2') led1State = false;
    if (cmd == '3') led2State = true;
    if (cmd == '4') led2State = false;

    digitalWrite(LED1, led1State);
    digitalWrite(LED2, led2State);

    updateDisplay();
  }
}
