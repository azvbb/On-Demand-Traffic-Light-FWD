/*
 * TIMER.c
 *
 * Created: 10/13/2022 4:18:38 PM
 *  Author: Ahmed El Azab
 */ 


#include "TIMER_interface.h"
#include "TIMER_registers.h"
#include "TIMER_config.h"

    // timer0 delay counter variable
	volatile u32 overflowcounter = 0;
	
    // timer2 delay counter variable
	volatile u32 overflowcounter2 = 0;


void TMR_voidTime0Init(void)
{
	#if TIMER0_MODE == NORMAL_MODE

	/* Select Mode = Normal Mode */
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,TCCR0_WGM00);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,TCCR0_WGM01);

	/* Init Timer register with the preload Value */
	TMR_u8_TMR0_TCNT0_REG = TMR_u8_TMR0_PRELOAD_VALUE;

	/* Enable OVF Interrupt */
	SET_BIT(TMR_u8_TMR_TIMSK_REG,TIMSK_TOIE0);

	/* Select Prescaler Value = 1024 */
	TMR_u8_TMR0_TCCR0_REG &= TMR_u8_TMR0_PRESCALAR_MASK;
	TMR_u8_TMR0_TCCR0_REG |= TMR_u8_TMR0_PRESCALAR;

	#elif TIMER0_MODE == CTC_MODE
	/* Select Mode = CTC Mode */
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,TCCR0_WGM00);
	SET_BIT(TMR_u8_TMR0_TCCR0_REG,TCCR0_WGM01);

	/*Set Compear MAtch Value*/
	TMR_u8_TMR0_OCR0_REG = TMR_u8_TMR0_COMPARE_MATCH_VALUE;

	/* Enable CTC Interrupt */
	SET_BIT(TMR_u8_TMR_TIMSK_REG,TIMSK_TOIE0);

	/* Select Prescaler Value = 1024 */
	TMR_u8_TMR0_TCCR0_REG &= TMR_u8_TMR0_PRESCALAR_MASK;
	TMR_u8_TMR0_TCCR0_REG |= TMR_u8_TMR0_PRESCALAR;

	#elif TIMER0_MODE == FAST_PWM_MODE
	/* FAst Pwm Mode*/
	SET_BIT(TMR_u8_TMR0_TCCR0_REG,6);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,3);
	/* Select non inverting mode*/
	SET_BIT(TMR_u8_TMR0_TCCR0_REG,5);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,4);

	/*Set the required compare match value*/
	//TMR_u8_TMR0_OCR0_REG = TMR_u8_TMR0_COMPARE_MATCH_VALUE;
	/* Select prescalar Value*/
	TMR_u8_TMR0_TCCR0_REG &= TMR_u8_TMR0_PRESCALAR_MASK;
	TMR_u8_TMR0_TCCR0_REG |= TMR_u8_TMR0_PRESCALAR;

	#endif

}


void TMR_voidTime2Init(void)
{

	/* Select Mode = Normal Mode */
	CLR_BIT(TMR_u8_TMR2_TCCR2_REG,TCCR2_WGM20);
	CLR_BIT(TMR_u8_TMR2_TCCR2_REG,TCCR2_WGM21);

	/* Init Timer register with the preload Value */
	TMR_u8_TMR2_TCCR2_REG = TMR_u8_TMR2_PRELOAD_VALUE;

	/* Enable OVF Interrupt */
	SET_BIT(TMR_u8_TMR_TIMSK_REG,TIMSK_TOIE2);

	/* Select Prescaler Value = 1024   and its controlled through the timer config file */
	TMR_u8_TMR2_TCCR2_REG &= TMR_u8_TMR2_PRESCALAR_MASK;
	TMR_u8_TMR2_TCCR2_REG |= TMR_u8_TMR2_PRESCALAR;

	


}

void TMR_voidTMR0SetPreLoad  (u8 Copy_u8Preload)
{
	TMR_u8_TMR0_TCNT0_REG = Copy_u8Preload;
}
void TMR_voidTMR0SetCompareMatcValue  (u8 Copy_u8CR0Value)
{
	TMR_u8_TMR0_OCR0_REG = Copy_u8CR0Value;
}

// 5 secs delay function with timer 0
void TMR_5secs_delay(void)
{
	TMR_voidTime0Init();
	while (overflowcounter < TMR_OVERFLOWS_NUMBER_5SECONDS)
	{
		while((GET_BIT(TMR_u8_TMR_TIFR_REG,0) == 0))
		{
			
		}
		SET_BIT(TMR_u8_TMR_TIFR_REG,0);
		overflowcounter++;
	}
	overflowcounter = 0; 
	TMR_u8_TMR0_TCCR0_REG = 0x00;

		
}

// 5 secs delay function with timer 2
void TMR2_5secs_delay(void)
{
	TMR_voidTime2Init();
	while (overflowcounter2 < TMR_OVERFLOWS_NUMBER_5SECONDS)
	{
		while((GET_BIT(TMR_u8_TMR_TIFR_REG,6) == 0))
		{
			
		}
		SET_BIT(TMR_u8_TMR_TIFR_REG,6);
		overflowcounter2++;
	}
	overflowcounter2 = 0;
	TMR_u8_TMR2_TCCR2_REG = 0x00;

	
}


// 1 sec delay function with timer 2
void TMR2_1sec_delay(void)
{
	TMR_voidTime2Init();
	while (overflowcounter2 < TMR_OVERFLOWS_NUMBER_1SECOND)
	{
		while((GET_BIT(TMR_u8_TMR_TIFR_REG,6) == 0))
		{
			
		}
		SET_BIT(TMR_u8_TMR_TIFR_REG,6);
		overflowcounter2++;
	}
	overflowcounter2 = 0;
	TMR_u8_TMR2_TCCR2_REG = 0x00;

	
}

// 1 sec delay function with timer 0
void TMR_1sec_delay(void)
{
		TMR_voidTime0Init();
	while (overflowcounter < TMR_OVERFLOWS_NUMBER_1SECOND)
	{
		while((GET_BIT(TMR_u8_TMR_TIFR_REG,0) == 0))
		{
			
		}
		SET_BIT(TMR_u8_TMR_TIFR_REG,0);
		overflowcounter++;
	}
	overflowcounter = 0;
	
	TMR_u8_TMR0_TCCR0_REG = 0x00;
}




