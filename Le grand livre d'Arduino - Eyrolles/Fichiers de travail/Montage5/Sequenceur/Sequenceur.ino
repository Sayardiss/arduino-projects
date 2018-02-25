/*
Auteur :      Erik Bartmann
Nom :         Le séquenceur de lumière
Version :     1.0
Références :  http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/For
              http://arduino.cc/en/Reference/DigitalWrite
              http://arduino.cc/en/Reference/Delay
*/
int ledPin[] = {7, 8, 9, 10, 11, 12, 13}; // Tableau de LED avec numéros des broches
int waitTime = 200; // Pause entre les changements en ms
void setup(){
  for(int i = 0; i < 7; i++)
    pinMode(ledPin[i], OUTPUT); // Toutes les broches du tableau comme sorties
}
void loop(){
  for(int i = 0; i < 7; i++){
    digitalWrite(ledPin[i], HIGH); // Élément du tableau au niveau HIGH
    delay(waitTime);
    digitalWrite(ledPin[i], LOW);  // Élément du tableau au niveau LOW
  }
}
