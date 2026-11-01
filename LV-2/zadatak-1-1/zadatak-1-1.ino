#include "TimerOne.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP);

  for(int i = 4; i<=11; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  digitalWrite(4, LOW);


  Timer1.initialize(1000000);
  Timer1.attachInterrupt(korak);

  attachInterrupt(digitalPinToInterrupt(2), promjenaSmjera, FALLING);

}
volatile int id = 0; 
volatile int smjer = 1;
volatile bool novi = false;
volatile bool bounce = false;

void korak()
{
  digitalWrite(id+4, HIGH);
  id = id + smjer;
  if(id > 7 ) { 
    id = 0;
  }
  if(id < 0)
  {
    id = 7;
  }
  
  digitalWrite(id+4, LOW);
  novi = true;
}

void promjenaSmjera(){
  if(!bounce){
    bounce = true;
    smjer = -smjer;
  }
  
}


void loop() {
  // put your main code here, to run repeatedly:
  if(bounce){
    delay(50);
    bounce = false;
  }
  
  if(novi)
  {
    Serial.println(id);
    novi = false;
  }

}
