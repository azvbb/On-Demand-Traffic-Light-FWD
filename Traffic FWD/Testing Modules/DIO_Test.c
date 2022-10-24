/*
 * DIO_Test.c
 *
 * Created: 10/16/2022 9:25:40 PM
 *  Author: Ahmed El Azab
 */ 

#include "DIO_Test.h"


// function to test the dio driver
void DIO_DRIVER_TEST(void)
{
	// in this function we check the 3 main functions of the dio driver and if they all work properly a specific pin will set to High and turn a led on
		u8 dio_check;
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
	DIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,&dio_check);
	
	if(dio_check == 1)
	{
		// if condition met which indicated that the driver is working well then A Led connected to PIN2 OF PORTA will be turned on
		DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_OUTPUT);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
	}
	
	
	
}