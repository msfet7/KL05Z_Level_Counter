/** 
* @file gui.c
* @author Mateusz Szpot
* @date December 2024, January 2025
*
* @brief File contains functions for LCD handling
*/

#include "gui.h"

#define STAIRS_TO_LVLS_DIV 12   // average number of stairs for one level

static uint16_t localStairsCount = 1;


void guiInit(){
    LCD1602_Init();
    LCD1602_Backlight(1);
}

void guiPrintStairs(uint16_t stairs){
    char str[17] = {0x20};

    // localStairsCount is used to minimalize screen flickering
    // Values are updated only if they changed
    if(stairs == localStairsCount) return;
    else{
        sprintf(str, "Stairs: %d", stairs);
        LCD1602_ClearAll();
        LCD1602_SetCursor(0,0);
        LCD1602_Print(str);
        sprintf(str, "Levels: %d", stairs/STAIRS_TO_LVLS_DIV);
        LCD1602_SetCursor(0,1);
        LCD1602_Print(str);
        localStairsCount = stairs;
    }

}

void showMessage(char* first, char* second){
    LCD1602_SetCursor(0,0);
    LCD1602_Print(first);
    LCD1602_SetCursor(0,1);
    LCD1602_Print(second);
}