/* 
 * File:   Main_SPI_Slv_2.c
 * Author: bhura
 *
 * Created on January 18, 2023, 10:37 PM
 */


#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

#define SS    PB1
#define MOSI  PB3
#define MISO  PB4
#define SCK   PB5

void SPI_Initialize();
void SPI_WriteData(unsigned char data);
unsigned char SPI_ReadData();

int main( void ) {
    DDRD = 0xff;
    SPI_Initialize();
    while(1){
        SPI_WriteData('C'); 
        PORTD = SPI_ReadData();
    }
    return 0;
}

void SPI_Initialize(){
    DDRB = (1<<MISO);
    SPCR = (1<<SPE);
}

void SPI_WriteData(unsigned char data){
    SPDR = data;
    while((SPSR & (1<<SPIF))==0);
}

unsigned char SPI_ReadData(){
    while((SPSR & (1<<SPIF))==0);
    return SPDR;
}

