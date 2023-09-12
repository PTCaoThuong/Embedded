#include "S32K144_Register.h"
#include "GPIO.h"

extern volatile unsigned int adjust_mode;
extern volatile unsigned int hh;
extern volatile unsigned int mm;
extern volatile unsigned int ss;
extern volatile unsigned int Check_mode;

#define GPIO_START_SECT_DATA_UNINIT
#include"GPIO_Memmap.h"
static volatile unsigned int mode=0;
#define GPIO_STOP_SECT_DATA_UNINIT
#include"GPIO_Memmap.h"

#define GPIO_START_SECT_CODE
#include"GPIO_Memmap.h"

void PORTC_IRQHandler(void){
	if(PORT_C->PCR[12] & (1<<24)){
		PORT_C->PCR[12] |= (1<<24); /* Clear flag */
		adjust_mode = 1;
		if(mode == 1){
			hh++;
			if(hh>23){
				hh=0;
			}
		}
		else if(mode == 2){
			adjust_mode = 3;
			mode = 0;
		}
		mode = 1;
	}
	
	else if(PORT_C->PCR[13] & (1<<24)){
		PORT_C->PCR[13] |= (1<<24); /* Clear flag */
		if(adjust_mode == 1){
			mm++;
			if(mm>59){
				mm=0;
			}
			mode = 2;
		}
		else{
			Check_mode = 0;
		}
	}
}
#define GPIO_STOP_SECT_CODE
#include"GPIO_Memmap.h"

