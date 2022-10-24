/*
 * PUSH_BUTTON.c
 *
 * Created: 10/14/2022 8:10:42 PM
 *  Author: Ahmed El Azab
 */ 
#include "PUSH_BUTTON_INTERFACE.h"


//Function to initialize the direction of the desired button Pin to INPUT

void Push_Button_Init(u8 copy_u8PORTNAME,u8 copy_u8PINNUMBER)
{
	DIO_u8SetPinDirection(copy_u8PORTNAME,copy_u8PINNUMBER,DIO_u8_INPUT);
	DIO_u8SetPinValue(copy_u8PORTNAME,copy_u8PINNUMBER,DIO_u8_LOW);
}
