# Universal Robot Controller (URC)

[![View PCB on KiCanvas](./assets/kicanvas_badge.svg)](https://kicanvas.org/?github=https://github.com/spikonado/URC/tree/main/pcb_design)

## Graphics

![Render](./assets/URC.png)

## Features

This is what the board can do:

- Can precisely control up to <ins>**4 Brushed DC Motors**</ins> with or without quadrature <ins>**encoders**</ins>.
- Can precisely control <ins>**Serial Bus Servos**</ins> from Feetech, Waveshare, etc.
- Communicate with and control a variety of <ins>**2D LiDARs**</ins>.
- Communicate with and control other robotics hardware through <ins>**CAN FD**</ins>.
- Supports voltages up to <ins>**36V**</ins>.
- Incredible support for <ins>**ROS 2**</ins>.

The board has two microcontrollers:

1. An [ESP32-S3 module](https://documentation.espressif.com/esp32-s3_datasheet_en.pdf), specifically the [ESP32-S3-WROOM-1-N16R8](https://documentation.espressif.com/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf), which comes with 16 MB flash and 8 MB PSRAM.
2. An [STM32G431KBU6](https://www.st.com/en/microcontrollers-microprocessors/stm32g431kb.html) being used specifically for motor control.

## Why?

There are no robot control boards out there that allow one to make a fully functional robot with just the board and a power source as the electronics.

Before this board existed, to make a robot that has 4 motors, 2 robot arms, and a LiDAR, one would need to buy the following:

1. A development board of a microcontroller like an ESP32.
2. A board that can connect to and control 4 DC Motors with quadrature encoders.
3. A board that can control Serial Bus Servos.
4. An SBC like a Raspberry Pi for the LiDAR.

And even after all of this, it would still be a headache to get all of that working together and using ROS 2 with it.

## Using the Board

1. Connect a USB-C cable to one of the board's USB-C ports.
2. If using the USB-CDC port, make sure to enable USB-CDC in Arduino IDE before trying to upload the firmware.
3. Flash one of the [firmware examples](./firmware_examples/).
4. Connect the board to the the peripherals you are using according to the wiring guide in the firmware examples.

## Zine

![Zine](./assets/zine.png)

## BOM

| Reference                                                  | Qty | Value / Part                | Footprint         | Manufacturer                       | MPN                                                                                             | Unit Price ($) | Total Price ($) |
| ---------------------------------------------------------- | --- | --------------------------- | ----------------- | ---------------------------------- | ----------------------------------------------------------------------------------------------- | -------------- | --------------- |
| C1,C3,C5,C6,C14,C15,C17,C18,C38                            | 9   | 10µF, 16V                   | C_0603_1608Metric | Murata Electronics                 | GRT188R61C106KE13D                                                                              | 0.447          | 4.023           |
| C2,C4,C7,C8,C9,C13,C16,C19,C20,C29,C32,C33,C37,C63,C64,C65 | 16  | 100nF, 16V                  | C_0402_1005Metric | Samsung Electro-Mechanics          | CL05B104KO5NNNC                                                                                 | 0.025          | 0.400           |
| C10,C11                                                    | 2   | 4.7µF, 50V                  | C_0805_2012Metric | Murata Electronics                 | GRT21BR61H475KE13L                                                                              | 0.940          | 1.880           |
| C12,C23,C26,C36,C41,C47,C53,C59                            | 8   | 100nF, 50V                  | C_0402_1005Metric | Murata Electronics                 | GRM155R61H104KE14D                                                                              | 0.120          | 0.960           |
| C21,C22,C24,C25,C34,C35,C42,C43,C45,C46,C51,C52,C57,C58    | 14  | 10µF, 50V                   | C_0805_2012Metric | Murata Electronics                 | GRM21BR61H106KE43L                                                                              | 0.608          | 8.512           |
| C27                                                        | 1   | 470pF, 50V                  | C_0402_1005Metric | YAGEO                              | CC0402KRX7R9BB471                                                                               | 0.304          | 0.304           |
| C28                                                        | 1   | 100µF                       | CP_Elec_8x6.9     | KEMET                              | A768KE107M1VLAS036                                                                              | 2.375          | 2.375           |
| C30,C31                                                    | 2   | 10pF, 1%                    | C_0402_1005Metric | Murata Electronics                 | GRT1555C1H100FA02D                                                                              | 0.245          | 0.490           |
| C39,C48,C54,C60                                            | 4   | 22nF, 50V                   | C_0402_1005Metric | Murata Electronics                 | GRM155R71H223JA12D                                                                              | 0.235          | 0.940           |
| C40,C49,C55,C61                                            | 4   | 220nF, 16V                  | C_0603_1608Metric | Samsung Electro-Mechanics          | CL10B224KO8NNNC                                                                                 | 0.251          | 1.004           |
| C44,C50,C56,C62                                            | 4   | 470nF, 10V                  | C_0402_1005Metric | Murata Electronics                 | GRM155R71A474KE01D                                                                              | 0.319          | 1.276           |
| D1,D2,D3,D5,D7,D8,D9,D10,D11,D12,D13,D14,D16               | 13  | SS14                        | D_SMA             | onsemi                             | SS14                                                                                            | 0.189          | 2.457           |
| D6                                                         | 1   | D_TVS_Dual_AAC              | SOT-23-3          | onsemi                             | NUP2105LT1G                                                                                     | 0.403          | 0.403           |
| J1,J2                                                      | 2   | USB-C Receptacle USB2.0 16P | USB4105-xx-A 16P  | GCT                                | USB4105-GF-A                                                                                    | 1.251          | 2.502           |
| J3,J6                                                      | 2   | XT60-M                      | XT60 Vertical     | Changzhou Amass Elec               | XT60-M                                                                                          | 0.906          | 1.812           |
| J7                                                         | 1   | 5267-03A                    | Molex SPOX 3-pin  | Molex                              | 22-03-5035                                                                                      | 0.564          | 0.564           |
| J8                                                         | 1   | Screw Terminal 1x05         | TB007-508-05      | Same Sky                           | TB007-508-05BE                                                                                  | 2.330          | 2.330           |
| J10,J11,J12,J13                                            | 4   | Screw Terminal 1x06         | TB007-508-06      | Same Sky                           | TB007-508-06BE                                                                                  | 2.736          | 10.944          |
| J15                                                        | 1   | JST SH 4-pin                | SM04B-SRSS-TB     | JST                                | SM04B-SRSS-TB                                                                                   | 2.013          | 2.013           |
| L1                                                         | 1   | 3.3µH                       | SRR1210A          | Bourns                             | SRR1210-3R3Y                                                                                    | 2.278          | 2.278           |
| Q1,Q2                                                      | 2   | MMBT3904                    | SOT-23            | onsemi                             | MMBT3904LT1G                                                                                    | 0.509          | 1.018           |
| Q3                                                         | 1   | MMBT3906                    | SOT-23            | onsemi                             | MMBT3906LT1G                                                                                    | 1.198          | 1.198           |
| R1,R2,R3,R4                                                | 4   | 5.1kΩ, 0.1%                 | R_0402_1005Metric | Panasonic                          | ERA-2AEB512X                                                                                    | 0.473          | 1.892           |
| R5                                                         | 1   | 1kΩ, 5%                     | R_0402_1005Metric | YAGEO                              | RC0402JR-071KL                                                                                  | 0.132          | 0.132           |
| R6                                                         | 1   | 22.1kΩ, 1%                  | R_0402_1005Metric | Panasonic                          | ERJ-2RKF2212X                                                                                   | 0.485          | 0.485           |
| R7                                                         | 1   | 47.5kΩ, 1%                  | R_0402_1005Metric | YAGEO                              | RC0402FR-0747K5L                                                                                | 0.123          | 0.123           |
| R8,R11,R12,R15,R17,R19,R20,R23,R24,R26,R27,R29,R30,R31     | 14  | 10kΩ, 5%                    | R_0402_1005Metric | YAGEO                              | RC0402JR-0710KL                                                                                 | 0.015          | 0.210           |
| R9                                                         | 1   | 100kΩ, 0.1%                 | R_0402_1005Metric | YAGEO                              | RT0402BRE07100KL                                                                                | 1.542          | 1.542           |
| R10                                                        | 1   | 19.1kΩ, 0.1%                | R_0402_1005Metric | YAGEO                              | RT0402BRD0719K1L                                                                                | 1.475          | 1.475           |
| R13                                                        | 1   | 20kΩ, 5%                    | R_0402_1005Metric | YAGEO                              | RC0402JR-0720KL                                                                                 | 0.108          | 0.108           |
| R14,R16                                                    | 2   | 100Ω, 5%                    | R_0402_1005Metric | Panasonic                          | ERJ-PA2J101X                                                                                    | 1.455          | 2.910           |
| R18                                                        | 1   | 120Ω, 5%                    | R_0805_2012Metric | Panasonic                          | ERJ-UP6F1200V                                                                                   | 0.220          | 0.220           |
| R21,R22,R25,R28                                            | 4   | 330kΩ, 5%                   | R_0402_1005Metric | YAGEO                              | RC0402FR-07330KL                                                                                | 0.032          | 0.128           |
| SW1,SW2                                                    | 2   | Push Button                 | KMR2              | C&K                                | KMR223G LFG                                                                                     | 1.811          | 3.622           |
| U1,U2                                                      | 2   | USBLC6-2P6                  | SOT-666           | STMicroelectronics                 | USBLC6-2P6                                                                                      | 0.720          | 1.440           |
| U3                                                         | 1   | CP2102N USB-UART            | QFN-24            | Silicon Labs                       | CP2102N-A02-GQFN24                                                                              | 4.025          | 4.025           |
| U4                                                         | 1   | ESP32-S3-WROOM-1-N16R8      | ESP32-S3-WROOM-1  | Espressif Systems                  | ESP32-S3-WROOM-1-N16R8                                                                          | 4.830          | 4.830           |
| U5                                                         | 1   | LMR51635YDDCR               | TSOT-23-6         | Texas Instruments                  | LMR51635YDDCR                                                                                   | 3.220          | 3.220           |
| U6                                                         | 1   | LD39200PU33R                | LD39200PU33R      | STMicroelectronics                 | LD39200PU33R                                                                                    | 1.302          | 1.302           |
| U7                                                         | 1   | SN74LVC1G125DBVR            | SOT-23-5          | Texas Instruments                  | SN74LVC1G125DBVR                                                                                | 0.604          | 0.604           |
| U8                                                         | 1   | SN74LVC1G126DBVR            | SOT-23-5          | Texas Instruments                  | SN74LVC1G126DBVR                                                                                | 0.973          | 0.973           |
| U9                                                         | 1   | MCP2518FD CAN-FD Controller | DFN-14            | Microchip Technology               | MCP2518FDT-E/QBB                                                                                | 2.278          | 2.278           |
| U10                                                        | 1   | MCP2562 CAN Transceiver     | SOIC-8            | Microchip Technology               | MCP2562-E/SN                                                                                    | 1.775          | 1.775           |
| U11                                                        | 1   | STM32G431KBU6               | QFN-32            | STMicroelectronics                 | STM32G431KBU6                                                                                   | 5.110          | 5.110           |
| U12,U13,U14,U15                                            | 4   | DRV8256PRGER                | VQFN-24           | Texas Instruments                  | DRV8256PRGER                                                                                    | 2.467          | 9.868           |
| Y1                                                         | 1   | 40 MHz Crystal              | 5032 SMD          | SUZHOU HANGJING ELEC&TECH CO., LTD | 0153G2-40.000F18HPLJK                                                                           | 2.800          | 2.800           |
| **Full PCB Manufacturing**                                 | 1   |                             |                   |                                    |                                                                                                 | ~150           | ~150            |
| **ST-Link/V2**                                             | 1   |                             |                   |                                    | https://www.prayogindia.in/product/st-link-v2-in-circuit-debugger-programmer-for-stm8-and-stm32 | ~15            | ~15             |
| **Grand Total**                                            |     |                             |                   |                                    |                                                                                                 |                | **~165**        |
