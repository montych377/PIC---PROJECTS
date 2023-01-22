/* 
 * File:   Main_ADC.c
 * Author: bhura
 *
 * Created on January 19, 2023, 3:42 PM
 */
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
#include "lcd.h"

void ADC_Initialize(){
    ADCON0 = 0x81;
    ADCON1 = 0x8e;
}
int ADC_Read(){
    ADCON0 |= 0x04;
    while(GO_nDONE);
    return ((ADRESH<<8) + ADRESL);
}
int main(int argc, char** argv) {
    TRISD = 0x00;
    TRISC = 0x00;
    char arr[15];
    ADC_Initialize();
    lcd_init();
    while(1){
        int data = ADC_Read();
        lcd_cmd(0x80);
        lcd_str("Convert Vol->temp");
        int temp = (data*500)/1023;
        sprintf(arr,"Temperature = %d",temp);
        lcd_cmd(0xc0);
        lcd_str(arr);
        __delay_ms(10);
    }
    return (EXIT_SUCCESS);
}

