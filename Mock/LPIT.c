#include "S32K144_Register.h"
#include "LPIT.h"
#include "GPIO.h"

extern volatile unsigned int Check_mode;
extern volatile unsigned int Check_timer;
extern volatile unsigned int hh;
extern volatile unsigned int mm;
extern volatile unsigned int ss;


#define LPIT_START_SECT_DATA
#include"LPIT_Memmap.h"
volatile unsigned int Check_Alarm = 1;
#define LPIT_STOP_SECT_DATA
#include"LPIT_Memmap.h"

#define LPIT_START_SECT_DATA_UNINIT
#include"LPIT_Memmap.h"
volatile unsigned int TimeOutAlarm=0;
#define LPIT_STOP_SECT_DATA_UNINIT
#include"LPIT_Memmap.h"

#define LPIT_START_SECT_CODE
#include"LPIT_Memmap.h"

void LPIT_Init(void){
	/* Enable NVIC */
	NVIC->ISER1 |= (1<<16); /* Channel 0 */
	/* Setting clock */
	PCC->LPIT |= (7<<24); /* 128 kHz */
	PCC->LPIT |= (1<<30);
	/* LPIT Initialization */
	LPIT0->MCR |= 1; /* Module Clock Enable */
	LPIT0->MCR |= (1<<3); /* Debug mode */
	/* Enable interrupt */
	LPIT0->MIER |= 1; /* Channel 0 */
	LPIT0->MSR = 0x1; /* clear flag */
	/* Set timer value start */
	LPIT0->TVAL0 = 128000; /* 1s */
	/* Configuration channel */
	LPIT0->TCTRL0 &= ~(3u<<2); /* 32bit periodic counter */
	/* Enable timer channel */
	LPIT0->TCTRL0 |= 1;
	/* Check_Alarm */
	Check_Alarm = 1;
}

void calculator(void){
	if(Check_timer == 1){
		Check_timer=0;
		ss+=1;
		if(ss>59){
			ss=0;
			mm++;
			if(mm>59){
				mm=0;
				hh++;
					if(hh>23){
					hh=0;
					}
			}
		}
	}
}


/* Alarm */

void Alarm(void){
	
	if(Check_mode == 1 && TimeOutAlarm <10){
		if(Check_Alarm == 1){
			Turn_off_led(0);
			Turn_on_led(15);
		}
		else if(Check_Alarm == 2){
			Turn_off_led(15);
			Turn_on_led(16);
		}
		else if(Check_Alarm == 3){
			Turn_off_led(16);
			Turn_on_led(0);
//		Check_mode = 0;
			Check_Alarm = 0;
		}
	}
	else{
	Check_Alarm = 1;
	Check_mode = 0;
	TimeOutAlarm = 0;
	TOff_all_led();
	}
}


#define LPIT_STOP_SECT_CODE
#include"LPIT_Memmap.h"

