#ifndef myNewLib_INCLUDED
#define myNewLib_INCLUDED

//#include </usr/include/sys/_types/_size_t.h>
#include <stdio.h> // for size_t
//#include </Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/6.1.0/include/stdint.h>

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2
#define LCD_5x8DOTS 0x00


class myPrint {
	friend class myLiquidCrystal;
	public:
		myPrint();
		size_t print(const char[]);
		size_t print(unsigned long, int = DEC);
		size_t print(double, int = 2);
	    virtual size_t write(uint8_t) = 0;

//	protected:
//	    //helper TFT reference
//	    TFT            *tft2;
};



class myLiquidCrystal: public myPrint{
	public:
	myLiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1,
				uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6,
				uint8_t d7);
	myLiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0,
				uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5,
				uint8_t d6, uint8_t d7);
		myLiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0,
				uint8_t d1, uint8_t d2, uint8_t d3);
		myLiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1,
				uint8_t d2, uint8_t d3);
		void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);
		void setCursor(uint8_t, uint8_t);
		void clear();
		//TODO
		virtual size_t write(uint8_t);

	};


class DHT {
	public:
		DHT(uint8_t pin, uint8_t type, uint8_t count = 6);
		void begin(void);
		float readHumidity(bool force = false);
		float readTemperature(bool S = false, bool force = false);
};


void pinMode(uint8_t pin, uint8_t mode);

void digitalWrite(uint8_t pin, uint8_t val);


//}
#endif //myNewLib_INCLUDED
