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
- **[Debug and Control Interface](#debug-and-control-interface)**
- **[Measurement Results](#measurement-results)**
  - [Linear Power Supply vs. Switched-Mode Power Supply](#linear-power-supply-vs-switched-mode-power-supply)
  - [Differential Input Module (AnalogConversion_v3)](#differential-input-module-analogconversion_v3)

# Introduction

Work in progress ...

# Rack
+ [Card Rail](https://it.rs-online.com/web/p/montanti-rack/2457848)
+ [Front Pannel Large](https://it.rs-online.com/web/p/accessori-per-contenitori/2879769) (10 HP)
+ [Front Pannel Small](https://us.rs-online.com/product/nvent-schroff/20848664/70294016/)  (4 HP)
+ [Case](https://it.rs-online.com/web/p/contenitori-e-scatole-rack/2550700?searchId=d65bfb2c-882b-444f-99ba-9c0d112e01d9&gb=s)  (42 HP)
+ [IEC Connector](https://it.rs-online.com/web/p/filtri-iec/8703669)

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

The firmware running on the STM32H753ZIT6 is mainly written in ANSI C and has been developed in <a href="https://www.st.com/en/development-tools/stm32cubeide.html">STM32CubeIDE</a> version 1.10.1 utilizing the official <a href="https://github.com/STMicroelectronics/stm32h7xx_hal_driver">STM32H7xx_HAL_Driver</a>. Among others, the firmware performs the following tasks:

- Configuration of the ADC AD7768 (on module <a href="#AnalogConversion_v3">AnalogConversion_v3</a>) via SPI (SPI_3).
- Reception of sampled data from the ADC AD7768 via SPI (SPI_2) and DMA (DMA1_Stream0).
- Transmission of sampled data from the ADC AD7768 via USB 2.0 Hi-Speed to the PC utilizing ULPI interface and an additional Hi-Speed USB PHY (USB3300).
- Handling USART connection (USART_1, via FT232RL chip on <a href="#USBConnectors_v1">USBConnectors_v1</a>) for debug purposes and for exchanging control/status commands with the PC.
- Controlling I2C bus (I2C_4) for controlling I/O expander TCA9534A (e.g. on module <a href="#AnalogConversion_v3">AnalogConversion_v3</a>) which, in turn, drives a relay driver (MAX4820) on the same module.
- Controlling front LEDs (on module <a href="#DigitalBackend_v1">DigitalBackend_v1</a>).

The complete source code can be found <a href="https://github.com/yildi1337/DAQv3/tree/main/firmware">here</a>.

# USB Driver

Two USB drivers are needed for operating the DAQ v3:

- For the reception of the sampled data from the ADC NI-VISA is utilized. The driver matching the hardware of this project has been generated with the NI-VISA Driver Wizard an can be downloaded <a href="https://github.com/yildi1337/DAQv3/tree/main/usb_driver/ni-visa">here</a>.
- To use the USB debug interface only the official USB serial driver from FTDI is required, which can be downloaded <a href="https://github.com/yildi1337/DAQv3/tree/main/usb_driver/ftdi">here</a>.

# Debug and Control Interface

Tool for graphical display of status information and for controlling the hardware via the virtual serial interface (second USB-B port). The python source code and a binary (only tested on x64 Microsoft Windows 10) can be downloaded <a href="https://github.com/yildi1337/DAQv3/tree/main/debug_interface">here</a>. 

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/debug_interface/screenshots/debug_interface_01.png" />
</p>

# Measurement Results

## Linear Power Supply vs. Switched-Mode Power Supply

Noise measurements (60 seconds) were performed while powering the electronics with the power supplies of versions v1 and v2, where the abbreviations PS and ACNV in the titles refer to the power supply and analog conversion modules.

The two linear power supply modules of version v1 both operate with transformers. This resulted in heavy magnetic interference in the form of the mains frequency and multiples thereof.

The two power supply modules of version v2 both operate with AC/DC power modules (<a href="https://www.tracopower.com/de/deu/model/tmlm-20105">TMLM 20105</a>, <a href="https://www.tracopower.com/de/deu/model/tmlm-20115">TMLM 20115</a>) from Traco Power. Their switching frequencies are around 132 +/- 8 kHz and thus above the useful range of 0 - 100 kHz (Nyquist frequency is 128 kHz).

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/measurement_results/noise_ps_v1_vs_p2_v2_acnv_v1.png" />
</p>

## Differential Input Module (AnalogConversion_v3)

The investigated setup consists of the modules:

- <a href="#Backplane_v1">Backplane_v1</a>
- <a href="#PowerSupply_5V_v2">PowerSupply_5V_v2</a>
- <a href="#PowerSupply_12V_v2">PowerSupply_12V_v2</a>
- <a href="#AnalogConversion_v3">AnalogConversion_v3</a>
- <a href="#DigitalBackend_v1">DigitalBackend_v1</a>
- <a href="#USBConnectors_v1">USBConnectors_v1</a>

### Mains Interference and Grounding

The two differential inputs of each channel were connected via <a href="https://www.mouser.de/ProductDetail/Amphenol-RF/132360?qs=V8V9vCxO5JtDrelx3RqrVA%3D%3D">50 Ohm SMA resistors</a> with AGND (SHIELD connected via R6 = 0 Ohm with AGND, <a href="https://github.com/yildi1337/DAQv3/blob/main/schematics/AnalogConversion_v3_Schematics.pdf">see schematics</a>).

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/measurement_results/noise_ps_v2_acnv_v3_grounding.png" />
</p>

Obviously, the lowest interference occurs in grounded mode and when GND of the backplane is directly connected to the chassis/the protective earth connector of the power entry module (first plot).

### Input Noise of Differential Opamp Driver and ADC

The measurement result from above is essential for the further development of the preamplifier. The gain of the preamplifier must be high enough to be able to neglect the noise from the opamp driver (ADA4945-1) and ADC (AD7768-4) determined here. A useful model for describing the power spectral density of the voltage noise $PSD(f)$ (in units of $\mathrm{V}^2/\mathrm{Hz}$) is the polynomial law 
$$\mathrm{PSD}(f) = \mathrm{LSD}^2(f) = \sum_{i=-1}^{0} b_i f^i$$ 
where $i=0$ and $i=-1$ refer to white noise and $1/f$ flicker noise, respectively, and $\mathrm{LSD}(f)$ referes to the linear spectrum density (in units of $\mathrm{V}/\sqrt{\mathrm{Hz}}$). For this measurement, values of
- $b_{-1} = 1.3 \cdot 10^{-13}~\mathrm{V}^2$
- $b_0 = {1.3 \cdot 10^{-15}~\mathrm{V}^2/\mathrm{Hz}}$
were found.

This results in a $1/f$ corner frequency of $f_{\mathrm{c}} = b_{-1}/b_0 = 100~\mathrm{Hz}$. The white voltage noise density is equal to $\sqrt{b_0} = 36~\mathrm{nV}/\sqrt{\mathrm{Hz}}$. Based on the two time domain noise signals RMS noise values of $13.2~\mu\mathrm{V}$ (channel 1) and $13.5~\mu\mathrm{V}$ (channel 2) were determined after substracting the DC offsets of $-6.5~\mathrm{mV}$ and $-1.8~\mathrm{mV}$.

The measured RMS noise values are in good agreement with the value of $11.58~\mu\mathrm{V}$ given in the datasheet (for the ADC only).

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/measurement_results/adc_datasheet_rms_noise.png" />
</p>

In addition, for $V_{\mathrm{ref}} = 5~\mathrm{V}$, the dynamic range of the utilized combination of opamp driver and ADC is better than 

$$\mathrm{DR} = 20 \cdot \log_{10}\left(\frac{2 \cdot V_{\mathrm{ref}}}{\sqrt{2} \cdot \mathrm{RMS}\ \mathrm{noise}}\right)~\mathrm{dB} = 114\ \mathrm{dB}$$ 

### ADC RAW Data for Several Input Configurations

<p align="center">
    <img src="https://github.com/yildi1337/DAQv3/blob/main/measurement_results/noise_ps_v2_acnv_v3_open_short_50ohm_raw.png" />
</p>

