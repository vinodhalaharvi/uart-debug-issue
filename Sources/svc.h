/**
 * svc.h
 * Routines for supervisor calls
 *
 * ARM-based K70F120M microcontroller board
 *   for educational purposes only
 * CSCI E-92 Spring 2014, Professor James L. Frankel, Harvard Extension School
 *
 * Written by James L. Frankel (frankel@seas.harvard.edu)
 */

#ifndef _SVC_H
#define _SVC_H

#define SVC_MaxPriority 15
#define SVC_PriorityShift 4

// Implemented SVC numbers
#define SVC_LED_INIT 4
#define SVC_LED_WRITE 5

#define SVC_PUSHBUTTON_INIT 6
#define SVC_PUSHBUTTON_READ 7 

#define SVC_UART_INIT 8 
#define SVC_UART_WRITE 9 
#define SVC_UART_READ 10 

#define SVC_LCDC_INIT 11 
#define SVC_LCDC_WRITE 12 

#define SVC_POTENTIOMETER_INIT 13
#define SVC_POTENTIOMETER_READ 14

#define SVC_THERMISTOR_INIT 15
#define SVC_THERMISTOR_READ 16
#define SVC_CAPACITIVEPAD_INIT 17
#define SVC_CAPACITIVEPAD_READ 18
#define SVC_MALLOC 19 
#define SVC_FREE 20 
#define SVC_MYOPEN 21
#define SVC_MYCLOSE 22
#define SVC_MYREAD 23
#define SVC_MYWRITE 24
#define SVC_FILE_CREATE 25
#define SVC_FILE_DELETE 26


void svcInit_SetSVCPriority(unsigned char priority);
void svcHandler(void);

void SVCLedWrite(int ch, int minor_num); 
void SVCLedInit(int minor_num); 
void SVCPushButtonInit(int minor_num); 
int SVCPushButtonRead(int minor_num); 
void SVCUartInit(int minor_num); 
int SVCUartRead(int minor_num); 
void SVCUartWrite(int ch, int minor_num); 
void SVCLcdcInit(int minor_num); 
void SVCLcdcWrite(int ch, int minor_num); 
void SVCCapacitivePadInit(int minor_num); 
int SVCCapacitivePadRead(int minor_num); 
void SVCPotentiometerInit(int minor_num); 
int SVCPotentiometerRead(int minor_num); 
void SVCThermistorInit(int minor_num); 
int SVCThermistorRead(int minor_num); 

void *SVCMalloc(unsigned);
void SVCFree(void *);
int SVCMyopen(const char *, unsigned);
int SVCFgetc(int);
int SVCFputc(int, int);
int SVCFClose(int);
int SVCCreate(char *);
int SVCDelete(char *);
#endif /* ifndef _SVC_H */
