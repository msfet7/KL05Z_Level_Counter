#include <stdio.h>
#include "MKL05Z4.h"
#include "i2c.h"
#include "frdm_bsp.h"
#include "exec.h"
#include "macroBlock.h"


void setup();

int main(void){
    
    setup();
    I2C_WriteReg(ADDRESS, HP_FILTER_CUTOFF, 0x03);
    I2C_WriteReg(ADDRESS, XYZ_DATA_CFG_REG, 0x10 );
    I2C_WriteReg(ADDRESS, CTRL_REG1, 1 );
    UART0->C2 |= UART0_C2_TE_MASK;

    while(TRUE){
        execute();
    }
    
}


void setup(){
    // Clocks configuration
    SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
    SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
    SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);

    // PortB configuration
    PORTB->PCR[TX] = PORT_PCR_MUX(2);
    PORTB->PCR[RX] = PORT_PCR_MUX(2);
    PORTB->PCR[7] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PTB->PDDR |= (0 << 7);

    // UART configuration
    UART0->C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK );	
     //baudrate = clock/((OSR+1)*BR)
    UART0->C4 = UART0_C4_OSR(13);
    UART0->BDH = UART0_BDH_SBR(0);
    UART0->BDL = UART0_BDH_SBR(13);
    // Even Partity, 8 bits, one stop bit
    // All registers are cleared :)

    // I2C cofiguration (all in mighty library👼)
    I2C_Init();

    
    
}