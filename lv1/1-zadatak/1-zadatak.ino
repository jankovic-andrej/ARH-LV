void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

}
int check = 0;
void loop() {
  // put your main code here, to run repeatedly:
  delay(100);


  check = 0;
  if(digitalRead(2) == LOW)
  {
    Serial.println("1");
    check = 1;
  }
  if(digitalRead(3) == LOW)
  {
    Serial.println("2");
    check = 1;
  }
  if(digitalRead(4) == LOW)
  {
    Serial.println("3");
    check = 1;
  }
  if(digitalRead(5) == LOW)
  {
    Serial.println("4");
    check = 1;
  }

  int analogValue = analogRead(14);

  if(analogValue > 900)
  {
     Serial.println("5");
    check = 1;
  }

  else if(analogValue > 700)
  {
    Serial.println("6");
    check = 1;
  }
  else if(analogValue > 500)
  {
     Serial.println("7");
    check = 1;
  }
  else if(analogValue > 300)
  {
     Serial.println("8");
    check = 1;
  }



  if(check == 0)
  {
    Serial.println("0");
  }



}