/*
 * BUTTON_Test.c
 *
 * Created: 10/16/2022 10:28:54 PM
 *  Author: Ahmed El Azab
 */ 


#include "BUTTON_Test.h"


void BUTTON_DRIVER_TEST(void)
{
	// we test the button driver in this function as we will use a push button and read its value and use it to turn on a led
	
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	u8 button_check;
	while(1)
	{
		
	
	
		DIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,&button_check);
		if(button_check == DIO_u8_HIGH)
		{
			LED_ON(DIO_u8_PORTA,DIO_u8_PIN0);
		}
		else
		{
			LED_OFF(DIO_u8_PORTA,DIO_u8_PIN0);
		}

	}
	
}