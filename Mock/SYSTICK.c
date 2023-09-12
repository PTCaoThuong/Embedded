#include "S32K144_Register.h"
#include "SYSTICK.h"




/* Enable systick */
void Systick_Init(void){
	/* Disable systick */
	SYST->CSR &= ~(1u);
	/* Clock source */
	SYST->CSR |= (1<<2);
	/* Enable interrupt */
	SYST->CSR |= (1<<1);
	/* Reload value */
	SYST->RVR = 4800000-1; /* 100ms */
	/* Clear current value */
	SYST->CVR |= 0;
	/* Enable systick */
	SYST->CSR |= 1;
}

