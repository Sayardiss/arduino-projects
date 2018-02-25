#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" 

const String GOOGLE_USERNAME = "votre_usernamegmail.com";
const String GOOGLE_PASSWORD = "votre_password";
const String SPREADSHEET_TITLE = "MaFeuilleDeCalculArduino";
const unsigned long RUN_INTERVAL_MILLIS = 2000; // Intervalle de mesure

// the last time we ran the Choreo
// (initialized to 60 seconds ago so the
// Choreo is run immediately when we start up)
unsigned long lastRun = (unsigned long) - RUN_INTERVAL_MILLIS;

void setup() {
  Serial.begin(9600);
  delay(4000);
  while (!Serial);
  Serial.print("Initialisation de la passerelle...");
  Bridge.begin();
  Serial.println("Terminée");
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
  unsigned long now = millis(); // Consigner l'heure en millisecondes
  if (now - lastRun >= RUN_INTERVAL_MILLIS) {
    lastRun = now;
    Serial.println("Mesure de la valeur par le capteur...");
    int analogValue0 = analogRead(A0);
    int analogValue1 = analogRead(A1);
    int analogValue2 = analogRead(A2);
    Serial.println("Inscription de la valeur dans la feuille de calcul...");
    TembooChoreo AppendRowChoreo; // Création de l'objet Choreo
    AppendRowChoreo.begin();      // Activation de l'objet Choreo

    // Temboo account credentials
    AppendRowChoreo.setAccountName(TEMBOO_ACCOUNT);
    AppendRowChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    AppendRowChoreo.setAppKey(TEMBOO_APP_KEY);

    // identify the Temboo Library choreo to run (Google > Spreadsheets > AppendRow)
    AppendRowChoreo.setChoreo("/Library/Google/Spreadsheets/AppendRow");
    // your Google username (usually your email address)
    AppendRowChoreo.addInput("Username", GOOGLE_USERNAME);
    // your Google account password
    AppendRowChoreo.addInput("Password", GOOGLE_PASSWORD);

    // the title of the spreadsheet you want to append to
    // NOTE: substitute your own value, retaining the "SpreadsheetTitle:" prefix.
    AppendRowChoreo.addInput("TitreDeLaFeuilleDeCalcul", SPREADSHEET_TITLE);

    // convert the time and sensor values to a comma separated string
    String rowData(getDateTime());
    rowData += ",";
    rowData += analogValue0;
    rowData += ",";
    rowData += analogValue1;
    rowData += ",";
    rowData += analogValue2;

    // add the RowData input item
    AppendRowChoreo.addInput("RowData", rowData);

    // run the Choreo and wait for the results
    // The return code (returnCode) will indicate success or failure
    unsigned int returnCode = AppendRowChoreo.run();

    // return code of zero (0) means success
    if (returnCode == 0) {
      Serial.println("Success! Appended " + rowData);
      Serial.println("");
    } else {
      // return code of anything other than zero means failure
      // read and display any error messages
      while (AppendRowChoreo.available()) {
        char c = AppendRowChoreo.read();
        Serial.print(c);
      }
    }
    AppendRowChoreo.close();
  }
}
