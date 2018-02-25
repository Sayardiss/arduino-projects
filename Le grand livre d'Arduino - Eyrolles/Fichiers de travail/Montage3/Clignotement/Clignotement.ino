/*
Auteur :      Erik Bartmann
Nom :         Clignotement avec gestion des intervalles
Version :     1.0
Références :  http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/If
              http://arduino.cc/en/Reference/Else
              http://arduino.cc/en/Reference/DigitalWrite
              http://arduino.cc/en/Reference/DigitalRead
              http://arduino.cc/en/Reference/Millis
*/
int ledPinBlink = 13;  // LED clignotante rouge en broche 13
int ledPinButton = 10; // LED de bouton-poussoir jaune en broche 10
int buttonPin = 8;     // Bouton-poussoir en broche 8
int buttonState;       // Variable pour enregistrement de l'état du bouton-poussoir
int interval = 2000;   // Intervalle de temps (2 secondes)
unsigned long prev;    // Variable de temps
int ledState = LOW;    // Variable d'état pour la LED clignotante
void setup(){
  pinMode(ledPinBlink, OUTPUT);  // Broche LED clignotante comme sortie
  pinMode(ledPinButton, OUTPUT); // Broche LED de bouton-poussoir comme sortie
  pinMode(buttonPin, INPUT);     // Broche bouton-poussoir comme entrée
  prev = millis();               // Mémoriser le compteur de temps actuel
}
void loop(){
  // Faire clignoter la LED clignotante via la gestion des intervalles
  if((millis() - prev) > interval){
    prev = millis();
    ledState = !ledState; // Bascule état de la LED
    digitalWrite(ledPinBlink, ledState); // Bascule la LED rouge
  }  
  // Interrogation de l'état du bouton-poussoir
  buttonState = digitalRead (buttonPin);
  if(buttonState == HIGH)
    digitalWrite(ledPinButton, HIGH); // LED jaune au niveau HIGH (5 V)
  else
    digitalWrite(ledPinButton, LOW);  // LED jaune au niveau LOW (0 V)
}


