/* 
 * File:   MAIN_LED_Button.c
 * Author: bhura
 *
 * Created on January 16, 2023, 11:13 AM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include  <util/delay.h>


int main(int argc, char** argv) {
    DDRC = 0x00;
    DDRD = 0xff;
    
    int i=0;
    while(1){
        if((PINC &1) == 1){
           PORTD = 0x01;
        }
        else
           PORTD = 0x00;
        {
            
        }
        
    }
    return (EXIT_SUCCESS);
}

