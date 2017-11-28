/*
  Arduino Starter Kit example
 Project 11  - Crystal Ball

 This sketch is written to accompany Project 11 in the
 Arduino Starter Kit

 Parts required:
 220 ohm resistor
 10 kilohm resistor
 10 kilohm potentiometer
 16x2 LCD screen
 tilt switch


 Created 13 September 2012
 by Scott Fitzgerald

 http://arduino.cc/starterKit

 This example code is part of the public domain
 */

// include the library code:
#include <LiquidCrystal.h>
#include <Arduino.h>

const int sensorPin = A0;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);

  // Print a message to the LCD.
  lcd.print("Temperature is");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
}

void loop() {

  lcd.setCursor(0, 1);
  // read the value on AnalogIn pin 0
  // and store it in a variable
  int sensorVal = analogRead(sensorPin);

  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 3.3;
  float temperature = (voltage - .5) * 100;

  lcd.print(temperature);
  lcd.print("*C");
  delay(2000);
}
