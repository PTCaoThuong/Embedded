#ifndef _S32K144_H_
#define _S32K144_H_

/* PCC */
typedef struct{
	volatile unsigned int dummy_1[45];
	volatile unsigned int LPSPI1;
	volatile unsigned int dummy_2[9];
	volatile unsigned int LPIT;
	volatile unsigned int dummy_3[18];
	volatile unsigned int PORTB;
	volatile unsigned int PORTC;
	volatile unsigned int PORTD;
	volatile unsigned int dummy_4[29];
	volatile unsigned int LPUART0;
	volatile unsigned int LPUART1;
}PCC_Type;

#define PCC_BASE_ADDRESS (0x40065000)
#define PCC ((PCC_Type*)PCC_BASE_ADDRESS)

/* GPIO */
typedef struct {
  volatile unsigned int PDOR;
  volatile  unsigned int PSOR;
  volatile  unsigned int PCOR;
  volatile  unsigned int PTOR;
  volatile const  unsigned int PDIR;
  volatile unsigned int PDDR;
  volatile unsigned int PIDR;
} GPIO_Type;

/* GPIO_B */
#define GPIOB_base_address   (0x400FF040u)
#define GPIOB   ((GPIO_Type*)(GPIOB_base_address))

/* GPIO_C */
#define GPIOD_base_address   (0x400FF0C0u)
#define GPIOD   ((GPIO_Type*)(GPIOD_base_address))

/* GPIO_D */
#define GPIOC_base_address   (0x400FF080u)
#define GPIOC   ((GPIO_Type*)(GPIOC_base_address))

/* LPIT */
typedef struct{
	volatile unsigned int VERID ;
	volatile unsigned int PARAM ;
	volatile unsigned int MCR ;
	volatile unsigned int MSR ;
	volatile unsigned int MIER ;
	volatile unsigned int SETTEN ;
	volatile unsigned int CLRTEN ;
	volatile unsigned int dummy_5[1]; 
	volatile unsigned int TVAL0 ;
	volatile unsigned int CVAL0 ;
	volatile unsigned int TCTRL0 ;
	volatile unsigned int dummy_6[1]; 
	volatile unsigned int TVAL1 ;
	volatile unsigned int CVAL1 ;
	volatile unsigned int TCTRL1 ;
	volatile unsigned int dummy_7[1]; 
	volatile unsigned int TVAL2 ;
	volatile unsigned int CVAL2 ;
	volatile unsigned int TCTRL2 ;
	volatile unsigned int dummy_8[1]; 
	volatile unsigned int TVAL3 ;
	volatile unsigned int CVAL3 ;
	volatile unsigned int TCTRL3 ;
}LPIT_Type;

#define LPIT_BASE_ADDRESS (0x40037000)
#define LPIT0 ((LPIT_Type*)LPIT_BASE_ADDRESS)

/* NVIC */
typedef struct{
	volatile unsigned int ISER0;
	volatile unsigned int ISER1;

}NVIC_Type;

#define NVIC_BASE_ADDRESS (0xE000E100)
#define NVIC ((NVIC_Type*)NVIC_BASE_ADDRESS)

/* PORT */

typedef struct{
	volatile unsigned int PCR[32];
}PORT_Type;

#define PORTB_BASE_ADDRESS (0x4004A000)
#define PORT_B ((PORT_Type*)PORTB_BASE_ADDRESS)

#define PORTC_BASE_ADDRESS (0x4004B000)
#define PORT_C ((PORT_Type*)PORTC_BASE_ADDRESS)

#define PORTD_BASE_ADDRESS (0x4004C000)
#define PORT_D ((PORT_Type*)PORTD_BASE_ADDRESS)

/* SYSTICK */

typedef struct{
	volatile unsigned int CSR;
	volatile unsigned int RVR;
	volatile unsigned int CVR;
}SYST_Type;

#define SYST_BASE_ADDRESS (0xE000E010)
#define SYST ((SYST_Type*)SYST_BASE_ADDRESS)

/* LPUART */

typedef struct{
	volatile unsigned int VERID_LPUART;
	volatile unsigned int PARAM_LPUART;
	volatile unsigned int GLOBAL;
	volatile unsigned int PINCFG;
	volatile unsigned int BAUD;
	volatile unsigned int STAT;
	volatile unsigned int CTRL;
	volatile unsigned int DATA;
	volatile unsigned int MATCH;
	volatile unsigned int MODIR;
	volatile unsigned int FIFO;
	volatile unsigned int WATER;

}LPUART_Type;

#define LPUART_BASE_ADDRESS (0x4006B000)
#define LPUART ((LPUART_Type*)LPUART_BASE_ADDRESS)

typedef struct{
	volatile unsigned int VERID_SPI;
	volatile unsigned int PARAM_SPI;
	volatile unsigned int dummy_9[2];
	volatile unsigned int CR;
	volatile unsigned int SR;
	volatile unsigned int IER;
	volatile unsigned int DER;
	volatile unsigned int CFGR0;
	volatile unsigned int CFGR1;
	volatile unsigned int dummy_10[2];
	volatile unsigned int DMR0;
	volatile unsigned int DMR1;
	volatile unsigned int dummy_11[2];
	volatile unsigned int CCR;
	volatile unsigned int dummy_12[5];
	volatile unsigned int FCR;
	volatile unsigned int FSR;
	volatile unsigned int TCR;
	volatile unsigned int TDR;
	volatile unsigned int dummy_13[2];
	volatile unsigned int RSR;
	volatile unsigned int RDR;
}LPSPI_Type;

#define LPSPI1_BASE_ADDRESS (0x4002D000)
#define LPSPI_1	((LPSPI_Type*)LPSPI1_BASE_ADDRESS)

typedef struct{
	volatile unsigned int dummy_14[193];
	volatile unsigned int FIRCDIV;
}SCG_Type;

#define SCG_BASE_ADDRESS (0x40064000)
#define SCG ((SCG_Type*)SCG_BASE_ADDRESS)

#endif
