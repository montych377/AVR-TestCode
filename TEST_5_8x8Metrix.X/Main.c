/* 
 * File:   Main.c
 * Author: bhura
 *
 * Created on January 16, 2023, 5:25 PM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

int arr[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
int arr1[8] = {0x0c,0x12,0x12,0x1e,0x12,0x12,0x12,0x00};
int main() {
    DDRD = 0xff; 
    DDRB = 0xff; 

    while(1) {
         
        for(int j = 0; j <8; j++) {
            for(int k = 0; k <20; k++) {
                    for(int i = 0; i < 8; i++) {
                        PORTB = ~(arr[i]);
                        PORTD = (arr1[i]<<(j));
                        _delay_ms(1);
//            PORTB = ~0x02;
//            PORTD = (0x12 << (i));
//            _delay_ms(1);
//            PORTB = ~0x04;
//            PORTD = (0x12 << (i));
//            _delay_ms(1);
//            PORTB = ~0x08;
//            PORTD = (0x1e << (i));
//            _delay_ms(1);
//            PORTB = ~0x10;
//            PORTD = (0x12 << (i));
//            _delay_ms(1);
//            PORTB = ~0x20;
//            PORTD = (0x12 << (i));
//            _delay_ms(1);
//            PORTB = ~0x40;
//            PORTD = (0x12 << (i));
//            _delay_ms(1);
//            PORTB = ~(0x80);
//            PORTD = (0x00 << (i));
//            _delay_ms(100);
                    }
                }
        }
    }
    return 0;
}

