/*
Auteur :       Erik Bartmann
Nom :          Le dé électronique
Version:       1.0
Références :   http://arduino.cc/en/Reference/Array
               http://arduino.cc/en/Reference/PinMode
               http://arduino.cc/en/Reference/Constants
               http://arduino.cc/en/Reference/DigitalWrite
               http://arduino.cc/en/Reference/Delay
               http://arduino.cc/en/Reference/For              
*/
#define WAITTIME 20
int pips[6][7] = {{0, 0, 0, 1, 0, 0, 0},   // Nombre sorti 1
                   {1, 0, 0, 0, 0, 0, 1},  // Nombre sorti 2
                   {1, 0, 0, 1, 0, 0, 1},  // Nombre sorti 3
                   {1, 0, 1, 0, 1, 0, 1},  // Nombre sorti 4
                   {1, 0, 1, 1, 1, 0, 1},  // Nombre sorti 5
                   {1, 1, 1, 0, 1, 1, 1}}; // Nombre sorti 6
int pin[] = {2, 3, 4, 5, 6, 7, 8};
int pinOffset = 2;   // Première LED sur broche 2
int buttonPin = 13;  // Bouton-poussoir sur broche 13

void setup(){
  for(int i = 0; i < 7; i++)
    pinMode(pin[i], OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop(){
  if(digitalRead(buttonPin) == HIGH)
    displayPips(random(1, 7)); // Générer un nombre entre 1 et 6 
}

void displayPips(int value){
  for(int i = 0; i < 7; i++)
  digitalWrite(i + pinOffset, (pips[value - 1][i] == 1)?HIGH:LOW);
  delay(WAITTIME); // Ajouter une courte pause 
}
