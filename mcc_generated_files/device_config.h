/**
  @Generated PIC10 / PIC12 / PIC16 / PIC18 MCUs Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the device_config.h file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K22
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above or later
        MPLAB             :  MPLAB X 5.45
*/

#ifndef DEVICE_CONFIG_H
#define	DEVICE_CONFIG_H

#define _XTAL_FREQ 64000000
    
#undef MOVING_AVERAGE_FILTER //0.9
#define AVERAGE_COUNT 10
#undef UNFILTERED_READING

// PID parameters
#define PID_P 5
#define PID_I 2
#define PID_D 0.1

//define PWM precision, 1023 = 10bit, 4095 = 12bit etc...
#define PWM_PRECISION 1023

/* obtain hash - python:
 * >>> import time
 * >>> hex(hash(time.time()))
*/
#define DEV_ID '0x15508980611abe11'

#endif	/* DEVICE_CONFIG_H */
/**
 End of File
*/
