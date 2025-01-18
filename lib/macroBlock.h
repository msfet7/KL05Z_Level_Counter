// UART pins
#define TX 1
#define RX 2
#define BTTN 7
#define INT2 10


// tresholds
#define ACTIVATION_TH -0.15
#define ACTIVATION_TH_HEX 0x03
#define DEXIT_TH 0.03
#define UEXIT_TH 0.10
#define ABSOLUTE_MAXIMUM_TH 0.4
#define ABSOLUTE_MINIMUM_TH -0.4

// debounce -> 50/1.25 [ms]
#define DEBOUNCE_COUNTER_HEX 0x28

// for future (i guess)
#define UNDER_TEST 0