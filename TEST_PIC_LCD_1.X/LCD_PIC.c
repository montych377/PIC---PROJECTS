#include "LCD_PIC.h"

void delay(int cnt)
{
    int i;
    for(i=0;i<cnt;i++);
}
void Lcd_CmdWrite(char cmd)
{
    LcdDataBus = cmd;             
    LcdControlBus &= ~(1<<LCD_RS);  
    LcdControlBus &= ~(1<<LCD_RW); 
    LcdControlBus |= (1<<LCD_EN);   
    delay(100);
    LcdControlBus &= ~(1<<LCD_EN); 

    delay(100);
}

void Lcd_DataWrite(char dat)
{
    LcdDataBus = dat;            
    LcdControlBus |= (1<<LCD_RS);  
    LcdControlBus &= ~(1<<LCD_RW); 
    LcdControlBus |= (1<<LCD_EN);   
    delay(100);
    LcdControlBus &= ~(1<<LCD_EN);

    delay(100);
}

void lcd_str(const char *ptr){
    while(*ptr){
        Lcd_DataWrite(*ptr++);
    }
}

void lcd_init(){
    Lcd_CmdWrite(0x38);       
    Lcd_CmdWrite(0x0c);   
    Lcd_CmdWrite(0x01);   
    Lcd_CmdWrite(0x80); 
}
