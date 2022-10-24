/*
 * EXT_INT_Test.c
 *
 * Created: 10/16/2022 9:28:07 PM
 *  Author: Ahmed El Azab
 */ 


#include "EXT_INT_Test.h"


void EXT_INT_DRIVER_TEST(void)
{
	while(1)
	{
		
	// in this function we will make a led turn on when we press the interrupt button to check if the driver is working correctly
	GI_voidEnable();
	EXTI_voidINT0Init();
	Push_Button_Init(DIO_u8_PORTD,DIO_u8_PIN2);
	}
	

}

/*
ISR(INT0_vect)
{
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
}
*/