#ifndef GUI
#define GUI

#include <stdio.h>
#include "lcd1602.h"

// GUI init
void guiInit();

// function for printing number of stairs and levels
void guiPrintStairs(uint16_t);

// function for "hot showing" messeges
void showMessage(char*, char*);

#endif //GUI