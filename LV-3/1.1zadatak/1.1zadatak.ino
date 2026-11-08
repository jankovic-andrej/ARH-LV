String str;

void setup()
{
  Serial.begin(9600);
}

void loop(){
  if(Serial.available())
  {
    char c = Serial.read();
    if(c == '\n')
    {
      int a;
      sscanf(str.c_str(), "%d", &a);
      Serial.println(a);
      str = "";
    }else{
      str +=c;
    }
  }
}