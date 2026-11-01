#include "TimerOne.h"
#include "PinChangeInterrupts.h"

volatile int current = 0;
volatile bool ispis = false; 
volatile bool ledState = false;
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
  ledState = !ledState;
  current = 4;
  ispis = true;
}

void tipka7()
{
  ledState = !ledState;
  current = 7;
  ispis = true;
}

void tipka18()
{
  ledState = !ledState;
  current = 18;
  ispis = true;
}

void tipka12()
{
  ledState = !ledState;
  current = 12;
  ispis = true;
}

void loop() {
  if (ispis) {
    ispis = false;
    digitalWrite(13, ledState);
    Serial.print("LED: ");
    Serial.print(ledState);
    Serial.print(", pin: ");
    Serial.println(current);
  }
}
