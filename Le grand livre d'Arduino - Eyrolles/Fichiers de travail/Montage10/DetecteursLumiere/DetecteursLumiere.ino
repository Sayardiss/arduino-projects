/*
Auteur :       Erik Bartmann
Nom :          Des détecteurs de lumière
Version :      1.0
Références :   http://arduino.cc/en/Reference/PinMode
               http://arduino.cc/en/Reference/Constants
               http://arduino.cc/en/Reference/For
               http://arduino.cc/en/Reference/DigitalWrite
               http://arduino.cc/en/Reference/Array
               http://arduino.cc/en/Reference/Map
*/
int pin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // Tableau des broches
int analogPin = 0;   // Broche de l'entrée analogique
int analogValue = 0; // Stocke la valeur analogique mesurée

void setup(){
  for(int i = 0; i < 10; i++)
    pinMode(pin[i], OUTPUT);
}

void loop(){
  analogValue = analogRead(analogPin);
  controlLEDs(analogValue);
}

// Fonction pour commander les LED
void controlLEDs(int value){
  int bargraphValue = map(value, 0, 1023, 0, 9);
  for(int i = 0; i < 10; i++)
    digitalWrite(pin[i], (bargraphValue >= i)?HIGH:LOW);
}
