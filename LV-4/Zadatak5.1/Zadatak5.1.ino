void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long t = pulseIn(3, HIGH);
  float d = t * 0.034 / 2;

  Serial.print("t = ");
  Serial.print(t);
  Serial.print(" us, d = ");
  Serial.print(d);
  Serial.println(" cm");

  delay(200);
}