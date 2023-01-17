#include "LCD_LM.h"

void LCD_Init(){
    LCD_Wcmd(0x01);
    LCD_Wcmd(0x02);
    LCD_Wcmd(0x06);
    LCD_Wcmd(0x38);
    LCD_Wcmd(0x0c);
}
void LCD_Wdata(unsigned char data){
    PORTD = data;
    PORTC |= (1<<LCD_RS);
    PORTC &= ~(1<<LCD_RW);
    PORTC |= (1<<LCD_EN);
    _delay_ms(3);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(3);
}
void LCD_Wcmd(unsigned char cmd){
    PORTD = cmd;
    PORTC &= ~(1<<LCD_RS);
    PORTC &= ~(1<<LCD_RW);
    PORTC |= (1<<LCD_EN);
    _delay_ms(3);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(3);
}
void LCD_Wstring(const char *ptr){
    while(*ptr){
        LCD_Wdata(*ptr++);
    }
}

