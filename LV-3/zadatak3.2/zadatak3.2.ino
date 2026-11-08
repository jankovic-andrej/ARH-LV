#include<Adafruit_NeoPixel.h>
#define PIN 14
#define NUMPIXELS 10
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int color[5] = {0, 255, 255, 255, 30};
String str;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pixels.begin();
    pixels.setBrightness(color[4]);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
    {
      char c = Serial.read();
      if(c == '\n')
      {
        int x[5];
        if(sscanf(str.c_str(), "%d,%d,%d,%d,%d", &x[0], &x[1], &x[2], &x[3], &x[4]) == 5)
        {
          if(x[0] >= 0 && x[0] <=9  && x[1] >= 0 && x[1] < 256 && x[2] >= 0 && x[2] < 256 && x[3] >= 0 && x[3] < 256 && x[4] >= 0 && x[4] < 256)
          {
            color[0] = x[0];
            color[1] = x[1];
            color[2] = x[2]; 
            color[3] = x[3];
            color[4] = x[4];  
          }
        }
        str = "";
      }else{
        str += c;
      }
    }
    pixels.setBrightness(color[4]);
    pixels.setPixelColor(color[0], pixels.Color(color[1], color[2], color[3]));
    pixels.show();
}
