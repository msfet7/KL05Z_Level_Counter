// UART pins
#define TX 1
#define RX 2

// accelerometer registers
#define ADDRESS 0x1d
#define XYZ_DATA_CFG_REG 0x0e
#define CTRL_REG1 0x2a
#define STATUS_REG 0x00
#define ACC_DATA_REGS 0x01
#define HP_FILTER_CUTOFF 0x0f

// tresholds
#define ACTIVATION_TH -0.15
#define DEXIT_TH 0.03
#define UEXIT_TH 0.10
#define ABSOLUTE_MAXIMUM_TH 0.4
#define ABSOLUTE_MINIMUM_TH -0.4

// for future (i guess)
#define UNDER_TEST 0