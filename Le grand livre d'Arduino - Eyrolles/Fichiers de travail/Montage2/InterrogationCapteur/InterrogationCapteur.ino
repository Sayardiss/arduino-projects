/*
Auteur :      Erik Bartmann
Nom :         Interrogation d'un capteur
Version :     1.0
Références :  http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/DigitalRead
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/If
              http://arduino.cc/en/Reference/Else
*/ 
int ledPin = 13;   // LED en broche 13
int buttonPin = 8; // Bouton-poussoir en broche 8
int buttonState;   // Variable pour enregistrer l'état du bouton
void setup(){
  pinMode(ledPin, OUTPUT);   // Broche LED en tant que sortie
  pinMode(buttonPin, INPUT); // Broche bouton-poussoir en tant qu'entrée
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
