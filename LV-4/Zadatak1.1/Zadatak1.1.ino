void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(3) == LOW) {
    Serial.println("Crvena");
  }
  if (digitalRead(4) == LOW) {
    Serial.println("Zuta");
  }
  if (digitalRead(5) == LOW) {
    Serial.println("Zelena");
  }
  delay(100);
}