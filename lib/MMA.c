#include "MMA.h"


// accelerometer registers
#define ADDRESS 0x1d
#define XYZ_DATA_CFG_REG 0x0e
#define CTRL_REG1 0x2a
#define STATUS_REG 0x00
#define OUT_X_REG 0x01
#define OUT_Y_REG 0x03
#define OUT_Z_REG 0x05
#define HP_FILTER_CUTOFF 0x0f

//accelerometer bits
#define XDR 0
#define YDR 1
#define ZDR 2

void MMABasicSetup(){
    // filter cutoff frequency set 
    I2C_WriteReg(ADDRESS, HP_FILTER_CUTOFF, 0x03);

    // filter turn on
    I2C_WriteReg(ADDRESS, XYZ_DATA_CFG_REG, 0x10 );
}

void MMATHSetup(){
    return;
}

void MMAMode(uint8_t isActive){
    I2C_WriteReg(ADDRESS, CTRL_REG1, isActive );
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
    float returnY = 0.0;
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
    float returnZ = 0.0;
    I2C_ReadReg(ADDRESS, STATUS_REG, &status);
    if(status & (1 << ZDR)){
        I2C_ReadRegBlock(ADDRESS, OUT_Z_REG, 2, accVal);
        returnZ = (float)((int16_t)((accVal[0] << 8)|accVal[1]) >> 2)/4096;
    } 
       

    return returnZ;
}

