/*
Auteur :       Erik Bartmann
Nom :          Bibliothèque-dé
Version :      1.0
Références :   http://arduino.cc/en/Reference/PinMode
               http://arduino.cc/en/Reference/Constants
               http://arduino.cc/en/Reference/If
               http://arduino.cc/en/Reference/DigitalRead
*/

#include "Dice.h"

Dice myDice(8, 9, 10, 11);

void setup(){
  pinMode(13, INPUT); // Pas obligatoire - oui mais pourquoi ?
}
void loop(){
  if(digitalRead(13) == HIGH)
              myDice.roll();
}
