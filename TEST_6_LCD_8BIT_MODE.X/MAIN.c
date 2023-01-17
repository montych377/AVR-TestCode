/* 
 * File:   MAIN.c
 * Author: bhura
 *
 * Created on January 17, 2023, 9:55 AM
 */
#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

#define LCD_RS PC0
#define LCD_RW PC1
#define LCD_EN PC2

void LCD_Initialize();
void LCD_WriteData(unsigned char data);
void LCD_WriteCmd(unsigned char cmd);
void LCD_WriteString(const char *ptr);
int main(int argc, char** argv) {
    DDRD = 0xFF;
    DDRC = 0x07;
    DDRB = 0x00;
    uint8_t i = 0;
    char arr[15];
    LCD_Initialize();
    while(1){
        if((PINB & 0x01) == 0x01){
            i++;
            while((PINB & 0x01) == 0x01);
        }
        LCD_WriteCmd(0x80);
        LCD_WriteString("Hello World!");
        LCD_WriteCmd(0xC0);
        sprintf(arr,"Count = %d",i);
        LCD_WriteString(arr);
        _delay_ms(10);
    }
    return (EXIT_SUCCESS);
}

void LCD_Initialize(){
    LCD_WriteCmd(0x01);
    LCD_WriteCmd(0x02);
    LCD_WriteCmd(0x06);
    LCD_WriteCmd(0x38);
    LCD_WriteCmd(0x0c);
    LCD_WriteCmd(0x80);
}
void LCD_WriteData(unsigned char data){
    PORTD = data;
    PORTC |=  (1<<LCD_RS);
    PORTC &= ~(1<<LCD_RW);
    PORTC |=  (1<<LCD_EN);
    _delay_ms(3);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(3);
}
void LCD_WriteCmd(unsigned char cmd){
    PORTD = cmd;
    PORTC &= ~(1<<LCD_RS);
    PORTC &= ~(1<<LCD_RW);
    PORTC |=  (1<<LCD_EN);
    _delay_ms(3);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(3);
}
void LCD_WriteString(const char *ptr){
    while(*ptr != '\0'){
        LCD_WriteData(*ptr++);
    }
}
