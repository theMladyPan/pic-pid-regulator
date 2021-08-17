/**
  TMR3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr3.c

  @Summary
    This is the generated driver implementation file for the TMR3 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR3.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K22
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr3.h"
#include "epwm1.h"
#include "epwm2.h"

/**
  Section: Global Variable Definitions
*/
volatile uint16_t timer3ReloadVal;
void (*TMR3_InterruptHandler)(void);


volatile uint16_t last_setpoint = 0;
volatile uint16_t action = 0;
volatile double i = 0;
volatile double p = 0;
volatile double d = 0;

/**
  Section: TMR3 APIs
*/

void TMR3_Initialize(void)
{
    //Set the Timer to the options selected in the GUI

    //T3GSS T3G_pin; TMR3GE disabled; T3GTM disabled; T3GPOL low; T3GGO done; T3GSPM disabled; 
    T3GCON = 0x00;

    //TMR3H 99; 
    TMR3H = 0x63;

    //TMR3L 192; 
    TMR3L = 0xC0;

    // Load the TMR value to reload variable
    timer3ReloadVal=TMR3;

    // Clearing IF flag before enabling the interrupt.
    PIR2bits.TMR3IF = 0;

    // Enabling TMR3 interrupt.
    PIE2bits.TMR3IE = 1;

    // Set Default Interrupt Handler
    TMR3_SetInterruptHandler(TMR3_DefaultInterruptHandler);

    // T3CKPS 1:4; T3OSCEN disabled; nT3SYNC synchronize; TMR3CS FOSC/4; TMR3ON enabled; T3RD16 disabled; 
    T3CON = 0x21;
}

void TMR3_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T3CONbits.TMR3ON = 1;
}

void TMR3_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T3CONbits.TMR3ON = 0;
}

uint16_t TMR3_ReadTimer(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
    
    T3CONbits.T3RD16 = 1;
	
    readValLow = TMR3L;
    readValHigh = TMR3H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void TMR3_WriteTimer(uint16_t timerVal)
{
    if (T3CONbits.nT3SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T3CONbits.TMR3ON = 0;

        // Write to the Timer3 register
        TMR3H = (uint8_t)(timerVal >> 8);
        TMR3L = (uint8_t)timerVal;

        // Start the Timer after writing to the register
        T3CONbits.TMR3ON =1;
    }
    else
    {
        // Write to the Timer3 register
        TMR3H = (uint8_t)(timerVal >> 8);
        TMR3L = (uint8_t)timerVal;
    }
}

void TMR3_Reload(void)
{
    TMR3_WriteTimer(timer3ReloadVal);
}

void TMR3_StartSinglePulseAcquisition(void)
{
    T3GCONbits.T3GGO = 1;
}

uint8_t TMR3_CheckGateValueStatus(void)
{
    return T3GCONbits.T3GVAL;
}

void TMR3_ISR(void)
{

    // Clear the TMR3 interrupt flag
    PIR2bits.TMR3IF = 0;
    TMR3_WriteTimer(timer3ReloadVal);

    // ticker function call;
    // ticker is 1 -> Callback function gets called everytime this ISR executes
    TMR3_CallBack();
}

void TMR3_CallBack(void)
{
    // Add your custom callback code here
    if(TMR3_InterruptHandler)
    {
        TMR3_InterruptHandler();
    }
}

void TMR3_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR3_InterruptHandler = InterruptHandler;
}

void TMR3_DefaultInterruptHandler(void){
    // add your TMR3 interrupt custom code
    // or set custom function using TMR3_SetInterruptHandler()
    d = d*.9 + .1*PID_D*((double)setpoint - (double)last_setpoint);
    last_setpoint = setpoint;
    p = PID_P*((double)setpoint - (double)voltage);
    i += PID_I*(double)(p)/100;
    action = (uint16_t)fminl(fmaxl(0, (p + i + d)), PWM_PRECISION);
    
    EPWM1_LoadDutyValue(action);
    EPWM2_LoadDutyValue(PWM_PRECISION - action);
}


/**
 End of File
*/
