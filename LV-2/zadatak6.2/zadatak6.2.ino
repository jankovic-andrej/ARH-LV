#include "TimerOne.h"
#include "PinChangeInterrupts.h"

volatile int period = 200;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

  pinMode(13, OUTPUT);

  attachPinChangeInterrupt(digitalPinToPCINT(4), tipka4, FALLING);
  attachPinChangeInterrupt(digitalPinToPCINT(7), tipka7, FALLING);
  attachPinChangeInterrupt(digitalPinToPCINT(12), tipka12, FALLING);
  attachPinChangeInterrupt(digitalPinToPCINT(18), tipka18, FALLING);
}


void tipka4()
{
  period = 200;
}

void tipka7()
{
  period = 500;
}

void tipka18()
{
  period = 700;
}

void tipka12()
{
  period = 1000;
}

void loop() {
    digitalWrite(13, HIGH);
    delay(period);
    digitalWrite(13, LOW);
    delay(period);



}
