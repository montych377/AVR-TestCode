/* 
 * File:   Main.c
 * Author: bhura
 *
 * Created on January 16, 2023, 11:32 AM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRD = 0xff;
    DDRC = 0x00;
    int i = 0;
    int arr[]={0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    while(1){
        if((PINC & 1) == 1 ){
            i++;
            while((PINC & 1 ) == 1);
        }
        
        if(i>8){
            i=0;
        }
        PORTD = arr[i];
    }
    return (EXIT_SUCCESS);
}

