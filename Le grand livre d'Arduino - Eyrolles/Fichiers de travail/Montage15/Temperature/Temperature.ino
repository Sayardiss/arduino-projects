/*
Auteur :       Erik Bartmann
Nom :          La température
Version :      1.0
Références :   http://arduino.cc/en/Reference/Serial
               http://arduino.cc/en/Reference/For
               http://arduino.cc/en/Reference/Delay
*/
#define sensorPin 0    // Connexion à la sortie du LM35 
#define DELAY 10       // Bref temps d'attente
const int cycles = 20; // Nombre de mesures

void setup(){
  Serial.begin(9600);
}

void loop(){
  float resultTemp = 0.0;
  for(int i = 0; i < cycles; i++){
    int analogValue = analogRead(sensorPin);
    float temperature = (5.0 * 100.0 * analogValue) / 1024;
    resultTemp += temperature; // Addition des valeurs mesurées
    delay(DELAY);
  }
  resultTemp /= cycles;       // Calcul de la moyenne
  Serial.println(resultTemp); // Envoi à l'interface série
}        

/* Sketch Processing - Téléchargez l'environnement de développement sur http://processing.org/download

import processing.serial.*;
Serial mySerialPort;
float realTemperature;
int temperature, xPos;
int[] yPos;
PFont font;

void setup(){
  size(321, 250); smooth();
  println(Serial.list());
  mySerialPort = new Serial(this, Serial.list()[0], 9600);
  mySerialPort.bufferUntil('\n');
  yPos = new int[width];
  for(int i = 0; i < width; i++)
    yPos[i] = 250;
  font = createFont("Courier New", 40, false);
  textFont(font, 40); textAlign(RIGHT);
}

void draw(){
  background(0, 0, 255, 100);
  strokeWeight(2); stroke(255, 0, 0);
  fill(100, 100, 100); rect(10, 100, width - 20, 130);
  strokeWeight(1); stroke(0, 255, 0);
  int yPosPrev = 0, xPosPrev = 0;
  // Décaler les valeurs du tableau vers la gauche
  for(int x = 1; x < width; x++)
    yPos[x-1] = yPos[x];
  // Ajout des nouvelles coordonnées de la souris à l'extrémité droite du tableau
  yPos[width-1] = temperature;
  // Affichage du tableau
  for(int x = 10; x < width - 10 ; x++)
    point(x, yPos[x]);
  fill(255);
  text(realTemperature + " °C", 250, 30); // Celsius
  delay(100);
}

void serialEvent (Serial mySerialPort){
  String portStream = mySerialPort.readString();
  float data = float(portStream);
  realTemperature = data;
  temperature = height - (int)map(data, 0, 100, 0, 130) - 25;
  println(realTemperature);
}
*/
