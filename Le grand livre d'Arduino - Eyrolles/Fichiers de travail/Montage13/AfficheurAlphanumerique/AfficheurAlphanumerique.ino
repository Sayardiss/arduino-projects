/*
Auteur :      Erik Bartmann
Nom :         Un afficheur alphanumérique
Version :     1.0
*/
#include <LiquidCrystal.h>
#define RS 12   // Register Select
#define E 11    // Enable
#define D4 5    // Ligne de données 4
#define D5 4    // Ligne de données 5
#define D6 3    // Ligne de données 6
#define D7 2    // Ligne de données 7
#define COLS 16 // Nombre de colonnes
#define ROWS 2  // Nombre de lignes
LiquidCrystal lcd(RS, E, D4, D5, D6, D7); // Instanciation de l'objet

void setup(){
  lcd.begin(COLS, ROWS);         // Nombres de colonnes et de lignes
  lcd.print("Un Arduino me");    // Affichage du texte
  lcd.setCursor(0, 1);           // Passer à la 2e ligne
  lcd.print("commande :-)");      // Affichage du texte
}

void loop(){/* vide */}
