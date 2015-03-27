#include "Printer.h"

char *Printer::alignLeft(char *msg, uint8_t length) {
	msg = Printer::trim(msg);

	int msgLength = strlen(msg);
	if (msgLength > length) {
		return "Texte trop grand !";
	}

	char *buffer = new char[length + 1];

	int i = 0;
	for (; i < msgLength; i++) {
		buffer[i] = msg[i];
	}
	for (; i < length; i++) {
		buffer[i] = ' ';
	}
	buffer[i] = '\0';

	return buffer;
}

char *Printer::alignCenter(char *msg, uint8_t length) {
	msg = Printer::trim(msg);

	int msgLength = strlen(msg);
	if (msgLength > length) {
		return "Texte trop grand !";
	}

	char *buffer = new char[length + 1];
	int leftSize = ((length - msgLength) >> 1);

	int i = 0;
	int j = 0;
	for (; i < leftSize; i++) {
		buffer[i] = ' ';
	}
	for (; i < leftSize + msgLength; i++, j++) {
		buffer[i] = msg[j];
	}
	for (; i < (length); i++) {
		buffer[i] = ' ';
	}
	buffer[i] = '\0';

	return buffer;
}

char *Printer::alignRight(char *msg, uint8_t length) {
	msg = Printer::trim(msg);

	int msgLength = strlen(msg);
	if (msgLength > length) {
		return "Texte trop grand !";
	}

	char *buffer = new char[length + 1];
	int leftSize = length - msgLength;

	int i = 0;
	int j = 0;
	for (; i < leftSize; i++) {
		buffer[i] = ' ';
	}
	for (; i < length; i++, j++) {
		buffer[i] = msg[j];
	}
	buffer[i] = '\0';

	return buffer;
}

char *Printer::ltrim(char *str) {
	while (isspace(*str)) {
		str++;
	}
	return str;
}

char *Printer::rtrim(char *str) {
	char *back = str + strlen(str);
	while (isspace(*--back)) {
	}
	*(back + 1) = '\0';
	return str;
}

char *Printer::trim(char *str) {
	return Printer::rtrim(Printer::ltrim(str));
}
