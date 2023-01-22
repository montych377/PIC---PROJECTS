/* 
 * File:   Main.c
 * Author: bhura
 *
 * Created on January 19, 2023, 6:29 AM
 */
#define _XTAL_FREQ 1000000
#include <stdio.h>
#include <stdlib.h>
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF  
#include <xc.h>

int main(int argc, char** argv) {
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0xff;
    int i=0,j=0,arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};;
    while(1){
        if((PORTD & 1) == 1){
            j++;
            while((PORTD & 1) == 1);
        }
        if(j>9){
            i++;
            j=0;
        }
        if(i>9){
            j++;
            i=0;
        }
        PORTC = 0x02;
        PORTB = arr[i];
        __delay_ms(50);
        PORTC = 0x01;
        PORTB = arr[j];
        __delay_ms(50);
        
    }
    return (EXIT_SUCCESS);
}

