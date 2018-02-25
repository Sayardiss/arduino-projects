/*
Auteur :       Erik Bartmann
Nom :          La commande du moteur
Version :      1.0
Attention :    L'écran LCD, qui est contrôlé par le bus I2C, requiert sous Arduino 1.0 une bibliothèque que j'ai modifiée, 
               car elle n'était pas encore disponible par le fabricant lors de l'écriture de ce sketch. Cette bibliothèque 
			   (l'ensemble du répertoire LiquidCrystal_I2C) doit être copiée dans le répertoire Arduino\libraries de votre
			   disque dur. 
Références :   http://www.arduino.cc/en/Reference/Wire
               http://www.arduino.cc/en/Reference/LiquidCrystal
               http://arduino.cc/en/Reference/PinMode
               http://arduino.cc/en/Reference/Constants
               http://arduino.cc/en/Reference/For
               http://arduino.cc/en/Reference/Delay
               http://arduino.cc/en/Reference/If
               http://arduino.cc/en/Reference/Else
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define sensorPin 0                  // Connexion à la sortie du LM35 
#define DELAY1 10                    // Bref temps d'attente lors de la mesure
#define DELAY2 500                   // Bref temps d'attente lors de l'affichage
#define motorPin 9                   // Broche commande du ventilateur
#define threshold 25                 // Température de commutation du ventilateur (25 degrés Celsius)
#define hysteresis 0.5               // Valeur d'hystérésis (0.5 degré Celsius)
const int cycles = 20;               // Nombre de mesures
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adresse I2C : 0x27 pour 16 caractères/2 lignes

void setup(){
  pinMode(motorPin, OUTPUT);
  lcd.init();      // Initialisation du LCD 
  lcd.backlight(); // Activation du rétroéclairage
}

void loop(){
  float resultTemp = 0.0;
  for(int i = 0; i < cycles; i++){
    int analogValue = analogRead(sensorPin);
    float temperature = (5.0 * 100.0 * analogValue) / 1024;
    resultTemp += temperature; // Addition des valeurs mesurées
    delay(DELAY1);
  }
  resultTemp /= cycles;         // Calcul de la somme
  lcd.clear();                  // Méthode clear pour effacer le contenu du LCD
  lcd.print("Temp: ");          // Méthode print pour écrire sur le LCD
  lcd.print(resultTemp);
  #if ARDUINO < 100
    lcd.print(0xD0 + 15, BYTE); // Caractère degré (Arduino 0022)
  #else
    lcd.write(0xD0 + 15);       // Caractère degré (Arduino 1.00)
  #endif
  lcd.print("C");
  lcd.setCursor(0, 1);          // Méthode setCursor pour positionner le curseur du LCD
  lcd.print("Moteur: ");
  if(resultTemp > (threshold + hysteresis))
    digitalWrite(motorPin, HIGH);
  else if(resultTemp < (threshold - hysteresis))
    digitalWrite(motorPin, LOW);
  lcd.print(digitalRead(motorPin) == HIGH?"en marche":"stop");
  delay(DELAY2);
}
