/* 
 * File:   LCD_LM.h
 * Author: bhura
 *
 * Created on January 17, 2023, 12:49 PM
 */

#ifndef LCD_LM_H
#define	LCD_LM_H

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
void LCD_Wstring(const char *ptr);



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_LM_H */

