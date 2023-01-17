/* 
 * File:   MAIN.c
 * Author: bhura
 *
 * Created on January 16, 2023, 1:26 PM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int main(int argc, char** argv) {
    DDRD = 0xFF;
    DDRC = 0xFF;
    int i = 0,j = 0,k = 0,l = 0, arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    
    while(1){
        for(i=0;i<=1;i++){
            for(j=0;j<10;j++){
                for(k=0;k<6;k++){
                    for(l=0;l<10;l++){
                        if(i==1&&j==1&&k==5&&l==9)
                        {
                            i=j=k=l=0;
                        }
                        PORTC = 0x0e;
                        PORTD = arr[i];
                        _delay_ms(15);
                        
                        PORTC = 0x0d;
                        PORTD = arr[j];
                        _delay_ms(15);
                        
                        PORTC = 0x0b;
                        PORTD = arr[k];
                        _delay_ms(15);
                        
                        PORTC = 0x07;
                        PORTD = arr[l];
                        _delay_ms(15);
                    }
                }
            }
        }
    }
    return (EXIT_SUCCESS);
}

