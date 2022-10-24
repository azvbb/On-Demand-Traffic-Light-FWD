/*
 * EXT_INT_registers.h
 *
 * Created: 10/13/2022 4:17:57 PM
 *  Author: Ahmed El Azab
 */ 


#ifndef EXT_INT_REGISTERS_H_
#define EXT_INT_REGISTERS_H_

/******************************** Macros For EXTI Registers************************************/


/******** The MCU Control Register contains control bits for interrupt sense control *********/
/********                      and general MCU functions.                           **********/
/*********************************************************************************************/
#define EXTI_u8_MCUCR_REG			*((volatile u8*)(0x55))			  /* MCU control register*/


/***********************************************************************************************/
/************** These Two Bits defines the condition will generate interrupt request ***********/
/***********************************************************************************************/
/***********************************  0 0 ---> For Low Level    ********************************/
/***********************************  0 1 ---> For Any Logical  ********************************/
/***********************************  1 0 ---> For Falling Edge ********************************/
/***********************************  1 1 ---> For Rising Edge  ********************************/
/***********************************************************************************************/
#define MCUCR_ISC11	3												/*Int1 sense control bit 1*/
#define MCUCR_ISC10 2                                              	/*Int1 sense control bit 0*/


/***********************************************************************************************/
/************** These Two Bits defines the condition will generate interrupt request ***********/
/***********************************************************************************************/
/***********************************  0 0 ---> For Low Level    ********************************/
/***********************************  0 1 ---> For Any Logical  ********************************/
/***********************************  1 0 ---> For Falling Edge ********************************/
/***********************************  1 1 ---> For Rising Edge  ********************************/
/***********************************************************************************************/
#define MCUCR_ISC01	1                                                 /*Int0 sense control bit 1*/
#define MCUCR_ISC00	0                                                 /*Int0 sense control bit 0*/



/***********************************************************************************************/

#define EXTI_u8_MCUCSR_REG			*((volatile u8*)(0x54))			/*MCU control and status register*/


/***********************************************************************************************/
/************** This Bit defines the condition will generate interrupt request ****************/
/**********************************************************************************************/
/***********************************   0 ---> For Falling Edge    *****************************/
/***********************************   1 ---> For Rising  Edge    *****************************/
/***********************************************************************************************/
#define MCUCSR_ISC2  6													/*INT 2 sense control bit */




#define EXTI_u8_GICR_REG			*((volatile u8*)(0x5B))   			/*General interrupt control register*/
#define GICR_INT0   6													/*INT0 PIE*/
#define GICR_INT1	7													/*INT1 PIE*/
#define GICR_INT2	5													/*INT2 PIE*/


#define EXTI_u8_GIFR_REG			*((volatile u8*)(0x5A))

/******************************** End of Macros For EXTI Registers ************************************/


// GLOBAL INT Register

#define GI_u8_SREG 				(*(volatile u8*)0x5F)
#define GI_u8_SREG_I 			7








#endif /* EXT_INT_REGISTERS_H_ */