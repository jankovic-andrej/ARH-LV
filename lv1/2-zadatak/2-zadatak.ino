void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);

}

const int ledPins[8] = {8, 9, 10, 11, 12, 13, 14, 15};
void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
  int x = analogRead(21);
  int y = map(x, 0,1023, 0,8);

  for(int i = 0; i<8; i++)
  {
    if( i < y)
    {
      digitalWrite(ledPins[i], LOW);
    }
    else{
      digitalWrite(ledPins[i],HIGH);
    }
   
  }

  Serial.print("x = ");
  Serial.print(x);
  Serial.print("  y = ");
  Serial.println(y);

  



}