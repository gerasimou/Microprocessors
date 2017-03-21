################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/sgerasimou/Documents/Eclipse/Eclipse\ Arduino/Eclipse\ Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5/src/utility/Adafruit_GFX.cpp \
/Users/sgerasimou/Documents/Eclipse/Eclipse\ Arduino/Eclipse\ Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5/src/utility/Adafruit_ST7735.cpp 

C_SRCS += \
/Users/sgerasimou/Documents/Eclipse/Eclipse\ Arduino/Eclipse\ Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5/src/utility/glcdfont.c 

C_DEPS += \
./libraries/TFT/src/utility/glcdfont.c.d 

LINK_OBJ += \
./libraries/TFT/src/utility/Adafruit_GFX.cpp.o \
./libraries/TFT/src/utility/Adafruit_ST7735.cpp.o \
./libraries/TFT/src/utility/glcdfont.c.o 

CPP_DEPS += \
./libraries/TFT/src/utility/Adafruit_GFX.cpp.d \
./libraries/TFT/src/utility/Adafruit_ST7735.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/TFT/src/utility/Adafruit_GFX.cpp.o: /Users/sgerasimou/Documents/Eclipse/Eclipse\ Arduino/Eclipse\ Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5/src/utility/Adafruit_GFX.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/cores/arduino" -I"/Users/sgerasimou/Documents/Programming/sloeber-workspace/AllSensors/core/Sensors" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/variants/standard" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/LiquidCrystal/1.0.4" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/LiquidCrystal/1.0.4/src" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire/src" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/SPI" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/SPI/src" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/TFT/src/utility/Adafruit_ST7735.cpp.o: /Users/sgerasimou/Documents/Eclipse/Eclipse\ Arduino/Eclipse\ Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5/src/utility/Adafruit_ST7735.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/cores/arduino" -I"/Users/sgerasimou/Documents/Programming/sloeber-workspace/AllSensors/core/Sensors" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/variants/standard" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/LiquidCrystal/1.0.4" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/LiquidCrystal/1.0.4/src" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire/src" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/SPI" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/SPI/src" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/TFT/src/utility/glcdfont.c.o: /Users/sgerasimou/Documents/Eclipse/Eclipse\ Arduino/Eclipse\ Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5/src/utility/glcdfont.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/cores/arduino" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/variants/standard" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/LiquidCrystal/1.0.4" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/LiquidCrystal/1.0.4/src" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire/src" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/SPI" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/SPI/src" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5" -I"/Users/sgerasimou/Documents/Eclipse/Eclipse Arduino/Eclipse Arduino.app/Contents/Eclipse/arduinoPlugin/libraries/TFT/1.0.5/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


