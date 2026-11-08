#include <Wire.h>
#include "LedControl.h"

#define ADRESA 0x30

LedControl lc = LedControl(12, 11, 10, 1);

int x = 3;
int y = 2;
int dx = 1;
int dy = 1;

unsigned long zadnje = 0;
int brzina = 200;

void setup() {
  Wire.begin();
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  Wire.requestFrom(ADRESA, 2);
  byte b[2];
  int i = 0;
  while (Wire.available() && i < 2) {
    b[i] = Wire.read();
    i++;
  }
  if (i == 2) {
    int v = b[0] | b[1] << 8;
    brzina = map(v, 0, 1023, 30, 500);
    brzina = constrain(brzina, 30, 500);
  }

  if (millis() - zadnje >= brzina) {
    zadnje = millis();

    lc.setLed(0, y, x, false);

    x += dx;
    y += dy;

    if (x <= 0 || x >= 7) dx = -dx;
    if (y <= 0 || y >= 7) dy = -dy;

    lc.setLed(0, y, x, true);
  }
}