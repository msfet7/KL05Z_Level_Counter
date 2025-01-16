#include "i2c.h"

// setup of basic accelerometer parameters
void MMABasicSetup();

// tresholds setup - for interrupts
void MMATHSetup();

// function for mode changing
void MMAMode(uint8_t);

// retrieving X data from accelerometer
float MMAGetAccXVal();

// retrieving y data from accelerometer
float MMAGetAccYVal();

// retrieving z data from accelerometer
float MMAGetAccZVal();