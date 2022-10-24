/*
 * TIMER_Test.c
 *
 * Created: 10/16/2022 9:27:31 PM
 *  Author: Ahmed El Azab
 */ 

#include "TIMER_Test.h"



void TIMER_DRIVER_TEST(void)
{
	// in this function we will check the delay functions on a led and it should be on after 6 secs of running
	
	TMR_voidTime0Init();
	TMR_5secs_delay();
	TMR_1sec_delay();
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
}