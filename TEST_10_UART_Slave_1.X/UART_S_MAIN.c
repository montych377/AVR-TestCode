/* 
 * File:   UART_S_MAIN.c
 * Author: bhura
 *
 * Created on January 17, 2023, 3:34 PM
 */
#define F_CPU 8000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

#define BAUD_RATE 9600

void UART_Initialize(long baud);
void UART_TX(unsigned char data);
unsigned char UART_RX();
void UART_TXstring(const char *ptr);


int main(int argc, char** argv) {
    DDRB = 0xff;
    UART_Initialize(BAUD_RATE);
    while(1){
        UART_TX('a');
        _delay_ms(2000);
        UART_TX('s');
        _delay_ms(2000);
        UART_TX('f');
        _delay_ms(2000);
        UART_TX('b');
        _delay_ms(2000);
        UART_TX('z');
        _delay_ms(2000);
        UART_TX('x');
        _delay_ms(2000);
    }
    return (EXIT_SUCCESS);
}

void UART_Initialize(long baud){
    int ubrr_value = (((F_CPU)/(8*baud))-1);
    UBRRL = ubrr_value;
    UBRRH = ubrr_value>>8;
    UCSRA = (1<<U2X);
    UCSRB = (1<<TXEN)|(1<<RXEN);
    UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}
void UART_TX(unsigned char data){
    UDR = data;
    while((UCSRA & (1<<TXC))==0);
}
unsigned char UART_RX(){
    while((UCSRA & (1<<RXC))==0);
    return UDR;
}
void UART_TXstring(const char *ptr){
    while(*ptr){
        UART_TX(*ptr++);
    }
}
