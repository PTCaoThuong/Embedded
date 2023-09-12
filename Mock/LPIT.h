#ifndef _LPIT_H_
#define _LPIT_H_


void LPIT_Init(void);
void LPIT0_Ch0_IRQHandler(void);
extern volatile unsigned int Check_mode;
extern volatile unsigned int Check_timer;
void calculator(void);
void Alarm(void);
extern volatile unsigned int Check_Alarm;
extern volatile unsigned int TimeOutAlarm;
extern volatile unsigned int wait_alam;
#endif

