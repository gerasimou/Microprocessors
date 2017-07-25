#include "Arduino.h"

//Libraries
#include <DHT.h>
#include <Wire.h>
#include "Adafruit_HTU21DF.h"
#include <TFT.h>
#include <SPI.h>
#include <LiquidCrystal.h>
#include <stdio.h>

// DHT
#define DHTPIN 15     		// DHT sensor PIN
#define DHTTYPE DHT22   	// DHT 22  (AM2302)

//TMP102
#define TMP102_I2CADDR 0x48	//TMP 102 address

//LCD 16x2
#define RS 2
#define ENABLE 3
#define D0 4
#define D1 5
#define D2 6
#define D3 7

// TFT Parameters for the Uno
#define RST  8
#define DC   9
#define CS   10

// LED
#define LEDPIN 14


// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

// Initialize HTU sensor
Adafruit_HTU21DF htu = Adafruit_HTU21DF();

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(RS, ENABLE, D0, D1, D2, D3);

// Initialise TFT
//TFT TFTscreen = TFT(CS, DC, RST);

//Variables
//int chk;
float hum; 	 				//Stores humidity value
float temp; 				//Stores temperature value

char output[5];				// char array to print to the screen
float temperature[3];
float humidity[3];


void setup()
{
  Serial.begin(9600);

  //led
  pinMode(LEDPIN, OUTPUT);  // Set digital pin 2 -> output

  //init DHT
  dht.begin();

  //init HTU
  if (!htu.begin()) {
     Serial.println("Couldn't find sensor!");
     while (1);
   }

  //init  LCD: set up  number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Starting");
//
//  //initTFT
//  TFTscreen.begin();
//  TFTscreen.background(0, 0, 0); 				// clear the screen with a black background
//  TFTscreen.stroke(255, 255, 255);				// set the font color to white
//  TFTscreen.setTextSize(2);						// set the font size
//  TFTscreen.text("Starting", 0, 0); 	// write the text to the top left corner of the screen
//
  delay(2000);
  lcd.clear();
//  TFTscreen.setTextSize(5);			  			// ste the font size very large for the loop
}


void runDHT22()
{
	//Read data and store it to variables hum and temp
	hum		= dht.readHumidity();
    temp	= dht.readTemperature();

    temperature[0]  = temp;
    humidity[0]		= hum;

    Serial.print("\tDHT\tT: ");
	Serial.print(temp);
	Serial.print("\tH: ");
	Serial.println(hum);
}


void runHTU()
{
	 hum	= htu.readHumidity();
     temp	= htu.readTemperature();

     temperature[1]	= temp;
     humidity[1]	= hum;

     Serial.print("\tHTU\tT: ");
	 Serial.print(temp);
	 Serial.print("\tH: ");
	 Serial.println(hum);
}


void runTMP102(){
	float temp = getTMP102Temperature();

	temperature[2] = temp;

	Serial.print("\tTMP\tT: ");
	Serial.println(temp);
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


//void showTFT(){
//	String timeStr = String(millis()/1000);
//	TFTscreen.stroke(255, 255, 255);
//	 // clear the screen before starting again
//	TFTscreen.background(0,0,0);
//	// print the sensor value
//	TFTscreen.text( String(millis()/1000).c_str(), 0, 0);
//	TFTscreen.text(String(humidity[0]).c_str(), 0, 40);
//	TFTscreen.text(String(humidity[1]).c_str(), 0, 80);
//}

void showLCD(){

	lcd.setCursor(0, 0);
    lcd.print(millis() / 1000);   // print the number of seconds since reset:

    //Print temp and humidity values to lcd
    // set the cursor to column 0, line 0
	lcd.setCursor(6, 0);
    lcd.print(temperature[0]);

    lcd.setCursor(0, 1);
    lcd.print(temperature[1]);

	lcd.setCursor(6, 1);
	lcd.print(temp);

}


void loop(){
	digitalWrite(LEDPIN, LOW);      // Pin 12 = 5 V, LED emits light
    delay(2000);
	digitalWrite(LEDPIN, HIGH);      // Pin 12 = 5 V, LED emits light
    Serial.println(millis()/1000);
	runDHT22();
	runHTU();
	runTMP102();
//	showTFT();
	showLCD();
	delay(100);
}
