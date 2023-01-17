/* 
 * File:   LCD.h
 * Author: bhura
 *
 * Created on January 17, 2023, 12:32 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif
#define F_CPU 1000000UL
#include <xc.h>
#include <util/delay.h>
    
#define LCD_RS PC3
#define LCD_RW PC4
#define LCD_EN PC5
    
void LCD_Init();
void LCD_Wdata(unsigned char data);
void LCD_Wcmd(unsigned char cmd);
void LCD_Wstring(char *ptr);
#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

