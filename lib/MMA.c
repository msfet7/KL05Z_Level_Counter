#include "MMA.h"


// accelerometer registers
#define ADDRESS 0x1d
#define STATUS_REG 0x00
#define OUT_X_REG 0x01
#define OUT_Y_REG 0x03
#define OUT_Z_REG 0x05
#define INT_SOURCE_REG 0x0c
#define XYZ_DATA_CFG_REG 0x0e
#define HP_FILTER_CUTOFF 0x0f
#define FF_MT_CFG_REG 0x15
#define FF_MT_SRC_REG 0x16
#define FF_MT_THS_REG 0x17
#define FF_MT_COUNT_REG 0x18
#define CTRL_REG1 0x2a
#define CTRL_REG4 0x2d
#define CTRL_REG5 0X2e

//accelerometer bits
#define XDR 0
#define YDR 1
#define ZDR 2
#define XHE 1
#define XHP 0
#define SRC_FF_MT 2
#define INT_EN_FF_MT 2
#define INT_CFG_FF_MT 2

void MMABasicSetup(){
    // filter cutoff frequency set 
    I2C_WriteReg(ADDRESS, HP_FILTER_CUTOFF, 0x03);

    // filter turn on
    I2C_WriteReg(ADDRESS, XYZ_DATA_CFG_REG, 0x10 );
}

void MMATHSetup(){
    // standby mode
    MMAMode(0);

    // configure accelerometer to detect motion on X axis
    I2C_WriteReg(ADDRESS, FF_MT_CFG_REG, 0xc8);

    // set the treshold value
    I2C_WriteReg(ADDRESS, FF_MT_THS_REG, ACTIVATION_TH_HEX);
    // set the debounce counter
    I2C_WriteReg(ADDRESS, FF_MT_COUNT_REG, DEBOUNCE_COUNTER_HEX);

    // enable interrupt
    I2C_WriteReg(ADDRESS, CTRL_REG4, (1 << INT_EN_FF_MT));

    // route interrupt to INT2 (connected to PTA10)
    I2C_WriteReg(ADDRESS, CTRL_REG5, (0 << INT_CFG_FF_MT));

    //active mode
    MMAMode(1);
}

void MMAMode(uint8_t isActive){
    I2C_WriteReg(ADDRESS, CTRL_REG1, isActive );
}

uint8_t MMAINTCheck(){
    uint8_t sourceINT = 0;
    uint8_t isMotionFall = 0;

    // dual read was needed, because sometimes the actual value of the INT_SOURCE_REG wasn't correct 
    I2C_ReadReg(ADDRESS, INT_SOURCE_REG, &sourceINT);
    I2C_ReadReg(ADDRESS, INT_SOURCE_REG, &sourceINT);
    
    if((sourceINT & (1 << SRC_FF_MT)) == 0x04){
        I2C_ReadReg(ADDRESS, FF_MT_SRC_REG, &isMotionFall);

        if(((isMotionFall) & ((1 << XHE) | (1 << XHP))) == 0x03) return 2; // interrupt detected - negative g 
        else if(((isMotionFall) & ((1 << XHE) | (1 << XHP))) == 0x02) return 1; // interrupt detected - positive g 
        else return 0; // no interrupt detected
    } 
    
    // this is (theoretically) unattainable point of function
    return 3 ; // no interrupt detected
}

float MMAGetAccXVal(){
    uint8_t accVal[2];
    uint8_t status = 0;
    
    static float returnX = 0.0;
    I2C_ReadReg(ADDRESS, STATUS_REG, &status);
    if(status & (1 << XDR)){
        I2C_ReadRegBlock(ADDRESS, OUT_X_REG, 2, accVal);
        returnX = (float)((int16_t)((accVal[0] << 8)|accVal[1]) >> 2)/4096;
    } 
       

    return returnX;
}

float MMAGetAccYVal(){
    uint8_t accVal[2];
    uint8_t status = 0;
    static float returnY = 0.0;
    I2C_ReadReg(ADDRESS, STATUS_REG, &status);
    if(status & (1 << YDR)){
        I2C_ReadRegBlock(ADDRESS, OUT_Y_REG, 2, accVal);
        returnY = (float)((int16_t)((accVal[0] << 8)|accVal[1]) >> 2)/4096;
    } 
       

    return returnY;
}

float MMAGetAccZVal(){
    uint8_t accVal[2];
    uint8_t status = 0;
    static float returnZ = 0.0;
    I2C_ReadReg(ADDRESS, STATUS_REG, &status);
    if(status & (1 << ZDR)){
        I2C_ReadRegBlock(ADDRESS, OUT_Z_REG, 2, accVal);
        returnZ = (float)((int16_t)((accVal[0] << 8)|accVal[1]) >> 2)/4096;
    } 
       

    return returnZ;
}

