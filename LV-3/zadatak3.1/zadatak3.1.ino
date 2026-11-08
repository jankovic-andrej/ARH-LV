  #include<Adafruit_NeoPixel.h>
  #define PIN 8
  #define NUMPIXELS 1
  Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

  String str;
  int color[4] = {255,255,255, 255};
  void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pixels.begin();
    pixels.setBrightness(color[3]);
  }

  void loop() {
    // put your main code here, to run repeatedly:
    if(Serial.available())
    {
      char c = Serial.read();
      if(c == '\n')
      {
        int x[4];
        if(sscanf(str.c_str(), "%d,%d,%d,%d", &x[0], &x[1], &x[2], &x[3]) == 4)
        {
          if(x[0] >= 0 && x[0] < 256 && x[1] >= 0 && x[1] < 256 && x[2] >= 0 && x[2] < 256 && x[3] >= 0 && x[3] < 256)
          {
            color[0] = x[0];
            color[1] = x[1];
            color[2] = x[2]; 
            color[3] = x[3]; 
          }
        }
        str = "";
      }else{
        str += c;
      }
    }

    
    
    pixels.setPixelColor(0, pixels.Color(color[0], color[1], color[2]));
    pixels.setBrightness(color[3]);
    pixels.show();
  }
