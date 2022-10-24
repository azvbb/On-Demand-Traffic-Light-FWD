/*
 * TIMER_interface.h
 *
 * Created: 10/13/2022 4:19:28 PM
 *  Author: Ahmed El Azab
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "../../Lib/BIT_MATHS.h"
#include "../../Lib/STD_TYPES.h"



void TMR_voidTime0Init(void);

void TMR_voidTime2Init(void);


void TMR_voidTimer1SetCompareMatchValueChannelA	(u16 Copy_u16OCR1AValue);

void TMR_voidTMR0SetPreLoad  (u8 Copy_u8Preload);

void TMR_voidTMR0SetCompareMatcValue  (u8 Copy_u8CR0Value);

void TMR_5secs_delay(void);
void TMR_1sec_delay(void);
void TMR2_5secs_delay(void);
void TMR2_1sec_delay(void);






#endif /* TIMER_INTERFACE_H_ */