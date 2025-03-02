# Level Counter
## Description
Repo contains code for a university project - Level Counter. I used [MKL05Z](https://kamami.pl/freedom-kinetis/199056-frdm-kl05z-zestaw-startowy-z-mikrokontrolerem-freescale-kinetis-kl05z-5906623434428.html)
dev board with attached [MMA8451Q](https://www.nxp.com/docs/en/data-sheet/MMA8451Q.pdf) accelerometer. As an external hardware I also used button, pin header 
and [LCD Screen](https://botland.com.pl/wyswietlacze-alfanumeryczne-i-graficzne/2351-wyswietlacz-lcd-2x16-znakow-niebieski-konwerter-i2c-lcm1602-5904422309244.html).

## Hardware
The connections are showed at the diagram below:
```
KL05Z      Hardware              Config
-------------------------------------------
PTB1         USB                 UART_TX
PTB2         USB                 UART_RX
PTB3       ACC_SCL               I2C_SCL
           LCD_SCL
PTB4       ACC_SDA               I2C_SDA
           LCD_SDA
PTB6       BUTTON             INPUT_PULLUP
PTB7     PIN_HEADER           INPUT_PULLUP
PTA10     ACC_INT2          INPUT_AND_INT_ENABLE
```

## Working principle
The device uses an accelerometer data to detect sequences present during walking up or downstairs.\
It has implemented so called **Fused State Machine**, which is responsible just for that and also for eliminating any false triggers.\
All of the details are described in the documentation (for the time of creation this README<2.03.2025> there is only polish version available. English version is in progress 😊).


##
Author: Mateusz Szpot \
Date: Dec 2024 - Jan 2025
