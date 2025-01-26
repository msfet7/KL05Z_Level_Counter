#ifndef BOARD_CONTROL
#define BOARD_CONTROL

#include <stdio.h>
#include "MKL05Z4.h"
#include "macroBlock.h"
#include "MMA.h"
#include "gui.h"

// function with debug features - sending xyz data by UART
void debug();

// function in loop
void execute();

// function in setup
void setup();

// changing which function is executing (debug or execute)
void debugControl();

// function returning value of a private variable isDebug
uint8_t debugState();

// MMA interrupt handler
void MMAIntControl();

// PIT interrupt handler
void PITIntControl();

#endif //BOARD_CONTROL