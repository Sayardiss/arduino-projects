#include <Wire.h>
const int sensorPin = A0;
void setup() {
  Serial.begin(9600);
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}
void loop() {
  delay(100);
}
// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {

  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0)*5;
  float temp = (voltage -.5)*100;
  Serial.println(temp);
  int te = (int)(temp*100);
  Serial.println(te);
  Wire.write(highByte(te));
  Serial.println(highByte(te));
  Wire.write(lowByte(te));
  Serial.println(lowByte(te));
}
