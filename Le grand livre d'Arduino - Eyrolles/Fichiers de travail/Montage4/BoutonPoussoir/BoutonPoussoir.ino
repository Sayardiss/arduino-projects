/*
Auteur :      Erik Bartmann
Nom :         Le bouton-poussoir récalcitrant
Version :     1.0
Références :  http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/If
              http://arduino.cc/en/Reference/Else
              http://arduino.cc/en/Reference/DigitalWrite
              http://arduino.cc/en/Reference/DigitalRead
              http://arduino.cc/en/Reference/Modulo
*/
int buttonPin = 2;           // Bouton-poussoir en broche 2
int buttonValue = 0;         // Variable pour enregistrer l'état du bouton-poussoir
int previousButtonValue = 0; // Variable pour enregistrer l'ancien état du bouton-poussoir
int ledPin = 8;              // LED en broche 8
int counter = 0;             // Variable de compteur
void setup(){
  pinMode(buttonPin, INPUT); // Broche bouton-poussoir comme entrée
  pinMode(ledPin, OUTPUT);   // Broche LED comme sortie
}

void loop(){
  buttonValue = digitalRead(buttonPin); // Interrogation du bouton-poussoir
  // La valeur précédente du bouton-poussoir est-elle différente de la valeur actuelle ?
  if(previousButtonValue != buttonValue){
    if(buttonValue == HIGH){
      counter++; // Incrémentation du compteur(+1)
    }
  }
  previousButtonValue = buttonValue; // Sauvegarde de la valeur actuelle du bouton-poussoir
  if(counter%2 == 0)                 // La variable du compteur est-elle un nombre pair ?
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}



