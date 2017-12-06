#include <Arduino.h>

/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 13;
int greenPin = 12;
int bluePin = 11;
int val;

#define INTMAX 20

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void setColor(int red, int green, int blue)
{


  red = INTMAX;
  blue = 0;
  green = INTMAX;
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);


  for (val = 0; val < INTMAX; val++){
    analogWrite(redPin, val);
    analogWrite(greenPin, INTMAX - val);
    delay(100);
  }


  for (val = 0; val < INTMAX; val++){
    analogWrite(redPin, INTMAX - val);
    analogWrite(bluePin, val);
    delay(100);
  }

  for (val = 0; val < INTMAX; val++){
    analogWrite(greenPin, val);
    analogWrite(bluePin, INTMAX - val);
    delay(100);
  }





}

void random(){
  
}

void loop()
{
  setColor(50, 0, 0);  // red
  delay(1000);
  setColor(0, 50, 0);  // green
  delay(1000);
  setColor(0, 0, 50);  // blue
  delay(1000);
  setColor(50, 50, 0);  // yellow
  delay(1000);
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 50, 50);  // aqua
  delay(1000);
}
