#include "Arduino.h"
/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
*/

//Libraries
#include <DHT.h>
#include <Wire.h>
#include "Adafruit_HTU21DF.h"


//Constants
#define DHTPIN 15     		// what pin we're connected to
#define LEDPIN 14     		// what pin we're connected to
#define DHTTYPE DHT22   	// DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE); 	// Initialize DHT sensor for normal 16mhz Arduino

Adafruit_HTU21DF htu = Adafruit_HTU21DF();


//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting!");
  pinMode(LEDPIN, OUTPUT);  // Set digital pin 2 -> output
  dht.begin();

  if (!htu.begin()) {
     Serial.println("Couldn't find sensor!");
     while (1);
   }
}

void runDHT22()
{
	//Read data and store it to variables hum and temp
	hum		= dht.readHumidity();
    temp	= dht.readTemperature();

    //Print temp and humidity values to serial monitor
	Serial.print("DHT\t\tHumidity: ");
	Serial.print(hum);
	Serial.print("\tTemp: ");
	Serial.println(temp);
}

void runHTU()
{
	 hum	= htu.readHumidity();
     temp	= htu.readTemperature();

	 Serial.print("HTU\t\tHumidity: ");
	 Serial.print(hum);
	 Serial.print("\tTemp: ");
	 Serial.println(temp);
}

void loop()
{
	digitalWrite(LEDPIN, LOW);      // Pin 12 = 5 V, LED emits light
    delay(2000);
	digitalWrite(LEDPIN, HIGH);      // Pin 12 = 5 V, LED emits light
	runDHT22();
	runHTU();
	delay(100);
}
