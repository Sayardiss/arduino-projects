#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information, as described below
#include <dht.h>           // Bibliothèque du capteur DHT11
#define DHT11_PIN 8        // Broche de données du DHT11

dht DHT;                   // Instance DHT11

int numRuns = 1;   // Execution count, so this doesn't run forever
int maxRuns = 30;  // Maximum number of times the Choreo should be executed

void setup() {
  Serial.begin(9600);
  delay(4000);
  while (!Serial);
  Bridge.begin();
}

String getDateTime() {
  Process time;
  time.runShellCommand("date"); // Date et heure du serveur
  String timeStamp = "";
  while (time.available()) {
    char c = time.read();
    timeStamp += c;
  }
  return timeStamp; // Affichage de l'horodatage
}

void loop()
{
  if (numRuns <= maxRuns) {
    String timestamp = getDateTime(); // Détermination de l'horodatage
    String tweet    = "";             // Message du tweet
    String msgDHT11 = "";             // Affichage de l'état du capteur

    int responseDHT11 = DHT.read11(DHT11_PIN); // Initialisation de DHT11
    switch (responseDHT11) { // Analyse de la réponse
      case DHTLIB_OK:
        msgDHT11 = "Sensor OK. ";
        break;
      case DHTLIB_ERROR_CHECKSUM:
        msgDHT11 = "Sensor FAIL. Checksum Error! ";
        break;
      case DHTLIB_ERROR_TIMEOUT:
        msgDHT11 = "Sensor FAIL. Timeout! ";
        break;
      default:
        msgDHT11 = "Sensor FAIL. Unknown Error! ";
        break;
    }
    float humidity    = DHT.humidity;    // Mesure de l'humidité
    float temperature = DHT.temperature; // Mesure de la température 
    Serial.println("Running StatusesUpdate - Run #" + String(numRuns++));

    TembooChoreo StatusesUpdateChoreo;

    // Invoke the Temboo client
    StatusesUpdateChoreo.begin();

    // Set Temboo account credentials
    StatusesUpdateChoreo.setAccountName(TEMBOO_ACCOUNT);
    StatusesUpdateChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    StatusesUpdateChoreo.setAppKey(TEMBOO_APP_KEY);

    // Set credential to use for execution
    StatusesUpdateChoreo.setCredential("EriksTwitter");

    // Tweet
    tweet = timestamp + " - " + 
      "DHT11-Status: " + msgDHT11 + " - " + 
      "Humidity: " + humidity + 
      "% - Temperature: " + temperature + " degrees Celsius";

    // Set Choreo inputs
    StatusesUpdateChoreo.addInput("StatusUpdate", tweet);

    // Identify the Choreo to run
    StatusesUpdateChoreo.setChoreo("/Library/Twitter/Tweets/StatusesUpdate");

    // Run the Choreo; when results are available, print them to serial
    StatusesUpdateChoreo.run();

    while (StatusesUpdateChoreo.available()) {
      char c = StatusesUpdateChoreo.read();
      Serial.print(c);
    }
    StatusesUpdateChoreo.close();

  }

  Serial.println("Waiting...");
  delay(30000); // wait 30 seconds between StatusesUpdate calls
}
