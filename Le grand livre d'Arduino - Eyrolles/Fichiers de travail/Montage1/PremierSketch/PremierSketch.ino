/*
Auteur :       Erik Bartmann
Nom :          Premier sketch 
Version :      1.0
Références :   http://arduino.cc/en/Reference/DigitalWrite
               http://arduino.cc/en/Reference/Delay
*/
int ledPin = 13; // Déclarer + initialiser broche numérique 13 comme sortie
void setup(){
  pinMode(ledPin, OUTPUT); // Broche numérique 13 comme sortie
}

void loop(){
  digitalWrite(ledPin, HIGH); // LED au niveau HIGH (5 V)
  delay(1000);                // Attendre une seconde
  digitalWrite(ledPin, LOW);  // LED au niveau LOW (0 V)
  delay(1000);                // Attendre une seconde
}
