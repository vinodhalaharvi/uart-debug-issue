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
//#include "uart.h"
//#include "lcdc.h"
#include "io.h"
#include "lcdcConsole.h"

#define CHAR_EOF 4

void consoleDemo();

int main(void) {
  /* After calling mcgInit, MCGOUTCLK is set to 120 MHz and the Bus
   * (peripheral) clock is set to 60 MHz.*/
  mcgInit();
  sdramInit();
  unsigned uart_fd = myopen("/dev/uart/1", 0); 
  unsigned lcdc_fd = myopen("/dev/lcdc/1", 0); 
  //uart_init(0);
  //lcdc_init(0);
  while(1) {
	char ch = myread(uart_fd);
	mywrite(ch, uart_fd);
	mywrite(ch, lcdc_fd);
	if(ch == CHAR_EOF) {
	  return 0;
	}
  }
  return 0;
}
