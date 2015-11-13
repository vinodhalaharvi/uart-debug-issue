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
#include "common.h"
#define CHAR_EOF 4
void consoleDemo();
extern unsigned mystdout; 
extern unsigned mystdin; 

int main(void) {
  /* After calling mcgInit, MCGOUTCLK is set to 120 MHz and the Bus
   * (peripheral) clock is set to 60 MHz.*/
  mcgInit();
  sdramInit();
  init_devices_fdtable(); 
  mystdin = myopen("/dev/uart/1", 0); 
  mystdout = myopen("/dev/lcdc/1", 0); 
  write_string("init on mystdin\r\n", mystdin); 
  write_string("init on stdout\r\n", mystdout); 
  while(1) {
	char ch = myread(mystdin);
	mywrite(mystdin, ch);
	mywrite(mystdout, ch);
	if(ch == CHAR_EOF) {
	  return 0;
	}
  }
  return 0;
}
