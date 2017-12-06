#include <Arduino.h>

#define RED1 2
#define YEL1 3
#define GRE1 4

#define RED2 10
#define YEL2 11
#define GRE2 12



int switchState = 0;

void gettingRed(int greenPin, int yellowPin, int redPin){
  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);

  delay(1000);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(redPin, LOW);
}

void setGreen(int greenPin, int yellowPin, int redPin){
  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);
}


void setup(){
  pinMode(RED1, OUTPUT);
  pinMode(YEL1, OUTPUT);
  pinMode(GRE1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(YEL2, OUTPUT);
  pinMode(GRE2, OUTPUT);

  gettingRed(GRE1, YEL1, RED1);
  gettingRed(GRE2, YEL2, RED2);
}

void loop(){
  setGreen(GRE1, YEL1, RED1);
  delay(5000);

  gettingRed(GRE1, YEL1, RED1);
  delay(1000);

  setGreen(GRE2, YEL2, RED2);
  delay(5000);

  gettingRed(GRE2, YEL2, RED2);
  delay(1000);
}
