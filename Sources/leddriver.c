/**
 * led.c
 * routines to manipulate the LEDs
 *
 * ARM-based K70F120M microcontroller board
 *   for educational purposes only
 * CSCI E-251 Fall 2012, Professor James L. Frankel, Harvard Extension School
 *
 * Written by James L. Frankel (frankel@seas.harvard.edu)
 */

#include "derivative.h"
#include "leddriver.h"

/**
 * Routine to initialize all of the LEDs
 * 
 * Note: This procedure *does* enable the appropriate port clock
 */
void ledInitAll(void) {
	/* Enable the clock for PORTA using the SIM_SCGC5 register (System Clock Gating
	 * Control Register 5) (See 12.2.13 on page 342 of the K70 Sub-Family Reference
	 * Manual, Rev. 2, Dec 2011) */
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	
	/* Turn off the LEDs */
	ledOrangeOff();
	ledYellowOff();
	ledGreenOff();
	ledBlueOff();

	/* Configure the LED ports */
	ledOrangeConfig();
	ledYellowConfig();
	ledGreenConfig();
	ledBlueConfig();
}


/**
 * Routine to configure the orange LED
 * 
 * Note: This procedure does not enable the port clock
 */ 
void ledOrangeConfig(void) {
    ledInit(); 
	/* Configure bit LED_ORANGE_PORTA_BIT of PORTA using the Pin Control Register
	 * (PORTA_PCR) to be a GPIO pin.  This sets the MUX field (Pin Mux Control) to
	 * GPIO mode (Alternative 1).  (See 11.4.1 on page 309 of the K70 Sub-Family
	 * Reference Manual, Rev. 2, Dec 2011) */
	PORT_PCR_REG(PORTA_BASE_PTR, LED_ORANGE_PORTA_BIT) =
			PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
	/* Above is equivalent to:
	PORTA_PCR11 = PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
	 * but uses my #define for the appropriate bit number.
	 */
	
	/* Configure bit LED_ORANGE_PORTA_BIT of PORTA using the Port Data Direction
	 * Register (GPIOx_PDDR) to be a GPIO output.  (See 60.2.6 on page 2155 of the
	 * K70 Sub-Family Reference Manual, Rev. 2, Dec 2011) */
	PTA_BASE_PTR->PDDR |= 1<<LED_ORANGE_PORTA_BIT;
}

/**
 * Routine to configure the yellow LED
 * 
 * Note: This procedure does not enable the port clock
 */ 
void ledYellowConfig(void) {
    ledInit(); 
	/* Configure bit LED_YELLOW_PORTA_BIT of PORTA to be a GPIO pin. */
	PORT_PCR_REG(PORTA_BASE_PTR, LED_YELLOW_PORTA_BIT) =
			PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
	/* Configure bit LED_YELLOW_PORTA_BIT of PORTA to be a GPIO output. */
	PTA_BASE_PTR->PDDR |= 1<<LED_YELLOW_PORTA_BIT;
}

/**
 * Routine to configure the green LED
 * 
 * Note: This procedure does not enable the port clock
 */ 
void ledGreenConfig(void) {
    ledInit(); 
	/* Configure bit LED_GREEN_PORTA_BIT of PORTA to be a GPIO pin. */
	PORT_PCR_REG(PORTA_BASE_PTR, LED_GREEN_PORTA_BIT) =
			PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
	/* Configure bit LED_GREEN_PORTA_BIT of PORTA to be a GPIO output. */
	PTA_BASE_PTR->PDDR |= 1<<LED_GREEN_PORTA_BIT;
}

/**
 * Routine to configure the blue LED
 * 
 * Note: This procedure does not enable the port clock
 */ 
void ledBlueConfig(void) {
    ledInit(); 
	/* Configure bit LED_BLUE_PORTA_BIT of PORTA to be a GPIO pin. */
	PORT_PCR_REG(PORTA_BASE_PTR, LED_BLUE_PORTA_BIT) =
			PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
	/* Configure bit LED_BLUE_PORTA_BIT of PORTA to be a GPIO output. */
	PTA_BASE_PTR->PDDR |= 1<<LED_BLUE_PORTA_BIT;
}

/**
 * Routine to turn off the orange LED
 */ 
void ledOrangeOff(void) {
	/* Turn off the orange LED by setting bit LED_ORANGE_PORTA_BIT of PORTA using
	 * the Port Set Output Register (GPIOx_PSOR).  (See 60.2.2 on page 2153 of the
	 * K70 Sub-Family Reference Manual, Rev. 2, Dec 2011) */
	PTA_BASE_PTR->PSOR = 1<<LED_ORANGE_PORTA_BIT;
}

/**
 * Routine to turn off the yellow LED
 */ 
void ledYellowOff(void) {
	/* Turn off the yellow LED */
	PTA_BASE_PTR->PSOR = 1<<LED_YELLOW_PORTA_BIT;
}

/**
 * Routine to turn off the green LED
 */ 
void ledGreenOff(void) {
	/* Turn off the green LED */
	PTA_BASE_PTR->PSOR = 1<<LED_GREEN_PORTA_BIT;
}

/**
 * Routine to turn off the blue LED
 */ 
void ledBlueOff(void) {
	/* Turn off the blue LED */
	PTA_BASE_PTR->PSOR = 1<<LED_BLUE_PORTA_BIT;
}

/**
 * Routine to turn on the orange LED
 */ 
void ledOrangeOn(void) {
	/* Turn on the orange LED by clearing bit LED_ORANGE_PORTA_BIT of PORTA using
	 * the Port Clear Output Register (GPIOx_PCOR).  (See 60.2.3 on page 2153 of the
	 * K70 Sub-Family Reference Manual, Rev. 2, Dec 2011) */
	PTA_BASE_PTR->PCOR = 1<<LED_ORANGE_PORTA_BIT;
}

/**
 * Routine to turn on the yellow LED
 */ 
void ledYellowOn(void) {
	/* Turn on the yellow LED */
	PTA_BASE_PTR->PCOR = 1<<LED_YELLOW_PORTA_BIT;
}

/**
 * Routine to turn on the green LED
 */ 
void ledGreenOn(void) {
	/* Turn on the green LED */
	PTA_BASE_PTR->PCOR = 1<<LED_GREEN_PORTA_BIT;
}

/**
 * Routine to turn on the blue LED
 */ 
void ledBlueOn(void) {
	/* Turn on the blue LED */
	PTA_BASE_PTR->PCOR = 1<<LED_BLUE_PORTA_BIT;
}


void ledInit(){ 
    SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
}

void ledOrangeWrite(int ch){
    ch == 0? ledOrangeOn(): ledOrangeOff(); 
}
void ledYellowWrite(int ch){
    ch == 0? ledYellowOn(): ledYellowOff(); 
}
void ledGreenWrite(int ch){
    ch == 0? ledGreenOn(): ledGreenOff(); 
}
void ledBlueWrite(int ch){
    ch == 0? ledBlueOn(): ledBlueOff(); 
}
