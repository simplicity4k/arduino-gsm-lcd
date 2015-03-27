#ifndef API_GSMSHIELD_H_
#define API_GSMSHIELD_H_

#include "GSM.h"
#include "Screen.h"

class GSMShield {

private:
	GSM gsm;
	GSMScanner scanner;
	GSMModem modem;
	GSM_SMS sms;

	char *pin = "0000";
	Screen *screen;

	boolean connected = false;
	int nbMsg = 0;

public:
	GSMShield();
	GSMShield(char *pin);
	GSMShield(char *pin, Screen *screen);
	virtual ~GSMShield();

	void connect();
	void receiveSms();
	void sendSms(char *nbr, char *msg);

	boolean isConnected();
};

#endif
