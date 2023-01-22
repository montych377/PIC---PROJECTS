/* 
 * File:   Main_T2.c
 * Author: bhura
 *
 * Created on January 15, 2023, 10:33 AM
 */

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

#define _XTAL_FREQ 8000000
#include <xc.h>

/*
 * Fosc = 8Mhz,  P = 16; req delay = 1ms
 * 
 * count = 256 - ((req delay * Fosc)/(P*4))
 * count = 256 - 126 = 130
 */
void delay_ms(unsigned int time) {
    PR2 = 130; 
    T2CONbits.T2CKPS0 = 1; 
    T2CONbits.T2CKPS1 = 1; 
    T2CONbits.TMR2ON = 1; 
    while (time > 0) {
        TMR2 = 0; 
        T2CONbits.TMR2ON = 1; 
        while (!PIR1bits.TMR2IF); 
        PIR1bits.TMR2IF = 0; 
        T2CONbits.TMR2ON = 0; 
        time--;
    }
}

void main(void) {
    TRISA = 0x00; // Set PORTB as output
    PORTA = 0x00; // Clear PORTB
    while(1) {
        PORTA = 0xFF; // Turn on all LEDs
        delay_ms(100); // Delay for 1 second
        PORTA = 0x00; // Turn off all LEDs
        delay_ms(100); // Delay for 1 second
    }
}

