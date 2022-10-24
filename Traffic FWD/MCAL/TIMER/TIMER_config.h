/*
 * TIMER_config.h
 *
 * Created: 10/13/2022 4:19:11 PM
 *  Author: Ahmed El Azab
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


#define TMR_u8_TMR0_PRELOAD_VALUE             0
#define TMR_u8_TMR1_PRELOAD_VALUE             0
#define TMR_u8_TMR0_COMPARE_MATCH_VALUE		  0
#define TMR_u16_TMRO_OVERFLOW_COUNTER         0
#define TMR_u8_TMR2_PRELOAD_VALUE             0

/* Choose Timer Operation Mode*/
/* Options: 1- NORMAL_MODE
 * 			2- CTC_MODE
 * 			3- FAST_PWM_MODE
 * 			4- PWM_PHASE_CORRECT
 */


#define TIMER0_MODE			NORMAL_MODE
#define TIMER2_MODE			NORMAL_MODE


/* Choose Division Factor*/
/* Options: 1-DIVIDE_BY_1
			2-DIVIDE_BY_8
			3-DIVIDE_BY_64
			4-DIVIDE_BY_256
			5-DIVIDE_BY_1024
*/

#define DIVIDE_BY_1										1
#define DIVIDE_BY_8										2
#define DIVIDE_BY_64									3
#define DIVIDE_BY_256									4
#define DIVIDE_BY_1024									5
#define TMR1_DIVIDE_BY_1024							    7


// prescalar mask to protect other bits values
#define TMR_u8_TMR0_PRESCALAR_MASK					0b11111000
#define TMR_u8_TMR2_PRESCALAR_MASK					0b11111000

#define TMR_u8_TMR0_PRESCALAR					DIVIDE_BY_1024
#define TMR_u8_TMR1_PRESCALAR					DIVIDE_BY_1024
#define TMR_u8_TMR2_PRESCALAR					TMR1_DIVIDE_BY_1024	




#define TMR_OVERFLOWS_NUMBER_5SECONDS           19
#define TMR_OVERFLOWS_NUMBER_1SECOND            4






#endif /* TIMER_CONFIG_H_ */