#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif
#include "Dice.h"
#define WAITTIME 20
// Constructeur paramétré
Dice::Dice(int A, int B, int C, int D){
  GroupA = A;
  GroupB = B;
  GroupC = C;
  GroupD = D;
  pinMode(GroupA, OUTPUT);
  pinMode(GroupB, OUTPUT);
  pinMode(GroupC, OUTPUT);
  pinMode(GroupD, OUTPUT);
}

// Méthode pour lancer le dé
void Dice::roll(){
  int number = random(1, 7);
  digitalWrite(GroupA, number%2!=0?HIGH:LOW);
  digitalWrite(GroupB, number>1?HIGH:LOW);
  digitalWrite(GroupC, number>3?HIGH:LOW);
  digitalWrite(GroupD, number==6?HIGH:LOW);
  delay(WAITTIME); // Ajouter une courte pause
}
