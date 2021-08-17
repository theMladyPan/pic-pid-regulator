/**
  CCP5 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp5.h

  @Summary
    This is the generated header file for the CCP5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for CCP5.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K22
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45
*/


#ifndef CCP5_H
#define CCP5_H

#include <xc.h>
/**
 * Initialization routine that takes inputs from the GUI.
 * @prototype        void CCP5_Initialize(void)
 * @param           none
 * @return           none
 * @comment          
 * @usage            CCP5_Initialize();
 */
void CCP5_Initialize(void);

#endif  // CCP5.h