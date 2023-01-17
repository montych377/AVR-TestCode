/* 
 * File:   newmain.c
 * Author: bhura
 *
 * Created on January 17, 2023, 12:45 PM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#include <util/delay.h>
#include "LCD_LM.h"

unsigned int ADC_Read(uint8_t channel);
int main(int argc, char** argv) {
    DDRD = 0xff;
    DDRC = 0xfe;
    DDRB = 0xff;
    LCD_Init();
    while(1){
        char arr[15];
        int data = ADC_Read(0);
        int temp = ((data*500)/1023);
        sprintf(arr,"ADC = %d",temp);
        LCD_Wcmd(0x80);
        LCD_Wstring(arr);
        _delay_ms(50);
        
        if(temp > 20){
            PORTB = 0x01;
        }
        else if(temp <= 15){
            PORTB = 0x00;
        }
    }
    return (EXIT_SUCCESS);
}

unsigned int ADC_Read(uint8_t channel){
    channel = channel & 0x07;
    ADMUX = (1<<REFS0)| channel;
    ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADPS0)|(1<<ADPS1);
    while((ADCSRA & (1<<ADIF))==0);
    return ADC;
}
