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
#include "uartdriver.h"
#include "lcdcdriver.h"
#include "lcdcConsole.h"

#define CHAR_EOF 4

void consoleDemo();

int main(void) {
  /* After calling mcgInit, MCGOUTCLK is set to 120 MHz and the Bus
   * (peripheral) clock is set to 60 MHz.*/

  mcgInit();

  sdramInit();

  uart_driver_init();

  lcdc_driver_init();

  consoleDemo();

  return 0;
}

void consoleDemo() {
  while(1) {
	char ch = uart_driver_read();

	// Echo the input character back to the UART
	uart_driver_write(ch);

	// Output the character on the TWR_LCD_RGB
	lcdc_driver_write(ch);

 	// Exit if character typed was a Control-D (EOF)
	if(ch == CHAR_EOF) {
	  return;
	}
  }
}
