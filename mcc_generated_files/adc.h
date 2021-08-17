/**
  ADC Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    adc.h

  @Summary
    This is the generated header file for the ADC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for ADC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K22
        Driver Version    :  2.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB             :  MPLAB X 5.45
*/

#ifndef ADC_H
#define ADC_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "device_config.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
        
extern volatile uint16_t res;
extern volatile uint16_t voltage;
extern volatile uint16_t average_counter;
extern volatile uint32_t average_sum;

/**
  Section: Data Types Definitions
*/

/**
 *  result size of an A/D conversion
 */

typedef uint16_t adc_result_t;

/**
 *  result type of a Double ADC conversion
 */
typedef struct
{
    adc_result_t adcResult1;
    adc_result_t adcResult2;
} adc_sync_double_result_t;

/** ADC Channel Definition

 @Summary
   Defines the channels available for conversion.

 @Description
   This routine defines the channels that are available for the module to use.

 Remarks:
   None
 */

typedef enum
{
    channel_AN0 =  0x0,
    channel_AN1 =  0x1,
    channel_CTMU =  0x1D,
    channel_DAC =  0x1E,
    channel_FVRBuf2 =  0x1F
} adc_channel_t;

/**
  Section: ADC Module APIs
*/

/**
  @Summary
    Initializes the ADC

  @Description
    This routine initializes the Initializes the ADC.
    This routine must be called before any other ADC routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();
    convertedValue = ADC_GetConversionResult();
    </code>
*/
void ADC_Initialize(void);

/**
  @Summary
    Allows selection of a channel for conversion

  @Description
    This routine is used to select desired channel for conversion.
    available

  @Preconditions
    ADC_Initialize() function should have been called before calling this function.

  @Returns
    None

  @Param
    Pass in required channel number
    "For available channel refer to enum under adc.h file"

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();
    ADC_SelectChannel(AN1_Channel);
    ADC_StartConversion();
    convertedValue = ADC_GetConversionResult();
    </code>
*/
void ADC_SelectChannel(adc_channel_t channel);

/**
  @Summary
    Starts conversion

  @Description
    This routine is used to start conversion of desired channel.
    
  @Preconditions
    ADC_Initialize() function should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();    
    ADC_StartConversion();
    convertedValue = ADC_GetConversionResult();
    </code>
*/
void ADC_StartConversion(void);

/**
  @Summary
    Returns true when the conversion is completed otherwise false.

  @Description
    This routine is used to determine if conversion is completed.
    When conversion is complete routine returns true. It returns false otherwise.

  @Preconditions
    ADC_Initialize() and ADC_StartConversion(void)
    function should have been called before calling this function.

  @Returns
    true  - If conversion is complete
    false - If conversion is not completed

  @Param
    None

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();
    ADC_StartConversion();

    while(!ADC_IsConversionDone());
    convertedValue = ADC_GetConversionResult();
    </code>
 */
bool ADC_IsConversionDone(void);

/**
  @Summary
    Returns the ADC conversion value.

  @Description
    This routine is used to get the analog to digital converted value. This
    routine gets converted values from the channel specified.

  @Preconditions
    This routine returns the conversion value only after the conversion is complete.
    Completion status can be checked using
    ADC_IsConversionDone() routine.

  @Returns
    Returns the converted value.

  @Param
    None

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();
    ADC_StartConversion();

    while(ADC_IsConversionDone());

    convertedValue = ADC_GetConversionResult();
    </code>
 */
adc_result_t ADC_GetConversionResult(void);

/**
  @Summary
    Returns the ADC conversion value
    also allows selection of a channel for conversion.

  @Description
    This routine is used to select desired channel for conversion
    and to get the analog to digital converted value.

  @Preconditions
    ADC_Initialize() function should have been called before calling this function.

  @Returns
    Returns the converted value.

  @Param
    Pass in required channel number.
    "For available channel refer to enum under adc.h file"

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();

    conversion = ADC_GetConversion(AN1_Channel);
    </code>
*/
adc_result_t ADC_GetConversion(adc_channel_t channel);

/**
  @Summary
    Acquisition Delay for temperature sensor

  @Description
    This routine should be called when temperature sensor is used.
    
  @Preconditions
    ADC_Initialize() function should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();    
    ADC_StartConversion();
    ADC_temperatureAcquisitionDelay();
    convertedValue = ADC_GetConversionResult();
    </code>
*/
void ADC_TemperatureAcquisitionDelay(void);

/**
  @Summary
    Implements ISR

  @Description
    This routine is used to implement the ISR for the interrupt-driven
    implementations.

  @Returns
    None

  @Param
    None
*/
void ADC_ISR(void);

/**
  @Summary
    Set Timer Interrupt Handler

  @Description
    This sets the function to be called during the ISR

  @Preconditions
    Initialize  the ADC module with interrupt before calling this.

  @Param
    Address of function to be set

  @Returns
    None
*/
 void ADC_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Timer Interrupt Handler

  @Description
    This is a function pointer to the function that will be called during the ISR

  @Preconditions
    Initialize  the ADC module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
extern void (*ADC_InterruptHandler)(void);

/**
  @Summary
    Default Timer Interrupt Handler

  @Description
    This is the default Interrupt Handler function

  @Preconditions
    Initialize  the ADC module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
void ADC_DefaultInterruptHandler(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

