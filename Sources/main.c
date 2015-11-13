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
#include "uart.h"
#include "uartdriver.h"
#include "lcdc.h"
#include "io.h"
#include "lcdcConsole.h"

#define CHAR_EOF 4

void consoleDemo();

int main(void) {
  /* After calling mcgInit, MCGOUTCLK is set to 120 MHz and the Bus
   * (peripheral) clock is set to 60 MHz.*/
  mcgInit();
  sdramInit();
  uart_init(0);
  lcdc_init(0);
  consoleDemo();
  return 0;
}

void consoleDemo() {
  while(1) {
	char ch = uart_read(0);
    //char ch = uartGetchar(UART2_BASE_PTR); 

	uart_write(ch, 0);
    //uartPutchar(UART2_BASE_PTR, ch); 

	lcdc_write(ch, 0);
	if(ch == CHAR_EOF) {
	  return;
	}
  }
}
