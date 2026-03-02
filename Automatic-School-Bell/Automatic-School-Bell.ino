// Arduino code for Automatic School Bell System

#include <TimeLib.h>

int bellPin = 9; // Pin connected to the bell

void setup() {
  pinMode(bellPin, OUTPUT);
  // set the time to 8:00 AM by default (HH:MM:SS)
  setTime(8, 0, 0, 1, 1, 2026);  // (hour, minute, second, day, month, year)
}

void loop() {
  // Get current hour and minute
  int currentHour = hour();
  int currentMinute = minute();

  // Set bell ringing times
  if ((currentHour == 8 && currentMinute == 0) || (currentHour == 12 && currentMinute == 0) || (currentHour == 15 && currentMinute == 30)) {
    ringBell();
    delay(60000); // ring for 60 seconds
  }
  delay(1000); // Check every minute
}

void ringBell() {
  digitalWrite(bellPin, HIGH);
  delay(1000); // Bell on for 1 second
  digitalWrite(bellPin, LOW);
}