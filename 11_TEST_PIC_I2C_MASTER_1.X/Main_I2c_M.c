/* 
 * File:   Main_I2c_M.c
 * Author: bhura
 *
 * Created on January 19, 2023, 5:25 PM
 */
#define _XTAL_FREQ 8000000
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
#define for ON and OFF.

#include <xc.h>


void I2C_Initialize(unsigned char c);
void I2C_Start(void);
void I2C_WriteData(unsigned char data);
unsigned char I2C_ReadData(unsigned short ack);
void I2C_Stop(void);

int main(int argc, char** argv) {
    I2C_Initialize(100);
    while(1){
        I2C_Start();
        I2C_WriteData(0xD0);
        I2C_WriteData(0x88);
        I2C_WriteData(0xFF);
        I2C_Stop();
        __delay_ms(1000);
    }
    return (EXIT_SUCCESS);
}

void I2C_Initialize(unsigned char c){
    SSPCON = 0x28;
    SSPCON2 = 0x00;
    SSPADD = (((_XTAL_FREQ)/(4*c*100))-1);
    SSPSTAT = 0;
}
void I2C_MasterWait(void){
    while((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Start(void){
    I2C_MasterWait();
    SEN = 1;
}
void I2C_WriteData(unsigned char data){
    I2C_MasterWait();
    SSPBUF = data;
}
unsigned char I2C_ReadData(unsigned short ack){
    unsigned char rec;
    I2C_MasterWait();
    RCEN = 1;
    I2C_MasterWait();
    rec = SSPBUF;
    I2C_MasterWait();
    ACKDT = (ack)?0:1;
    ACKEN = 1;
    return rec;
}
void I2C_Stop(void){
    I2C_MasterWait();
    PEN = 1;
}

