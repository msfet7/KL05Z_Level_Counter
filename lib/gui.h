/** 
* @file gui.h
* @author Mateusz Szpot
* @date December 2024, January 2025
*
* @brief File contains functions for LCD handling
*/

#ifndef GUI
#define GUI

#include <stdio.h>
#include "lcd1602.h"

/**
 * @brief Initialization of the LCD Screen
 */
void guiInit();

/**
 * @brief Function for printing number of stairs and levels
 * @param numbers of counted stairs
 */
void guiPrintStairs(uint16_t);

/**
 * @brief function for "hot showing" messeges
 * @param text displayed on the first line
 * @param text displayed on the second line
 */
void showMessage(char*, char*);

#endif //GUI