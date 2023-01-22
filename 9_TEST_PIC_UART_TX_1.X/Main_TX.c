/* 
 * File:   Main_TX.c
 * Author: bhura
 *
 * Created on January 19, 2023, 4:07 PM
 */
#define _XTAL_FREQ 16000000
#include <stdio.h>
#include <stdlib.h>
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF   

#include <xc.h>
#define BUADRATE 9600
void UART_Initialize(long Baud);
void UART_WriteData(unsigned char data);
void UART_WriteString(char *ptr);
unsigned char UART_ReadData();

int main(int argc, char** argv) {
    UART_Initialize(BUADRATE);
    UART_WriteString("Hello Sofcon !\r");
    while(1){
        UART_WriteData('a');
        __delay_ms(100);
        UART_WriteData('b');
        __delay_ms(100);
    }
    return (EXIT_SUCCESS);
}

void UART_Initialize(long Baud){
    unsigned long baud_value = (((_XTAL_FREQ) /(64*Baud))-1);
    SPBRG = baud_value;
    TXSTA = 0x24;
    RCSTA = 0x90;
}
void UART_WriteData(unsigned char data){
    while(!TXIF);
    TXREG = data;
}
unsigned char UART_ReadData(){
    if(OERR)
    {
        CREN = 0;
        CREN = 1;
    }
    while(!RCIF);
    return RCREG;
}
void UART_WriteString(char *ptr){
    while(*ptr){
        UART_WriteData(*ptr++);
    }
}

