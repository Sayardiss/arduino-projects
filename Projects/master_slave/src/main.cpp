#include <Arduino.h>

// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

char *morse[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };


#include <Wire.h>

void printMorse(char c){
  char car;
  if (c >= 'a' && c <= 'z'){
    c = c-'a';
    char* str = morse[c];
    while(*str){
      car = *str;

      digitalWrite(2, HIGH);
      if(car == '.'){
        delay(200);
      } else {
        delay(500);
      }
      digitalWrite(2, LOW);
      delay(500);

      str++;
    }
  }
}

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  pinMode(2, OUTPUT);

}

void loop() {
  Wire.requestFrom(8, 6);    // request 6 bytes from slave device #8
  //digitalWrite(2, LOW);

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    // digitalWrite(2, (c=='H') ? HIGH: LOW);
    // delay(500);
    // digitalWrite(2, LOW);
    printMorse(c);
    Serial.print(c);         // print the character
  }

  //delay(2000);
  //digitalWrite(2, HIGH);
  delay(500);
}
