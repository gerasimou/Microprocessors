

#g++ -Wall -std=c++11 -o lcdTime lcdTime.cpp -lwiringPi -lwiringPiDev

g++ -Wall -std=c++11 -o dhtLCD mainDHT.cpp pi_dht_read.c pi_mmio.c common_dht_read.c -lwiringPi -lwiringPiDev

