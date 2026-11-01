#include "TimerOne.h"

volatile int kocka = 1;
volatile bool bacena = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), baci, FALLING);
}

void baci(){
  bacena = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  kocka++;
  if(kocka > 6)
  {
    kocka = 1;
  }
  if(bacena)
  {
    bacena = false;
    Serial.println(kocka);
  }
}
