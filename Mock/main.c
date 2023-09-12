#include "S32K144_Register.h"
#include "GPIO.h"
#include "UART.h"
#include "SPI.h"
#include "LPIT.h"


#define UART_START_SECT_DATA_UNINIT
#include"UART_Memmap.h"
volatile STATE t_state = UNINIT;
volatile unsigned int wait_alam = 0;
volatile unsigned int Check_mode=0; 
volatile unsigned int mm=0;
volatile unsigned int ss=0;
volatile unsigned int alarm_hh=0;
volatile unsigned int alarm_mm=0;
volatile unsigned int alarm_ss=0;
#define UART_STOP_SECT_DATA_UNINIT
#include"UART_Memmap.h"

#define UART_START_SECT_DATA
#include"UART_Memmap.h"
volatile unsigned char string[20]={'0','0','0','0','0','0','0','0','0','0','0','0'};
volatile unsigned int hh=12;
volatile unsigned int adjust_mode = 4;
#define UART_STOP_SECT_DATA
#include"UART_Memmap.h"

#define LPIT_START_SECT_DATA_UNINIT
#include"LPIT_Memmap.h"
volatile unsigned int Check_timer=0; //lpit
#define LPIT_STOP_SECT_DATA_UNINIT
#include"LPIT_Memmap.h"

int main(void){
	Clock_init();
	LPIT_Init();
	Lpuart_Init();
	SPI_Init();
	Setting_SPI();
	GPIO_Init();
	LED_Init();
	BUTTON_Init();
	TOff_all_led();
	
	while(1){
	t_state = Uart_GetTransmitState();
	Uart_TxMainFunction();

	if(adjust_mode == 0 || adjust_mode == 2 || adjust_mode == 3){ //khi adjust_mode = 1 va adjust_mode = 4 la truong hop luc chua cai gio va khi dieu chinh gio bang nut nhan
		calculator();
	}
	if(adjust_mode == 2){	//khi nhan duoc chuoi cai dat bao thuc thi se hien thi bao thuc do len
		
			Display_watch3();
			if(wait_alam>2){
				adjust_mode=0;
				
			}
		
	}
	else if(adjust_mode == 4){ //khi dong ho vua bat chua duoc cai dat bat cu gi
			Display_watch();			
		}
	
	else if(adjust_mode == 1){ //khi an nut thu nhat de cai dat gio
		Turn_on_led(0);
	}
	else if(adjust_mode == 3){ //an nut thu nhat lan nua de ket thuc qua trinh cai dat
		Turn_off_led(0);
		adjust_mode = 0;
		ss=0;
	}

	uart_program(); //nhan chuoi du lieu tu pc ve board bang uart
	if(adjust_mode == 0 || adjust_mode == 1 || adjust_mode == 3){
		Display_watch2();
	}
	
	uart_check_alarm();
	Alarm();
	}
	
}



