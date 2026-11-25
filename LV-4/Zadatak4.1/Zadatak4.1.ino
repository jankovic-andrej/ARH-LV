#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {7, 8, 9, 10};
byte colPins[COLS] = {13, 11, 12};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char pin[4] = {'1', '2', '3', '4'};
char unos[4];
int brojZnamenki = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Upisi PIN:");
}

void loop() {
  char key = customKeypad.getKey();

  if (key) {
    unos[brojZnamenki] = key;
    brojZnamenki++;
    Serial.print('*');

    if (brojZnamenki == 4) {
      Serial.println();

      bool tocan = true;
      for (int i = 0; i < 4; i++) {
        if (unos[i] != pin[i]) {
          tocan = false;
        }
      }

      if (tocan) {
        Serial.println("PIN tocan - sef otkljucan");
      } else {
        Serial.println("PIN kriv");
      }

      brojZnamenki = 0;
    }
  }
}