################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Adafruit_HTU21DF_Library/Adafruit_HTU21DF.cpp 

LINK_OBJ += \
./Adafruit_HTU21DF_Library/Adafruit_HTU21DF.cpp.o 

CPP_DEPS += \
./Adafruit_HTU21DF_Library/Adafruit_HTU21DF.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Adafruit_HTU21DF_Library/Adafruit_HTU21DF.cpp.o: ../Adafruit_HTU21DF_Library/Adafruit_HTU21DF.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/cores/arduino" -I"/Users/sgerasimou/Documents/Programming/sloeber-workspace/DHT22Sensor/core/Sensors" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/variants/standard" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


