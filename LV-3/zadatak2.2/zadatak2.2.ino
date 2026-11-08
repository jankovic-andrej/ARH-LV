String str;
String boja = "zuta";
String boje[6] = {"crvena", "plava", "zuta", "zelena", "ljubicasta", "bijela"};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    char c = Serial.read();
    if(c == '\n')
    {
      char x[20];
      if(sscanf(str.c_str() , "%19s", x) == 1)
      {
        for(int i = 0;i<6; i++)
        {
          if(String(x) == boje[i])
          {
            boja = x;
          }
        }
      }
      str = "";
    }else{
      str += c;
    }

  }


  if(boja == "crvena"){
      analogWrite(3, 0);
      analogWrite(5, 255);
      analogWrite(6, 255);

    }else if(boja == "plava")
    {
      analogWrite(3, 255);
      analogWrite(5, 255);
      analogWrite(6, 0);

    }else if(boja == "zuta")
    {
      analogWrite(3, 0);
      analogWrite(5, 0);
      analogWrite(6, 255);

    }else if(boja == "zelena")
    {
      analogWrite(3, 255);
      analogWrite(5, 0);
      analogWrite(6, 255);

    }else if(boja == "ljubicasta")
    {
      analogWrite(3, 0);
      analogWrite(5, 255);
      analogWrite(6, 0);

    }else if(boja == "bijela")
    {
      analogWrite(3, 0);
      analogWrite(5, 0);
      analogWrite(6, 0);

    }
}
