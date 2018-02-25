/*
Auteur :      Erik Bartmann
Nom :         Le son et plus encore (partie 2)
Version :     1.0
Références :  http://arduino.cc/en/Reference/Array
              http://arduino.cc/en/Reference/Tone
              http://arduino.cc/en/Reference/NoTone
              http://arduino.cc/en/Reference/Delay
*/
#define piezoPin 13        // Élément piézoélectrique sur broche 13
#define toneDuration 500   // Durée du son
#define tonePause 800      // Longueur de la pause entre les sons
int tones[] = {523, 659, 587, 698, 659, 784, 698, 880};
int elements = sizeof(tones) / sizeof(tones[0]);

void setup(){
  noTone(piezoPin);                         // Rendre le piézo muet
  for(int i = 0; i < elements; i++){
    tone(piezoPin, tones[i], toneDuration); // Exécuter le son
    delay(tonePause);                       // Pause entre les sons
  }
}

void loop(){/* vide */}
