/*
 * main.c
 * LCDRGB main program
 * 
 * Main module to demonstrate input from UART and output to TWR-LCD-RGB
 *
 * ARM-based K70F120M microcontroller board
 *   for educational purposes only
 * CSCI E-92 Spring 2014, Professor James L. Frankel, Harvard Extension School
 *
 * Written by James L. Frankel (frankel@seas.harvard.edu)
 */

/*
 * In addition to this file (main.c), this project requires the following files:
 *   lcdc.c
 *   lcdc.h
 *   lcdcConsole.c
 *   lcdcConsole.h
 *   mcg.c
 *   mcg.h
 *   profont.c
 *   profont.h
 *   sdram.c
 *   sdram.h
 *   uart.c
 *   uart.h
 */
#include "mcg.h"
#include "sdram.h"
#include "io.h"
#include "lcdcConsole.h"
#include "svc.h"
#include <stdio.h>
#include "common.h"
#include "delay.h"
#include "led.h"
#include "pushbutton.h"
#define CHAR_EOF 4

void consoleDemo();
extern unsigned mystdout; 
extern unsigned mystdin; 

int verify_led(void) {
    char print_string[1000]; 
    const unsigned long int delayCount = 0x7ffff;
    sprintf(print_string, "Starting SVCall project\n");
    write_string(print_string, mystdout); 
    svcInit_SetSVCPriority(7);
    sprintf(print_string, "FlashLED Project Starting\n");
    write_string(print_string, mystdout); 
    SVCLedInit(0);
    while(1) {
        delay(delayCount * 3);	
        SVCLedWrite(1, 0);
        SVCLedWrite(1, 1);
        SVCLedWrite(1, 2);
        SVCLedWrite(1, 3);
        delay(delayCount * 3);	
        SVCLedWrite(0, 0);
        SVCLedWrite(0, 1);
        SVCLedWrite(0, 2);
        SVCLedWrite(0, 3);
    }
    sprintf(print_string, "FlashLED Project Completed\n");
    write_string(print_string, mystdout); 
    return 0;
}

int verify_pushbutton(void) {
    char print_string[1000]; 
    sprintf(print_string, "Pushbuttons Project Starting\n");
    write_string(print_string, mystdout); 
    unsigned i; 
    for (i = 0; i < NUM_OF_LEDS; ++i) {
        SVCLedInit(i); 
        SVCPushButtonInit(i); 
    }
    while(1) {
        if(SVCPushButtonRead(0)) {
            SVCLedWrite(0,3);
        } else {
            SVCLedWrite(1,3);
        }
        if(SVCPushButtonRead(1)) {
            SVCLedWrite(0,0);
        } else {
            SVCLedWrite(1,0);
        }
    }
    sprintf(print_string, "Pushbuttons Project Completed\n");
    write_string(print_string, mystdout); 
    return 0;
}


void verify_uart_lcdc(){ 
    write_string("init on mystdin\r\n", mystdin); 
    write_string("init on stdout\r\n", mystdout); 
    while(1) {
        char ch = myread(mystdin);
        mywrite(mystdin, ch);
        mywrite(mystdout, ch);
        if(ch == CHAR_EOF){
            return; 
        }
    }

}

int main(void) {
    /* After calling mcgInit, MCGOUTCLK is set to 120 MHz and the Bus
     * (peripheral) clock is set to 60 MHz.*/
    mcgInit();
    sdramInit();
    init_devices_fdtable(); 
    mystdin = myopen("/dev/uart/1", 0); 
    mystdout = myopen("/dev/lcdc/1", 0); 
    //verify_uart_lcdc(); 
    verify_led(); 
    //verify_pushbutton(); 
    return 0;
}
