#include "TimerOne.h"

volatile unsigned long brojac = 0;
unsigned long next = 10000;
volatile bool radi = true;
volatile bool ispis = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize(100);
  Timer1.attachInterrupt(povecaj);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(2), startStop, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), ispisi, FALLING);
 
}

void startStop()
{
  radi = !radi;
}


void povecaj()
{
  if(radi)
  {
    brojac++;
  }
  
}

void ispisi()
{
   ispis = true;
}



void loop() {
  // put your main code here, to run repeatedly:
 
    if(ispis)
    {
      Serial.println(brojac/ 10000.0, 3);
      ispis = false;
    }
}
