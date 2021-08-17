/**
  ADC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc.c

  @Summary
    This is the generated driver implementation file for the ADC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for ADC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K22
        Driver Version    :  2.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB             :  MPLAB X 5.45
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "adc.h"

volatile uint16_t res = 0;
volatile uint16_t voltage = 0;
volatile uint16_t average_counter = 0;
volatile uint32_t average_sum = 0;

/**
  Section: ADC Module APIs
*/


void (*ADC_InterruptHandler)(void);

void ADC_Initialize(void)
{
    // set the ADC to the options selected in the User Interface
    
    // TRIGSEL CCP5; NVCFG VSS; PVCFG FVRbuf2; 
    ADCON1 = 0x08;
    
    // ADFM right; ACQT 0; ADCS FOSC/64; 
    ADCON2 = 0x86;
    
    // ADRESL 0; 
    ADRESL = 0x00;
    
    // ADRESH 0; 
    ADRESH = 0x00;
    
    // GO_nDONE stop; ADON enabled; CHS AN0; 
    ADCON0 = 0x01;
    
    // Enabling ADC interrupt.
    PIE1bits.ADIE = 1;
	
	// Set Default Interrupt Handler
    ADC_SetInterruptHandler(ADC_DefaultInterruptHandler);
}

void ADC_SelectChannel(adc_channel_t channel)
{
    // select the A/D channel
    ADCON0bits.CHS = channel;    
    // Turn on the ADC module
    ADCON0bits.ADON = 1;  
}

void ADC_StartConversion(void)
{
    // Start the conversion
    ADCON0bits.GO_nDONE = 1;
}


bool ADC_IsConversionDone(void)
{
    // Start the conversion
    return ((bool)(!ADCON0bits.GO_nDONE));
}

adc_result_t ADC_GetConversionResult(void)
{
    // Conversion finished, return the result
     return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

adc_result_t ADC_GetConversion(adc_channel_t channel)
{
    // select the A/D channel
    ADCON0bits.CHS = channel;    

    // Turn on the ADC module
    ADCON0bits.ADON = 1;

    // Start the conversion
    ADCON0bits.GO_nDONE = 1;

    // Wait for the conversion to finish
    while (ADCON0bits.GO_nDONE)
    {
    }

    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

void ADC_TemperatureAcquisitionDelay(void)
{
    __delay_us(200);
}

void ADC_ISR(void)
{
    // Clear the ADC interrupt flag
    PIR1bits.ADIF = 0;
	
	if(ADC_InterruptHandler)
    {
        ADC_InterruptHandler();
    }
}

void ADC_SetInterruptHandler(void (* InterruptHandler)(void)){
    ADC_InterruptHandler = InterruptHandler;
}

void ADC_DefaultInterruptHandler(void){
    // add your ADC interrupt custom code
    // or set custom function using ADC_SetInterruptHandler()

    res = ADC_GetConversionResult();    
    
    #ifdef MOVING_AVERAGE_FILTER
    voltage = (uint16_t)((double)(voltage*MOVING_AVERAGE_FILTER) + (double)((1-MOVING_AVERAGE_FILTER)*res*4));
    #endif /* MOVING_AVERAGE_FILTER */

    #ifdef UNFILTERED_READING
    voltage = res*4;
    #endif /* UNFILTERED_READING */

    #ifdef AVERAGE_COUNT
    average_sum += res*4;
    if(++average_counter == AVERAGE_COUNT){
        voltage = average_sum / AVERAGE_COUNT;
        average_sum = 0;
        average_counter = 0;
    }else{
        ;
    }    
    #endif /* AVERAGE_COUNT */
    
    
}
/**
 End of File
*/