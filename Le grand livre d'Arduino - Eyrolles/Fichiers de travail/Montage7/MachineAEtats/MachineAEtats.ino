/*
Auteur :      Erik Bartmann
Nom :         La machine à états
Version :     1.0
Références :  http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/DigitalWrite
              http://arduino.cc/en/Reference/Delay
*/
#define DELAY1 10000  // Pause 1, 10 secondes
#define DELAY2 2000   // Pause 2, 2 secondes
#define DELAY3 3000   // Pause 3, 3 secondes
int ledPinRed = 7;    // Broche 7 commande la LED rouge
int ledPinOrange = 6; // Broche 6 commande la LED orange
int ledPinGreen = 5;  // Broche 5 commande la LED verte

void setup(){
  pinMode(ledPinRed, OUTPUT);    // Broche comme sortie
  pinMode(ledPinOrange, OUTPUT); // Broche comme sortie
  pinMode(ledPinGreen, OUTPUT);  // Broche comme sortie
}

void loop(){
  digitalWrite(ledPinRed, HIGH);    // Allumage LED rouge
  delay(DELAY1);                    // Attendre 10 secondes 
  digitalWrite(ledPinOrange, HIGH); // Allumage LED orange
  delay(DELAY2);                    // Attendre 2 secondes 
  digitalWrite(ledPinRed, LOW);     // Extinction LED rouge
  digitalWrite(ledPinOrange, LOW);  // Extinction LED orange
  digitalWrite(ledPinGreen, HIGH);  // Allumage LED verte
  delay(DELAY1);                    // Attendre 10 secondes 
  digitalWrite(ledPinGreen, LOW);   // Extinction LED verte
  digitalWrite(ledPinOrange, HIGH); // Allumage LED orange
  delay(DELAY3);                    // Attendre 3 secondes 
  digitalWrite(ledPinOrange, LOW);  // Extinction LED orange
}
