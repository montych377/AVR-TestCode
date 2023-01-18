/* 
 * File:   MAIN_pwm_2.c
 * Author: bhura
 *
 * Created on January 18, 2023, 1:04 PM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRB |= (1<<PB3);
    TCCR2 |= (1<<COM21)|(1<<WGM20)|(1<<WGM21);
    TCCR2 |= (1<<CS21);
    
    while(1){
        for(int i=0;i<1000;i++){
            OCR2 = i;
            _delay_ms(10);
        }
        for(int i=1000;i>=0;i--){
            OCR2 = i;
            _delay_ms(10);
        }
    }
    return (EXIT_SUCCESS);
}

