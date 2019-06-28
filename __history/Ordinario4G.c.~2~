#include <18F4620.h>
#include <stdlib.h>
#include <stdio.h>

#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O

#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #define RX_232        PIN_C7
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1,UART1,RCV=RX_232)
   #use fast_io(c)
#endif 
#int_rda
void isr_rda(void){
    
}
#int_timer0
void timer_0()
{ 
}
void main(void){

while(1){

    }
}
