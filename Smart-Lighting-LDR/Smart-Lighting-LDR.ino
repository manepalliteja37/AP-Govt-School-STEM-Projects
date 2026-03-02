#define LDR1 2
#define LDR2 3
#define LDR3 4
#define LDR4 5

#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11

void setup() {
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(LDR4, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void controlLight(int ldrPin, int ledPin) {
  if (digitalRead(ldrPin) == LOW)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}

void loop() {
  controlLight(LDR1, LED1);
  controlLight(LDR2, LED2);
  controlLight(LDR3, LED3);
  controlLight(LDR4, LED4);
}
