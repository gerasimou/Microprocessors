#include "Arduino.h"

//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
	pinMode(2, OUTPUT);  // Set digital pin 13 -> output

	Serial.println("Beep!");

	tone(3, 3000, 1000);        // Play tone for 1 second
	delay(1000);
}


// The loop function is called in an endless loop
void loop()
{
	Serial.println("Waiting for reset...");
	digitalWrite(2, HIGH);      // Pin 13 = 5 V, LED emits light
	delay(500);
	digitalWrite(2, LOW);      // Pin 13 = 5 V, LED emits light
	delay(500);
}
