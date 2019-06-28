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

int conteo1=1;
int conteo2=1;
int conteo3=1;
int contador100=0;
int contador300=0;
int contador500=0;


void isr_rda(void){
    
}
#int_timer0
void timer_0()
{ 
    set_timer0(65217);
    contador100++;
    contador300++;
    contador500++;
}
void main(void){
     setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8);
     set_timer0(65217);
     enable_interrupts(int_timer0);
     enable_interrupts(global);
     
    output_a(0x0);   
    output_b(0x0);     
    output_d(0x0);
while(1){
    //contador 1 (100hzs)
    if(contador100==1){
         conteo1*=2;   
         contador100=0;
      }  
     if(conteo1==64){
      conteo1=1;
     }
     output_a(conteo1);
     
    //contador 2 (400ms)
    if(contador300==3){
         conteo2*=2;   
         contador300=0;
      }
   
     if(conteo2==256){
      conteo2=1;
     }
     output_b(conteo2);
    
      //contador 3  (700ms)
       if(contador500==5){
         conteo3*=2;   
         contador500= 0;
      }
     if(conteo3 ==256){
      conteo3=1;
     }
     output_d(conteo3);
    }
}
