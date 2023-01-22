/* 
 * File:   LCD_PIC.h
 * Author: bhura
 *
 * Created on January 14, 2023, 10:49 AM
 */

#ifndef LCD_PIC_H
#define	LCD_PIC_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>
#define LcdDataBus      PORTB
#define LcdControlBus   PORTD

#define LcdDataBusDirnReg   TRISB
#define LcdCtrlBusDirnReg   TRISD

#define LCD_RS     0
#define LCD_RW     1
#define LCD_EN     2

void delay(int cnt);
void Lcd_CmdWrite(char cmd);
void Lcd_DataWrite(char data);
void lcd_init();
void lcd_str(const char *ptr);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_PIC_H */

