#include "LCD.h"


void lcd_init(){
    lcd_cmd(0x01);
    lcd_cmd(0x38);
    lcd_cmd(0x0c);
    lcd_cmd(0x02);
    lcd_cmd(0x06);
}
void lcd_cmd(unsigned char cmd){
    PORTD = cmd;
    PORTC &= ~0x01;
    PORTC &= ~0x02;
    PORTC |=  0x04;
    _delay_ms(3);
    PORTC &= ~0x04;
    _delay_ms(3);
}
void lcd_data(unsigned char data){
    PORTD = data;
    PORTC |=  0x01;
    PORTC &= ~0x02;
    PORTC |=  0x04;
    _delay_ms(3);
    PORTC &= ~0x04;
    _delay_ms(3);
}
void lcd_str(const char *ptr){
    while(*ptr){
        lcd_data(*ptr++);
    }
}

