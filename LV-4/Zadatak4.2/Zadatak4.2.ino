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

int melodija[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  Serial.begin(9600);
  customKeypad.setHoldTime(1000);
  Serial.println("Upisi PIN:");
}

void loop() {
  char key = customKeypad.getKey();

  if (customKeypad.getState() == HOLD && brojZnamenki > 0) {
    brojZnamenki = 0;
    Serial.println();
    Serial.println("Reset unosa. Upisi PIN:");
  }

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
        otkljucaj();
      } else {
        Serial.println("PIN kriv");
      }

      brojZnamenki = 0;
      Serial.println("Upisi PIN:");
    }
  }
}

void otkljucaj() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  for (int i = 0; i < 8; i++) {
    tone(6, melodija[i], 200);
    delay(250);
  }
  noTone(6);

  digitalWrite(13, LOW);
  pinMode(13, INPUT_PULLUP);
}