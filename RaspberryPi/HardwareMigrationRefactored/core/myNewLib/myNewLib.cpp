#include "myNewLib.hpp"

#include "../common_dht_read.h"
#include "../pi_dht_read.h"
#include <wiringPi.h>
#include <lcd.h>
#include "../../Constants.h"
//#include <string>
#include <sstream>

//lcd handle
int lcdHandle;
#define ROWS 2
#define COLS 16
#define BITS 4

//Sensor
float t = 0.0f;
float h  = 0.0f;


//int cursorX = 0;
//int cursorY = 0;
//namespace myNewLib {

	myLiquidCrystal::myLiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1,
			uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
			: myPrint() {
	  	//init lcd
	  	lcdHandle = lcdInit (ROWS, COLS, BITS, LCD_RS, LCD_ENABLE, LCD_D0, LCD_D1, LCD_D2, LCD_D3, 0, 0, 0, 0);
		return;
	}

	myLiquidCrystal::myLiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0,
			uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
			: myPrint() {
	  	//init lcd
	  	lcdHandle = lcdInit (ROWS, COLS, BITS, LCD_RS, LCD_ENABLE, LCD_D0, LCD_D1, LCD_D2, LCD_D3, 0, 0, 0, 0);
		return;
	}

	myLiquidCrystal::myLiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0,
			uint8_t d1, uint8_t d2, uint8_t d3)
		: myPrint() {
	  	//init lcd
	  	lcdHandle = lcdInit (ROWS, COLS, BITS, LCD_RS, LCD_ENABLE, LCD_D0, LCD_D1, LCD_D2, LCD_D3, 0, 0, 0, 0);
		return;
	}

	myLiquidCrystal::myLiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
		: myPrint() {
	  	//init lcd
	  	lcdHandle = lcdInit (ROWS, COLS, BITS, LCD_RS, LCD_ENABLE, LCD_D0, LCD_D1, LCD_D2, LCD_D3, 0, 0, 0, 0);
		return;
	}

	void myLiquidCrystal::begin(uint8_t cols, uint8_t rows, uint8_t charsize){
		//Columns and rows are given in constructor --> Nothing
		return;
	}

	void myLiquidCrystal::setCursor(uint8_t a, uint8_t b){
		lcdPosition(lcdHandle, a, b);
		return;
	}

	void myLiquidCrystal::clear() {
		lcdClear    (lcdHandle) ;
		return;
	}

	//TODO: pure virtual not considered
	size_t myLiquidCrystal::write(uint8_t value) {
//		return l->write(value);
	  return 1; // assume sucess
	}


	myPrint::myPrint(){
	}

	size_t myPrint::print(const char str[])
	{
	  lcdPuts(lcdHandle, str);
	  return 0;
	}

	size_t myPrint::print(unsigned long n, int base)
	{
	  lcdPuts(lcdHandle, n + "");
	  return 0;
	}


	size_t myPrint::print(double n, int digits)
	{
	  //std::string s(n);
	 // s.concat(n);
	  std::stringstream s;
	  s << n;
	  lcdPuts(lcdHandle, s.str().c_str());
	  return 0;
	}


	DHT::DHT(uint8_t pin, uint8_t type, uint8_t count) {
		//Nothing
		return;
	}

	void DHT::begin(void) {
		//Nothing
		return;
	}

	float DHT::readHumidity(bool force) {
		//read sensors
		int result = pi_dht_read(DHT22, DHT_PIN, &t, &h);
		return h;
	}

	float DHT::readTemperature(bool S, bool force) {
		//read sensors
		int result = pi_dht_read(DHT22, DHT_PIN, &t, &h);
		return t;
	}

//?}

	void pinMode(uint8_t pin, uint8_t mode)
	{
		pinMode(pin, mode);
	}

	void digitalWrite(uint8_t pin, uint8_t val)
	{
	    digitalWrite (pin, val) ;	// On
	}
