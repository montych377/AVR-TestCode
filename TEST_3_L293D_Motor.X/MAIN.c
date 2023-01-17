/* 
 * File:   MAIN.c
 * Author: bhura
 *
 * Created on January 16, 2023, 2:15 PM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRC = 0xff;
    DDRD = 0x00;
    while(1){
        if((PIND & 0x01) == 0x01){
            PORTC = 0x01;
        }
        else if((PIND & 0x02) == 0x02){
            PORTC = 0x02;
        }
        else if((PIND & 0x04) == 0x04){
            PORTC = 0x04;
        }
        else if((PIND & 0x08) == 0x08){
            PORTC = 0x08;
        }
    }
    return (EXIT_SUCCESS);
}

