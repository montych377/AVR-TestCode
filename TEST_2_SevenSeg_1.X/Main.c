/* 
 * File:   Main.c
 * Author: bhura
 *
 * Created on January 16, 2023, 12:15 PM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    int i,arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    DDRD = 0xff;
    while(1){
        for(i=0;i<10;i++){
            PORTD = arr[i]; 
            _delay_ms(1000);
        }
    }
    return (EXIT_SUCCESS);
}

