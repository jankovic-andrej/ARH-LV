Claude
Zadatak 7.2: “najbrži prst”
Ideja
Igra: svi igrači čekaju, pa prvi koji stisne svoju tipku pobjeđuje. Ispiše se redni broj igrača (1 do 4) i proteklo vrijeme od zadnjeg stiska (po zadatku, od prethodnog pritiska/starta kruga).

Razlika u odnosu na 7.1:

Svaka tipka je jedan igrač (4 → igrač 1, 7 → igrač 2, 12 → igrač 3, 18 → igrač 4).
Nakon što je prvi stisnuo, ostali pritisci se ignoriraju dok ne počne novi krug.
Treba način da se krug resetira. Najjednostavnije: nakon ispisa pobjednika loop() pričeka (npr. 3 s), nulira ms i otvori novi krug.
Kod
cpp
#include "TimerOne.h"
#include "PinChangeInterrupts.h"

volatile unsigned long ms = 0;
volatile unsigned long proteklo = 0;
volatile int igrac = 0;          // 0 = još nitko nije stisnuo
volatile bool ispis = false;

void otkucaj() {
  ms++;
}

void pritisak(int broj) {
  if (igrac == 0) {              // samo prvi pritisak u krugu računa
    igrac = broj;
    proteklo = ms;
    ispis = true;
  }
}

void tipka4()  { pritisak(1); }
void tipka7()  { pritisak(2); }
void tipka12() { pritisak(3); }
void tipka18() { pritisak(4); }

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

  Serial.println("Spremni! Stisnite tipku.");
}

void loop() {
  if (ispis) {
    ispis = false;
    Serial.print("Pobjednik: igrac ");
    Serial.print(igrac);
    Serial.print(", vrijeme: ");
    Serial.print(proteklo);
    Serial.println(" ms");

    delay(3000);                 // pauza prije novog kruga

    noInterrupts();
    ms = 0;
    igrac = 0;                   // otvori novi krug
    interrupts();

    Serial.println("Novi krug! Stisnite tipku.");
  }
}
Kako radi
Timer1 svake 1 ms povećava ms (vrijeme od početka kruga).
Prvi pritisak: igrac je 0, pa se spremi tko je stisnuo i proteklo = ms. Svi sljedeći pritisci vide igrac != 0 i ništa ne rade.
loop() ispiše pobjednika, čeka 3 s (delay je u loop() dopušten), resetira ms i igrac i počinje novi krug.
Napomene
Pritisci tijekom 3 s pauze se ignoriraju jer je igrac još različit od 0.
noInterrupts() / interrupts() oko reseta štiti 4-bajtni ms od čitanja usred promjene.
Ako zadatak na labosima traži “vrijeme od zadnjeg stiska” doslovno (vrijeme između pritisaka, kao u 7.1), umjesto resetiranja kruga nuliraj ms pri svakom pritisku i ispisuj i broj igrača. Provjeri s asistentom koju varijantu žele.
daj mi molim te bez komentara

cpp
#include "TimerOne.h"
#include "PinChangeInterrupts.h"

volatile unsigned long ms = 0;
volatile unsigned long proteklo = 0;
volatile int igrac = 0;
volatile bool ispis = false;

void otkucaj() {
  ms++;
}

void pritisak(int broj) {
  if (igrac == 0) {
    igrac = broj;
    proteklo = ms;
    ispis = true;
  }
}

void tipka4()  { pritisak(1); }
void tipka7()  { pritisak(2); }
void tipka12() { pritisak(3); }
void tipka18() { pritisak(4); }

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

  Serial.println("Spremni! Stisnite tipku.");
}

void loop() {
  if (ispis) {
    ispis = false;
    Serial.print("Pobjednik: igrac ");
    Serial.print(igrac);
    Serial.print(", vrijeme: ");
    Serial.print(proteklo);
    Serial.println(" ms");

    delay(3000);

    noInterrupts();
    ms = 0;
    igrac = 0;
    interrupts();

    Serial.println("Novi krug! Stisnite tipku.");
  }
}



Claude is AI and can make mistakes.
Claude finished the response
