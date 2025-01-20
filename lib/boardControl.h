#include <stdio.h>
#include "MKL05Z4.h"
#include "macroBlock.h"
#include "i2c.h"
#include "MMA.h"

// function in loop
void execute();

// function in setup
void setup();

// interrupt handler
void intControl();