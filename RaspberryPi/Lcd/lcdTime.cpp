#include <wiringPi.h>          
#include <lcd.h>               
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include <iostream>

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  0               //Register select pin
#define LCD_E   2               //Enable Pin
#define LCD_D4  21               //Data pin 4
#define LCD_D5  22               //Data pin 5
#define LCD_D6  23               //Data pin 6
#define LCD_D7  24               //Data pin 7

int main()
{
    int lcd;               
  wiringPiSetup();        
  lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
              
   lcdPuts(lcd, "Hello, world!");   
	for (;;){
		std::ostringstream oss;
		oss << rand() % 100;

		lcdPuts(lcd, oss.str().c_str());
		std::cout << oss.str().c_str() << std::endl;	

		delay(2000);
		lcdClear(lcd);
	}
}
