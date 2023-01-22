/* 
 * File:   MAIN_LCD.c
 * Author: bhura
 *
 * Created on January 19, 2023, 12:59 PM
 */
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

void lcd_cmd(unsigned char cmd){
    PORTB = cmd;
    PORTC &= ~0x01;
    PORTC &= ~0x02;
    PORTC |= 0x04;
    __delay_ms(3);
    PORTC &= ~0x04;
    __delay_ms(3);
}

void lcd_data(unsigned char data){
    PORTB = data;
    PORTC |=  0x01;
    PORTC &= ~0x02;
    PORTC |= 0x04;
    __delay_ms(3);
    PORTC &= ~0x04;
    __delay_ms(3);
}
void lcd_init(){
    lcd_cmd(0x02);
    lcd_cmd(0x38);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
    lcd_cmd(0x0c);
}
void lcd_string(char *ptr){
    while(*ptr!='\0'){
        lcd_data(*ptr++);
    }
}
int main() {
    TRISB = 0X00;
    TRISC = 0X00;
    lcd_init();
    
    while(1){
    lcd_cmd(0x80);
    lcd_string("HELLO WORLD !");
    __delay_ms(100);
    }
    return (EXIT_SUCCESS);
}

