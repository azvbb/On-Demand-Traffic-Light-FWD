/*
 * EXT_INT_config.h
 *
 * Created: 10/13/2022 5:09:36 PM
 *  Author: Ahmed El Azab
 */ 


#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_


/*Choose INT0 Sense control(interrupt trigger)
 * Options:		1- EXTI_u8_LOW_LEVEL
 * 				2- EXTI_u8_ANY_LOGICAL_CHANGE
 * 				3- EXTI_u8_FALLING_EDGE
 * 				4- EXTI_u8_RISING_EDGE
 * */
#define EXTI_INT0_SENSE				EXTI_u8_RAISING_EDGE

/*Choose INT1 Sense control(interrupt trigger)
 * Options:		1- EXTI_u8_LOW_LEVEL
 * 				2- EXTI_u8_ANY_LOGICAL_CHANGE
 * 				3- EXTI_u8_FALLING_EDGE
 * 				4- EXTI_u8_RISING_EDGE
 * */
#define EXTI_INT1_SENSE				EXTI_u8_FALLIN_EDGE

/*Choose INT2 Sense control(interrupt trigger)
 * Options:		1- EXTI_u8_FALLING_EDGE
 * 				2- EXTI_u8_RISING_EDGE
 * */
#define EXTI_INT2_SENSE				EXTI_u8_FALLIN_EDGE


/*Choose INT0 peripheral interrupt enable initial state
 * Options:		1- ENABLED
 * 				2- DISABLED
 * 									*/
#define EXTI_INT0_INITIAL_STATE		ENABLED

/*Choose INT0 peripheral interrupt enable initial state
 * Options:		1- ENABLED
 * 				2- DISABLED
 * 									*/
#define EXTI_INT1_INITIAL_STATE		DISABLED

/*Choose INT0 peripheral interrupt enable initial state
 * Options:		1- ENABLED
 * 				2- DISABLED
 * 									*/
#define EXTI_INT2_INITIAL_STATE		DISABLED




#endif /* EXT_INT_CONFIG_H_ */