#include "S32K144_Register.h"
#include "GPIO.h"

#define GPIO_START_SECT_CODE
#include"GPIO_Memmap.h"

/* GPIO init */

void GPIO_Init(void){
	/* Enable clock */
	PCC->PORTC |= (1<<30);	/* PORT C */
	PCC->PORTD |= (1<<30);	/* PORT D */
	/* Clear MUX */
	PORT_C->PCR[12] &= ~(7u<<8);	/* PORT C */
	PORT_C->PCR[13] &= ~(7u<<8);
	
	PORT_D->PCR[0] &= ~(7u<<8);		/* PORT D */
	PORT_D->PCR[15] &= ~(7u<<8);
	PORT_D->PCR[16] &= ~(7u<<8);
	/* Set GPIO */
	PORT_C->PCR[12] |= (1u<<8);		/* PORT C */
	PORT_C->PCR[13] |= (1u<<8);
	
	PORT_D->PCR[0] |= (1u<<8);		/* PORT D */
	PORT_D->PCR[15] |= (1u<<8);
	PORT_D->PCR[16] |= (1u<<8);
	/* Disable Pull up/down */
	PORT_C->PCR[12] &= ~(1u<<1);	/* PORT C */
	PORT_C->PCR[13] &= ~(1u<<1);

	PORT_D->PCR[0] &= ~(1u<<1);		/* PORT D */
	PORT_D->PCR[15] &= ~(1u<<1);
	PORT_D->PCR[16] &= ~(1u<<1);
}
	
	

/* Enable Led */

void LED_Init(void){
	/* Set pin is output */
	GPIOD->PDDR |= (1);
	GPIOD->PDDR |= (1<<15);
	GPIOD->PDDR |= (1<<16);
}

/* Enable Button */

void BUTTON_Init(void){
	/* Set interrupt */
	PORT_C->PCR[12] |= (9u<<16);
	PORT_C->PCR[13] |= (9u<<16);
	/* Set pin is input */
	GPIOC->PDDR &= ~(1u<<12);
	GPIOC->PDDR &= ~(1u<<13);
	/* Set NVIC */
	NVIC->ISER1 |= (1<<29);
}

/* Turn on led */

void Turn_on_led(unsigned int LED_Pin){
	GPIOD->PDOR &= ~(1<<LED_Pin);
}

void Turn_off_led(unsigned int LED_Pin){
	GPIOD->PDOR |= (1<<LED_Pin);
}

void TOff_all_led(void){
	GPIOD->PDOR |= ( (1) | (1<<15) | (1<<16) );
}

#define GPIO_STOP_SECT_CODE
#include"GPIO_Memmap.h"
