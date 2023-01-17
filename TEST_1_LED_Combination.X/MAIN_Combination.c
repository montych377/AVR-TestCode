/* 
 * File:   MAIN_Combination.c
 * Author: bhura
 *
 * Created on January 15, 2023, 9:00 PM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRD = 0xFF;
    int i;
    while(1){
        for(i=0;i<8;i++){
            PORTD ^= (1<<i);
            _delay_ms(1000);
        }
    }
    return (EXIT_SUCCESS);
}



