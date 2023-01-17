/* 
 * File:   Main.c
 * Author: bhura
 *
 * Created on January 16, 2023, 12:36 PM
 */

#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    int i,j,arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    DDRD = 0xff;
    DDRC = 0xff;
    while(1){
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                PORTC = 0x02;
                PORTD = arr[i];
                _delay_ms(50);
                PORTC = 0x01;
                PORTD = arr[j];
                _delay_ms(50);
            }
        }
    }
    return (EXIT_SUCCESS);
}

