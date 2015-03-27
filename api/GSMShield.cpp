#include "GSMShield.h"

/**
 * Default constructor.
 */
GSMShield::GSMShield() {
	Serial.print("Pin : ");
	Serial.println(this->pin);
}

/**
 * Constructor with pin parameter.
 *
 * @param char *pin
 */
GSMShield::GSMShield(char *pin) {
	this->pin = pin;
	Serial.print("Pin : ");
	Serial.println(this->pin);
	Serial.println();
}

/**
 * Constructor with pin parameter.
 *
 * @param char *pin
 * @param Screen *screen
 */
GSMShield::GSMShield(char *pin, Screen *screen) {
	this->pin = pin;
	this->screen = screen;
	Serial.print("Pin : ");
	Serial.println(this->pin);
	Serial.println();
}

/**
 * Default destructor.
 */
GSMShield::~GSMShield() {
}

void GSMShield::connect() {
	if (this->gsm.begin(this->pin) == GSM_READY) {
		this->connected = true;
		if(this->screen == NULL) {
			Serial.println("Connection etablie.");
			Serial.print("Reseau : ");
			Serial.println(scanner.getCurrentCarrier());
			Serial.print("Signal : ");
			Serial.print(scanner.getSignalStrength());
			Serial.println("/31");
			Serial.println();
		}
		else {
			delay(1000);
			char *buffer = new char[21];
			strcat(buffer, (char *) scanner.getCurrentCarrier().c_str());
			screen->printMsgLeft(buffer , 0);
		}
	}
}

void GSMShield::receiveSms() {
	char c;
	char nbr[20];
	while (sms.available()) {
		sms.remoteNumber(nbr, 20);
		Serial.print(nbr);
		Serial.print(" : ");
		while (c = sms.read()) {
			Serial.print(c);
		}
		Serial.println("");
		sms.flush();
		this->sendSms(nbr, "Message recu par l'Arduino !");
	}
}

void GSMShield::sendSms(char *nbr, char *msg) {
	this->sms.beginSMS(nbr);
	this->sms.print(msg);
	this->sms.endSMS();
	Serial.print("Envoi a ");
	Serial.print(nbr);
	Serial.print(" du message '");
	Serial.print(msg);
	Serial.println("'");
	Serial.println("");
}

boolean GSMShield::isConnected() {
	return this->connected;
}
