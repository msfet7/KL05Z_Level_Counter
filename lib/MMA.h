/** 
* @file MMA.h
* @author Mateusz Szpot
* @date December 2024, January 2025
*
* @brief File contains functions for MMA accelerometer (setup, interrupt, axis data acquisition)
*/

#ifndef MMA
#define MMA

#include "i2c.h"
#include "macroBlock.h"

/**
 * @brief Setup of the basic accelerometer parameters
 */
void MMABasicSetup();

/**
 * @brief Tresholds setup - for interrupts
 */
void MMATHSetup();

/**
 * @brief Function for mode changing
 * @param HIGHorLOW state
 */
void MMAMode(uint8_t);

/**
 * @brief Interrupt check function
 * @returns 0(no interrupt), 1(positive interrupt), 2(negative interrupt)
 */
uint8_t MMAINTCheck();

/**
 * @brief X Axis data data acquisition
 * @returns X axis value
 */
float MMAGetAccXVal();

/**
 * @brief Y Axis data data acquisition
 * @returns Y axis value
 */
float MMAGetAccYVal();

/**
 * @brief Z Axis data data acquisition
 * @returns Z axis value
 */
float MMAGetAccZVal();

#endif //MMA