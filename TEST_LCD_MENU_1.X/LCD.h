/* 
 * File:   LCD.h
 * Author: bhura
 *
 * Created on January 13, 2023, 11:21 AM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif
#define F_CPU 1000000UL
#include <xc.h>
#include <util/delay.h>
    
#define LCD_DATA_PORT PORTD
#define LCD_DATA_PORT_DIR DDRD
    
#define LCD_RS PC0    
#define LCD_EN PC1   
    
#define MODE_4BIT 0    
#define MODE_8BIT 1    
    
void LCD_Initialize(uint8_t mode);
void LCD_Write_4Data(unsigned char data);
void LCD_Write_4Cmd(unsigned char cmd);
void LCD_Write_4String(uint8_t x, uint8_t y, const char *ptr);
void LCD_Write_8Data(unsigned char data);
void LCD_Write_8Cmd(unsigned char cmd);
void LCD_Write_8String(uint8_t x, uint8_t y, const char *ptr);



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

