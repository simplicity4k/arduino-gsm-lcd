#include "Screen.h"

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

/**
 * Default constructor.
 */
Screen::Screen() {
	lcd.begin(LCD_COLUMNS, LCD_LINES);
	lcd.backlight();
}

/**
 * Default destructor.
 */
Screen::~Screen() {
}

/**
 * Shows a left aligned message.
 *
 * @param char *msg
 * @param uint8_t line
 *
 * @return void
 */
void Screen::printMsgLeft(char *msg, uint8_t line) {
	lcd.setCursor(0, line);
	lcd.print(Printer::alignLeft(msg, LCD_COLUMNS));
}

/**
 * Shows a centered message.
 *
 * @param char *msg
 * @param uint8_t line
 *
 * @return void
 */
void Screen::printMsgCenter(char *msg, uint8_t line) {
	lcd.setCursor(0, line);
	lcd.print(Printer::alignCenter(msg, LCD_COLUMNS));
}

/**
 * Shows a right aligned message.
 *
 * @param char *msg
 * @param uint8_t line
 *
 * @return void
 */
void Screen::printMsgRight(char *msg, uint8_t line) {
	lcd.setCursor(0, line);
	lcd.print(Printer::alignRight(msg, LCD_COLUMNS));
}
