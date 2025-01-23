#include "boardControl.h"

// accelerometer axis data
typedef struct{
    float x;
    float y;
    float z;
} accData;

//states for fused state machine
// more in documentation
typedef enum{
    NIHIL,      //nothing
    ACTIVE,     //active state
    DOWNTH,     //down treshold
    UPTH,       //up treshold
    STRPP       //stair++
} state;

//int main(){

// data

static char data[45] = {0x20};
static uint8_t length = 0;
static uint16_t endCycle = 0;

static uint8_t isDetected = 0;
volatile uint8_t intDetected = 0;

volatile uint16_t ticks = 0;

static int16_t stairsCounted = 0;

//while(1){

//function declaration for test
#if UNDER_TEST == 1
void execute(){
    if(!((PTB->PDIR) & (1 << BTTN))){
        isClicked = 1;
        MMAMode(1);
    }    
    accData axis = {MMAGetAccXVal(), MMAGetAccYVal(), MMAGetAccZVal()};
    
    length = sprintf(data, "%d; %.2f; %.2f; %.2f\n", endCycle+1 ,axis.x , axis.y, axis.z);

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
    accData axis = {MMAGetAccXVal(), MMAGetAccYVal(), MMAGetAccZVal()};
    state currentState;
    ticks = 0;
    if(intDetected == 1){
        uint8_t gEvent = 0;
        gEvent = MMAINTCheck();

        // if in the future the positive g will be use - switch rest
        // otherwise switch will be replaced with single if
        switch (gEvent)
        {
        case 1:
            // for positive g - do nothing
            currentState = NIHIL;
            break;
        case 2:
            // for negative g - go active
            currentState = ACTIVE;
            break;        
        case 0:            
        default:
            break;
        }
        intDetected = 0;
    }else currentState = NIHIL;

    
    // begin of fused state machine (more in the documentation)
    while(currentState != NIHIL){        
        axis.x = MMAGetAccXVal();
        
        
        // timer breaker
        PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK;
        if(ticks == FINAL_TICKS){
            PIT->CHANNEL[0].TCTRL &= ~PIT_TCTRL_TEN_MASK;
            ticks = 0;
            currentState = NIHIL;
            break;
        }
    
        // breakers
        if(axis.x > ABSOLUTE_MAXIMUM_TH || axis.x < ABSOLUTE_MINIMUM_TH) {
            //isDetected = 0;
            currentState = NIHIL;
            break;
        }       

        // state machine
        switch (currentState){
        case ACTIVE:
            if(axis.x > DEXIT_TH) currentState = DOWNTH;
            break;
        case DOWNTH:
            if(axis.x > UEXIT_TH) currentState = UPTH;
            if(axis.x < DEXIT_TH) currentState = NIHIL;
            break;
        case UPTH:
            if(axis.x < UEXIT_TH) currentState = STRPP;
            break;
        case STRPP:
            length = sprintf(data, "%d \n", ticks);
            for(int i = 0; i < length; i++){
                while(!(UART0->S1 & UART0_S1_TDRE_MASK));
                //DELAY(35);
                UART0->D = data[i];     
            }       

            stairsCounted++;
            //isDetected = 0;
            currentState = NIHIL;
            break;
        default:
            break;
        }        
    }
    
}

//}}
#endif



void setup(){
    // Clocks configuration
    SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
    SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
    SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
    SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);

    // PortA cnfiguration
    PORTA->PCR[INT2] |= PORT_PCR_MUX(1);
    PORTA->PCR[INT2] |= PORT_PCR_IRQC(0xa);
    PTA->PDDR |= (0 << INT2);

    // PortB configuration
    PORTB->PCR[TX] |= PORT_PCR_MUX(2);
    PORTB->PCR[RX] |= PORT_PCR_MUX(2);
    PORTB->PCR[BTTN] |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PTB->PDDR |= (0 << BTTN);

    // Port interrupt configuration
    NVIC_SetPriority(PORTA_IRQn, 3);
    NVIC_ClearPendingIRQ(PORTA_IRQn);
    NVIC_EnableIRQ(PORTA_IRQn);

    // PIT configuration
    const uint32_t pitTick = SystemCoreClock / 100;         // Time * Clock; Time = 10ms
    PIT->MCR &= ~PIT_MCR_MDIS_MASK;
    PIT->CHANNEL[0].LDVAL = PIT_LDVAL_TSV(pitTick);
    PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK;
 
    // PIT interrupt  configuration
    //NVIC_SetPriority(PIT_IRQn, 2);
    NVIC_ClearPendingIRQ(PIT_IRQn);
	NVIC_EnableIRQ(PIT_IRQn);
    
    // UART configuration
    UART0->C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK );	
    UART0->C4 = UART0_C4_OSR(13);
    UART0->BDH = UART0_BDH_SBR(0);
    UART0->BDL = UART0_BDH_SBR(13); 
    //baudrate |= clock/((OSR+1)*BR)
    // Even Partity, 8 bits, one stop bit
    // All registers are cleared :)

    // I2C cofiguration (all in mighty library👼)
    I2C_Init();

    //MMA accelerometer configuration
    MMABasicSetup();
    MMATHSetup();
}

void MMAIntControl(){
    uint32_t isfValue = PORTA->ISFR & (1 << INT2);

    if(isfValue == (1 << INT2)){
        intDetected = 1;
    }
    PORTA->ISFR |= (1 << INT2);
    NVIC_ClearPendingIRQ(PORTA_IRQn);
}

void PITIntControl(){
    ticks++;
    PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
    NVIC_ClearPendingIRQ(PIT_IRQn);
}


// comment bin (called in polish "lista bubli")
/*
    length = sprintf(data, " %.2f    %d\n", axis.x, isDetected);
    for(int i = 0; i < length; i++){
        while(!(UART0->S1 & UART0_S1_TDRE_MASK));
        //DELAY(35);
        UART0->D = data[i];     
    } 
    
    
*/