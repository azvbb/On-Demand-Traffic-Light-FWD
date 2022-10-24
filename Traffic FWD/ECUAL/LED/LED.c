/*
 * LED.c
 *
 * Created: 10/13/2022 4:19:48 PM
 *  Author: Ahmed El Azab
 */ 

#include "LED_interface.h"

// function to put the desired pin to HIGH State
LED_ON(u8 copy_PORTNUMBER , u8 copy_PINNUMBER)
{
	
	DIO_u8SetPinValue(copy_PORTNUMBER,copy_PINNUMBER,DIO_u8_HIGH);
	


}
// function to put the desired pin to low State

LED_OFF(u8 copy_PORTNUMBER , u8 copy_PINNUMBER)
{
	
	DIO_u8SetPinValue(copy_PORTNUMBER,copy_PINNUMBER,DIO_u8_LOW);
	

}