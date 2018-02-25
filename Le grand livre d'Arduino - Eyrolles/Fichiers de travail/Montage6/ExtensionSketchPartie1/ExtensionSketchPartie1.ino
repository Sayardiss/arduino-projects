/*
Auteur :      Erik Bartmann
Nom :         Extension de port (extension du sketch, première partie)
Version :     1.0
Références :  http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/DigitalWrite
              http://arduino.cc/en/Reference/For              
*/
int shiftPin = 8;   // SH_CP
int storagePin = 9; // ST_CP
int dataPin = 10;   // DS
int dataArray[] = {1, 0, 1, 0, 1, 1, 0, 1};
void setup(){
  pinMode(shiftPin, OUTPUT);
  pinMode(storagePin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  resetPins(); // Mettre toutes les broches à LOW 
  putPins(dataArray); // Régler les broches sur le tableau de données
  // Transmission des registres mémoire internes aux sorties
  digitalWrite(storagePin, HIGH); // ST_CP
}

void loop(){/* vide */}

void resetPins(){
  digitalWrite(shiftPin, LOW);
  digitalWrite(storagePin, LOW);
  digitalWrite(dataPin, LOW);
}

void putPins(int data[]){
  for(int i = 0; i < 8; i++){
    resetPins();
    digitalWrite(dataPin, data[i]); delay(20);
    digitalWrite(shiftPin, HIGH); delay(20);
  }
}
