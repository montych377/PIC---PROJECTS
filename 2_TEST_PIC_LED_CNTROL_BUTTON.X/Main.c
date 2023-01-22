/* 
 * File:   Main.c
 * Author: bhura
 *
 * Created on January 18, 2023, 10:59 PM
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
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>

int main(int argc, char** argv) {
    TRISB = 0x00;
    TRISD = 0xff;
    int i = 0, arr[] = {0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    while(1){
        if((PORTD & 1) == 1){
            i++;
            while((PORTD & 1) == 1);
        }
        if(i>8){
            i=0;
        }
        PORTB = arr[i];
    }
    return (EXIT_SUCCESS);
}

