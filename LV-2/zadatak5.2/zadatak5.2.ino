#include "TimerOne.h"

volatile int kocka = 1;
volatile bool bacena = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), baci, FALLING);

  Timer1. initialize(1000);
  Timer1.attachInterrupt(vrti);
}

void baci(){
  bacena = true;
}

void vrti(){
  kocka++;
  if(kocka > 6)
  {
    kocka = 1;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(bacena)
  {
    bacena = false;
    Serial.println(kocka);
  }
}
