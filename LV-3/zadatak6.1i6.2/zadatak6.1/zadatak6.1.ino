#include "PCF85063A-SOLDERED.h"
#include "OLED-Display-SOLDERED.h"

PCF85063A rtc;
OLED_Display display;

void ispisiDvije(int v) {
  if (v < 10) display.print("0");
  display.print(v);
}

void setup() {
  Serial.begin(9600);
  rtc.begin();
  rtc.setTime(12, 0, 0);

  display.begin();
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
}

void loop() {
  int h = rtc.getHour();
  int m = rtc.getMinute();
  int s = rtc.getSecond();

  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.println(s);

  display.clearDisplay();
  display.setCursor(10, 24);
  ispisiDvije(h);
  display.print(":");
  ispisiDvije(m);
  display.print(":");
  ispisiDvije(s);
  display.display();

  delay(1000);
}