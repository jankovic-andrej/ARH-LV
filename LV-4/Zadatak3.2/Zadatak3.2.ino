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

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop(){
  char customKey = customKeypad.getKey();

  if (customKey){
    Serial.println(customKey);

    switch (customKey) {
      case '1': tone(6, 262, 200); break;
      case '2': tone(6, 294, 200); break;
      case '3': tone(6, 330, 200); break;
      case '4': tone(6, 349, 200); break;
      case '5': tone(6, 392, 200); break;
      case '6': tone(6, 440, 200); break;
      case '7': tone(6, 494, 200); break;
      case '8': tone(6, 523, 200); break;
      case '9': tone(6, 587, 200); break;
      case '*': tone(6, 659, 200); break;
      case '0': tone(6, 698, 200); break;
      case '#': tone(6, 784, 200); break;
    }
  }
}