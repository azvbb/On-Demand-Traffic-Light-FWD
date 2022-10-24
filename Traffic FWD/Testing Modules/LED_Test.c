/*
 * LED_Test.c
 *
 * Created: 10/16/2022 10:27:57 PM
 *  Author: Ahmed El Azab
 */ 


#include "LED_Test.h"



void LED_DRIVER_TEST(void)
{
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	
		// in this function we will test the led driver by using it to turn off and turn on a led with the help of a timer
	while(1)
	{
	LED_ON(Cars_PORT,LED_RED);
	TMR_1sec_delay();

	LED_OFF(Cars_PORT,LED_RED);
	TMR_1sec_delay();
	}
	
}