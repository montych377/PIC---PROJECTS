#include "lcd.h"


void lcd_cmd(unsigned char cmd){
    PORTD = cmd & 0xf0;
    PORTC &= ~0x01;
    PORTC &= ~0x02;
    PORTC |=  0x04;
    __delay_ms(3);
    PORTC &= ~0x04;
    
    PORTD = (cmd<<4) & 0xf0;
    PORTC &= ~0x01;
    PORTC &= ~0x02;
    PORTC |=  0x04;
    __delay_ms(3);
    PORTC &= ~0x04;
}

void lcd_data(unsigned char data){
    PORTD = data & 0xf0;
    PORTC |=  0x01;
    PORTC &= ~0x02;
    PORTC |=  0x04;
    __delay_ms(3);
    PORTC &= ~0x04;
    
    PORTD = (data<<4) & 0xf0;
    PORTC |=  0x01;
    PORTC &= ~0x02;
    PORTC |=  0x04;
    __delay_ms(3);
    PORTC &= ~0x04;
}
void lcd_str(char *ptr){
   while(*ptr){
        lcd_data(*ptr++);
    } 
}
void lcd_init(){
    
    lcd_cmd(0x01);
    lcd_cmd(0x02);
    lcd_cmd(0x06);
    lcd_cmd(0x28);
    lcd_cmd(0x0c);
}

