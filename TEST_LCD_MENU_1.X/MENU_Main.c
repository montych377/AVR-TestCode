/*
 * File:   MENU_Main.c
 * Author: bhura
 *
 * Created on January 13, 2023, 11:20 AM
 */


#include <xc.h>
#include "LCD.h"

int  main(void) {
    LCD_DATA_PORT_DIR = 0XFF;
    DDRC = 0XFF;
    LCD_Initialize(MODE_4BIT);
    
    while(1){
        LCD_Write_4Cmd(0x80);
        LCD_Write_4Data('A');
        _delay_ms(1000); 
    }
    return 0;
}
