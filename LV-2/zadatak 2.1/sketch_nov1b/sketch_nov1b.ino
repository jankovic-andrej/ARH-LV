#include "TimerOne.h"

volatile unsigned long brojac = 0;
unsigned long next = 10000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize(100);
  Timer1.attachInterrupt(povecaj);


 
}

void povecaj()
{
  brojac++;
}




void loop() {
  // put your main code here, to run repeatedly:
  if(brojac % 10000 == 0 && brojac > 0)
  {
    Serial.println(brojac/ 10000.0, 3);
    delay(1);
  }
}
