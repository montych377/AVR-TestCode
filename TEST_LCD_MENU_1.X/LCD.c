#include "LCD.h"

void LCD_Initialize(uint8_t mode){
    
    switch(mode){
        case 0:{
            LCD_Write_4Cmd(0x28);
            LCD_Write_4Cmd(0x02);   
            LCD_Write_4Cmd(0x06);   
            LCD_Write_4Cmd(0x01);   
            LCD_Write_4Cmd(0x0C); 
        }
        case 1:{
            LCD_Write_8Cmd(0x38);   
            LCD_Write_8Cmd(0x01);   
            LCD_Write_8Cmd(0x02);   
            LCD_Write_8Cmd(0x06);   
            LCD_Write_8Cmd(0x0C);    
        }
          
        
    }
}
void LCD_Write_4Data(unsigned char data){
    LCD_DATA_PORT = (LCD_DATA_PORT&0xf0)|(data & 0x0f);
    PORTC |= (1<<LCD_RS);
    PORTC |= (1<<LCD_EN);
    _delay_ms(1);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(200);
    
    LCD_DATA_PORT =(LCD_DATA_PORT&0x0f)| (data<<4) ;
    PORTC |= (1<<LCD_RS);
    PORTC |= (1<<LCD_EN);
    _delay_ms(1);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(2);
}
void LCD_Write_4Cmd(unsigned char cmd){
    LCD_DATA_PORT = (cmd & 0x0f)|(LCD_DATA_PORT&0xf0);
    PORTC &= ~(1<<LCD_RS);
    PORTC |= (1<<LCD_EN);
    _delay_ms(11);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(200);
    LCD_DATA_PORT = (cmd<<4)| (LCD_DATA_PORT&0x0f);
    PORTC |= (1<<LCD_EN);
    _delay_ms(1);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(2);
}
void LCD_Write_4String(uint8_t x, uint8_t y, const char *ptr);
void LCD_Write_8Data(unsigned char data){
    LCD_DATA_PORT = data;
    PORTC |= (1<<LCD_RS);
    PORTC |= (1<<LCD_EN);
    _delay_ms(10);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(10);
            
}
void LCD_Write_8Cmd(unsigned char cmd){
    LCD_DATA_PORT = cmd;
    PORTC &= ~(1<<LCD_RS);
    PORTC |= (1<<LCD_EN);
    _delay_ms(10);
    PORTC &= ~(1<<LCD_EN);
    _delay_ms(10);
}
void LCD_Write_8String(uint8_t x, uint8_t y, const char *ptr);
