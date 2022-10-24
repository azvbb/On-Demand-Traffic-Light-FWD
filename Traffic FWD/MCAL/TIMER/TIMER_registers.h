/*
 * TIMER_registers.h
 *
 * Created: 10/13/2022 4:18:56 PM
 *  Author: Ahmed El Azab
 */ 


#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_

/* Timer0 Registers */
#define TMR_u8_TMR0_TCCR0_REG                   *((volatile u8 *)0x53)
#define TCCR0_WGM00								6
#define TCCR0_WGM01								3
#define TCCR0_COM01								5
#define TCCR0_COM00								4

#define TMR_u8_TMR0_TCNT0_REG                   *((volatile u8 *)0x52)
#define TMR_u8_TMR0_OCR0_REG                    *((volatile u8 *)0x5C)

/* Timer2 Registers */
#define TMR_u8_TMR2_TCCR2_REG                   *((volatile u8 *)0x45)
#define TCCR2_WGM20								6
#define TCCR2_WGM21								3
#define TCCR2_COM21								5
#define TCCR2_COM20								4

#define TMR_u8_TMR0_TCNT2_REG                   *((volatile u8 *)0x44)
#define TMR_u8_TMR0_OCR2_REG                    *((volatile u8 *)0x43)



#define TMR_u8_TMR_TIMSK_REG                    *((volatile u8 *)0x59)
#define TIMSK_TOIE0								0
#define TIMSK_OCIE0								1
#define TIMSK_TOIE2                             6

#define TMR_u8_TMR_TIFR_REG                     *((volatile u8 *)0x58)

/* Timer 1 Registers*/
#define TMR_u8_TMR1_TCCR1A_REG					*((volatile u8*)0x4F)
#define TCCR1A_COM1A1	                        7
#define TCCR1A_COM1A0	                        6
#define TCCR1A_WGM11	                        1
#define TCCR1A_WGM10	                        0

#define TIMSK_TOIE1                             2

#define TMR_u8_TMR1_TCCR1B_REG					*((volatile u8*)0x4E)
#define TCCR1B_WGM13	                        4
#define TCCR1B_WGM12	                        3
#define TCCR1B_CS12		                        2
#define TCCR1B_CS11		                        1
#define TCCR1B_CS10		                        0


#define TMR_u8_TMR1_TCNT1L_REG					*((volatile u8*)0x4C)
#define TMR_u8_TMR1_TCNT1H_REG					*((volatile u8*)0x4D)
#define TMR_u16_TMR1_TCNT1_REG					*((volatile u16*)0x4C)


#define TMR_u8_TMR1_OCR1AH_REG					*((volatile u8*)0x4B)
#define TMR_u8_TMR1_OCR1AL_REG					*((volatile u8*)0x4A)
#define TMR_u16_TMR1_OCR1A_REG					*((volatile u16*)0x4A)/*First pin that timer 1 control its signal (generate pwm on it)*/

#define TMR_u8_TMR1_OCR1BH_REG					*((volatile u8*)0x49)
#define TMR_u8_TMR1_OCR1BL_REG					*((volatile u8*)0x48)
#define TMR_u16_TMR1_OCR1B_REG					*((volatile u16*)0x48)/*First pin that timer 2 control its signal (generate pwm on it)*/

#define TMR_u8_TMR1_ICR1H_REG					*((volatile u8*)0x47)
#define TMR_u8_TMR1_ICR1L_REG					*((volatile u8*)0x46)
#define TMR_u16_TMR1_ICR1_REG					*((volatile u16*)0x46)




/*Macros For Timer0 Operation Modes*/
#define NORMAL_MODE                      0
#define CTC_MODE                         1
#define FAST_PWM_MODE                    2
#define PWM_PHASE_CORRECT                3





#endif /* TIMER_REGISTERS_H_ */