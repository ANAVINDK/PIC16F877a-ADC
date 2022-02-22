/**
 * @file adc.c
 * @author ANAVIND K
 * @brief  function definition for configuration of ADC module of PIC16F877a.
 * @version 1.0
 * @date 2022-01-01  
 */
#include<xc.h>
#include"adc.h"

void delay(int count)
      {while(count--);}

void INIT_ADC(char CONV_CLOCK,char PORT_SELECT, char RESULT_FORMAT)
{
    ADCON1bits.PCFG = PORT_SELECT;// PORT configuration bits
    ADCON0bits.ADCS = CONV_CLOCK; //Select clock
    ADCON1bits.ADCS2 = CONV_CLOCK;
    ADCON1bits.ADFM = RESULT_FORMAT;// RIGHT justified or LEFT justified.
}

unsigned int READ_ADC(char CHANNEL)
{
    ADCON0bits.CHS = CHANNEL;// select channel 
     ADCON0bits.ADON = 1; // Turn ON  ADC module 
      delay(1000);
    ADCON0bits.GO = 1;    // start Analog to Digital conversion
    while(ADCON0bits.GO);
    return ((ADRESH<<8)+ADRESL);
}


