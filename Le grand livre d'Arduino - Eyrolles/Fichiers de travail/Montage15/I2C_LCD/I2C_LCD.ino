#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adresse I2C : 0x27 pour 16 caractères/2 lignes

void setup(){
  lcd.init();      // Initialisation du LCD 
  lcd.backlight(); // Activation du rétroéclairage
  lcd.print("Bonjour utilisateur d'Arduino !");
}

void loop(){
  
}
