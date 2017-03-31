// Do not remove the include below
#include "Microphone.h"

// LED
#define LEDPIN 14

const int sampleWindow = 250; // Sample window width in mS (250 mS = 4Hz)
unsigned int knock;

//The setup function is called once at startup of the sketch
void setup() {
	// Add your initialization code here
	Serial.begin(9600);
	//led
	pinMode(LEDPIN, OUTPUT);  // Set digital pin 2 -> output
}

// The loop function is called in an endless loop
void loop() {
//	digitalWrite(LEDPIN, LOW);      // Pin 12 = 5 V, LED emits light
//    delay(1000);
//	digitalWrite(LEDPIN, HIGH);      // Pin 12 = 5 V, LED emits light
//    Serial.println(millis()/1000);
//	delay(1000);

	unsigned long start = millis();  // Start of sample window
	unsigned int peakToPeak = 0;   // peak-to-peak level

	unsigned int signalMax = 0;
	unsigned int signalMin = 1024;

	// collect data for 250 miliseconds
	while (millis() - start < sampleWindow) {
		knock = analogRead(2);
		if (knock < 1024) //This is the max of the 10-bit ADC so this loop will include all readings
				{
			if (knock > signalMax) {
				signalMax = knock;  // save just the max levels
			} else if (knock < signalMin) {
				signalMin = knock;  // save just the min levels
			}
		}
	}
	peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
	double volts = (peakToPeak * 3.3) / 1024;  // convert to volts

	Serial.println(volts);
	if (volts >= 1.0) {
		//turn on LED
		digitalWrite(LEDPIN, HIGH);
		delay(500);
		Serial.println("Knock Knock");
	} else {
		//turn LED off
		digitalWrite(LEDPIN, LOW);
	}
}
