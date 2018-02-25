/*
Auteur :      Erik Bartmann
Nom :         Le dé électronique avec groupes
Version :     1.0
*/
#define WAITTIME 20
int GroupA = 8;  // LED 4
int GroupB = 9;  // LED 1 + 7
int GroupC = 10; // LED 3 + 5
int GroupD = 11; // LED 2 + 6
int buttonPin = 13; // Bouton-poussoir à la broche 13

void setup(){
  pinMode(GroupA, OUTPUT);
  pinMode(GroupB, OUTPUT);
  pinMode(GroupC, OUTPUT);
  pinMode(GroupD, OUTPUT);
}

void loop(){
  if(digitalRead(buttonPin) == HIGH)
  displayPips(random(1, 7)); // Générer un nombre entre 1 et 6
}

void displayPips(int value){
  // Éteindre tous les groupes
  digitalWrite(GroupA, LOW);
  digitalWrite(GroupB, LOW);
  digitalWrite(GroupC, LOW);
  digitalWrite(GroupD, LOW);
  // Commande de tous les groupes
  if(value%2 != 0) // La valeur est-elle impaire ?
    digitalWrite(GroupA, HIGH);
  if(value > 1)
    digitalWrite(GroupB, HIGH);
  if(value > 3)
    digitalWrite(GroupC, HIGH);
  if(value == 6)
    digitalWrite(GroupD, HIGH);
  delay(WAITTIME); // Ajouter une courte pause
}
