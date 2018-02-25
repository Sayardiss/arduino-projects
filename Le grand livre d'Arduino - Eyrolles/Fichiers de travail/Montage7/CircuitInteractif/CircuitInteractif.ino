/*
Auteur :      Erik Bartmann
Nom :         La machine à états (circuit interactif)
Version :     1.0
*/
#define DELAY0 10000        // Pause 0, 10 secondes
#define DELAY1 1000         // Pause 1, 1 seconde
#define DELAY2 2000         // Pause 2, 2 secondes
#define DELAY3 3000         // Pause 3, 3 secondes
int ledPinRedDrive = 7;     // Broche 7 commande la LED rouge (feux pour automobilistes)
int ledPinOrangeDrive = 6;  // Broche 6 commande la LED orange (feux pour automobilistes)
int ledPinGreenDrive = 5;   // Broche 5 commande la LED verte (feux pour automobilistes)
int ledPinRedWalk = 3;      // Broche 3 commande la LED rouge (feux pour piétons)
int ledPinGreenWalk = 2;    // Broche 2 commande la LED verte (feux pour piétons)
int buttonPinLight = 8;     // Bouton gérant les feux reliés à la broche 8
int buttonLightValue = LOW; // Variable pour l'état du bouton gérant les feux

void setup(){
  pinMode(ledPinRedDrive, OUTPUT);      // Broche comme sortie
  pinMode(ledPinOrangeDrive, OUTPUT);   // Broche comme sortie
  pinMode(ledPinGreenDrive, OUTPUT);    // Broche comme sortie
  pinMode(ledPinRedWalk, OUTPUT);       // Broche comme sortie
  pinMode(ledPinGreenWalk, OUTPUT);     // Broche comme sortie
  pinMode(buttonPinLight, INPUT);       // Broche comme entrée
  digitalWrite(ledPinGreenDrive, HIGH); // Valeurs de départ (vert pour automobilistes)
  digitalWrite(ledPinRedWalk, HIGH);    // Valeurs de départ (rouge pour piétons)
}
void loop(){
  // Lire l'état du bouton gérant les feux dans la variable
  buttonLightValue = digitalRead (buttonPinLight);
  // Si bouton appuyé, fonction appelée
  if(buttonLightValue == HIGH)
    lightChange();
}
void lightChange(){
  digitalWrite(ledPinGreenDrive, LOW);
  digitalWrite(ledPinOrangeDrive, HIGH); delay(DELAY3);
  digitalWrite(ledPinOrangeDrive, LOW);
  digitalWrite(ledPinRedDrive, HIGH); delay(DELAY1);
  digitalWrite(ledPinRedWalk, LOW);
  digitalWrite(ledPinGreenWalk, HIGH); delay(DELAY0);
  digitalWrite(ledPinGreenWalk, LOW);
  digitalWrite(ledPinRedWalk, HIGH); delay(DELAY1);
  digitalWrite(ledPinOrangeDrive, HIGH); delay(DELAY2);
  digitalWrite(ledPinRedDrive, LOW);
  digitalWrite(ledPinOrangeDrive, LOW);
  digitalWrite(ledPinGreenDrive, HIGH);
}
