#include "MyKeyPad.h"
// Constructeur paramétré
MyKeyPad::MyKeyPad(int rowArray[], int colArray[]){
  // Copier le tableau des broches
  for(int r = 0; r < 4; r++)
    row[r] = rowArray[r];
  for(int c = 0; c < 3; c++)
    col[c] = colArray[c];
  // Programmation des broches numériques
  for(int r = 0; r < 4; r++)
    pinMode(row[r], OUTPUT);
  for(int c = 0; c < 3; c++)
    pinMode(col[c], INPUT);
  // Définition initiale de debounceTime à 300 ms
  debounceTime = 300;
}

// Méthode pour régler le temps de rebond
void MyKeyPad::setDebounceTime(unsigned int time){
   debounceTime = time;
}

// Méthode pour déterminer la touche appuyée sur le clavier numérique
char MyKeyPad::readKey(){
  char key = KEY_NOT_PRESSED;
  for(int r = 0; r < 4; r++){
    digitalWrite(row[r], HIGH);
    for(int c = 0; c < 3; c++){
      if((digitalRead(col[c]) == HIGH)&&(millis() - lastValue) >= debounceTime){
        if((c==2)&&(r==3)) key = KEY_1;
        if((c==1)&&(r==3)) key = KEY_2;
        if((c==0)&&(r==3)) key = KEY_3;
        if((c==2)&&(r==2)) key = KEY_4;
        if((c==1)&&(r==2)) key = KEY_5;
        if((c==0)&&(r==2)) key = KEY_6;
        if((c==2)&&(r==1)) key = KEY_7;
        if((c==1)&&(r==1)) key = KEY_8;
        if((c==0)&&(r==1)) key = KEY_9;
        if((c==2)&&(r==0)) key = KEY_STAR; // *
        if((c==1)&&(r==0)) key = KEY_0;
        if((c==0)&&(r==0)) key = KEY_HASH; // #
        lastValue = millis();
      }
    }
  digitalWrite(row[r], LOW); // Restauration du niveau initial
  }
  return key;
}
