/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F27Q83
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set D7_ aliases
#define D7__TRIS                 TRISBbits.TRISB0
#define D7__LAT                  LATBbits.LATB0
#define D7__PORT                 PORTBbits.RB0
#define D7__WPU                  WPUBbits.WPUB0
#define D7__OD                   ODCONBbits.ODCB0
#define D7__ANS                  ANSELBbits.ANSELB0
#define D7__SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define D7__SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define D7__Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define D7__GetValue()           PORTBbits.RB0
#define D7__SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define D7__SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define D7__SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define D7__ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define D7__SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define D7__SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define D7__SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define D7__SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set D6_ aliases
#define D6__TRIS                 TRISBbits.TRISB1
#define D6__LAT                  LATBbits.LATB1
#define D6__PORT                 PORTBbits.RB1
#define D6__WPU                  WPUBbits.WPUB1
#define D6__OD                   ODCONBbits.ODCB1
#define D6__ANS                  ANSELBbits.ANSELB1
#define D6__SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define D6__SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define D6__Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define D6__GetValue()           PORTBbits.RB1
#define D6__SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define D6__SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define D6__SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define D6__ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define D6__SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define D6__SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define D6__SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define D6__SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set D5_ aliases
#define D5__TRIS                 TRISBbits.TRISB2
#define D5__LAT                  LATBbits.LATB2
#define D5__PORT                 PORTBbits.RB2
#define D5__WPU                  WPUBbits.WPUB2
#define D5__OD                   ODCONBbits.ODCB2
#define D5__ANS                  ANSELBbits.ANSELB2
#define D5__SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define D5__SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define D5__Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define D5__GetValue()           PORTBbits.RB2
#define D5__SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define D5__SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define D5__SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define D5__ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define D5__SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define D5__SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define D5__SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define D5__SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set D4_ aliases
#define D4__TRIS                 TRISBbits.TRISB3
#define D4__LAT                  LATBbits.LATB3
#define D4__PORT                 PORTBbits.RB3
#define D4__WPU                  WPUBbits.WPUB3
#define D4__OD                   ODCONBbits.ODCB3
#define D4__ANS                  ANSELBbits.ANSELB3
#define D4__SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define D4__SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define D4__Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define D4__GetValue()           PORTBbits.RB3
#define D4__SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define D4__SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define D4__SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define D4__ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define D4__SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define D4__SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define D4__SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define D4__SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set EN_ aliases
#define EN__TRIS                 TRISBbits.TRISB4
#define EN__LAT                  LATBbits.LATB4
#define EN__PORT                 PORTBbits.RB4
#define EN__WPU                  WPUBbits.WPUB4
#define EN__OD                   ODCONBbits.ODCB4
#define EN__ANS                  ANSELBbits.ANSELB4
#define EN__SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define EN__SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define EN__Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define EN__GetValue()           PORTBbits.RB4
#define EN__SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define EN__SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define EN__SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define EN__ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define EN__SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define EN__SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define EN__SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define EN__SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RS_ aliases
#define RS__TRIS                 TRISCbits.TRISC3
#define RS__LAT                  LATCbits.LATC3
#define RS__PORT                 PORTCbits.RC3
#define RS__WPU                  WPUCbits.WPUC3
#define RS__OD                   ODCONCbits.ODCC3
#define RS__ANS                  ANSELCbits.ANSELC3
#define RS__SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RS__SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RS__Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RS__GetValue()           PORTCbits.RC3
#define RS__SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RS__SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RS__SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define RS__ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define RS__SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define RS__SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define RS__SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RS__SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set LED_G aliases
#define LED_G_TRIS                 TRISCbits.TRISC4
#define LED_G_LAT                  LATCbits.LATC4
#define LED_G_PORT                 PORTCbits.RC4
#define LED_G_WPU                  WPUCbits.WPUC4
#define LED_G_OD                   ODCONCbits.ODCC4
#define LED_G_ANS                  ANSELCbits.ANSELC4
#define LED_G_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED_G_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED_G_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED_G_GetValue()           PORTCbits.RC4
#define LED_G_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED_G_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED_G_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LED_G_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LED_G_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LED_G_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LED_G_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define LED_G_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/