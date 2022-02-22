/**
 * @file main.c
 * @author ANAVIND K
 * @brief  configuration of ADC module of PIC16F877a.
 * @version 1.0
 * @date 2022-01-01  
 */

#include <xc.h>
#include"adc.h"

/**
 * @brief The main program function
 * All test/Demo cases are here.
 * @return int Returns 0 on successful execution
 */
unsigned int ADC_OUT;
int main(void)
{    TRISA = 0xFF; 
     TRISB = 0x00;
     TRISD = 0x00;
    INIT_ADC(FOSC_16,PORTS_8_0,RIGHT_JUST);
    while(1)
    { 
ADC_OUT = READ_ADC(CHANNEL_0);
    PORTD = ADRESH;
    PORTB = ADRESL;
    }  // Output is provided to PORT B and PORT D for experimentation purpose.
    return 0;
}
