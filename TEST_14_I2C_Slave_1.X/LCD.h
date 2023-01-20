/* 
 * File:   LCD.h
 * Author: bhura
 *
 * Created on January 18, 2023, 3:41 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#define F_CPU 1000000UL
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <util/delay.h>

void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_str(const char *ptr);


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

