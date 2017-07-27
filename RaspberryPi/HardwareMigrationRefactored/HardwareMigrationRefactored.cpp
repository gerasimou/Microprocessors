// Do not remove the include below
#include "HardwareMigrationRefactored.h"

//Libraries
#include <stdio.h>
#include <wiringPi.h>          
#include "core/myNewLib/myNewLib.hpp"


// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHT_PIN, DHT_TYPE);

// Initialize the library with the numbers of the interface pins
myLiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_D0, LCD_D1, LCD_D2, LCD_D3);

//Variables
//int chk;
float hum; 	 				//Stores humidity value
float temp; 				//Stores temperature value

char output[5];				// char array to print to the screen
float temperature[3];
float humidity[3];


//The setup function is called once at startup of the sketch
void setup()
{
  //led
  pinMode(LED_PIN, OUTPUT);  // Set digital pin 2 -> output

  //init DHT
  dht.begin();

  //init  LCD: set up  number of columns and rows:
  lcd.begin(16, 2);

  //print messages
  lcd.print("Waiting");
}


void runDHT22()
{
	//Read data and store it to variables hum and temp
	hum		= dht.readHumidity();
    temp	= dht.readTemperature();

    temperature[0]  = temp;
    humidity[0]		= hum;
}


void showLCD(){

	lcd.setCursor(0, 0);
    lcd.print(millis() / 1000.0);   // print the number of seconds since reset:

    //Print temp and humidity values to lcd
    // set the cursor to column 0, line 0
	lcd.setCursor(6, 0);
    lcd.print(temperature[0]);

    lcd.setCursor(0, 1);
    lcd.print(temperature[1]);

	lcd.setCursor(6, 1);
	lcd.print(humidity[0]);

}


//int time window
unsigned long timeWindow = 10000;
unsigned long previous = millis();//-timeWindow*2;
unsigned long now = millis();

void loop(){
	//every 10s
	lcd.clear();
//	String s("Waiting ");
	do{
		now      = millis();
		lcd.setCursor(0,0);
		lcd.print("Waiting");
		lcd.setCursor(10,0);
		lcd.print(now/1000.0);
		delay(1000);
		lcd.clear();
	}
	while (now - previous < timeWindow);

	lcd.clear();
	previous = now;
	do {
		now      = millis();
		digitalWrite(LED_PIN, HIGH);      // Pin 12 = 5 V, LED emits light
		//run sensors
		runDHT22();
		//show messages on LCDs
		showLCD();
		digitalWrite(LED_PIN, LOW);      // Pin 12 = 5 V, LED emits light
		delay(2000);
	}
	while (now - previous < timeWindow);
	previous = now;
}



int main(void)
{
	setup();

	for (;;) {
		loop();
	}

	return 0;
}
