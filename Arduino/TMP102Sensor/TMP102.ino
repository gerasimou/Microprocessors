//Arduino 1.0+ Only
//Arduino 1.0+ Only

//////////////////////////////////////////////////////////////////
//©2011 bildr
//Released under the MIT License - Please reuse change and share
//Simple code for the TMP102, simply prints temperature via serial
//////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#define LEDPIN 14     		// what pin we're connected to

//TMP102 address
#define TMP102_I2CADDR 0x48

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);



void setup(){
  Serial.begin(9600);
  Wire.begin();

  //led
  pinMode(LEDPIN, OUTPUT);  // Set digital pin 2 -> output

  //init  LCD: set up  number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Starting");
  delay(2000);
  lcd.clear();
}


void loop(){
  digitalWrite(LEDPIN, LOW);      // Pin 12 = 5 V, LED emits light
  delay(2000);
  digitalWrite(LEDPIN, HIGH);      // Pin 12 = 5 V, LED emits light
  runTMP102();
  delay(100);
}


void runTMP102(){
	float temp = getTMP102Temperature();
	Serial.print("Celsius: ");
	Serial.println(temp);
	lcd.setCursor(0, 1);
	lcd.print(temp);
}


float getTMP102Temperature(){
  Wire.requestFrom(TMP102_I2CADDR,2);

  byte MSB = Wire.read();
  byte LSB = Wire.read();

  //it's a 12bit int, using two's compliment for negative
  int TemperatureSum = ((MSB << 8) | LSB) >> 4;

  float celsius = TemperatureSum*0.0625;
  return celsius;
}
