/*
 * Constants.h
 *
 *  Created on: 31 Mar 2017
 *      Author: sgerasimou
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_


// DHT
#define DHT_PIN 21     		//Analog 1
#define DHT_TYPE 22   	//DHT 22  (AM2302)

//#define INPUT 0x0
//#define OUTPUT 0x1

//#define HIGH 0x1
//#define LOW  0x0

//TMP102
#define TMP102_I2CADDR 0x48	//TMP 102 address

//LCD 16x2
#define LCD_RS 0
#define LCD_ENABLE 2
#define LCD_D0 21
#define LCD_D1 22
#define LCD_D2 23
#define LCD_D3 24

// TFT Parameters for the Uno
#define TFT_RST  8
#define TFT_DC   9
#define TFT_CS 10

// LED
#define LED_PIN 25			//Analog 0

//Piezobuzzer
#define MELODYPIN 17		//Analog 3




#endif /* CONSTANTS_H_ */
