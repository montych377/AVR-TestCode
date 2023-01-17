/* 
 * File:   MAIN_T.c
 * Author: bhura
 *
 * Created on January 17, 2023, 4:21 PM
 */
#define F_CPU 8000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

void Timer0_init(int ms){
    int i;
    for(i=0;i<ms;i++){
        TCNT0 = 225;
        TCCR0 = (1<<CS02);
        while((TIFR & (1<<TOV0))==0);
        TCCR0 = 0;
        TIFR|=(1<<TOV0);
    }
}
int main(int argc, char** argv) {
    DDRD = 0xff;
    while(1){
        PORTD = 0xff;
        Timer0_init(1000);
        PORTD = 0x00;
        Timer0_init(1000);
    }
    return (EXIT_SUCCESS);
}

