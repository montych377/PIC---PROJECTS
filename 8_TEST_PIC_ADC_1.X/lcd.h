/* 
 * File:   lcd.h
 * Author: bhura
 *
 * Created on January 19, 2023, 3:52 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif
#define _XTAL_FREQ 1000000
#include <xc.h>
    
void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_str(char *ptr);


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

