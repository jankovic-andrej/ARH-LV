String str;
int ms = 500;
unsigned long zadnje = 0;
bool stanje = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    char c = Serial.read();
    if(c == '\n')
    {
      int a;
      if (sscanf(str.c_str(), "%d", &a) == 1 && a > 0) {
        ms = a;
        Serial.println(ms);
      }
      str = "";
    }else{
      str +=c;
    }
  }


  if (millis() - zadnje >= ms) {
    zadnje = millis();
    stanje = !stanje;
    digitalWrite(13, stanje);
  }
}
