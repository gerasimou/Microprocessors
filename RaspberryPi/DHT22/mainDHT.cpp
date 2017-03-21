#include "common_dht_read.h"
#include "pi_dht_read.h"
#include <stdio.h>

int main(void){

	float temp = 0.0f;
	float hum  = 0.0f;
	int   pin  = 21; 

	int result = pi_dht_read(DHT22, pin, &temp, &hum);

	printf("%d\t %.2f\t %.2f", result, temp, hum);
}
