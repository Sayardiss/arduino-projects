#ifndef Dice_h
#define Dice_h
#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif
class Dice{
public:
  Dice(int, int, int, int); // Constructeur
  void roll(); // Méthode pour lancer le dé
private:
  int GroupA; // Variable membre pour groupe de LED A
  int GroupB; // Variable membre pour groupe de LED B
  int GroupC; // Variable membre pour groupe de LED C
  int GroupD; // Variable membre pour groupe de LED D
};
#endif
