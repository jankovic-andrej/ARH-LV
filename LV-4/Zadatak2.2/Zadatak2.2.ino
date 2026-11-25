#include <Keypad.h>

const byte ROWS = 1;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {{'1', '2', '3'}};
byte rowPins[ROWS] = {A3};
byte colPins[COLS] = {A0, A1, A2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char tipka = 0;
int jacina = 0;
unsigned long zadnjeVrijeme = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  customKeypad.addEventListener(keypadEvent);
  customKeypad.setHoldTime(500);
}

void loop() {
  customKeypad.getKey();

  if (customKeypad.getState() == HOLD && millis() - zadnjeVrijeme >= 1000) {
    zadnjeVrijeme = millis();
    jacina = jacina + 51;
    if (jacina > 255) jacina = 255;
    prikaziBoju();
  }
}

void keypadEvent(KeypadEvent key) {
  switch (customKeypad.getState()) {
    case PRESSED:
      tipka = key;
      jacina = 51;
      Serial.println("PRESSED");
      prikaziBoju();
      break;

    case HOLD:
      zadnjeVrijeme = millis();
      jacina = jacina + 51;
      if (jacina > 255) jacina = 255;
      Serial.println("HOLD");
      prikaziBoju();
      break;

    case RELEASED:
      tipka = 0;
      jacina = 0;
      Serial.println("RELEASED");
      prikaziBoju();
      break;
  }
}

void prikaziBoju() {
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);

  if (tipka == '1') {
    analogWrite(9, jacina);
  }
  if (tipka == '2') {
    analogWrite(9, jacina);
    analogWrite(10, jacina);
  }
  if (tipka == '3') {
    analogWrite(10, jacina);
  }
}