#define PIN 12

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN, OUTPUT);
}

void loop(){
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(PIN, HIGH);
    delay(100); // Pause d'1 seconde
    
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(PIN, LOW);
    delay(100); // Pause d'1 seconde
}
