#include "S32K144_Register.h"
#include "UART.h"
#include "LPIT.h"
#include "SPI.h"

extern volatile unsigned int Check_mode;
extern volatile unsigned char string[20];
extern volatile unsigned int hh;
extern volatile unsigned int mm;
extern volatile unsigned int ss;
extern volatile unsigned int alarm_hh;
extern volatile unsigned int alarm_mm;
extern volatile unsigned int alarm_ss;
extern volatile unsigned int adjust_mode;
extern volatile unsigned int wait_alam;

#define UART_START_SECT_DATA_UNINIT
#include"UART_Memmap.h"
static volatile unsigned int uart_check=0;
static volatile unsigned char uart_data;
static volatile unsigned int index=0;
#define UART_STOP_SECT_DATA_UNINIT
#include"UART_Memmap.h"

#define UART_START_SECT_DATA
#include"UART_Memmap.h"
static unsigned char trans[20]="Frame error\n";
static unsigned char trans_2[20]="Amazing Good Job!\n";
#define UART_STOP_SECT_DATA
#include"UART_Memmap.h"


#define UART_START_SECT_CODE
#include"UART_Memmap.h"

void LPUART1_RxTx_IRQHandler(void){
	uart_data = (char)LPUART->DATA;
	uart_check = 1;
}

/*[s:03:04:05]*/
void uart_program(void){
	if(index > 0 && uart_check==1){
		string[index] = uart_data;
		index++;
		uart_check=0;
	}
	if(uart_data == '[' && uart_check==1){
		string[0] = uart_data;
		index=1;
		uart_check=0;
	}
	if(index > 12){
	Uart_Transmit(trans,12);
	index = 0;
	}
	else{
		if(LPUART->STAT & (1<<20)){
			LPUART->STAT = 0x100000;
			if(string[11]==']'){
				string[11] = '0';
				uart_data = '0';
				if(string[1]=='s'){
					uart_check_program();
				}
				else if(string[1] == 'a'){
					uart_alarm_program();
				}
				else{
					Uart_Transmit(trans,12);
				}
			}
			else if(string[11]!= ']'){
				Uart_Transmit(trans,12);
			}
			index = 0;
		}
	}
//	if(uart_data == ']'){
//		uart_data = '0';
//		if(string[1]=='s'){
//			uart_check_program();
//		}
//		else if(string[1] == 'a'){
//			uart_alarm_program();
//		}
//		index = 0;
//	}
	
}


void uart_check_program(void){
		hh=(string[3] - 48 )*10 + (string[4]-48);
		if(hh<=23){
			mm = (string[6] - 48 )*10 + (string[7]-48);
			if(mm<=59){
				ss = (string[9] - 48 )*10 + (string[10]-48);
				if(ss<=59){
					adjust_mode = 0;
					Uart_Transmit(trans_2,18);
				}
				else{
					Uart_Transmit(trans,12);
				}
			}
			else{
				Uart_Transmit(trans,12);
			}
			
		}
		else{
			Uart_Transmit(trans,12);
		}
			
}

void uart_alarm_program(void){
		alarm_hh=(string[3] - 48 )*10 + (string[4]-48);
		if(hh<=23){
			alarm_mm = (string[6] - 48 )*10 + (string[7]-48);
			if(alarm_mm<=59){
				alarm_ss = (string[9] - 48 )*10 + (string[10]-48);
				if(alarm_ss<=59){
					adjust_mode = 2;
					Uart_Transmit(trans_2,18);
					wait_alam = 0;
				}
				else{
					Uart_Transmit(trans,12);
				}
			}
			else{
				Uart_Transmit(trans,12);
			}
			
		}
		else{
			Uart_Transmit(trans,12);
		}

}

void uart_check_alarm(void){
	if(hh == alarm_hh && mm == alarm_mm && ss == alarm_ss){
		Check_mode = 1;
	}
	else{}

}

#define UART_STOP_SECT_CODE
#include"UART_Memmap.h"

