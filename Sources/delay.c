/**
 * delay.c
 * routines to delay via looping
 * 
 * ARM-based K70F120M microcontroller board
 *   for educational purposes only
 * CSCI E-92 Spring 2014, Professor James L. Frankel, Harvard Extension School
 *
 * Written by James L. Frankel (frankel@seas.harvard.edu)
 */

#include "delay.h"

/**
 * Routine to delay for user specified interval
 */ 
void delay(unsigned long int limit) {
  unsigned long int i;
  for(i = 0; i < limit; i++) {
  }
}

/**
 * Assembly routine to delay for user specified interval
 * 
 * With 120 MHz clock, each loop is 4 cycles * (1/120,000,000) seconds cycle
 * time.  So, each loop is .0000000333 seconds = 33.333 nanoseconds.
 */ 
/*void asmDelay(unsigned long int limit);
__asm("\n\
	.global	asmDelay\n\
asmDelay:\n\
	adds	r0,r0,#-1\n\
	bne	asmDelay\n\
	bx	lr\n\
      ");*/
