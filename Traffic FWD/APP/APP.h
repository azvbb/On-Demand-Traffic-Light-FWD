/*
 * APP.h
 *
 * Created: 10/13/2022 4:21:47 PM
 *  Author: Ahmed El Azab
 */ 

#ifndef APP_H_
#define APP_H_


#include "../ECUAL/LED/LED_interface.h"
#include "../ECUAL/PUSH_BUTTON/PUSH_BUTTON_INTERFACE.h"

//enum data type for the check current led variable
typedef enum EN_Current{
	RED,YELLOW,GREEN
}EN_Current_Led;



//macros for interrupt state
#define Interupt_pressed       1
#define Interupt_Npressed      0




void appstart(void);

void Car_Mode(void);


#endif /* APP_H_ */
