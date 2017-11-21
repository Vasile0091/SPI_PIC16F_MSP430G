/*
 * File:   main.c
 * Author: vasile
 *
 * Created on 16 noiembrie 2017, 10:54
 */

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 8000000 // needed for use the delay functions

//Defines needed by SPI
#define SSPEN               (1U << 5)   //Turn on SPI mode
#define CKP                 (1U << 4)   //Clock idle on high level
#define SSPM                0x03        //Fosc/64  

#define TRISC_SDO_MASK           _TRISC_TRISC2_MASK
#define TRISC_SDI_MASK           _TRISC_TRISC1_MASK
#define TRISC_SS_MASK            _TRISC_TRISC3_MASK
#define TRISC_SCLK_MASK          _TRISC_TRISC0_MASK

#define SMP     (1u << 7)   // 1 = Input data sampled at end of data output time
#define CKE     (1u << 6)   //1 = Transmit occurs on transition from active to Idle clock state

void init_SPI_MasterMode();
void write_SPI_MasterMode();
void read_SPI_MasterMode();

void main(void) 
{   
    init_SPI_MasterMode();
    
    while(1)
    {        
        
        
    }
}

void init_SPI_MasterMode()
{
    //Program the SSPCON1<5:0> and SSPSTAT<7:6>
    /*
     Before enabling SPI by setting SSPEN, the other pin SCK, SDI, SDO and SS
     must have the coresponding TRIS set properly*/
    
    /* Steps
     * 1. Set SCK, SDI, SDO and SS pinout with the corresponding TRIS (output or input pins)
     * 2. Configure SSPSTAT register
     * 3. Configure SSPCON1 register
     */
    TRISC |= TRISC_SDI_MASK;
    TRISC &= (~(TRISC_SDO_MASK | TRISC_SCLK_MASK | TRISC_SS_MASK));
    
    SSPSTAT |= SMP;
    SSPSTAT &= CKE;
    
    SSPCON1 |= SSPEN | CKP | SSPM;
}

void write_SPI_MasterMode()
{
    //Write data to SSPBUF register 
}

void read_SPI_MasterMode()
{
   
}

