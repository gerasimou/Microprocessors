#include "Arduino.h"
//The setup function is called once at startup of the sketch

#define PIN 14    		// what pin we're connected to

void setup()
{
//	pinMode(13, OUTPUT);  // Set digital pin 13 -> output
	pinMode(PIN, OUTPUT);  // Set digital pin 12 -> output
	Serial.begin(9600);

}

// The loop function is called in an endless loop
void loop()
{
//	digitalWrite(13, HIGH);      // Pin 13 = 5 V, LED emits light
	digitalWrite(PIN, LOW);      // Pin 12 = 5 V, LED emits light
	delay(500);                  // ..for 0.5 seconds
//	digitalWrite(13, LOW);       // Pin 13 = 0 V, LED no light
	digitalWrite(PIN, HIGH);       // Pin 12 = 0 V, LED no light
    Serial.print(" Light");
	delay(500);                  // ..for 0.5 seconds
  }
