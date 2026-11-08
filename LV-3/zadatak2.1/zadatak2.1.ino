String str;

int smjer = 1;
int ms = 500;
int current_led = 8;

unsigned long zadnje = 0;

int pinovi[8] = {8,9,10,11,12,13,14,15};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int i = 0; i<=7; i++)
  {
    pinMode(pinovi[i], OUTPUT);
    digitalWrite(pinovi[i], HIGH);
  } 

  digitalWrite(current_led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char c = Serial.read();
    if(c == '\n'){
      int smjer1, ms1;
      if(sscanf(str.c_str(), "%d,%d", &smjer1, &ms1) == 2 && ms1 > 0 && (smjer1 == -1 || smjer1 == 1))
      {
        smjer = smjer1;
        ms = ms1;
      }
      str = "";

    }
    else{
      str += c;
    }
  }



  if (millis() - zadnje >= ms) {
    zadnje = millis();


    //gasi sve - pali sljedeci
    digitalWrite(current_led, HIGH);
    current_led += smjer;
    if(current_led > 15)
    {
      current_led = 8;
    }
    if(current_led <8)
    {
      current_led = 15;
    }
    digitalWrite(current_led, LOW);

    
  }
}
