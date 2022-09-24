# DAQv3
A Dual-Channel, Low Noise, Modular, 100 kHz Bandwidth, 24-Bit Data Acquisition (DAQ) Device / FFT Signal Analyzer

# Table of Contents

- **[Introduction](#introduction)**
- **[CAD Model](#cad-model)**
- **[Modules](#modules)**
  - [AnalogConversion_v1](#AnalogConversion_v1)
  - [AnalogConversion_v2](#AnalogConversion_v2)
  - [AnalogConversion_v3](#AnalogConversion_v3)
  - [Backplane_v1](#Backplane_v1)
  - [DigitalBackend_v1](#DigitalBackend_v1)
  - [PowerSupply_5V_v1](#PowerSupply_5V_v1)
  - [PowerSupply_5V_v2](#PowerSupply_5V_v2)
  - [PowerSupply_12V_v1](#PowerSupply_12V_v1)
  - [PowerSupply_12V_v2](#PowerSupply_12V_v2)
  - [USBConnectors_v1](#USBConnectors_v1)
- **[Firmware](#firmware)**
- **[USB Driver](#usb-driver)**
- **[Noise Measurements](#noise-measurements)**
  - [Evolution](#evolution)
  - [Current Status](#current-status)

# Introduction

Work in progress ...


# CAD Model

The complete CAD model can be downloaded <a href="https://github.com/yildi1337/DAQv3/tree/main/cad_complete/inventor">here</a> (Autodesk Inventor 2023 files) including all <a href="#modules">modules</a> and the case.

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_complete/DAQ_v3.png" />
</p>


# Modules

## AnalogConversion_v1

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/AnalogConversion_v1_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/AnalogConversion_v1.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/AnalogConversion_v1.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/AnalogConversion_v1_2022-03-20.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/AnalogConversion_v1.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_AnalogConversion_v1.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/AnalogConversion_v1.png" />
</p>

## AnalogConversion_v2

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/AnalogConversion_v2_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/AnalogConversion_v2.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/AnalogConversion_v2.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/AnalogConversion_v2_2022-05-25.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/AnalogConversion_v2.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_AnalogConversion_v2.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/AnalogConversion_v2.png" />
</p>

## AnalogConversion_v3

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/AnalogConversion_v3_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/AnalogConversion_v3.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/AnalogConversion_v3.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/AnalogConversion_v3_2022-07-25.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/AnalogConversion_v3.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_AnalogConversion_v3.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/AnalogConversion_v3.png" />
</p>

## Backplane_v1

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/Backplane_v1_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/Backplane_v1.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/Backplane_v1.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/Backplane_v1_2022-03-20.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/Backplane_v1.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_Backplane_v1.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/Backplane_v1.png" />
</p>

## DigitalBackend_v1

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/DigitalBackend_v1_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/DigitalBackend_v1.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/DigitalBackend_v1.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/DigitalBackend_v1_2022-03-20.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/DigitalBackend_v1.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_DigitalBackend_v1.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/DigitalBackend_v1.png" />
</p>

## PowerSupply_12V_v1

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/PowerSupply_12V_v1_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/PowerSupply_12V_v1.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/PowerSupply_12V_v1.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/PowerSupply_12V_v1_2022-03-20.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/PowerSupply_12V_v1.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_PowerSupply_12V_v1.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/PowerSupply_12V_v1.png" />
</p>

## PowerSupply_12V_v2

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/PowerSupply_12V_v2_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/PowerSupply_12V_v2.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/PowerSupply_12V_v2.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/PowerSupply_12V_v2_2022-05-25.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/PowerSupply_12V_v2.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_PowerSupply_12V_v2.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/PowerSupply_12V_v2.png" />
</p>

## PowerSupply_5V_v1

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/PowerSupply_5V_v1_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/PowerSupply_5V_v1.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/PowerSupply_5V_v1.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/PowerSupply_5V_v1_2022-03-20.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/PowerSupply_5V_v1.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_PowerSupply_5V_v1.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/PowerSupply_5V_v1.png" />
</p>

## PowerSupply_5V_v2

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/PowerSupply_5V_v2_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/PowerSupply_5V_v2.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/PowerSupply_5V_v2.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/PowerSupply_5V_v2_2022-05-25.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/PowerSupply_5V_v2.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_PowerSupply_5V_v2.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/PowerSupply_5V_v2.png" />
</p>


## USBConnectors_v1

- [Schematics (PDF)](https://github.com/yildi1337/DAQv3/blob/main/schematics/USBConnectors_v1_Schematics.pdf)
- [Schematics (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/USBConnectors_v1.sch)
- [Board (Eagle)](https://github.com/yildi1337/DAQv3/blob/main/eagle/USBConnectors_v1.brd)
- [Gerber Files](https://github.com/yildi1337/DAQv3/blob/main/pcb_gerber/USBConnectors_v1_2022-03-14.zip)
- [3D Step File](https://github.com/yildi1337/DAQv3/blob/main/cad_modules_step/USBConnectors_v1.step)
- [Bill of Materials](https://github.com/yildi1337/DAQv3/blob/main/pcb_bom/BOM_USBConnectors_v1.txt)

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/cad_modules_pictures/USBConnectors_v1.png" />
</p>

# Firmware

The firmware running on the STM32H753ZIT6 is mainly written in ANSI C and has been developed in <a href="https://www.st.com/en/development-tools/stm32cubeide.html">STM32CubeIDE</a> version 1.10.1 utilizing the official <a href="https://github.com/STMicroelectronics/stm32h7xx_hal_driver">STM32H7xx_HAL_Driver</a>. The firmware performs the following tasks, among others:

- Configuration of the ADC AD7768 (on module <a href="#AnalogConversion_v3">AnalogConversion_v3</a>) via SPI (SPI_3).
- Reception of sampled data from the ADC AD7768 via SPI (SPI_2) and DMA (DMA1_Stream0).
- Transmission of sampled data from the ADC AD7768 via USB 2.0 Hi-Speed to the PC utilizing ULPI interface and an additional Hi-Speed USB PHY (USB3300).
- Handling USART connection (USART_1, via FT232RL chip on <a href="#USBConnectors_v1">USBConnectors_v1</a>) for debug purposes and for exchanging control/status commands with the PC.
- Controlling I2C bus (I2C_4) for controlling I/O expander TCA9534A (e.g. on module <a href="#AnalogConversion_v3">AnalogConversion_v3</a>) which, in turn, drives a relay driver (MAX4820) on the same module.
- Controlling front LEDs (on module <a href="#DigitalBackend_v1">DigitalBackend_v1</a>).

The complete source code can be found in <a href="https://github.com/yildi1337/DAQv3/tree/main/firmware">here</a>.

# USB Driver

Two USB drivers are needed for operating the DAQ v3:

- For the reception of the sampled data from the ADC NI-VISA is utilized. The driver matching the hardware of this project has been generated with the NI-VISA Driver Wizard an can be downloaded <a href="https://github.com/yildi1337/DAQv3/tree/main/usb_driver/ni-visa">here</a>.
- To use the USB debug interface only the official USB serial driver from FTDI is required, which can be downloaded <a href="https://github.com/yildi1337/DAQv3/tree/main/usb_driver/ftdi">here</a>.

# Noise Measurements

## Evolution

Noise measurements were performed for several combinations of modules, where the abbreviations PS and ACNV in the titles refer to the power supply and analog conversion modules.

The two linear power supply modules of version v1 both operate with transformers and rectifiers. This resulted in magnetic interference in the form of the mains frequency and multiples thereof.

The two power supply modules of version v2 both operate with AC/DC power modules (<a href="https://www.tracopower.com/de/deu/model/tmlm-20105">TMLM 20105</a>, <a href="https://www.tracopower.com/de/deu/model/tmlm-20115">TMLM 20115</a>) from Traco Power. Their switching frequencies are around 132 +/- 8 kHz and thus above the useful range of 0 - 100 kHz.

The <a href="#AnalogConversion_v3">AnalogConversion_v3</a> module contains a relay for optionally connecting the front panel (chassis) to the analog ground (AGND) of the PCB (Grounded Mode). In floating mode significantly more interference occurs.

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/measurement_results/noise_evolution_short.png" />
</p>

## Current Status

The current setup consists of the modules:

- <a href="#Backplane_v1">Backplane_v1</a>
- <a href="#PowerSupply_5V_v2">PowerSupply_5V_v2</a>
- <a href="#PowerSupply_12V_v2">PowerSupply_12V_v2</a>
- <a href="#AnalogConversion_v3">AnalogConversion_v3</a>
- <a href="#DigitalBackend_v1">DigitalBackend_v1</a>
- <a href="#USBConnectors_v1">USBConnectors_v1</a>

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/measurement_results/noise_ps_v2_acnv_v3_open_short_50ohm.png" />
</p>

