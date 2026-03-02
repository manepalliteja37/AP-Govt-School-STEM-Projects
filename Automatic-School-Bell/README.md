#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BUZZER 6
#define LED 7

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int currentPeriod = 1;
bool isLunch = false;
unsigned long periodStart;

void ringBell() {
  digitalWrite(BUZZER, HIGH);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED, LOW);
}

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setCursor(0, 20);
  display.println("Automatic School Bell");
  display.display();
  delay(2000);

  periodStart = millis();
}

void loop() {

  unsigned long elapsed = millis() - periodStart;
  unsigned long duration = isLunch ? 600000UL : 300000UL;

  unsigned long remaining = duration - elapsed;

  int minutes = (remaining / 1000) / 60;
  int seconds = (remaining / 1000) % 60;

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Day 1");

  if (!isLunch) {
    display.print("Period: ");
    display.println(currentPeriod);
  } else {
    display.println("Lunch Break");
  }

  display.print("Time Left: ");
  if (minutes < 10) display.print("0");
  display.print(minutes);
  display.print(":");
  if (seconds < 10) display.print("0");
  display.print(seconds);

  display.display();

  if (elapsed >= duration) {
    ringBell();
    periodStart = millis();

    if (!isLunch) {
      currentPeriod++;
      if (currentPeriod == 5) isLunch = true;
    } else {
      isLunch = false;
    }

    if (currentPeriod > 8) {
      display.clearDisplay();
      display.setCursor(0, 20);
      display.println("School Over");
      display.display();
      while (1);
    }
  }
}
