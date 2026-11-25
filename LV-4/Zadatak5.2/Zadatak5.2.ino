void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long t = pulseIn(3, HIGH, 30000);
  float d = t * 0.034 / 2;

  Serial.print("d = ");
  Serial.print(d);
  Serial.println(" cm");

  if (t > 0 && d >= 5 && d <= 100) {
    int f = map(d, 5, 100, 2000, 200);
    int pauza = map(d, 5, 100, 50, 500);

    tone(6, f, 100);
    delay(100 + pauza);
  } else {
    noTone(6);
    delay(100);
  }
}