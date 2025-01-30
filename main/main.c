///////////////////////////////////////////////////////////////
/**
*   @file main.c 
*   @author Mateusz Szpot
*   @date December 2024, January 2025
*   @brief Level counter using accelerometer
*/
///////////////////////////////////////////////////////////////

#include "MMA.h"
#include "boardControl.h"


void PORTA_IRQHandler(void){
    MMAIntControl();
}


void PIT_IRQHandler(void){
    PITIntControl();
}


int main(void){
    
    // setup
    setup();
    debugControl();
    MMAMode(1);    

    // main loop
    while(TRUE){
        if(debugState() == 0){
            execute();
        }else{
            debug();
        }   
    }
    
}
