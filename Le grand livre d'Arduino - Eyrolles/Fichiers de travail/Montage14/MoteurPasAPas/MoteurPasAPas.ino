/*
Auteur :       Erik Bartmann
Nom :          Le moteur pas-à-pas
Version :      1.0
Références :   http://arduino.cc/en/Reference/Array
               http://arduino.cc/en/Reference/PinMode
               http://arduino.cc/en/Reference/Constants
               http://arduino.cc/en/Reference/For
               http://arduino.cc/en/Reference/If
               http://arduino.cc/en/Reference/DigitalWrite
               http://arduino.cc/en/Reference/Delay
*/
#define Stepper_A1 5 // Broche pour connexion A1
#define Stepper_A3 4 // Broche pour connexion A3
#define Stepper_B1 3 // Broche pour connexion B1
#define Stepper_B3 2 // Broche pour connexion B3

byte stepValues[5][4] = {{LOW, LOW, LOW, LOW},    // Moteur à l'arrêt
                         {LOW, HIGH, HIGH, LOW},  // Pas 1
                         {LOW, HIGH, LOW, HIGH},  // Pas 2
                         {HIGH, LOW, LOW, HIGH},  // Pas 3
                         {HIGH, LOW, HIGH, LOW}}; // Pas 4
void setup(){
  pinMode(Stepper_A1, OUTPUT);
  pinMode(Stepper_A3, OUTPUT);
  pinMode(Stepper_B1, OUTPUT);
  pinMode(Stepper_B3, OUTPUT);
  for(int i = 0; i < 10; i++){
    action(30, 2);   // 30 pas vers la droite avec pause de 2 ms 
    action(-30, 10); // 30 pas vers la gauche avec pause de 10 ms 
  }
  action(0, 0);      // Mise hors courant
}

void loop(){/* vide */}

void action(int count, byte delayValue){
  if(count > 0) // Rotation vers la droite
    for(int i = 0; i < count; i++)
      for(int sequenceStep = 1; sequenceStep <= 4; sequenceStep++)
        moveStepper(sequenceStep, delayValue);
  if(count < 0) // Rotation vers la gauche
    for(int i = 0; i < abs(count); i++)
      for(int sequenceStep = 4; sequenceStep > 0; sequenceStep--)
        moveStepper(sequenceStep, delayValue);
  if(count == 0) // Mise hors courant
    moveStepper(0, delayValue);
}
  
void moveStepper(byte s, byte delayValue){
  digitalWrite(Stepper_A1, stepValues[s][0]);
  digitalWrite(Stepper_A3, stepValues[s][1]);
  digitalWrite(Stepper_B1, stepValues[s][2]);
  digitalWrite(Stepper_B3, stepValues[s][3]);
  delay(delayValue); // Pause
}
