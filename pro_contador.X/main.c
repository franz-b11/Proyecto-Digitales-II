/*
/////////////////// DATOS DEL PROGRAMA ////////////////////

//  TTITULO: Contador
//  MICRO:PIC16F15244
//  ESTUDIANTES: maicol P. Franz   L
//  Profesor: Harold F MURCIA
//  FECHA: 10 de noviembre de 2020

///////////// CONFIGURACI�N del MCU ////////////////// */

#include <xc.h>

#include <stdint.h>

#include <stdbool.h>

#include <conio.h>

#include <stdlib.h>

#include <stdio.h>

#include "flex_lcd.h"


#pragma config FEXTOSC = OFF // External Oscillator Mode Selection bits->Oscillator not enabled
#pragma config RSTOSC = HFINTOSC_1MHZ // Power-up Default Value for COSC bits->HFINTOSC (1 MHz)
#pragma config CLKOUTEN = OFF // Clock Out Enable bit->CLKOUT function is disabled; I/O function on RA4
#pragma config VDDAR = HI // VDD Range Analog Calibration Selection bit->Internal analog systems are calibrated for operation between VDD = 2.3V - 5.5V

// CONFIG2
#pragma config MCLRE = EXTMCLR // Master Clear Enable bit->If LVP = 0, MCLR pin is MCLR; If LVP = 1, RA3 pin function is MCLR
#pragma config PWRTS = PWRT_OFF // Power-up Timer Selection bits->PWRT is disabled
#pragma config WDTE = OFF // WDT Operating Mode bits->WDT disabled; SEN is ignored
#pragma config BOREN = ON // Brown-out Reset Enable bits->Brown-out Reset Enabled, SBOREN bit is ignored
#pragma config BORV = LO // Brown-out Reset Voltage Selection bit->Brown-out Reset Voltage (VBOR) set to 1.9V
#pragma config PPS1WAY = ON // PPSLOCKED One-Way Set Enable bit->The PPSLOCKED bit can be cleared and set only once in software
#pragma config STVREN = ON // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset

// CONFIG4
#pragma config BBSIZE = BB512 // Boot Block Size Selection bits->512 words boot block size
#pragma config BBEN = OFF // Boot Block Enable bit->Boot Block is disabled
#pragma config SAFEN = OFF // SAF Enable bit->SAF is disabled
#pragma config WRTAPP = OFF // Application Block Write Protection bit->Application Block is not write-protected
#pragma config WRTB = OFF // Boot Block Write Protection bit->Boot Block is not write-protected
#pragma config WRTC = OFF // Configuration Registers Write Protection bit->Configuration Registers are not write-protected
#pragma config WRTSAF = OFF // Storage Area Flash (SAF) Write Protection bit->SAF is not write-protected
#pragma config LVP = ON // Low Voltage Programming Enable bit->Low Voltage programming enabled. MCLR/Vpp pin function is MCLR. MCLRE Configuration bit is ignored.

// CONFIG5
#pragma config CP = OFF // User Program Flash Memory Code Protection bit->User Program Flash Memory code protection is disabled


//  Definiciones  //
#define botonsu PORTAbits.RA2     //remplazo del sensor1   s1
#define botonre PORTCbits.RC3     //remplazo del sensor2  s2
#define bo_aumen_gen_max PORTBbits.RB5 // boton para aumentar gente max
#define bo_dis_gen_max PORTBbits.RB7   // boton para disminuir gente max

#define encender_led_verde LATAbits.LATA3=1;
#define encender_led_naranja LATAbits.LATA0=1;
#define encender_led_rojo LATAbits.LATA4=1;
#define encender_alarma LATAbits.LATA5=1;

#define apagar_led_verde LATAbits.LATA3=0;
#define apagar_led_naranja LATAbits.LATA0=0;
#define apagar_led_rojo LATAbits.LATA4=0;
#define apagar_alarma LATAbits.LATA5=0;
//   Varibles global   //
int mitad=0;
char carac[20];
int contadoperso;
int persomax=0;


//programa principal

void PIN_MANAGER_Initialize(void) 
{
  // LATx registers
  LATA = 0x00;
  LATB = 0x00;
  LATC = 0x00;

  // TRISx registers
  TRISA = 0b00010000;
  TRISB = 0b10100000;
  TRISC = 0b00000100;

  // ANSELx registers
  ANSELC = 0;
  ANSELB = 0;
  ANSELA = 0;

  // WPUx registers/
 
  WPUC = 0x04;

  // ODx registers
  ODCONA = 0x04;
  ODCONB = 0x00;
  ODCONC = 0x00;

  // SLRCONx registers
  SLRCONA = 0x37;
  SLRCONB = 0xFF;
  SLRCONC = 0xFF;

  // INLVLx registers
  INLVLA = 0x3F;
  INLVLB = 0xFF;
  INLVLC = 0xFF;


  //SALIDAS DE LOS LEDS
  TRISA3 =0; //LED VERDE
  TRISA0=0;  //LED NARANJA
  TRISA4=0;  //LED ROJO
  TRISA5=0;  //BUZZER
  //ENTRADAS BOTONES
  TRISA2 =1;    //SUMAR 2
  TRISC3 =1;    //RESTAR 2
  TRISB7 =1;    //AUMENTAR CAPACIDAD
  TRISB5 =1;    //DISMINUIR CAPACIDAD
}

void main(void)
{
    
    PIN_MANAGER_Initialize();
    LATAbits.LATA2=1;
    
  //sumador y restador  
    Lcd_Init();
    Lcd_Cmd(LCD_CURSOR_OFF);
    __delay_ms(1000);
      while(1) 
    {
    if(bo_aumen_gen_max==0){
    __delay_ms(20);
    }
    if(bo_aumen_gen_max==1)
    {
        persomax=persomax+2;    
        
         sprintf(carac, "Personasmax: %d",persomax);//tener encuenta la cantidad de texto
        Lcd_Out2(1,2,carac);
        __delay_ms(500);
        
    }
    if(bo_dis_gen_max==1)
    {
       persomax=persomax-2;
    sprintf(carac, "Personasmax: %d",persomax);  //tener encuenta la cantidad de texto
        Lcd_Out2(1,2,carac);
        __delay_ms(500);

    }   
    if(botonsu==0){  //para los sensores
    __delay_ms(50);
    }
    if(botonsu==1)
    {
        contadoperso++;
         sprintf(carac, "Personasdentro: %d",contadoperso); //primero tiene que sumar
        Lcd_Out2(1,2,carac);
        __delay_ms(500);
        
    }
    if(botonre==1)
    {
        contadoperso--;
    sprintf(carac, "Personasdentro: %d",contadoperso);
        Lcd_Out2(1,2,carac);
        __delay_ms(500);

    }
      }
 
    mitad=0,5*persomax; //el porcentaje de la mitad de personas
    apagar_led_verde;
    apagar_led_naranja;
    apagar_led_rojo;
    
    while (mitad>contadoperso)
    {
      encender_led_verde;
       __delay_ms(1000);
       mitad=0,5*persomax;      //volver a evaluar para salir
    }
    
    while (mitad <=contadoperso <persomax)
    {
       apagar_led_verde;
       encender_led_naranja;
       __delay_ms(1000);
      mitad=0,5*persomax;       //volver a evaluar para salir
    }   
    while (contadoperso=persomax)
    {
      apagar_led_naranja;
      encender_led_rojo;
      __delay_ms(1000);
     mitad=0,5*persomax;        //volver a evaluar para salir
    }
      while (contadoperso>persomax){
          
      encender_alarma;
      __delay_ms(1000);
     mitad=0,5*persomax;        //volver a evaluar para salir
    }
    

}
     
   