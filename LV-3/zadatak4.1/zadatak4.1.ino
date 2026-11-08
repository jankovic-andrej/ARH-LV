#include<Adafruit_NeoPixel.h>
#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11

#define PIN 14
#define NUMPIXELS 10
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pixels.begin();
    pixels.setBrightness(30);
    dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float t = dht.readTemperature();

  int n = map(t, 15, 35, 0, 10);
  n = constrain(n, 0, 10);
  Serial.println(t);
  pixels.clear();
  for(int i = 0; i<10; i++)
  {
    if(i<n)
    {
      pixels.setPixelColor(i, 0, 255, 255);
    }
  }
  pixels.show();


}
