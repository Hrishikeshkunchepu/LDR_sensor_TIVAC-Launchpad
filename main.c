
#include <stdio.h>  // Diamond braces for sys lib: Standard I/O
#include <stdint.h> // C99 variable types
//#include "PLL.h"
#include "UART.h"
#include "../tm4c123gh6pm.h"
#include "ADCSWTrigger.h"





float intensity(float);

void Output_Init(void);

unsigned long ADCvalue;
float vin;
float i;



int main(void) {unsigned long volatile delay;
  
	
	
	ADC0_InitSWTriggerSeq3_Ch1();
  //PLL_Init();
	Output_Init();              // initialize UART0 module
  printf("This program calculates ADC of analog senosr \n");
  
	
	while(1){
    ADCvalue = ADC0_InSeq3();   //ADC conversion value stored in SS3 FIFO register.
		printf("%lu \n", ADCvalue);  
             
    vin = (3.3* ADCvalue)/4096; //voltage at Analog pin
		i = intensity(vin);          // Intensity calculation using LDR
		
		printf("\noutput voltage = %lf \n", vin); 
		printf("\noutput Intensity = %lf \n", i); 

    for(delay=0; delay<10000000; delay++){};
  }
}



float intensity(float a){
	
	a = (2500-500*vin)/(vin*3.3);
  return a;


}