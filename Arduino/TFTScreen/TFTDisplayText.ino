/*
  Arduino TFT text example

  This example demonstrates how to draw text on the
  TFT with an Arduino. The Arduino reads the value
  of an analog sensor attached to pin A0, and writes
  the value to the LCD screen, updating every
  quarter second.

  This example code is in the public domain

  Created 15 April 2013 by Scott Fitzgerald

  http://www.arduino.cc/en/Tutorial/TFTDisplayText

 */
#include <Arduino.h>
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
#include <time.h>


// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

// pin definition for the Leonardo
// #define cs   7
// #define dc   0
// #define rst  1

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

// char array to print to the screen
char sensorPrintout[4];

void setup() {
  Serial.begin(9600);


  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

  // write the static text to the screen
  // set the font color to white
  TFTscreen.stroke(255, 255, 255);
  // set the font size
  TFTscreen.setTextSize(2);
  // write the text to the top left corner of the screen
  TFTscreen.text("Simos Gerasimou:\n ", 0, 0);
  // ste the font size very large for the loop
  TFTscreen.setTextSize(5);

  Serial.println("Starting: ");
}

//void loop() {
//
//  // Read the value of the sensor on A0
//  String sensorVal = String(analogRead(A0));
//
//  // convert the reading to a char array
//  sensorVal.toCharArray(sensorPrintout, 4);
//
//  // set the font color
//  TFTscreen.stroke(255, 255, 255);
//  // print the sensor value
//  TFTscreen.text(sensorPrintout, 0, 20);
//  TFTscreen.text(sensorPrintout, 0, 60);
//  // wait for a moment
//  delay(1000);
//  // erase the text you just wrote
//  TFTscreen.stroke(0, 0, 0);
//  TFTscreen.text(sensorPrintout, 0, 20);
//  TFTscreen.text(sensorPrintout, 0, 60);
//
////  Serial.print("Sensor: ");
////  Serial.println(sensorVal);
//
//     // current date/time based on current system
////     time_t now = time(0);
//     // convert now to string form
////     char* dt = ctime(&now);
////     Serial.print("The local date and time is: ");  + dt);
//
//
//}


void loop(){
	TFTscreen.stroke(255, 0, 0); // set the stroke color to red
	TFTscreen.line(0, 10, TFTscreen.width(), 10); // draw a line across the screen
	delay(1000);

  TFTscreen.noStroke(); // don't draw a line around the next rectangle
  TFTscreen.fill(0,255,0); // set the fill color to green
  TFTscreen.rect(0,20,TFTscreen.width(),10); //draw a rectangle across the screen
  delay(1000);

  TFTscreen.fill(0,0,255); // set the fill color to blue
  TFTscreen.stroke(255,255,255); // outline the rectangle with a white line
  TFTscreen.rect(0,45,TFTscreen.width(),45); // draw a fat rectangle
  delay(1000);

  TFTscreen.background(0,0,0); // clear the screen before starting again
  Serial.println(millis() / 1000);   // print the number of seconds since reset:
  delay(1000);
}
