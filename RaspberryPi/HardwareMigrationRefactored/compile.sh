

#g++ -Wall -std=c++11 -o lcdTime lcdTime.cpp -lwiringPi -lwiringPiDev

g++ -Wall -std=c++11 -o HMRefactored HardwareMigrationRefactored.cpp HardwareMigrationRefactored.h core/pi_dht_read.c core/pi_mmio.c core/common_dht_read.c core/myNewLib/myNewLib.cpp -lwiringPi -lwiringPiDev

