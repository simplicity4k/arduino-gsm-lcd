#ifndef API_PRINTER_H_
#define API_PRINTER_H_

#include <string.h>
#include <ctype.h>
#include <stdint.h>

class Printer {

public:
	static char *alignLeft(char *msg, uint8_t length);
	static char *alignCenter(char *msg, uint8_t length);
	static char *alignRight(char *msg, uint8_t length);

private:
	static char *ltrim(char *str);
	static char *rtrim(char *str);
	static char *trim(char *str);
};

#endif
