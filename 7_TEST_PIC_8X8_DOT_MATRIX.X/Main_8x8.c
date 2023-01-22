/* 
 * File:   Main_8x8.c
 * Author: bhura
 *
 * Created on January 19, 2023, 2:18 PM
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

int main(){
    TRISD = 0x00;
    TRISC = 0x00;
    int arr[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    int Mrr[] = {0x11,0x1b,0x15,0x11,0x11,0x11,0x11,0x00};
    int Orr[] = {0x06,0x09,0x09,0x09,0x09,0x09,0x06,0x00};
    int Nrr[] = {0x11,0x13,0x13,0x15,0x15,0x19,0x11,0x00};
    int Trr[] = {0x1f,0x04,0x04,0x04,0x04,0x04,0x04,0x00};
    int Yrr[] = {0x11,0x0a,0x04,0x04,0x04,0x04,0x04,0x00};
    while(1){
        for(int k=0;k<8;k++){
            for(int j=0;j<10;j++){
                for(int i=0;i<8;i++){
                   PORTD = ~arr[i];
                   PORTC = (Mrr[i] << (k));
                   __delay_ms(1);

                }
            }
        }
        
        for(int k=0;k<8;k++){
            for(int j=0;j<10;j++){
                for(int i=0;i<8;i++){
                   PORTD = ~arr[i];
                   PORTC = (Orr[i] << (k));
                   __delay_ms(1);

                }
            }
        }
        
        for(int k=0;k<8;k++){
            for(int j=0;j<10;j++){
                for(int i=0;i<8;i++){
                   PORTD = ~arr[i];
                   PORTC = (Nrr[i] << (k));
                   __delay_ms(1);

                }
            }
        }
        
        for(int k=0;k<8;k++){
            for(int j=0;j<10;j++){
                for(int i=0;i<8;i++){
                   PORTD = ~arr[i];
                   PORTC = (Trr[i] << (k));
                   __delay_ms(1);

                }
            }
        }
        
        for(int k=0;k<8;k++){
            for(int j=0;j<10;j++){
                for(int i=0;i<8;i++){
                   PORTD = ~arr[i];
                   PORTC = (Yrr[i] << (k));
                   __delay_ms(1);

                }
            }
        }

    }
}

