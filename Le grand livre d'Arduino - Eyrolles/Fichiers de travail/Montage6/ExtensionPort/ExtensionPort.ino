/*
Auteur :      Erik Bartmann
Nom :         Extension de port
Version :     1.0
Références :  http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/DigitalWrite
              http://arduino.cc/en/Reference/Delay              
*/
int shiftPin = 8;   // SH_CP
int storagePin = 9; // ST_CP
int dataPin = 10;   // DS

void setup(){
  pinMode(shiftPin, OUTPUT);
  pinMode(storagePin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  resetPins(); // Mise de toutes les broches sur LOW 
  // Mise de DS sur HIGH pour reprise ultérieure par SH_CP
  digitalWrite(dataPin, HIGH); // DS
  delay(20); // Brève pause avant traitement
  // Transmission du niveau à DS dans registres mémoire internes
  digitalWrite(shiftPin, HIGH); // SH_CP
  delay(20); // Brève pause avant traitement
  // Transmission des registres mémoire internes aux sorties
  digitalWrite(storagePin, HIGH); // ST_CP
  delay(20);
}

void loop(){/* vide */}

// Réinitialisation de toutes les broches -> niveau LOW
void resetPins(){
  digitalWrite(shiftPin, LOW);
  digitalWrite(storagePin, LOW);
  digitalWrite(dataPin, LOW);
}
