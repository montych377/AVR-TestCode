/* 
 * File:   Main.c
 * Author: bhura
 *
 * Created on January 17, 2023, 10:14 AM
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
void LCD_WriteData4bit(unsigned char data);
void LCD_WriteCmd4bit(unsigned char cmd);
void LCD_WriteString4bit(const char *ptr);

int main(int argc, char** argv) {
    DDRD = 0xff;
    DDRC = 0x07;
    LCD_Initialize();
    while(1){
        LCD_WriteCmd4bit(0x80);
        LCD_WriteString4bit("Hello World !");
        _delay_ms(100);
    }
    return (EXIT_SUCCESS);
}

void LCD_Initialize(){
    LCD_WriteCmd4bit(0x01);
    LCD_WriteCmd4bit(0x02);
    LCD_WriteCmd4bit(0x06);
    LCD_WriteCmd4bit(0x28);
    LCD_WriteCmd4bit(0x0c);
    LCD_WriteCmd4bit(0x80);
}
void LCD_WriteData4bit(unsigned char data){
    PORTD = data & 0xf0;
    PORTC |=  (1<<LCD_RS);
    PORTC &= ~(1<<LCD_RW);
    PORTC |=  (1<<LCD_EN);
    _delay_ms(3);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(3);
    
    PORTD = (data<<4) & 0xf0;
    PORTC |=  (1<<LCD_RS);
    PORTC &= ~(1<<LCD_RW);
    PORTC |=  (1<<LCD_EN);
    _delay_ms(3);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(3);
}
void LCD_WriteCmd4bit(unsigned char cmd){
    PORTD = cmd & 0xf0;
    PORTC &= ~(1<<LCD_RS);
    PORTC &= ~(1<<LCD_RW);
    PORTC |=  (1<<LCD_EN);
    _delay_ms(3);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(3);
    
    PORTD = (cmd<<4) & 0xf0;
    PORTC &= ~(1<<LCD_RS);
    PORTC &= ~(1<<LCD_RW);
    PORTC |=  (1<<LCD_EN);
    _delay_ms(3);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(3);
}
void LCD_WriteString4bit(const char *ptr){
    while(*ptr != '\0'){
        LCD_WriteData4bit(*ptr++);
    }
}
