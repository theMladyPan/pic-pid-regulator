/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K22
        Driver Version    :  2.00
*/

#include "mcc_generated_files/mcc.h"
#include <stdlib.h>

volatile uint16_t setpoint = 1000;
char str[16];

/*
                         Main application
 */

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    
    //TRISB = 0x00;  
    while (1)
    {
        // Add your application code
        LED_G_SetHigh();
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        sprintf(str, "%d    ", voltage);
        Lcd_Print_String(str);
        
        while(!EUSART1_is_tx_ready());
        printf("U: %d, ", voltage);
        printf("A: %d\n", action);

        LED_G_Toggle();
        __delay_ms(100);
    }
}
/**
 End of File
*/