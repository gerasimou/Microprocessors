#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_HTU21DF.h"

// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (A5 on UNO)
// Connect SDA to I2C data pin (A4 on UNO)

Adafruit_HTU21DF htu = Adafruit_HTU21DF();

void setup() {
  Serial.begin(9600);
  Serial.println("HTU21D-F test");

  if (!htu.begin()) {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
  Serial.println("Starting!");
}


void loop() {
  Serial.print("Temp: ");
  Serial.print(htu.readTemperature());
  Serial.print("\t\tHum: ");
  Serial.println(htu.readHumidity());
  delay(500);
}
