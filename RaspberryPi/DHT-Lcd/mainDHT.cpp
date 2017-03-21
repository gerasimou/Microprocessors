#include "common_dht_read.h"
#include "pi_dht_read.h"
#include <stdio.h>
#include <iomanip>

#include <wiringPi.h>          
#include <lcd.h>               
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include <iostream>


//USE WIRINGPI PIN NUMBERS
#define LCD_RS  25               //Register select pin
#define LCD_E   24               //Enable Pin
#define LCD_D4  23               //Data pin 4
#define LCD_D5  22               //Data pin 5
#define LCD_D6  21               //Data pin 6
#define LCD_D7  14               //Data pin 7

//USE RPI numbers
#define DHT_PIN 21


int main(void){

	//init wiringPi protocol
  	wiringPiSetup();        
  
  	//init lcd
  	int lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);

  	lcdPuts(lcd, "Starting!");   


	float temp = 0.0f;
	float hum  = 0.0f;

	for (;;){
		//read sensors
		int result = pi_dht_read(DHT22, DHT_PIN, &temp, &hum);

		std::ostringstream oss;
		//oss << rand() % 100;
		oss <<  result <<" "<< temp <<"% "<< hum <<"%";
                
		std::stringstream ss; 
		ss << std::fixed << std::setprecision(2) << temp;

//		lcdPuts(lcd, ss.str().c_str());//oss.str().c_str());
                lcdPuts(lcd, oss.str().c_str());

		std::cout << oss.str().c_str() << std::endl;	

		delay(2000);
		lcdClear(lcd);
	}
}
