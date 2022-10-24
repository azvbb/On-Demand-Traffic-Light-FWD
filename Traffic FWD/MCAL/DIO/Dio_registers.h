/*
 * Dio_registers.h
 *
 * Created: 10/13/2022 4:16:31 PM
 *  Author: Ahmed El Azab
 */ 


#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_


#define DIO_u8_PORTA_REG					*((volatile u8*)0x3b)
#define DIO_u8_DDRA_REG						*((volatile u8*)0x3A)
#define DIO_u8_PINA_REG						*((volatile u8*)0x39)

#define DIO_u8_PORTB_REG					*((volatile u8*)0x38)
#define DIO_u8_DDRB_REG						*((volatile u8*)0x37)
#define DIO_u8_PINB_REG						*((volatile u8*)0x36)


#define DIO_u8_PORTC_REG					*((volatile u8*)0x35)
#define DIO_u8_DDRC_REG						*((volatile u8*)0x34)
#define DIO_u8_PINC_REG						*((volatile u8*)0x33)

#define DIO_u8_PORTD_REG					*((volatile u8*)0x32)
#define DIO_u8_DDRD_REG						*((volatile u8*)0x31)
#define DIO_u8_PIND_REG						*((volatile u8*)0x30)

#define DIO_u8_INITIAL_OUTPUT				1
#define DIO_u8_INITIAL_INPUT				0


#define	DIO_u8_OUTPUT_HIGH					1
#define	DIO_u8_OUTPUT_LOW					0
#define	DIO_u8_INPUT_FLOATING				0
#define	DIO_u8_INPUT_PULLUP					1

// useful macro like function to concatenate bits values in one binary 8bits number
#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)		Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0





#endif /* DIO_REGISTERS_H_ */