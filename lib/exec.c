#include "exec.h"

//int main(){

// data
char data[45] = {0x20};
float x = 0;
float y = 0;
float z = 0;
uint8_t length = 0;
uint16_t endCycle = 0;
uint8_t status;
uint8_t accVal[2];
//uint8_t isDetected = 0;
int8_t isDetected = 0; //noninterrupt
uint8_t isClicked = 0;
uint8_t isCatched = 0;
uint8_t isReady = 0;

//while(1){

//function declaration for test
#if UNDER_TEST == 1
void execute(){
    if(!((PTB->PDIR)&(1 << 7))){
        isClicked = 1;
        MMAMode(1);
    }    

    x = MMAGetAccXVal();
    y = MMAGetAccYVal();
    z = MMAGetAccZVal();
    length = sprintf(data, "%d; %.2f; %.2f; %.2f\n", endCycle+1 ,x , y, z);

    if(isClicked){
        for(int i = 0; i < length; i++){
            while(!(UART0->S1 & UART0_S1_TDRE_MASK));
            //DELAY(35);
            UART0->D = data[i];     
        }
        DELAY(50)
        endCycle++;
    }
    // 500 in 20s
    if(endCycle == 1200) {
        isClicked = 0;
        endCycle = 0;
        if(((UART0->S1) & UART0_S1_TDRE_MASK)){
            UART0->D = '\n';
        }
        MMAMode(0);
    }

}

// function declaration for use
#else
void execute(){
    x = MMAGetAccXVal();

    // interupt simulation
    if(x < ACTIVATION_TH && x > ACTIVATION_TH - 0.05 && isDetected == 0) isDetected = 1;

    //noninterrupt
    if(isDetected == -2){
        if(x > 0) isDetected = 0;
    }
    if(isDetected == 2){
        if(x < 0) isDetected = 0;
    }

    // after "interupt" execution
    while(isDetected == 1){        
        x = MMAGetAccXVal();
        
        /*
        length = sprintf(data, "%.2f\n", x);
        for(int i = 0; i < length; i++){
            while(!(UART0->S1 & UART0_S1_TDRE_MASK));
            //DELAY(35);
            UART0->D = data[i];     
        }
        */
        
        // explenation in documentation (there isn't any for now XD)
        if(x > DEXIT_TH && isReady == 0) isReady = 1;
        if(x > UEXIT_TH && isCatched == 0 && isReady == 1) isCatched = 1;
        if(x < UEXIT_TH && isCatched == 1){
            while(!(UART0->S1 & UART0_S1_TDRE_MASK));
            UART0->D = 'a';
            

            isCatched = isDetected = isReady = 0;
            break;
            
        }
        if(x < DEXIT_TH && isReady == 1){
            while(!(UART0->S1 & UART0_S1_TDRE_MASK));
            UART0->D = 'b';
            
            isCatched = isDetected = isReady = 0;
            break;
        }
        if(x > ABSOLUTE_MAXIMUM_TH || x < ABSOLUTE_MINIMUM_TH){
            isCatched = isReady = 0;
            isDetected = x < 0 ? -2 : 2; // only for noninterrupt code - interrupt version = bye bye
            break;
        }
    }
}

//}}
#endif

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

    //MMA accelerometer configuration
    MMABasicSetup();
}