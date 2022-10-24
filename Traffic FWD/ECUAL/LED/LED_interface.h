/*
 * LED_interface.h
 *
 * Created: 10/13/2022 4:20:07 PM
 *  Author: Ahmed El Azab
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../MCAL/DIO/Dio_interface.h"
// Macros for Pedestrian and Cars Ports and Pins

#define Pedesterian_PORT    DIO_u8_PORTB
#define Cars_PORT           DIO_u8_PORTA
#define LED_RED             DIO_u8_PIN0
#define LED_YELLOW          DIO_u8_PIN1
#define LED_GREEN           DIO_u8_PIN2
#define LED_BLUE            DIO_u8_PIN7




LED_ON(u8 copy_PORTNUMBER , u8 copy_PINNUMBER);

LED_OFF(u8 copy_PORTNUMBER , u8 copy_PINNUMBER);





#endif /* LED_INTERFACE_H_ */