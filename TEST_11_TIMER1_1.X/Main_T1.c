/* 
 * File:   Main_T1.c
 * Author: bhura
 *
 * Created on January 17, 2023, 4:47 PM
 */
#define F_CPU 8000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

void Timer1_delay(int ms){
    int i;
    for(i=0;i<ms;i++){
        TCNT1 = 65528;
        TCCR1A = 0;
        TCCR1B = (1<<CS10)|(1<<CS12);
        while((TIFR & (1<<TOV1))==0);
        TCNT1 = 0;
        TIFR |= (1<<TOV1);
    }
}
int main(int argc, char** argv) {
    DDRD = 0xff;
    while(1){
        PORTD = 0xff;
        Timer1_delay(1);
        PORTD = 0x00;
        Timer1_delay(1);
    }
    return (EXIT_SUCCESS);
}

