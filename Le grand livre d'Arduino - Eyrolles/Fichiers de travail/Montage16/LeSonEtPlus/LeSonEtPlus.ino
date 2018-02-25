/*
Auteur :      Erik Bartmann
Nom :         Le son et plus encore
Version :     1.0
Références :  http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/DigitalWrite
              http://arduino.cc/en/Reference/DelayMicroseconds
*/
#define piezoPin 13 // Élément piézoélectrique sur broche 13
#define DELAY 1000
void setup(){
  pinMode(piezoPin, OUTPUT);
}

void loop(){
  digitalWrite(piezoPin, HIGH); delayMicroseconds(DELAY);
  digitalWrite(piezoPin, LOW); delayMicroseconds(DELAY);
}
