/* 
 * File:   Main_T2.c
 * Author: bhura
 *
 * Created on January 17, 2023, 5:26 PM
 */
#define F_CPU 8000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

void Timer2_delay(int ms){
    int i;
    for(i=0;i<ms;i++){
        TCNT2 = 248;
        TCCR2 = (1<<CS20)|(1<<CS22)|(1<<CS21);
        while((TIFR & (1<<TOV2))==0);
        TCNT2 = 0;
        TIFR|=(1<<TOV2);
    }
}
int main(int argc, char** argv) {
    DDRD = 0xff;
    while(1){
        PORTD = 0xff;
        Timer2_delay(1);
        PORTD = 0x00;
        Timer2_delay(1);
    }
    return (EXIT_SUCCESS);
}

