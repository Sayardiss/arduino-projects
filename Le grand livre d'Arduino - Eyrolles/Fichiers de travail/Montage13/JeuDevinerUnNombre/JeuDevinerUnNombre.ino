/*
Auteur :       Erik Bartmann
Nom :          Jeu : deviner un nombre
Version :      1.0
Références :   http://www.arduino.cc/en/Reference/LiquidCrystal
               http://arduino.cc/en/Reference/If
               http://arduino.cc/en/Reference/Else
               http://arduino.cc/en/Reference/Delay
               http://arduino.cc/en/Reference/AnalogRead
               http://arduino.cc/en/Reference/Random
               http://arduino.cc/en/Reference/RandomSeed
*/
#include <LiquidCrystal.h>
#include "MyAnalogKeyPad.h"

#define analogPinKeyPad 0 // Définition de la broche analogique
#define MIN 10            // Limite inférieure du nombre aléatoire
#define MAX 1000          // Limite supérieure du nombre aléatoire
#define RS 12             // Broche Register Select du LCD
#define E 11              // Broche Enable du LCD
#define D4 5              // Ligne de données LCD broche 4
#define D5 4              // Ligne de données LCD broche 5
#define D6 3              // Ligne de données LCD broche 6
#define D7 2              // Ligne de données LCD broche 7
#define COLS 16           // Nombre de colonnes LCD
#define ROWS 2            // Nombre de lignes LCD

int arduinoNumber, tries; // Le nombre généré, nombre d'essais
char yourNumber[5];       // Nombre à 5 chiffres maxi
byte place;
MyAnalogKeyPad myOwnKeyPad(analogPinKeyPad); // Instanciation clavier
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);    // Instanciation LCD 

void setup(){
  myOwnKeyPad.setDebounceTime(500);   // Réglage temps de rebond 500 ms 
  lcd.begin(COLS, ROWS);              // Nombres de lignes et de colonnes
  lcd.blink();                        // Faire clignoter le curseur
  startSequence();                    // Appel de la séquence de démarrage
}

void loop(){
  char myKey = myOwnKeyPad.readKey(); // Lecture de la touche appuyée
  if(myKey != KEY_NOT_PRESSED){       // Interrogation si une touche quelconque appuyée
    yourNumber[place] = myKey;
    place++;
    lcd.print(myKey);                 // Afficher la touche sur le LCD
  }
  if(place == int(log10(MAX))+1){
    tries++;
    int a = atoi(yourNumber);
    if(a == arduinoNumber){
      lcd.clear();                    // Effacer écran LCD
      lcd.print("Exact !!!");         // Affichage sur LCD
      lcd.setCursor(0, 1);            // Positionnement curseur sur 2e ligne
      lcd.print("Essai : " + String(tries));
      delay(4000);                    // Attendre 4 secondes 
      tries = 0;                      // Remise à zéro du nombre d'essais
      startSequence();                // Appel de startSequence
    }
    else if(a < arduinoNumber){
      lcd.setCursor(0, 1);            // Positionnement curseur sur 2e ligne
      lcd.print("Trop petit");        // Affichage sur LCD
      lcd.setCursor(0, 0);            // Positionnement curseur sur 1re ligne
    }
    else{
      lcd.setCursor(0, 1);            // Positionnement curseur sur 2e ligne
      lcd.print("Trop grand");        // Affichage sur LCD
      lcd.setCursor(0, 0);            // Positionnement curseur sur 1re ligne
    }
    lcd.setCursor(2, 0);              // Positionnement curseur sur 3e emplacement de la 1re ligne
    place = 0;
  }
}

int randomNumber(int minimum, int maximum){
  randomSeed(analogRead(5));
  return random(minimum, maximum + 1);
}

void startSequence(){
  arduinoNumber = randomNumber(MIN, MAX);    // Générer le nombre à deviner
  lcd.clear();                               // Effacer écran LCD
  lcd.print("Devine un nombre");             // Affichage sur LCD
  lcd.setCursor(0, 1);                       // Positionnement curseur sur 2e ligne
  lcd.print("de " + String(MIN) + " - " + String(MAX));
  delay(4000);                               // Attendre 4 secondes
  lcd.clear();                               // Effacer écran LCD
  lcd.print(">>");                           // Affichage sur LCD
}
