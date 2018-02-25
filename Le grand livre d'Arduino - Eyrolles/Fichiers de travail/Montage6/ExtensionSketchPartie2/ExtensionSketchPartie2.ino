/*
Auteur :      Erik Bartmann
Nom :         Extension de port (extension du sketch, deuxième partie)
Version :     1.0
Références :  http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/DigitalWrite
              http://arduino.cc/en/Reference/ShiftOut
              http://arduino.cc/en/Reference/Delay
*/
int shiftPin = 8;     // SH_CP
int storagePin = 9;   // ST_CP
int dataPin = 10;     // DS
byte Value = 157;     // Valeur à transférer

void setup(){
  pinMode(shiftPin, OUTPUT);
  pinMode(storagePin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop(){
  digitalWrite(storagePin, LOW);
  shiftOut(dataPin, shiftPin, MSBFIRST, Value);
  digitalWrite(storagePin, HIGH);
  delay(20);
}
