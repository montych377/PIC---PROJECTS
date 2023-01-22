
#define _XTAL_FREQ 1000000
#include <stdio.h>
#include <stdlib.h>
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#include <xc.h>

#define LCD_RS PORTCbits.RC0
#define LCD_RW PORTCbits.RC1

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

int main(){
    TRISD = 0x00;
    TRISC = 0x00;
    
    lcd_init();
    lcd_cmd(0x80);
    lcd_str("Hello World !");
    
    while(1){
        
    }
    return 0;
}

