#include "TimerOne.h"
#include "PinChangeInterrupts.h"

volatile unsigned long ms = 0;
volatile unsigned long proteklo = 0;
volatile int tipka = 0;
volatile bool ispis = false;

void otkucaj() {
  ms++;
}

void pritisak(int pin) {
  proteklo = ms;
  ms = 0;
  tipka = pin;
  ispis = true;
}

void tipka4()  { pritisak(4); }
void tipka7()  { pritisak(7); }
void tipka12() { pritisak(12); }
void tipka18() { pritisak(18); }

void setup() {
  Serial.begin(9600);

  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(otkucaj);

  attachPinChangeInterrupt(digitalPinToPCINT(4), tipka4, FALLING);
  attachPinChangeInterrupt(digitalPinToPCINT(7), tipka7, FALLING);
  attachPinChangeInterrupt(digitalPinToPCINT(12), tipka12, FALLING);
  attachPinChangeInterrupt(digitalPinToPCINT(18), tipka18, FALLING);
}

void loop() {
  if (ispis) {
    ispis = false;
    Serial.print("Tipka na pinu ");
    Serial.print(tipka);
    Serial.print(": ");
    Serial.print(proteklo);
    Serial.println(" ms od zadnjeg stiska");
  }
}