/*
 * EXT_INT_interface.h
 *
 * Created: 10/13/2022 4:18:15 PM
 *  Author: Ahmed El Azab
 */ 


#ifndef EXT_INT_INTERFACE_H_
#define EXT_INT_INTERFACE_H_

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATHS.h"



#define EXTI_u8_INT0		0
#define EXTI_u8_INT1		1
#define EXTI_u8_INT2		2
#define ENABLED             1
#define DISABLED            0


#define EXTI_u8_FALLIN_EDGE					1
#define EXTI_u8_RAISING_EDGE				2
#define EXTI_u8_ANY_LOGICAL_CHANGE			3
#define EXTI_u8_LOW_LEVEL					4

/*********************************************************************************/
/******************************* Interrupt vectors *******************************/
/*********************************************************************************/

/* External Interrupt Request 0 */
#define INT0_vect				__vector_1
/* External Interrupt Request 1 */
#define INT1_vect				__vector_2
/* External Interrupt Request 2 */
#define INT2_vect				__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define USART_RXC_vect			__vector_13
/* USART Data Register Empty */
#define USART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define USART_TXC_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect			   	__vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   	__vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20

/*********************************************************************************/
/*********************************************************************************/
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)
/*********************************************************************************/
/*********************************************************************************/


/**************************************************************************************/
/*Description: Initiate Required Bit to request an interrupt on INT0 Pin
 * Inputs:  No Inputs
 * Outputs: No Outputs
*
**************************************************************************************/
void EXTI_voidINT0Init (void);


/**************************************************************************************/
/*Description: Initiate Required Bit to request an interrupt on INT0 Pin
 * Inputs:  No Inputs
 * Outputs: No Outputs
*/
/**************************************************************************************/
void EXTI_voidINT1Init (void);


/**************************************************************************************/
/*Description: Initiate Required Bit to request an interrupt on INT0 Pin
 * Inputs:  No Inputs
 * Outputs: No Outputs
*/
/**************************************************************************************/
void EXTI_voidINT2Init (void);


/**************************************************************************************/
/*Description: Change sense control of the require Interrupt
 * Inputs:	1- Copy_u8IntNumber : the required interrupt number to change sense control
 * 				Options: 1- EXTI_INT0
 * 						 2- EXTI_INT1
 * 						 3- EXTI_INT2
 * 			2- Copy_u8IntEdgeSrc: The required sense control for the external interrupt
 * 				Options: 1- EXTI_u8_LOW_LEVEL
 * 				         2- EXTI_u8_ANY_LOGICAL_CHANGE
 * 				         3- EXTI_u8_FALLING_EDGE
 * 				         4- EXTI_u8_RISING_EDGE
 * Outputs: Error state
 * 				Options: 1- OK
 * 						 2- NOK
 *																			          */
/**************************************************************************************/
u8 EXTI_u8ExtIEnable        (u8 Copy_u8IntNum, u8 Copy_u8IntEdgeSrc);

/**************************************************************************************/
/*Description: Disable the require Interrupt
 * Inputs:	1- Copy_u8IntNumber : the required interrupt number to be disabled
 * 				Options: 1- EXTI_INT0
 * 						 2- EXTI_INT1
 * 						 3- EXTI_INT2
 * Outputs: Error state
 * 				Options: 1- OK
 * 						 2- NOK
 *																			          */
/**************************************************************************************/
u8 EXTI_u8ExtIDisable       (u8 Copy_u8IntNum);


u8 EXTI_u8ExtISetCallBack   (u8 Copy_u8IntNum, void (*Copy_pfCallBack)(void));

// general interupt enable/disable

void GI_voidEnable (void);
void GI_voidDisable (void);


#endif /* EXT_INT_INTERFACE_H_ */