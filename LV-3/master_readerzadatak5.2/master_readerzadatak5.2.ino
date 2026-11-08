// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#define ADRESA 

void setup() {
  Wire.begin();        // join I2C bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(ADRESA, 2);    // request 6 bytes from slave device #8

  byte x[2];
  int i = 0;
  while (Wire.available() && i<2) { // slave may send less than requested
    x[i] = Wire.read(); // receive a byte as character
    i++;
  }

  if (i == 2) {
    int vrijednost = x[0] | x[1] << 8;
    Serial.println(vrijednost);
  }

  delay(100);
}
