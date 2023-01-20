/* 
 * File:   Main_Slv.c
 * Author: bhura
 *
 * Created on January 18, 2023, 3:12 PM
 */
#define F_CPU 8000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <xc.h>
#include <util/delay.h>

void lcd_init();
void lcd_data(char data);
void lcd_cmd(char cmd);
void lcd_str(const char *ptr);

void I2C_Initialize(unsigned char Slv_address);
char I2C_ReadData();
void ACk_Match();

int main(int argc, char** argv) {
    DDRB = 0xff;
    DDRC = 0x07;
    DDRD = 0xff;
    lcd_init();
    lcd_cmd(0x80);
    lcd_str("I2C Slave Init");
    while(1){
    }
    return (EXIT_SUCCESS);
}
void I2C_Initialize(unsigned char Slv_address){
    TWAR = Slv_address;
}

char I2C_ReadData(){
    TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
    while((TWCR & (1<<TWINT))==0);
    while((TWSR & (0xF8)) != 0x80);
    return TWDR;
}

void ACk_Match(){
    while((TWSR & (0xf8)) != 0x60){
        TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
        while((TWCR & (1<<TWINT)) == 0);
    }
}


void lcd_init(){
    lcd_cmd(0x01);
    lcd_cmd(0x02);
    lcd_cmd(0x06);
    lcd_cmd(0x38);
    lcd_cmd(0x0c);
}
void lcd_data(char data){
    PORTD = data;
    PORTC &= ~(1<<PC0);
    PORTC &= ~(1<<PC1);
    PORTC |=  (1<<PC2);
    _delay_ms(10);
    PORTC &= ~(1<<PC2);
    _delay_ms(10);
    
}
void lcd_cmd(char cmd){
    PORTD = cmd;
    PORTC |= (1<<PC0);
    PORTC &= ~(1<<PC1);
    PORTC |=  (1<<PC2);
    _delay_ms(10);
    PORTC &= ~(1<<PC2);
    _delay_ms(10);
}
void lcd_str(const char *ptr){
    while(*ptr){
        lcd_data(*ptr++);
    }
}