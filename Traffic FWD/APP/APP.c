/*
 * APP.c
 *
 * Created: 10/13/2022 4:21:36 PM
 *  Author: Ahmed El Azab
 */ 

#include "APP.h"

// defining state and flag variables


// initiate interrupt flag with not pressed 
u8 interrupt_check = Interupt_Npressed;
// initiate the current_led variable with GREEN since its the start case of the normal mode
EN_Current_Led current_led = GREEN;

void appstart(void)
{
    // Initializing Direction and Value of LED DIO PINS
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN7,DIO_u8_OUTPUT);

	// initializing Interrupt Button Pin
	Push_Button_Init(DIO_u8_PORTD,DIO_u8_PIN2);
	// Initializing Timer0
	TMR_voidTime0Init();
	TMR_voidTime2Init();

	//Initializing INTERRUPT 0
    EXTI_voidINT0Init();
	//Enable of Global Interrupt
	GI_voidEnable();
	
		Car_Mode();
}


void Car_Mode(void)
{
	// Cars_Mode function is the normal mode of the traffic lights and it keeps checking if the interrupt button was pressed or not so it can switch to Pedestrian Mode
	
	/*Green Cars Led and ped red is on for 5 seconds then cars green is off and the yellow led starts blinking for 5 secs
	 while the ped red is still on then they are off and the car red and ped green is on for 5 secs and repeats untill the
	button is pressed */
	while(1)
	{
		// turn off pedestrian mode led
		LED_OFF(Pedesterian_PORT,LED_BLUE);
		    do
		    {
				LED_OFF(Cars_PORT,LED_YELLOW);
				LED_OFF(Cars_PORT,LED_RED);
			    LED_ON(Cars_PORT,LED_GREEN);
				LED_OFF(Pedesterian_PORT,LED_GREEN);
				LED_ON(Pedesterian_PORT,LED_RED);
			    TMR_5secs_delay();
			    current_led = YELLOW;
		    } while (current_led == GREEN);
		    
		    do
		    {
				LED_OFF(Cars_PORT,LED_GREEN);
			    LED_ON(Cars_PORT,LED_YELLOW);
			    TMR_1sec_delay();
			    LED_OFF(Cars_PORT,LED_YELLOW);
			    TMR_1sec_delay();
			    LED_ON(Cars_PORT,LED_YELLOW);
			    TMR_1sec_delay();
			    LED_OFF(Cars_PORT,LED_YELLOW);
			    TMR_1sec_delay();
			    LED_ON(Cars_PORT,LED_YELLOW);
			    TMR_1sec_delay();
			    current_led = RED;

		    } while (current_led == YELLOW);
		    do{
			    LED_OFF(Cars_PORT,LED_YELLOW);
			    LED_ON(Cars_PORT,LED_RED);
				LED_ON(Pedesterian_PORT,LED_GREEN);
				LED_OFF(Pedesterian_PORT,LED_RED);
			    TMR_5secs_delay();
				LED_OFF(Cars_PORT,LED_RED);
				current_led = YELLOW;
				LED_ON(Cars_PORT,LED_YELLOW);
				TMR_1sec_delay();
				LED_OFF(Cars_PORT,LED_YELLOW);
				TMR_1sec_delay();
				LED_ON(Cars_PORT,LED_YELLOW);
				TMR_1sec_delay();
				LED_OFF(Cars_PORT,LED_YELLOW);
				TMR_1sec_delay();
				LED_ON(Cars_PORT,LED_YELLOW);
				TMR_1sec_delay();
			    current_led = GREEN;
		    }while(current_led == RED);
			}
	
}


ISR(INT0_vect)
{
	
	
	
	      //          here is where the pedestrian mode happens
	
	
	
	// turn off all leds to avoid any conflicts
	
		
	
	LED_OFF(Cars_PORT,LED_GREEN);
	LED_OFF(Pedesterian_PORT,LED_GREEN);
	LED_OFF(Cars_PORT,LED_RED);
	LED_OFF(Pedesterian_PORT,LED_RED);
	LED_OFF(Cars_PORT,LED_YELLOW);
	LED_OFF(Pedesterian_PORT,LED_YELLOW);
	
	// turn on Pedestrian mode led
	if(current_led != RED)
	{
		
	LED_ON(Pedesterian_PORT,LED_BLUE);
	}
	
	if(interrupt_check == Interupt_Npressed)
	{
		interrupt_check = Interupt_pressed;
		if(current_led == RED)
		{
			// nothing happens car red still on and ped green still on
			LED_ON(Cars_PORT,LED_RED);
			LED_ON(Pedesterian_PORT,LED_GREEN);
			current_led = RED;
			TMR2_5secs_delay();
			LED_OFF(Cars_PORT,LED_RED);
			LED_ON(Cars_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_OFF(Cars_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_ON(Cars_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_OFF(Cars_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_ON(Cars_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_OFF(Cars_PORT,LED_YELLOW);
			LED_ON(Cars_PORT,LED_GREEN);
			LED_OFF(Pedesterian_PORT,LED_GREEN);
			LED_ON(Pedesterian_PORT,LED_RED);
			
			
		}
		else if (current_led == YELLOW)
		{
			
			// If Car YELLOW is BLINKING the ped red will be on and both yellow leds start to blink for 5 secs
			LED_ON(Pedesterian_PORT,LED_RED);
			LED_ON(Cars_PORT,LED_YELLOW);
			LED_ON(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_OFF(Cars_PORT,LED_YELLOW);
			LED_OFF(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_ON(Cars_PORT,LED_YELLOW);
			LED_ON(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_OFF(Cars_PORT,LED_YELLOW);
			LED_OFF(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_ON(Cars_PORT,LED_YELLOW);
			LED_ON(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_OFF(Cars_PORT,LED_YELLOW);
			LED_OFF(Pedesterian_PORT,LED_YELLOW);
			// then car green is off , ped red is off , car red is on and green ped is on for 5 secs
			LED_ON(Cars_PORT,LED_RED);
			LED_ON(Pedesterian_PORT,LED_GREEN);
			LED_OFF(Pedesterian_PORT,LED_RED);
			LED_OFF(Cars_PORT,LED_GREEN);
			TMR2_5secs_delay();
			
		}
		else if (current_led == GREEN)
		{
			// If Car green is on the ped red will be on and both yellow leds start to blink for 5 secs
			LED_ON(Pedesterian_PORT,LED_RED);
			LED_ON(Cars_PORT,LED_GREEN);
			LED_ON(Cars_PORT,LED_YELLOW);
			LED_ON(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_OFF(Cars_PORT,LED_YELLOW);
			LED_OFF(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_ON(Cars_PORT,LED_YELLOW);
			LED_ON(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_OFF(Cars_PORT,LED_YELLOW);
			LED_OFF(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_ON(Cars_PORT,LED_YELLOW);
			LED_ON(Pedesterian_PORT,LED_YELLOW);
			TMR2_1sec_delay();
			LED_OFF(Cars_PORT,LED_YELLOW);
			LED_OFF(Pedesterian_PORT,LED_YELLOW);
			// then car green is off , ped red is off , car red is on and green ped is on for 5 secs
			LED_ON(Cars_PORT,LED_RED);
			LED_ON(Pedesterian_PORT,LED_GREEN);
			LED_OFF(Pedesterian_PORT,LED_RED);
			LED_OFF(Cars_PORT,LED_GREEN);
			TMR2_5secs_delay();
			
			
		}
		// after both green and yellow states the car red will be off and both yellow leds start to blink while ped green is still on
		if(current_led != RED)
		{
			
		
		LED_OFF(Cars_PORT,LED_RED);
		LED_ON(Cars_PORT,LED_YELLOW);
		LED_ON(Pedesterian_PORT,LED_YELLOW);
		TMR2_1sec_delay();
		LED_OFF(Cars_PORT,LED_YELLOW);
		LED_OFF(Pedesterian_PORT,LED_YELLOW);
		TMR2_1sec_delay();
		LED_ON(Cars_PORT,LED_YELLOW);
		LED_ON(Pedesterian_PORT,LED_YELLOW);
		TMR2_1sec_delay();
		LED_OFF(Cars_PORT,LED_YELLOW);
		LED_OFF(Pedesterian_PORT,LED_YELLOW);
		TMR2_1sec_delay();
		LED_ON(Cars_PORT,LED_YELLOW);
		LED_ON(Pedesterian_PORT,LED_YELLOW);
		TMR2_1sec_delay();
		LED_OFF(Cars_PORT,LED_YELLOW);
		LED_OFF(Pedesterian_PORT,LED_YELLOW);
		LED_OFF(Pedesterian_PORT,LED_GREEN);
		LED_ON(Pedesterian_PORT,LED_RED);
		LED_ON(Cars_PORT,LED_GREEN);
		}
		
		
		
		// setting the interrupt flag back to not pressed right before going back to the normal mode so it can be activated again
		interrupt_check = Interupt_Npressed;
	}
}
