#ifndef SCREEN_H_
#define SCREEN_H_

#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#include "Printer.h"

const uint8_t LCD_COLUMNS = 20;
const uint8_t LCD_LINES = 4;

class Screen {

public:
	Screen();
	virtual ~Screen();

	void printMsgLeft(char *msg, uint8_t line);
	void printMsgCenter(char *msg, uint8_t line);
	void printMsgRight(char *msg, uint8_t line);

};

#endif
