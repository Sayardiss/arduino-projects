#ifndef MYANALOGKEYPAD_H
#define MYANALOGKEYPAD_H
#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#define KEY_NOT_PRESSED '-' // Nécessaire si aucune touche n'est appuyée
#define KEY_1 '1'
#define KEY_2 '2'
#define KEY_3 '3'
#define KEY_4 '4'
#define KEY_5 '5'
#define KEY_6 '6'
#define KEY_7 '7'
#define KEY_8 '8'
#define KEY_9 '9'
#define KEY_0 '0'
#define KEY_STAR '*'
#define KEY_HASH '#'

class MyAnalogKeyPad{
  public:
    MyAnalogKeyPad(byte analogPin);  // Constructeur paramétré
    void setDebounceTime(unsigned int debounceTime); // Réglage du temps de rebond
    void setThresholdValue(byte tv); // Réglage du seuil de tolérance
    char readKey();                  // Détermine la touche appuyée sur le clavier numérique
  private:
    byte analogPin;            // Broche analogique pour l'enregistrement des valeurs mesurées
    unsigned int debounceTime; // Variable locale pour temps de rebond
    long lastValue;            // Dernière valeur de la fonction millis
    byte threshold;            // Valeur de tolérance
};
#endif
