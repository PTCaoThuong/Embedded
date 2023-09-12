#include "S32K144_Register.h"
#include "SPI.h"


extern volatile unsigned char string[20];
extern volatile unsigned int hh;
extern volatile unsigned int mm;
extern volatile unsigned int ss;
extern volatile unsigned int alarm_hh;
extern volatile unsigned int alarm_mm;
extern volatile unsigned int alarm_ss;

#define SPI_START_SECT_CODE
#include"SPI_Memmap.h"

/* SPI Init */
void SPI_Init(void){
	/* Setting pin */
	PCC->PORTB |= (1<<30);
		/* Clear MUX */
	PORT_B->PCR[14] &= ~(7u<<8);
	PORT_B->PCR[15] &= ~(7u<<8);
	PORT_B->PCR[16] &= ~(7u<<8);
	PORT_B->PCR[17] &= ~(7u<<8);
		/* ALT 3 */
	PORT_B->PCR[14] |= (3<<8);	/* LPSPI1_CLK */
	PORT_B->PCR[15] |= (3<<8);	/* LPSPI1_SIN */
	PORT_B->PCR[16] |= (3<<8);	/* LPSPI1_OUT */
	PORT_B->PCR[17] |= (3<<8);	/* LPSPI1_PS3 */
	/* Select source LPSPI */
	PCC->LPSPI1 |= (3<<24); /* FIRCDIV2_CLK */
	PCC->LPSPI1 |= (1<<30);
	/* Setting clock */
	LPSPI_1->CCR |= 4;
	LPSPI_1->CCR |= (4<<24);
	LPSPI_1->CCR |= (4<<16);
	
	LPSPI_1->TCR |= ((3<<27) | (15) | (3<<24) ); /* Transmit FIFO */
	LPSPI_1->CFGR1 |= (1<<3); /* No stall */
	
	/* Configures LPSPI mode */
	LPSPI_1->CFGR1 |= 1;
	LPSPI_1->CR |= (1<<3);
	/* Enable module */
	LPSPI_1->CR |= 1;	
}

/* Enable clock */

void Clock_init(void){
	SCG->FIRCDIV |= (1<<8);

}

void LPSPI1_send_char(unsigned int data){
	while(((LPSPI_1->SR)	& 1u) == 0);
	LPSPI_1->TDR = data;
}


void Display_watch(void){
	LPSPI1_send_char(0x010A);
	LPSPI1_send_char(0x020A);
	LPSPI1_send_char(0x030A);
	LPSPI1_send_char(0x040A);
	LPSPI1_send_char(0x050A);
	LPSPI1_send_char(0x060A);
	LPSPI1_send_char(0x070A);
	LPSPI1_send_char(0x080A);

}

void Display_watch2(void){
	LPSPI1_send_char(0x0100 + ss%10);
	LPSPI1_send_char(0x0200 + ss/10);
	LPSPI1_send_char(0x030A);
	LPSPI1_send_char(0x0400 + mm%10);
	LPSPI1_send_char(0x0500 + mm/10);
	LPSPI1_send_char(0x060A);
	LPSPI1_send_char(0x0700 + hh%10);
	LPSPI1_send_char(0x0800 + hh/10);

}

void Display_watch3(void){
	LPSPI1_send_char(0x0100 + alarm_ss%10);
	LPSPI1_send_char(0x0200 + alarm_ss/10);
	LPSPI1_send_char(0x030A);
	LPSPI1_send_char(0x0400 + alarm_mm%10);
	LPSPI1_send_char(0x0500 + alarm_mm/10);
	LPSPI1_send_char(0x060A);
	LPSPI1_send_char(0x0700 + alarm_hh%10);
	LPSPI1_send_char(0x0800 + alarm_hh/10);

}


void Setting_SPI(void){
		/* intensity*/
	LPSPI1_send_char(0x0A01);
	
	/* scan limit*/
	LPSPI1_send_char(0x0B07);

	/* Normal Operation */
	LPSPI1_send_char(0x0C01);

	 /* Display Test */
//	LPSPI1_send_char(0x0F01);
 
		/* Decode mode */
	LPSPI1_send_char(0x09FF);

}

#define SPI_STOP_SECT_CODE
#include"SPI_Memmap.h"

