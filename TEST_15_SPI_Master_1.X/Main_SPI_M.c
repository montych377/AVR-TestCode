#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


#define SS   PB0
#define MOSI PB3
#define MISO PB4
#define SCK  PB5

void SPI_Initialize();
void SPI_WriteData(unsigned char data);
unsigned char SPI_ReadData();
int main(){
    DDRD = 0xff;
    SPI_Initialize();
    while(1){
        SPI_WriteData('B');
        PORTD = SPI_ReadData();
    }
}

void SPI_Initialize(){
    DDRB = (1<<MOSI)|(1<<SS)|(1<<SCK);
    SPCR = (1<<SPE)|(1<<SPR0)|(1<<MSTR);
}
void SPI_WriteData(unsigned char data){
    SPDR = data;
    while((SPSR & (1<<SPIF)) ==0);
}
unsigned char SPI_ReadData(){
    while((SPSR & (1<<SPIF))==0);
    return SPDR;
}