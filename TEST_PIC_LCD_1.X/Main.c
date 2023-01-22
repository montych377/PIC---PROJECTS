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
#include "LCD_PIC.h"

void adc_init() {
    ADCON0 = 0b00000001; // Select AN0 as the input channel
    ADCON1 = 0b00001110; // Configure the reference voltage
    ADCON2 = 0b10101011; // Set the acquisition time and conversion clock
}

unsigned int read_adc() {
    ADCON0bits.GO = 1; // Start the conversion
    while(ADCON0bits.GO); // Wait for the conversion to complete
    return ((ADRESH << 8) + ADRESL); // Combine the high and low byte
}

void main() {
    adc_init();
    TRISA = 0x00;
    while(1) {
        unsigned int adc_value = read_adc();
        // Do something with the ADC value
        PORTA = adc_value;
    }
}


//int main()
//{
//    LcdDataBusDirnReg = 0x00; 
//    LcdCtrlBusDirnReg = 0x00; 
//    lcd_init();
//    while(1){
//        Lcd_CmdWrite(0x80);
//        lcd_str("Hello World");
//        
//    }
//}