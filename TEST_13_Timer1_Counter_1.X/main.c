#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_str(const char *ptr);



void Timer_Counter(){
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B |= (1<<CS01)|(1<<CS00)|(1<<CS02);
    
}
int main(int argc, char** argv) {
    DDRB = 0xff;
    DDRC = 0x07;
    DDRD = 0x00;
    uint8_t data;
    char arr[10];
    lcd_init();
    Timer_Counter();
    while(1){
        data = TCNT1;
        sprintf(arr,"Counter = %d",data);
        lcd_cmd(0x80);
        lcd_str(arr);
        _delay_ms(100);
        
    }
    return (EXIT_SUCCESS);
}

void lcd_init(){
    lcd_cmd(0x01);
    lcd_cmd(0x38);
    lcd_cmd(0x0c);
    lcd_cmd(0x02);
    lcd_cmd(0x06);
}
void lcd_cmd(unsigned char cmd){
    PORTB = cmd;
    PORTC &= ~0x01;
    PORTC &= ~0x02;
    PORTC |=  0x04;
    _delay_ms(3);
    PORTC &= ~0x04;
    _delay_ms(3);
}
void lcd_data(unsigned char data){
    PORTB = data;
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



