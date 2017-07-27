#include "myNewLib.hpp"

#include <TFT.h>
#include "Adafruit_HTU21DF.h"
#include "../../Constants.h"

int cursorX = 0;
int cursorY = 0;
TFT            *tft;
// Initialize HTU sensor
Adafruit_HTU21DF *htu;
#define SENSOR "HTU "

//namespace myNewLib {

	myLiquidCrystal::myLiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1,
			uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
			: myPrint() {
//		l = new LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7);

		// Initialise TFT
		tft = new  TFT(TFT_CS, TFT_DC, TFT_RST);
		return;
	}

	myLiquidCrystal::myLiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0,
			uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
			: myPrint() {
//		l = new LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);

		// Initialise TFT
		tft = new  TFT(TFT_CS, TFT_DC, TFT_RST);
		return;
	}

	myLiquidCrystal::myLiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0,
			uint8_t d1, uint8_t d2, uint8_t d3)
		: myPrint() {


		// Initialise TFT
		tft = new  TFT(TFT_CS, TFT_DC, TFT_RST);
		return;
	}

	myLiquidCrystal::myLiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
		: myPrint() {
//	}
//		l = new LiquidCrystal(rs, enable, d0, d1, d2, d3);

		// Initialise TFT
		tft = new  TFT(TFT_CS, TFT_DC, TFT_RST);
//		tft2 = tft;
		return;
	}

	void myLiquidCrystal::begin(uint8_t cols, uint8_t rows, uint8_t charsize){
//		l->begin(cols, rows, charsize);
		//  //initTFT
		  tft->begin();
		  tft->background(0, 0, 0); 		// clear the screen with a black background
		  tft->stroke(255, 255, 255);		// set the font color to white
		  tft->setTextSize(2);				// set the font size

		return;
	}

	void myLiquidCrystal::setCursor(uint8_t a, uint8_t b){
//		l->setCursor(a, b);
		cursorX = a;
		if (a==0 && b==0){
			cursorX = 0;
			cursorY = 0;
		}
		else if (a==6 && b==0){
			cursorX = 0;
			cursorY = 30;
		}
		else if (a==0 && b==1){
			cursorX = 0;
			cursorY = 60;
		}
		else if (a==6 && b==1){
			cursorX = 0;
			cursorY = 90;
		}
		return;
	}

	void myLiquidCrystal::clear() {
//		l->clear();
		tft->background(0,0,0);
		return;
	}

	//TODO: pure virtual not considered
	size_t myLiquidCrystal::write(uint8_t value) {
//		return l->write(value);
//	  return 1; // assume sucess
	}


	myPrint::myPrint(){
	}

	size_t myPrint::print(const char str[])
	{
	  tft->text(str, cursorX, cursorY); 	// write the text to the top left corner of the screen
	  return 0;//write(str);
	}

	size_t myPrint::print(unsigned long n, int base)
	{
		tft->stroke(255, 255, 255);
		// clear the screen before starting again
		tft->background(0,0,0);
		// print the sensor value
		 tft->text(String(n).c_str(), cursorX, cursorY);
	  return 0;
	}


	size_t myPrint::print(double n, int digits)
	{
		String s(n);
//		s.concat(n);
		tft->text(s.c_str(), cursorX, cursorY);
	  return 0;
	}


	DHT::DHT(uint8_t pin, uint8_t type, uint8_t count) {
		htu = new Adafruit_HTU21DF();
		return;
	}

	void DHT::begin(void) {
		//init HTU
		if (!htu->begin()) {
			Serial.println("Couldn't find sensor!");
			while (1);
		}
		return;
	}

	float DHT::readHumidity(bool force) {
		return htu->readHumidity();
	}

	float DHT::readTemperature(bool S, bool force) {
		return htu->readTemperature();
	}

//?}


