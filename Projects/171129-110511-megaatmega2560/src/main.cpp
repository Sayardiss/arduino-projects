#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);


void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output

  lcd.begin(16, 2);
  lcd.print("Ask the");
  lcd.setCursor(0,1);
  lcd.print("Crystal Temp!");
}

void printTempLCD(float temperature){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The temperature is");
  lcd.setCursor(0,1);
  lcd.print(temperature);
  lcd.print(" C");
}

void loop() {
  Wire.requestFrom(8, 2);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    byte c1 = Wire.read(); // receive a byte as character
    byte c2 = Wire.read();

    int temp = (c1 << 8) | c2;
    float temperature = ((float)temp)/100;

    Serial.println(temperature);
    printTempLCD(temperature);
  }

  delay(2000);
}
