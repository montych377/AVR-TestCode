/* 
 * File:   Main.c
 * Author: bhura
 *
 * Created on January 16, 2023, 12:54 PM
 */

#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    int i = 0,j = 0,arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    DDRD = 0xff;
    DDRC = 0xff;
    DDRB = 0x00;
    while(1){
        if((PINB & 1) == 1){
            j++;
            while((PINB & 1) == 1);
        }
        if(j>9){
            i++;
            j=0;
        }
        if(i>9){
            j++;
            i=0;
        }
        PORTC = 0x02;
        PORTD = arr[i];
        _delay_ms(20);
        PORTC = 0x01;
        PORTD = arr[j];
        _delay_ms(20);
        
         
    }
    return (EXIT_SUCCESS);
}

