/*
 * EXT_INT.c
 *
 * Created: 10/13/2022 4:17:28 PM
 *  Author: Ahmed El Azab
 */ 




#include "EXT_INT_config.h"
#include "EXT_INT_registers.h"
#include "EXT_INT_interface.h"


void EXTI_voidINT0Init (void)
{
// Selecting interrupt trigger
	#if EXTI_INT0_SENSE == EXTI_u8_LOW_LEVEL
	CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC01);
	CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC00);

	#elif EXTI_INT0_SENSE == EXTI_u8_ANY_LOGICAL_CHANGE
	CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC01);
	SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC00);

	#elif EXTI_INT0_SENSE == EXTI_u8_FALLIN_EDGE
	SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC01);
	CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC00);

	#elif EXTI_INT0_SENSE == EXTI_u8_RAISING_EDGE
	SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC01);
	SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC00);

	#else
	#error"Wrong EXTI_INT0_SENSE configuration option"
	#endif
// check if the initial state in config is enabled or disabled
	#if EXTI_INT0_INITIAL_STATE == ENABLED
	SET_BIT(EXTI_u8_GICR_REG,GICR_INT0);

	#elif EXTI_INT0_INITIAL_STATE == DISABLED
	CLR_BIT(EXTI_u8_GICR_REG,GICR_INT0);
	#else
	#error"Wrong EXTI_INT0_INITIAL_STATE configuration option"
	#endif
}

void EXTI_voidINT2Init (void)
{

	#if EXTI_INT2_SENSE == EXTI_u8_FALLIN_EDGE
	CLR_BIT(EXTI_u8_MCUCSR_REG,MCUCSR_ISC2);

	#elif EXTI_INT2_SENSE == EXTI_u8_RAISING_EDGE
	SET_BIT(EXTI_u8_MCUCSR_REG,MCUCSR_ISC2);

	#else
	#error"Wrong EXTI_INT2_SENSE configuration option"     // error message
	#endif

	#if EXTI_INT2_INITIAL_STATE == ENABLED
	SET_BIT(EXTI_u8_GICR_REG,GICR_INT2);

	#elif EXTI_INT2_INITIAL_STATE == DISABLED
	CLR_BIT(EXTI_u8_GICR_REG,GICR_INT2);
	#else
	#error"Wrong EXTI_INT2_INITIAL_STATE configuration option"  // error message
	#endif
}




// function to enable global interrupt
void GI_voidEnable (void)
{
	SET_BIT(GI_u8_SREG,GI_u8_SREG_I);
}

// function to disable global interrupt
void GI_voidDisable (void)
{
	CLR_BIT(GI_u8_SREG,GI_u8_SREG_I);
}

