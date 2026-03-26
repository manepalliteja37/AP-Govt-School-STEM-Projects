#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// TFT Pins
#define TFT_CS   10
#define TFT_RST  8
#define TFT_DC   9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// LEDs + Button + Buzzer
int leds[] = {2, 3, 4, 5, 6};
int buttonPin = 7;
int buzzer = 12; //optional buzzer pin

int state = 0;
bool lastButton = HIGH;

// 🌸 Simple Flower draw
void drawFlower(int x, int y) {
  // petals
  tft.fillCircle(x, y, 3, ST77XX_RED);
  tft.fillCircle(x+4, y, 3, ST77XX_YELLOW);
  tft.fillCircle(x-4, y, 3, ST77XX_YELLOW);
  tft.fillCircle(x, y+4, 3, ST77XX_YELLOW);
  tft.fillCircle(x, y-4, 3, ST77XX_YELLOW);

  // center
  tft.fillCircle(x, y, 2, ST77XX_WHITE);
}

// 🌸 Falling flowers animation
void animateFlowers() {
  for (int y = 0; y < 160; y += 15) {

    tft.fillRect(0, 0, 128, 160, ST77XX_BLACK); // smoother clear

    for (int x = 10; x < 120; x += 30) {
      drawFlower(x, y);
    }

    delay(100);
  }
}

// ✨ Fade Text
void fadeText(String text, int x, int y, int size, uint16_t color) {
  for (int i = 0; i < 3; i++) {
    tft.setTextColor(color);
    tft.setTextSize(size);
    tft.setCursor(x, y);
    tft.println(text);
    delay(120);
  }
}

// LEDs OFF
void clearLEDs() {
  for (int i = 0; i < 5; i++) digitalWrite(leds[i], LOW);
}

// Normal text display
void showText(String l1, String l2, String l3, uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextSize(2);
  tft.setTextColor(color);
  tft.setCursor(10, 30);
  tft.println(l1);

  tft.setTextSize(1);
  tft.setCursor(10, 70);
  tft.println(l2);

  tft.setCursor(10, 100);
  tft.println(l3);
}


void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(0);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  for (int i = 0; i < 5; i++) pinMode(leds[i], OUTPUT);

  tft.fillScreen(ST77XX_BLACK);
}

void loop() {
  bool currentButton = digitalRead(buttonPin);

  if (lastButton == HIGH && currentButton == LOW) {
    state++;
    if (state > 6) state = 0;
   // 🔊 beep first (clean sound)
   digitalWrite(buzzer, HIGH);
   delay(200);
   digitalWrite(buzzer, LOW);
   clearLEDs();


    switch (state) {

      case 0:
        digitalWrite(leds[0], HIGH);
        showText("Sweet ", "Mom Love ", "Stable Voltage", ST77XX_YELLOW);
        break;

      case 1:
        digitalWrite(leds[1], HIGH);
        showText("Bitter ", "Failures ", "Noise Signal", ST77XX_BLUE);
        break;

      case 2:
        digitalWrite(leds[2], HIGH);
        showText("Spicy ", "Anger ", "Overcurrent", ST77XX_RED);
        break;

      case 3:
        digitalWrite(leds[3], HIGH);
        showText("Sour ", "Surprises ", "Signal Spike", ST77XX_GREEN);
        break;

      case 4:
        digitalWrite(leds[4], HIGH);
        showText("Salty ", "Tears ", "Corrosion", ST77XX_WHITE);
        break;

case 5:
  for (int i = 0; i < 5; i++) digitalWrite(leds[i], HIGH);

  tft.fillScreen(ST77XX_BLACK);

  // Line 1
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_CYAN);
  tft.setCursor(30, 20);
  tft.println("Ugadi");

  // Line 2
  tft.setCursor(20, 50);
  tft.println("Pachadi");

  // Line 3
  tft.setTextSize(1);
  tft.setCursor(10, 90);
  tft.println("Life = Mix");

  // Line 4
  tft.setCursor(10, 110);
  tft.println("Circuit Complete");

  break;

case 6:
  clearLEDs();

  // 🌸 Flowers falling
  animateFlowers();

  // 🎨 Gradient
  tft.fillScreen(ST77XX_BLACK);  // ✅ pure black background
  tft.drawRect(0, 0, 128, 160, ST77XX_GREEN);
  // 💡 LED blink
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) digitalWrite(leds[j], HIGH);
    delay(150);
    for (int j = 0; j < 5; j++) digitalWrite(leds[j], LOW);
    delay(150);
  }

  // ✨ Final text
  fadeText("Andariki", 20, 40, 2, ST77XX_WHITE);
  fadeText("Ugadi Subhakankshulu", 5, 70, 1, ST77XX_YELLOW);
  fadeText("Mee Mad Thinker", 20, 100, 1, ST77XX_CYAN);
  fadeText("Signing Off ", 20, 120, 1, ST77XX_GREEN);

  break;
    }

    delay(300);
  }

  lastButton = currentButton;
}
