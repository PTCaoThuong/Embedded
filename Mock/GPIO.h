#ifndef _GPIO_H_
#define _GPIO_H_

void GPIO_Init(void);
void LED_Init(void);
void BUTTON_Init(void);
void PORTC_IRQHandler(void);
void Turn_on_led(unsigned int LED_Pin);
void Turn_off_led(unsigned int LED_Pin);
void TOff_all_led(void);
extern volatile unsigned int adjust_mode;
extern volatile unsigned int hh;
extern volatile unsigned int mm;
extern volatile unsigned int ss;
extern volatile unsigned int Check_mode;

#endif
