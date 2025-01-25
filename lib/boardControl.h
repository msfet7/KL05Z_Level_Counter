#ifndef BOARD_CONTROL
#define BOARD_CONTROL

#include <stdio.h>
#include "MKL05Z4.h"
#include "macroBlock.h"
#include "MMA.h"
#include "gui.h"


//void debug();
// function in loop
void execute();

// function in setup
void setup();

void debugControl();

//void debugState();

// MMA interrupt handler
void MMAIntControl();

// PIT interrupt handler
void PITIntControl();

#endif //BOARD_CONTROL