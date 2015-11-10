/* Source copied from CSCIE-92 class sample code */
#include "derivative.h"
#include <stdio.h>
#include <stdlib.h>
#include "derivative.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "potentiometerdriver.h"
#include "potentiometer.h"
typedef unsigned long uintptr_t; 

potentiometer_t potentiometers[NUM_OF_POTENTIOMETERS] = { 
    {potentiometer_driver_init, potentiometer_driver_read}
};

int potentiometer_init(void * minor_num){ 
    int fd = (int) (uintptr_t) minor_num; 
    potentiometers[fd].init(); 
    return 0;
}

int potentiometer_read(void *minor_num){ 
    int fd = (int) (uintptr_t) minor_num; 
    return potentiometers[fd].read(); 
}

