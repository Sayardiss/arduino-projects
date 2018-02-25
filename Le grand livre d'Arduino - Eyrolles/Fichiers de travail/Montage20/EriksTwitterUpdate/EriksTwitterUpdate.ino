#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information, as described below

int numRuns = 1;   // Execution count, so this doesn't run forever
int maxRuns = 10;   // Maximum number of times the Choreo should be executed

void setup() {
  Serial.begin(9600); 
  delay(4000);
  while(!Serial);
  Bridge.begin();
}
void loop()
{
  if (numRuns <= maxRuns) {
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
    
    // Set Choreo inputs
    StatusesUpdateChoreo.addInput("StatusUpdate", "Hello, this is a message from Erik! - again !!!");
    
    // Identify the Choreo to run
    StatusesUpdateChoreo.setChoreo("/Library/Twitter/Tweets/StatusesUpdate");
    
    // Run the Choreo; when results are available, print them to serial
    StatusesUpdateChoreo.run();
    
    while(StatusesUpdateChoreo.available()) {
      char c = StatusesUpdateChoreo.read();
      Serial.print(c);
    }
    StatusesUpdateChoreo.close();

  }

  Serial.println("Waiting...");
  delay(30000); // wait 30 seconds between StatusesUpdate calls
}
