/**
 * @file adc.h
 * @author ANAVIND K
 * @brief  function declaration for configuration of ADC module of PIC16F877a.
 * @version 1.0
 * @date 2022-01-01  
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
    /**
     * @brief Selecting the A/D Conversion Clock
     * The A/D conversion time per bit is defined as TAD. 
     * The A/D conversion requires 11.5TAD per 10-bit conversion. 
     * The source of the A/D conversion clock is software selected.
     * The four possible options for TAD are: 
     * @note For faster conversion times, the selection of another clock source is recommended.
     * @note For device frequencies above 1 MHz, the device must be in SLEEP for the entire conversion, or the A/D accuracy may be out of specification.
     */
    
// Conversion Clock Select bits
#define FOSC_2  000 /**< period of Oscillator 2Tosc.*/
#define FOSC_4  100 /**< period of Oscillator 4Tosc.*/   
#define FOSC_8  001 /**< period of Oscillator 8Tosc.*/
#define FOSC_16 101 /**< period of Oscillator 16Tosc.*/      
#define FOSC_32 010 /**< period of Oscillator 32Tosc.*/
#define FOSC_64 110 /**< period of Oscillator 64Tosc.*/      
#define RC      011 /**< Internal RC Oscillator.*/
    
//Analog Channel Select bits
 #define CHANNEL_0 000/**< To select Channel 0 - AN0.*/
 #define CHANNEL_1 001/**< To select Channel 1 - AN1.*/
 #define CHANNEL_2 010/**< To select Channel 2 - AN2.*/    
 #define CHANNEL_3 011/**< To select Channel 3 - AN3.*/   
 #define CHANNEL_4 100/**< To select Channel 4 - AN4.*/    
 #define CHANNEL_5 101/**< To select Channel 5 - AN5.*/    
 #define CHANNEL_6 110/**< To select Channel 6 - AN6.*/    
 #define CHANNEL_7 111/**< To select Channel 7 - AN7.*/

//Port configuration bits
// PORTS_C_R ---> R ->  # of A/D voltage references
//  C -> # of analog input channels 
/**
 * A/D Port Configuration Control bits.  
 */    
#define PORTS_8_0 0000 /**< To set all ports as analog Inputs.*/
#define PORTS_7_1 0001 /**< AN7,AN6,AN5,AN4,AN2,AN1,AN0 as analog inputs */ 
#define PORTS_5_0 0010 /**< AN7,AN6,AN5 as digital I/O and AN4,AN3,AN2,AN1,AN0 as analog inputs */
#define PORTS_4_1 0011 /**< AN7,AN6,AN5,as digital I/O and AN4,AN2,AN1,AN0 as analog inputs */
#define PORTS_3_0 0100 /**< AN7,AN6,AN5,AN4,AN2as digital I/O and AN3,AN1,AN0 as analog inputs */
#define PORTS_2_1 0101 /**< AN7,AN6,AN5,AN4,AN2as digital I/O and AN1,AN0 as analog inputs */
#define PORTS_0_0 0110 /**< AN7,AN6,AN5,AN4,AN2as digital I/O and AN3,AN1,AN0 as digital I/O */
#define PORTS_6_2 1000 /**< AN7,AN6,AN5,AN4,AN1,AN0 as analog inputs */ 
#define PORTS_6_0 1001 /**< AN7,AN6as digital I/O and AN5,AN4,AN3,AN2,AN1,AN0 as analog inputs */ 
#define PORTS_5_1 1010 /**< AN7,AN6 as digital I/O and AN5,AN4,AN2,AN1,AN0 as analog inputs */ 
#define PORTS_4_2 1011 /**< AN7,AN6 as digital I/O and AN5,AN4,AN1,AN0 as analog inputs */ 
#define PORTS_3_2 1100 /**< AN7,AN6,AN5 as digital I/O and AN4,AN1,AN0 as analog inputs */
#define PORTS_2_2 1101 /**< AN7,AN6,AN5,AN4 as digital I/O and AN1,AN0 as analog inputs */   
#define PORTS_1_0 1110 /**< AN7,AN6,AN5,AN4,AN2,AN1 as digital I/O and AN0 as analog input */ 
#define PORTS_1_2 1111 /**< AN7,AN6,AN5,AN4,AN1 as digital I/O and AN0 as analog input */ 
    
    
//Result format select
/**
 * @brief Result Format selection. 
 * The ADRESH:ADRESL register pair is the location where the 10-bit A/D result is loaded at the completion of the A/D conversion.
 * This register pair is 16-bits wide.
 * The A/D module gives the flexibility to left or right justify the 10-bit result in the 16-bit result register.
 */    
#define RIGHT_JUST  1 /**< To set result format as right justified*/
#define LEFT_JUST 0  /**< To set result format as left justified*/
/**
 * @brief Calling Delay for acquisition time.
 * After the A/D module has been configured as desired, the selected channel must be acquired before the conversion is started.
 * There is a minimum acquisition time to ensure that the holding capacitor is charged to a level that will give the desired accuracy for the A/D conversion.
 * So a delay is called for full charging of holding capacitor to input voltage. 
 * @param count The value to be set for delay.
 */    
void delay(int);
/**
 * @brief To initialize ADC module.
 * The analog ports and conversion clock is selected in this function.
 * ADCON1 and ADCON0 registers are updated.
 * ADC module power on bit internally set inside. 
 * Setting respective bits will enable analog to digital conversion on selected channel.
 * @param CONV_CLOCK The frequency of oscillation is selected.
 * @param PORT_SELECT To set analog input and digital I/O.
 * @note Delay is called internally. 
 */
void INIT_ADC(char CONV_CLOCK,char PORT_SELECT, char RESULT_FORMAT);
/**
 * @brief Starting Analog to Digital conversion.
 * This function will start conversion on selected channel.
 * Conversion starts by setting GO/DONE bit.
 * Waits for conversion to end and returns result.
 * @warning function should be callled only after calling INIT_ADC() function.   
 * @param CHANNEL Selecting Channel to convert analog value to digital.
 * @note Only one channel can be selected at a particular time.
 * @return unsigned int Result of conversion. The result is 16 bits.
 * @see INIT_ADC();  
 */
unsigned int READ_ADC(char CHANNEL);

    
    
    




#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

