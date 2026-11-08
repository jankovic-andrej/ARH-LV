#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);

int x = 3;
int y = 2;
int dx = 1;
int dy = 1;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  lc.setLed(0, y, x, false);

  x += dx;
  y += dy;

  if (x <= 0 || x >= 7) dx = -dx;
  if (y <= 0 || y >= 7) dy = -dy;

  lc.setLed(0, y, x, true);

  delay(100);
}