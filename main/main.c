#include <stdio.h>
#include "MKL05Z4.h"
#include "i2c.h"
#include "frdm_bsp.h"
#include "exec.h"
#include "macroBlock.h"
#include "MMA.h"



int main(void){
    
    setup();
    
    MMAMode(1);
    
    UART0->C2 |= UART0_C2_TE_MASK;

    while(TRUE){
        execute();
    }
    
}
