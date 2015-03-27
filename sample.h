#ifndef _sample_H_
#define _sample_H_

#include "Arduino.h"
#include "api/Screen.h"
#include "api/GSMShield.h"
#include "TaskScheduler.h"

#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
}
#endif

void gmsShieldCallback();
void gsmShieldReceiveSmsCallback();

#endif
