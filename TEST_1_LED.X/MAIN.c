/* 
 * File:   MAIN.c
 * Author: bhura
 *
 * Created on January 16, 2023, 11:03 AM
 */

#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRD = 0XFF;
    while(1){
        PORTD = 0xff;
        _delay_ms(1000);
        PORTD = 0x00;
        _delay_ms(1000);
        
    }
    return (EXIT_SUCCESS);
}

