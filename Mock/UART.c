#include "S32K144_Register.h"
#include "UART.h"

extern volatile STATE t_state;

#define UART_START_SECT_DATA_UNINIT
#include"UART_Memmap.h"
static volatile unsigned int t_length=0;
static volatile unsigned int t_index=0;
static volatile unsigned char TxBuffer[30];
#define UART_STOP_SECT_DATA_UNINIT
#include"UART_Memmap.h"

#define UART_START_SECT_CODE
#include"UART_Memmap.h"

void Lpuart_Init(void){
	/* Enable NVIC LPUART1 */
	NVIC->ISER1 |= (1<<1);
	/* Setting Tx/Rx pin */
	PCC->PORTC |= (1<<30);
	
	PORT_C->PCR[6] &= ~(7u<<8);
	PORT_C->PCR[7] &= ~(7u<<8);
	
	PORT_C->PCR[6] |= (2u<<8);
	PORT_C->PCR[7] |= (2u<<8);
	/* Clock source */
	PCC->LPUART1 |= (3<<24); /* FIRCDIV2_CLK */
	PCC->LPUART1 |= (1<<30);
	/* Setting baud rate */
	LPUART->BAUD &= ~(0x1fu << 24);
	LPUART->BAUD &= ~(0x1fffu);
	LPUART->BAUD |= 312u;
	/* Setting frame */
	LPUART->BAUD &= ~(1u<<13);
	LPUART->CTRL &= ~(1u<<4);
	LPUART->CTRL &= ~(1u);
	/* Enable receive interrupt */
	LPUART->CTRL |= (1<<21);
	/* Enable Tx & Rx */
	LPUART->CTRL |= (1<<19);
	LPUART->CTRL |= (1<<18);
	
	t_state = IDLE;
}

void Uart_Init(void){

	/* Setting Tx/Rx pin */
	PCC->PORTC |= (1<<30);
	
	PORT_C->PCR[6] &= ~(7u<<8);
	PORT_C->PCR[7] &= ~(7u<<8);
	
	PORT_C->PCR[6] |= (2u<<8);
	PORT_C->PCR[7] |= (2u<<8);
	/* Clock source */
	PCC->LPUART1 |= (3<<24); /* FIRCDIV2_CLK */
	PCC->LPUART1 |= (1<<30);
	/* Setting baud rate */
	LPUART->BAUD &= ~(0x1fu << 24);
	LPUART->BAUD &= ~(0x1fffu);
	LPUART->BAUD |= 312u;
	/* Setting frame */
	LPUART->BAUD &= ~(1u<<13);
	LPUART->CTRL &= ~(1u<<4);
	LPUART->CTRL &= ~(1u);

	/* Enable Tx & Rx */
	LPUART->CTRL |= (1<<19);
	LPUART->CTRL |= (1<<18);
}

unsigned char Uart_GetTransmitState(void){
	if(t_length != 0){
		return BUSY;
	}
	else{
		return IDLE;
	}
}

void Uart_Transmit(unsigned char* u8_TxBuffer, unsigned int u4_Length){
	if(t_state == IDLE){
		for(unsigned int i =0;i < u4_Length;i++){
			TxBuffer[i] = u8_TxBuffer[i];
			t_length++;
		}
	}
	
}


void Uart_TxMainFunction(void){
	if(t_state == BUSY){
	 if(LPUART->STAT & (1<<23u)){
		LPUART->DATA = TxBuffer[t_index];
		t_length--;
		t_index++;
	 }
	}
	else if(t_state == IDLE){
		t_index = 0;
	}
}

#define UART_STOP_SECT_CODE
#include"UART_Memmap.h"
