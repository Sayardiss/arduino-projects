/*
Auteur :       Erik Bartmann
Nom :          Numérique appelle analogique
Version :      1.0
Références :   http://arduino.cc/en/Reference/PinMode
               http://arduino.cc/en/Reference/Constants
               http://arduino.cc/en/Reference/For
               http://arduino.cc/en/Reference/DigitalWrite
               http://arduino.cc/en/Reference/BitRead
*/
int pinArray[] = {8, 9, 10, 11, 12, 13};
byte R2RPattern;

void setup(){
  for(int i = 0; i < 6; i++)
    pinMode(pinArray[i], OUTPUT);
  R2RPattern = B000001; // Configuration binaire pour commander les sorties numériques
}

void loop(){
  for(int i = 0; i < 6; i++){
    digitalWrite(pinArray[i], bitRead(R2RPattern, i) == 1?HIGH:LOW);
  }
}

