/*
Auteur :       Erik Bartmann
Nom :          Le clavier numérique
Version :      1.0
Références :   http://arduino.cc/en/Reference/Serial
               http://arduino.cc/en/Reference/If
*/
#include "MyKeyPad.h"
int rowArray[] = {2, 3, 4, 5};            // Initialiser le tableau avec les numéros de broche des lignes
int colArray[] = {6, 7, 8};               // Initialiser le tableau avec les numéros de broche des colonnes
MyKeyPad myOwnKeyPad(rowArray, colArray); // Instanciation d'un objet

void setup(){
  Serial.begin(9600);               // Préparer la sortie série
  myOwnKeyPad.setDebounceTime(500); // Régler le temps du rebond à 500 ms 
}

void loop(){
  char myKey = myOwnKeyPad.readKey(); // Lecture de la touche appuyée
  if(myKey != KEY_NOT_PRESSED)        // Une touche quelconque a-t-elle été appuyée ?
    Serial.println(myKey);            // Impression du caractère de la touche
}

