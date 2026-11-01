#include "TimerOne.h"

volatile int currentDig = 0;
volatile unsigned int x = 0;
const int pot10[4] = {1000, 100, 10, 1};
volatile int ms = 0;
volatile bool state = true;

volatile byte segment[11][8] = {
{0,0,0,0,0,0,1,1}, // 0
{1,0,0,1,1,1,1,1}, // 1
{0,0,1,0,0,1,0,1}, // 2
{0,0,0,0,1,1,0,1}, // 3
{1,0,0,1,1,0,0,1}, // 4
{0,1,0,0,1,0,0,1}, // 5
{0,1,0,0,0,0,0,1}, // 6
{0,0,0,1,1,1,1,1}, // 7
{0,0,0,0,0,0,0,1}, // 8
{0,0,0,0,1,0,0,1}, // 9
{1,1,1,1,1,1,1,1}}; // OFF

void setup() {
  // put your setup code here, to run once:
  for(int i = 4; i<16; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  
  digitalWrite(4, LOW);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(nextDigit);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);


  attachInterrupt(digitalPinToInterrupt(2), pauza, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), nastavi, FALLING);
}

void pauza()
{
  state = false;
}
void nastavi()
{
  state = true;
}

void nextDigit()
{
  if(state)
  {
    ms++;
    if(ms >= 10)
    {
      ms = 0;
      x++;
      if(x> 9999) {x = 0;}
    }
  }

  digitalWrite(currentDig + 4, HIGH);
    currentDig++;
    if(currentDig>3)
    {
      currentDig = 0;
    }

  
  int z = (x / pot10[currentDig])% 10;
  for(int i = 0; i<8; i++)
  {
    digitalWrite(8+i, segment[z][i]);
  }


  if (currentDig == 1) {
  digitalWrite(15, LOW);
  } else {
    digitalWrite(15, HIGH);
  }




  digitalWrite(currentDig + 4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
