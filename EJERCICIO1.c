#include <stdint.h> //LIBRERIAS
#include "tm4c123gh6pm.h"//
//TOGGLE LED RED

void main(void) {
	uint32_t n; // VARIABLE 32 BITS
	//
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)==0) { }
	//RELOJ DEL PUERTO F
	
	GPIO_PORTF_DIR_R |= 0x02; //ENTRADA O SALIDA?
	GPIO_PORTF_DR8R_R |=0x02; //CORRIENTE?
	GPIO_PORTF_DEN_R |=0x02; //SEÑAL DIGITAL?
	
	while(1){ //FOREVER RUN A TASK
		GPIO_PORTF_DATA_R |=0X02; //SET
		for(n = 0; n < 800000; n++);//WAIT
		GPIO_PORTF_DATA_R &= ~(0X02);//RESET
		for(n = 0; n < 800000; n++);//WAIT
		} 
	} 