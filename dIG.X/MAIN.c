/*
 *DATOS DEL PROGRAMA
 *TITULO:
 * MICRO: PIC15F15244
 * ESTUDIANTES:
 *      MAICOL STIVEN PRADA AGUIAR 24201910141
 *      FRANZ LOPEZ ARREDONDO 2420191051 
 * DOCENTE: HAROLD F MURCIA
 * 
 */

//CONFIGURACIONES DEL MCU//
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "flex_lcd.h"

#pragma config FEXTOSC = OFF    // External Oscillator Mode Selection bits->Oscillator not enabled
#pragma config RSTOSC = HFINTOSC_1MHZ    // Power-up Default Value for COSC bits->HFINTOSC (1 MHz)
#pragma config CLKOUTEN = OFF    // Clock Out Enable bit->CLKOUT function is disabled; I/O function on RA4
#pragma config VDDAR = HI    // VDD Range Analog Calibration Selection bit->Internal analog systems are calibrated for operation between VDD = 2.3V - 5.5V

// CONFIG2
#pragma config MCLRE = EXTMCLR    // Master Clear Enable bit->If LVP = 0, MCLR pin is MCLR; If LVP = 1, RA3 pin function is MCLR
#pragma config PWRTS = PWRT_OFF    // Power-up Timer Selection bits->PWRT is disabled
#pragma config WDTE = OFF    // WDT Operating Mode bits->WDT disabled; SEN is ignored
#pragma config BOREN = ON    // Brown-out Reset Enable bits->Brown-out Reset Enabled, SBOREN bit is ignored
#pragma config BORV = LO    // Brown-out Reset Voltage Selection bit->Brown-out Reset Voltage (VBOR) set to 1.9V
#pragma config PPS1WAY = ON    // PPSLOCKED One-Way Set Enable bit->The PPSLOCKED bit can be cleared and set only once in software
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset

// CONFIG4
#pragma config BBSIZE = BB512    // Boot Block Size Selection bits->512 words boot block size
#pragma config BBEN = OFF    // Boot Block Enable bit->Boot Block is disabled
#pragma config SAFEN = OFF    // SAF Enable bit->SAF is disabled
#pragma config WRTAPP = OFF    // Application Block Write Protection bit->Application Block is not write-protected
#pragma config WRTB = OFF    // Boot Block Write Protection bit->Boot Block is not write-protected
#pragma config WRTC = OFF    // Configuration Registers Write Protection bit->Configuration Registers are not write-protected
#pragma config WRTSAF = OFF    // Storage Area Flash (SAF) Write Protection bit->SAF is not write-protected
#pragma config LVP = ON    // Low Voltage Programming Enable bit->Low Voltage programming enabled. MCLR/Vpp pin function is MCLR. MCLRE Configuration bit is ignored.
// CONFIG5
#pragma config CP = OFF    // User Program Flash Memory Code Protection bit->User Program Flash Memory code protection is disabled


/////  DEFINICIONES  /////
#define _XTAL_FREQ_1000000 
#define ACQ_US_DELAY 10 
//      LEDS        //
//LED DE POCO AFORO
#define on_l_verde()     LATBbits.LATB5 =1;
#define off_l_verde()    LATBbits.LATB5 =0;
//LED DE MEDIO AFORO
#define on_l_naranja()  LATAbits.LATA2=1;
#define off_l_naranja() LATAbits.LATA2=0;
//LED DE AFORO COMPLETO
#define on_l_rojo()     LATAbits.LATA1=1;
#define off_l_rojo()    LATAbits.LATA1=0;
//BUZZER
#define on_buz()        LATBbits.LATB7=1;
#define off_buz()       LATBbits.LATB7=0;
//caso impo

/////       VARIABLES GLOBALES      /////
char tex[20];
unsigned int per_max=0;
unsigned int cantidad=0;
int mitad=0;
/////       INICIALIZACION DE PINES     /////
void PIN_MANAGER_Initialize(void) {
 // LATx registers
  LATA = 0x00;
  LATB = 0x00;
  LATC = 0x00;

  // TRISx registers    
  TRISA = 0b00000000;
  TRISB = 0b00000000;           
  TRISC = 0b00001111;         // 4 entradas:  Botones de aumentar el aforo y B

  // ANSELx registers
  ANSELC = 0;
  //ANSELB = 0;
  ANSELA = 0;

  // WPUx registers/

  // ODx registers
  ODCONA = 0x04;
  //ODCONB = 0x00;
  ODCONC = 0x00;

  // SLRCONx registers
  SLRCONA = 0x37;
  //SLRCONB = 0xFF;
  SLRCONC = 0xFF;

  // INLVLx registers
  INLVLA = 0x3F;
  //INLVLB = 0xFF;
  INLVLC = 0xFF;
  
}   
void OSCILLATOR_Initialize(void)
{
    OSCEN=0x00;
    OSCFRQ=0x00;
    OSCTUNE=0x00;
}
void ValorDeGenMax (void){
    Lcd_Cmd(LCD_CLEAR);
    sprintf(tex,"defina la");
    Lcd_Out2(1,0,tex);
    sprintf(tex,"cantidad maxima");
    Lcd_Out2(2,0,tex);
    __delay_ms(5000);
}
void mostrargenmax (void){
    Lcd_Cmd(LCD_CLEAR);
    sprintf(tex,"capacidad: %d",per_max);
    Lcd_Out2(2,0,tex);
    __delay_ms(500);
}
void mostrarcantidad (void){
    Lcd_Cmd(LCD_CLEAR);
    sprintf(tex,"Actual: %d",cantidad);
    Lcd_Out2(1,0,tex);
    __delay_ms(500);   
}

void apagarsalidas (void){
    off_l_verde();
    off_l_naranja();
    off_l_rojo();
    off_buz();
    
}
void main(void){
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    Lcd_Init();
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
    apagarsalidas();
    ValorDeGenMax();       //mostrar mensaje para leer la cantidad max
    Lcd_Cmd(LCD_CLEAR);
    
    while(1){
        per_max=per_max;          
        
        if(PORTCbits.RC0 == 0){
           per_max=per_max+2;     //aumentar la cantidad maxima
           __delay_ms(500);
           mostrargenmax();
             apagarsalidas();
 
        }
        else if(PORTCbits.RC1 == 0){
            per_max=per_max-2;      //disminuir la cantidad maxima
            __delay_ms(500);
            mostrargenmax();
              apagarsalidas();
            
        }    
            else if(PORTCbits.RC3 == 0){
           cantidad=cantidad+1;     //sensor 1 lee que entro alguien
           __delay_ms(500);
           mostrarcantidad();
             apagarsalidas();
        }
        else if(PORTCbits.RC2 == 0){
            cantidad=cantidad-1;    //senson 2 lee que salio alguien
            __delay_ms(500);
            mostrarcantidad(); 
              apagarsalidas();
        }     

        mitad=0.5*per_max;
        if(cantidad < mitad){
            apagarsalidas();
            on_l_verde();
           __delay_ms(500);
           
        }
        else if (cantidad<per_max){
            apagarsalidas();
            on_l_naranja();
            __delay_ms(500);
            
        }
        else if (cantidad>per_max)  
        {
              apagarsalidas();
            on_l_rojo();
            on_buz();
            __delay_ms(500);
            
        } 
        else if(per_max==cantidad)
        {
              apagarsalidas();
            on_l_rojo();
            __delay_ms(500);   
        }
        
        }
    }
   
