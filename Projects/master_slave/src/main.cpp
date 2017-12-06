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

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


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

void receiveTemp(){
  char c1 = Wire.read();
  char c2 = Wire.read();
  char c3 = Wire.read();
  char c4 = Wire.read();

  Serial.print(c1);
  Serial.print(c2);
  Serial.print('.');
  Serial.print(c3);
  Serial.print(c4);

  Serial.print('\n');
}

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  pinMode(2, OUTPUT);


  lcd.begin(16, 2);
  lcd.print("Ask the");
  lcd.setCursor(0,1);
  lcd.print("Crystal Temp!");
}

void loop() {
  Wire.requestFrom(8, 4);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    receiveTemp();

    //int tmp = (lsb | (msb<<8));
    //float tmpFloat = tmp/100.0;
    // digitalWrite(2, (c=='H') ? HIGH: LOW);
    // delay(500);
    // digitalWrite(2, LOW);
    //
    //printMorse(c);
    //double tmp = ((double)c)/100.0;
    //Serial.print(tmpFloat);         // print the character

  }
  delay(4000);
}
