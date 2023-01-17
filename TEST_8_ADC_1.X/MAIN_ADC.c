/* 
 * File:   MAIN_ADC.c
 * Author: bhura
 *
 * Created on January 17, 2023, 11:46 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "LCD.h"

unsigned int ADC_Read(int channel);

int main(int argc, char** argv) {
    DDRD = 0xff;
    DDRC = 0xfe;
    LCD_Init();
    
    while(1){
        char arr[15];
        int data = ADC_Read(0);
        int vol = data*5/1023;
        sprintf(arr,"ADC = %d",vol);
        LCD_Wcmd(0x80);
        LCD_Wstring(arr);
    }
    return (EXIT_SUCCESS);
}
unsigned int ADC_Read(int channel){
    channel = channel & 0x07;
    ADMUX = (1<<REFS0)|channel;
    ADCSRA = (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADSC);
    while((ADCSRA & (1<<ADIF)) == 0);
    return ADC;
}
