void setup() {
  Serial.begin(9600);

  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  pinMode(9, OUTPUT);   
  pinMode(10, OUTPUT);  
  pinMode(11, OUTPUT);  
}

void loop() {
  
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  if (digitalRead(3) == LOW) {        
    digitalWrite(9, HIGH);
    Serial.println("Crvena");
  }
  if (digitalRead(4) == LOW) {        
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    Serial.println("Zuta");
  }
  if (digitalRead(5) == LOW) {        
    digitalWrite(10, HIGH);
    Serial.println("Zelena");
  }

  delay(100);
}