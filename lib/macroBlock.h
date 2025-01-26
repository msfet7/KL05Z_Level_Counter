// UART pins
#define TX 1
#define RX 2
#define BTTN 7
#define INT2 10

// values for timer
#define FINAL_TICKS 50     // 1 step ~ 10ms, time window = 500ms, FINAL_TICKS = time window / 1 step

// tresholds
#define ACTIVATION_TH -0.15
#define ACTIVATION_TH_HEX 0x12
#define DEXIT_TH 0.05
#define UEXIT_TH 0.10
#define ABSOLUTE_MAXIMUM_TH 0.45
#define ABSOLUTE_MINIMUM_TH -0.45

// debounce -> 50/1.25 [ms]
#define DEBOUNCE_COUNTER_HEX 0x12

// for future (i guess)
#define UNDER_TEST 0