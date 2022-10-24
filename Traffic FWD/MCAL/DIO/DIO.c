/*
 * DIO.c
 *
 * Created: 10/13/2022 4:16:00 PM
 *  Author: Ahmed El Azab
 */ 




/* Then Include From : MCAL Layer*/
#include "DIO_interface.h"
#include "DIO_registers.h"
#include "DIO_config.h"


u8 DIO_u8SetPinDirection (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection)
{
		//error indicator variable

	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	// check if the arguments are correct
	
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7)
	&&((Copy_u8PinDirection == DIO_u8_INPUT) || (Copy_u8PinDirection == DIO_u8_OUTPUT)) )
	{
		
		// switch case on the PORT so it selects the desired port we want to enable one of its pins
		/* after selecting the port we use the CLR_BIT macro-like function to set the pin to INPUT Direction or SET_BIT to set the pin
		 to OUTPUT Direction
		 */
		
		
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA :
			if(Copy_u8PinDirection == DIO_u8_INPUT)
			{
				CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);
			}
			else
			{
				SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);
			}
			break ;
			case DIO_u8_PORTB :
			if(Copy_u8PinDirection == DIO_u8_INPUT)
			{
				CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);
			}
			else
			{
				SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);
			}
			break ;
			case DIO_u8_PORTC :
			if(Copy_u8PinDirection == DIO_u8_INPUT)
			{
				CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);
			}
			else
			{
				SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);
			}
			break ;
			case DIO_u8_PORTD :
			if(Copy_u8PinDirection == DIO_u8_INPUT)
			{
				CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);
			}
			else
			{
				SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);
			}
			break ;
		}
	}
	
		//  if arguments aren't correct or the function failed it returns STD_TYPES_NOK which is a macro to 0

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue     (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
		//error indicator variable
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
		// check if the arguments are correct
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7)
	&& ((Copy_u8PinValue == DIO_u8_LOW)|| (Copy_u8PinValue== DIO_u8_HIGH)))
	{
		// switch case on the PORT so it selects the desired port we want to enable one of its pins
		// after selecting the port we use the CLR_BIT macro-like function to set the pin to low or SET_BIT to set the pin to high
		
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA :
			if(Copy_u8PinValue == DIO_u8_LOW)
			{
				CLR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);
			}
			else
			{
				SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);
			}
			break;
			case DIO_u8_PORTB :
			if(Copy_u8PinValue == DIO_u8_LOW)
			{
				CLR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);
			}
			else
			{
				SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);
			}
			break;
			case DIO_u8_PORTC :
			if(Copy_u8PinValue == DIO_u8_LOW)
			{
				CLR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);
			}
			else
			{
				SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);
			}
			break;
			case DIO_u8_PORTD :
			if(Copy_u8PinValue == DIO_u8_LOW)
			{
				CLR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);
			}
			else
			{
				SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);
			}
			break;
		}
	}
	
	//  if arguments aren't correct or the function failed it returns STD_TYPES_NOK which is a macro to 0

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue     (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8PinValue)
{
	// variable to save the pin value in
	u8 Local_ReturnedPinValue;
	
		//error indicator variable
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	// check if the arguments are correct
	
	if((Copy_u8PortId <= DIO_u8_PORTD)&&(Copy_u8PinId <= DIO_u8_PIN7)&&(Copy_pu8PinValue != NULL))
	{
		// switch case on the PORT so it selects the desired port we want to enable one of its pins
		 // after selecting the port we use the GET_BIT macro-like function to save the value of the bit in the variable we made
		 
		 // and then if the variable = 0 it sets the argument variable to 0 and if 1 it does the same but with 1
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA :
			Local_ReturnedPinValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);
			if(Local_ReturnedPinValue == 0)
			{
				*Copy_pu8PinValue = DIO_u8_LOW;
			}
			else
			{
				*Copy_pu8PinValue = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTB :
			Local_ReturnedPinValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);
			if(Local_ReturnedPinValue == 0)
			{
				*Copy_pu8PinValue = DIO_u8_LOW;
			}
			else
			{
				*Copy_pu8PinValue = DIO_u8_HIGH;
			}			break;
			case DIO_u8_PORTC :
			Local_ReturnedPinValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);
			if(Local_ReturnedPinValue == 0)
			{
				*Copy_pu8PinValue = DIO_u8_LOW;
			}
			else
			{
				*Copy_pu8PinValue = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTD :
			Local_ReturnedPinValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);
			if(Local_ReturnedPinValue == 0)
			{
				*Copy_pu8PinValue = DIO_u8_LOW;
			}
			else
			{
				*Copy_pu8PinValue = DIO_u8_HIGH;
			}
			break;
		}
	}
	// if arguments aren't correct or the function failed it returns STD_TYPES_NOK which is a macro to 0
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

