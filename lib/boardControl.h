/** 
* @file boardControl.h
* @author Mateusz Szpot
* @date December 2024, January 2025
*
* @brief File contains functions for setup, main loop and interrupt handlers
*/

#ifndef BOARD_CONTROL
#define BOARD_CONTROL

#include <stdio.h>
#include <math.h>
#include "MKL05Z4.h"
#include "macroBlock.h"
#include "MMA.h"
#include "gui.h"

/**
 * @brief Function with debug features - sending xyz data by UART
 */
void debug();

/**
 * @brief Function detecting stairs
 */
void execute();

/**
 * @brief Setup function
 */
void setup();

/**
 * @brief Function for setting debug or execute mod
 */
void debugControl();

/**
 * @brief Function returning value of a private variable isDebug (isDebug getter)
 * @return isDebug variable
 */
uint8_t debugState();

/**
 * @brief MMA accelerometer interrupt handler
 */
void MMAIntControl();

/**
 * @brief PIT Timer interrupt handler
 */
void PITIntControl();

#endif //BOARD_CONTROL