/*
Auteur :      Erik Bartmann
Nom :         Jeu de la séquence des couleurs
Version :     1.0
*/
#define MAXARRAY 5                      // Définir la longueur de la séquence
int ledPin[] = {2, 3, 4, 5};            // Tableau de LED avec numéros de broche
#define piezoPin 13                     // Broche piézo
#define buttonPinRed 6                  // Broche bouton-poussoir LED rouge
#define buttonPinGreen 7                // Broche bouton-poussoir LED verte
#define buttonPinYellow 8               // Broche bouton-poussoir LED jaune
#define buttonPinWhite 9                // Broche bouton-poussoir LED blanche
#define ledStatePinGreen 10             // LED d'état verte
#define ledStatePinYellow 11            // LED d'état jaune
#define ledStatePinRed 12               // LED d'état rouge
int colorArray[MAXARRAY];               // Contient la suite de chiffres pour les couleurs à afficher
int tones[] = {1047, 1175, 1319, 1397}; // Fréquences des sons pour les 4 couleurs
int counter = 0;                        // Nombre de LED actuellement allumées
boolean fail = false;

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < 4; i++)
    pinMode(ledPin[i], OUTPUT); // Programmation des broches de LED comme sortie
  pinMode(buttonPinRed, INPUT); digitalWrite(buttonPinRed, HIGH);
  pinMode(buttonPinGreen, INPUT); digitalWrite(buttonPinGreen, HIGH);
  pinMode(buttonPinYellow, INPUT); digitalWrite(buttonPinYellow, HIGH);
  pinMode(buttonPinWhite, INPUT); digitalWrite(buttonPinWhite, HIGH);
  pinMode(ledStatePinGreen, OUTPUT);
  pinMode(ledStatePinYellow, OUTPUT);
  pinMode(ledStatePinRed, OUTPUT);
}

void loop(){
  Serial.println("Départ du jeu");
  generateColors();
  int buttonCode;
  for(int i = 0; i <= counter; i++){ // Boucle extérieure
  giveSignalSequence(i);
  for(int k = 0; k <= i; k++){       // Boucle intérieure
    while(digitalRead(buttonPinRed) && digitalRead(buttonPinGreen) &&
    digitalRead(buttonPinYellow) && digitalRead(buttonPinWhite));
    Serial.println("Bouton poussé !"); // Pour contrôle dans Serial Monitor
    // Affichage de la couleur appuyée
    if(!digitalRead(buttonPinRed))
      buttonCode = 0;
    if(!digitalRead(buttonPinGreen))
      buttonCode = 1;
    if(!digitalRead(buttonPinYellow))
      buttonCode = 2;
    if(!digitalRead(buttonPinWhite))
      buttonCode = 3;
    giveSignal(buttonCode);
    // Vérifier si la bonne couleur a été appuyée
    if(colorArray[k] != buttonCode){
      fail = true;
    break; // Quitter la boucle for interne
    }
  }
  if(!fail)
    Serial.println("correct"); // Pour contrôle dans Serial Monitor
  else{
    digitalWrite(ledStatePinRed, HIGH);
    for(int i = 3000; i > 500; i-=150){
      tone(piezoPin, i, 10); delay(20);
    }
    Serial.println("faux"); // Pour contrôle dans Serial Monitor
    delay(2000);
    digitalWrite(ledStatePinRed, LOW);
    counter = 0; fail = false;
    break; // Quitter la boucle for
  }
  delay(2000);
  if(counter + 1 == MAXARRAY){
    digitalWrite(ledStatePinGreen, HIGH);
    for(int i = 500; i < 3000; i+=150){
      tone(piezoPin, i, 10); delay(20);
    }
    Serial.println("Fini !"); // Pour contrôle dans Serial Monitor
    delay(2000);
    digitalWrite(ledStatePinGreen, LOW);
    counter = 0; fail = false;
    break; // Quitter la boucle for extérieure
  }
  counter++; // Incrémenter le compteur
  }
}

void giveSignalSequence(int value){
  // Affichage LEDs
  for(int i = 0; i <= value; i++){
    digitalWrite(2 + colorArray[i], HIGH);
    generateTone(colorArray[i]); delay(1000);
    digitalWrite(2 + colorArray[i], LOW); delay(1000);
  }
}

void generateTone(int value){
  tone(piezoPin, tones[value], 1000);
}

void giveSignal(int value){
  // Affichage LED + Tonsignal
  digitalWrite(2 + value, HIGH); generateTone(value); delay(200);
  digitalWrite(2 + value, LOW); delay(200);
}

void generateColors(){
  randomSeed(analogRead(0));
  for(int i = 0; i < MAXARRAY; i++)
  colorArray[i] = random(4); // Générer des chiffres aléatoires de 0 à 3
  // 0 = rouge, 1 = vert, 2 = jaune, 3 = blanc
  for(int i = 0; i < MAXARRAY; i++)
    Serial.println(colorArray[i]); // Pour contrôle dans Serial Monitor
}

