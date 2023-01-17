/* 
 * File:   Man.c
 * Author: bhura
 *
 * Created on January 16, 2023, 12:43 PM
 */

#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    int i = 0,arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    DDRD = 0xff;
    DDRC = 0x00;
    while(1){
       if((PINC & 1)== 1){ 
           i++;
           while((PINC & 1)== 1);
       }
        PORTD = arr[i]; 
        if(i>9){
            i=0;
        }    
    }
    return (EXIT_SUCCESS);
}

