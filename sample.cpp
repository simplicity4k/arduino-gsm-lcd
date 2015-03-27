#include "sample.h"

Task gsmShieldTask(60000, -1, &gmsShieldCallback);
Task gsmShieldReceiveSmsTask(10000, -1, &gsmShieldReceiveSmsCallback);

Scheduler runner;
GSMShield *gsm;

void gmsShieldCallback() {
	if (!gsm->isConnected()) {
		gsm->connect();
		if (gsm->isConnected()) {
			runner.addTask(gsmShieldReceiveSmsTask);
			gsmShieldReceiveSmsTask.enable();
			Serial.println("En attente de reception de messages");
			Serial.println();
		}
	}
}

void gsmShieldReceiveSmsCallback() {
	if (gsm->isConnected()) {
		gsm->receiveSms();
	}
}

void setup() {
	Serial.begin(9600);
	Serial.println("Initialisation");

	gsm = new GSMShield("1234", new Screen());

	runner.init();
	runner.addTask(gsmShieldTask);
	gsmShieldTask.enable();
}

void loop() {
	runner.execute();
}
