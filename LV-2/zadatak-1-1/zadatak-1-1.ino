#include "TimerOne.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);

  for(int i = 4; i<=11; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  digitalWrite(4, LOW);


  Timer1.initialize(1000000);
  Timer1.attachInterrupt(korak);

}
volatile int index = 0; 

void korak()
{
  digitalWrite(index+4, HIGH);
  index++;
  if(index == 8 ) { 
    index = 0;
  }

  digitalWrite(index+4, LOW);

}


void loop() {
  // put your main code here, to run repeatedly:

}
