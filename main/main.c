///////////////////////////////////////////////////////////
// Project name: Floor counter
// Author: Mateusz Szpot
// Field of study: Electronics
///////////////////////////////////////////////////////////
#include <stdio.h>
#include "MKL05Z4.h"
#include "i2c.h"
#include "frdm_bsp.h"
#include "boardControl.h"
#include "macroBlock.h"
#include "MMA.h"

void PORTA_IRQHandler(void){
    intControl();
}


int main(void){
    
    setup();

    MMAMode(1);    
    UART0->C2 |= UART0_C2_TE_MASK;

    while(TRUE){
        execute();
    }
    
}
