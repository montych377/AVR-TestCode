/* 
 * File:   UART_Main.c
 * Author: bhura
 *
 * Created on January 17, 2023, 1:54 PM
 */
#define F_CPU 8000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

#define BAUD_RATE 9600

void UART_Initialize(long baud);
void UART_TX(unsigned char data);
void UART_TXstring(const char *ptr);
unsigned char UART_RX();

int main(int argc, char** argv) {
    
    DDRC = 0XFF;
    UART_Initialize(BAUD_RATE);
    UART_TXstring("Bluetooth Control Robot\r");
    while(1){
        char data = UART_RX();
        
        UART_TXstring("\r");
        if(data == 'f'){
            PORTC = 0x04;
            UART_TXstring("FIRST_Robot Forward\r");
        }
        if(data == 'b')
        {
            PORTC = 0x08;
            UART_TXstring("FIRST_Robot Backward\r");
            
        }
        if(data == 'a'){
            PORTC = 0x10;
            UART_TXstring("SECOUND_Robot Forward\r");
        }
        if(data == 's')
        {
            PORTC = 0x20;
            UART_TXstring("SECOUND_Robot Backward\r");
            
        }
        if(data == 'z')
        {
            PORTC = 0x14;
            UART_TXstring("BOTH_Robot Forward\r");
            
        }
        if(data == 'x')
        {
            PORTC = 0x28;
            UART_TXstring("BOTH_Robot Backward\r");
            
        }
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
    while((UCSRA & (1<<UDRE))==0);
   
    
}
void UART_TXstring(const char *ptr){
    while(*ptr){
        UART_TX(*ptr++);
    }
}
unsigned char UART_RX(){
    while((UCSRA & (1<<RXC)) == 0);
    return UDR;
}

