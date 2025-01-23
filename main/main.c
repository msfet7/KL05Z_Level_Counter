#include <stdio.h>
#include "MKL05Z4.h"
#include "i2c.h"
#include "frdm_bsp.h"
#include "boardControl.h"
#include "macroBlock.h"
#include "MMA.h"

void PORTA_IRQHandler(void){
    MMAIntControl();
}

void PIT_IRQHandler(void){
    PITIntControl();
}


int main(void){
    
    setup();

    MMAMode(1);    
    UART0->C2 |= UART0_C2_TE_MASK;

    while(TRUE){
        execute();
    }
    
}
