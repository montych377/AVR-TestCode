/* 
 * File:   Main_PWM.c
 * Author: bhura
 *
 * Created on January 18, 2023, 2:32 AM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRB |= (1<<PB1);
    TCCR1A |= (1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<CS00);
    while(1){
        for(int i=0;i<200;i++){
            OCR1A = i;
            _delay_ms(10);
        }
        for(int i=200;i>=0;i--){
            OCR1A = i;
            _delay_ms(10);
        }
    }
    return (EXIT_SUCCESS);
}

