#include "MyAnalogKeyPad.h"
// Constructeur paramétré
MyAnalogKeyPad::MyAnalogKeyPad(byte ap){
  // Broche analogique pour l'enregistrement des valeurs mesurées
  analogPin = ap;
  // Définition de la valeur initiale de debounceTime 
  debounceTime = 300;
  // Définition de la valeur de tolérance
  threshold = 5;
}

// Méthode pour régler le temps de rebond
void MyAnalogKeyPad::setDebounceTime(unsigned int time){
  debounceTime = time;    
}

// Méthode pour régler le seuil de tolérance
void MyAnalogKeyPad::setThresholdValue(byte tv){
  threshold = tv;    
}
  
// Méthode pour déterminer la touche appuyée sur le clavier numérique 
char MyAnalogKeyPad::readKey(){
  char key = KEY_NOT_PRESSED; 
  byte aValue = analogRead(analogPin);
  if((aValue > 0)&&(millis() - lastValue >= debounceTime)){
    if((aValue > (176 - threshold)) && (aValue < (176 + threshold))) key = KEY_1; 
    if((aValue > (163 - threshold)) && (aValue < (163 + threshold))) key = KEY_2;
    if((aValue > (149 - threshold)) && (aValue < (149 + threshold))) key = KEY_3;
    if((aValue > (136 - threshold)) && (aValue < (136 + threshold))) key = KEY_4;
    if((aValue > (122 - threshold)) && (aValue < (122 + threshold))) key = KEY_5;
    if((aValue > (108 - threshold)) && (aValue < (108 + threshold))) key = KEY_6;
    if((aValue > (94 - threshold)) && (aValue < (94 + threshold))) key = KEY_7;
    if((aValue > (79 - threshold)) && (aValue < (79 + threshold))) key = KEY_8;
    if((aValue > (64 - threshold)) && (aValue < (64 + threshold))) key = KEY_9;
    if((aValue > (48 - threshold)) && (aValue < (48 + threshold))) key = KEY_STAR;
    if((aValue > (32 - threshold)) && (aValue < (32 + threshold))) key = KEY_0;
    if((aValue > (15 - threshold)) && (aValue < (15 + threshold))) key = KEY_HASH;
    lastValue = millis();
  }
return key;
}
