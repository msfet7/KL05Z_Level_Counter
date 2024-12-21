#include <stdio.h>
#include "MKL05Z4.h"
#include "i2c.h"
#include "frdm_bsp.h"
#include "macroBlock.h"


void setup();

int main(void){
    uint8_t isClicked = 0;
    uint8_t status;
    uint8_t accVal[6];
    float x = 0;
    float y = 0;
    float z = 0;
    char data[45] = {0x20};
    uint8_t length = 0;
    uint16_t endCycle = 0;
    
    setup();
    I2C_Init();
    I2C_WriteReg(ADDRESS, HP_FILTER_CUTOFF, 0);
    I2C_WriteReg(ADDRESS, XYZ_DATA_CFG_REG, 0x10 );
    


    UART0->C2 |= UART0_C2_TE_MASK;
    while(TRUE){
        if(!((PTB->PDIR)&(1 << 7))){
            isClicked = 1;
            I2C_WriteReg(ADDRESS, CTRL_REG1, 1 );
        }    

        I2C_ReadReg(ADDRESS, STATUS, &status);

        if(status & (1 << 3)){
            I2C_ReadRegBlock(ADDRESS, ACC_DATA_REGS, 6, accVal);
        }

        x = (float)((int16_t)((accVal[0] << 8)|accVal[1]) >> 2)/4096;
        y = (float)((int16_t)((accVal[2] << 8)|accVal[3]) >> 2)/4096;
        z = (float)((int16_t)((accVal[4] << 8)|accVal[5]) >> 2)/4096;
        length = sprintf(data, "%d; %.2f; %.2f; %.2f\n", endCycle+1 ,x , y, z);

        if(isClicked){
            for(int i = 0; i < length; i++){
                while(!(UART0->S1 & UART0_S1_TDRE_MASK));
                //DELAY(35);
                UART0->D = data[i];     
            }
            DELAY(100)
            endCycle++;
        }
        // 500 in 20s
        if(endCycle == 300) {
            isClicked = 0;
            endCycle = 0;
            if(((UART0->S1) & UART0_S1_TDRE_MASK)){
                UART0->D = '\n';
            }
            I2C_WriteReg(ADDRESS, CTRL_REG1, 0 );
        }

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
    
}