/* 
 * File:   Main_I2c.c
 * Author: bhura
 *
 * Created on January 18, 2023, 1:24 PM
 */
#define F_CPU 8000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

void I2C_Initialize();
void I2C_Start();
void I2C_Stop();
void I2C_WriteData(unsigned char data);
void I2C_WriteAddress(unsigned char address);

int main(int argc, char** argv) {
    
    I2C_Initialize();
    
    while(1){
        I2C_Start();
        I2C_WriteAddress(0x20);
        I2C_WriteData('A');
        I2C_Stop();
        _delay_ms(1000);
        I2C_Start();
        I2C_WriteAddress(0x20);
        I2C_WriteData('B');
        I2C_Stop();
        _delay_ms(1000);
    }
}

void I2C_Initialize(){
    TWBR = 0x00;
    TWBR = 0x0c;
}
void I2C_Start(){
    TWCR = (1<<TWSTA)|(1<<TWINT)|(1<<TWEN);
    while((TWCR & (1<<TWINT))==0);
    while((TWSR & (0XF8)) != 0X08);
}
void I2C_Stop(){
    TWCR = (1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
    
}
void I2C_WriteAddress(unsigned char address){
    TWDR = address;
    TWCR = (1<<TWEN)|(1<<TWINT);
    while((TWSR & (0XF8)) != 0X18);
}
void I2C_WriteData(unsigned char data){
    TWDR = data;
    TWCR = (1<<TWEN)|(1<<TWINT);
    while((TWSR & (0XF8)) != 0X28);
}




