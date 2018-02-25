/*
Auteur :       Erik Bartmann
Nom :          Communication réseau
Version :      1.0
Références :   http://arduino.cc/en/Reference/Array
               http://www.arduino.cc/en/Reference/Ethernet
               http://www.arduino.cc/en/Reference/SPI
               http://arduino.cc/en/Reference/If
               http://arduino.cc/en/Reference/Delay
               http://arduino.cc/en/Reference/For
*/
#include <SPI.h>
#include <Ethernet.h>
byte MACAddress[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; // Adresse MAC
byte IPAddress[] = {192, 168, 2, 110};                    // Adresse IP
int const HTTPPORT = 80;                                  // Port HTTP 80 (port standard)
String barColor[] = {"ff0000", "00ff00", "00ffff", "ffff00", "ff00ff", "550055"}; // Couleurs RGB pour barres de couleur
#define HTML_TOP "<html>\n<head><title>Arduino Web-Server</title></head>\n<body>"
#define HTML_BOTTOM "</body>\n</html>"
EthernetServer myServer(HTTPPORT); // Démarrage du serveur web sur le port indiqué
void setup(){
  Ethernet.begin(MACAddress, IPAddress); // Initialisation Ethernet 
  myServer.begin();                      // Démarrage du serveur
}

void loop(){
  EthernetClient myClient = myServer.available();
  if(myClient){
    myClient.println("HTTP/1.1 200 OK");
    myClient.println("Content-Type: text/html");
    myClient.println();
    myClient.println(HTML_TOP);      // HTML début
    showValues(myClient);            // Contenu HTML
    myClient.println(HTML_BOTTOM);   // HTML fin
  }
  delay(1);                          // Courte pause pour navigateur web
  myClient.stop();                   // Fermeture connexion client
}

void showValues(EthernetClient &myClient){
  for(int i = 0; i < 6; i++){
    myClient.print("Analog Pin ");
    myClient.print(i);
    myClient.print(": ");
    myClient.print(analogRead(i));
    myClient.print("<div style=\"height: 15px; background-color: #");
    myClient.print(barColor[i]);
    myClient.print("; width:");
    myClient.print(analogRead(i));
    myClient.println("px; border: 2px solid;\"></div>");
  }
}

