#include "S32K144_Register.h"
#include "LPIT.h"

extern volatile unsigned int Check_timer;
extern volatile unsigned int Check_Alarm;
extern volatile unsigned int Check_mode;
extern volatile unsigned int TimeOutAlarm;
extern volatile unsigned int wait_alam;


#define LPIT_START_SECT_CODE
#include"LPIT_Memmap.h"

void LPIT0_Ch0_IRQHandler(void){
	LPIT0->MSR = 0x1;
	Check_timer = 1;
	wait_alam++;
	if(Check_mode == 1){
		Check_Alarm++;
		TimeOutAlarm++;
	}
	
}

#define LPIT_STOP_SECT_CODE
#include"LPIT_Memmap.h"


