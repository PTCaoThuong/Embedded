typedef enum{
	UNINIT,
	IDLE,
	BUSY,
	EMPTY,
	NOT_EMP
}STATE;
extern volatile unsigned char string[20];
extern volatile unsigned int hh;
extern volatile unsigned int mm;
extern volatile unsigned int ss;
extern volatile unsigned int Check_mode;
extern volatile unsigned int alarm_hh;
extern volatile unsigned int alarm_mm;
extern volatile unsigned int alarm_ss;
extern volatile unsigned int adjust_mode;
unsigned char Uart_GetTransmitState(void);
void Uart_Transmit(unsigned char* u8_TxBuffer, unsigned int u4_Length);
void Uart_TxMainFunction(void);
extern volatile unsigned int wait_alam;
extern volatile STATE t_state;


void uart_program1(void);
void Lpuart_Init(void);
void LPUART1_RxTx_IRQHandler(void);
void Uart_Init(void);
void uart_program(void);
void uart_check_program(void);
void uart_alarm_program(void);
void uart_check_alarm(void);
