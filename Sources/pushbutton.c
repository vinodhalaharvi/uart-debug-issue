#include "derivative.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pushbutton.h"
#include "pushbuttondriver.h"
typedef unsigned long uintptr_t; 

pushbutton_t pushbuttons[NUM_OF_PUSHBUTTONS] = { 
    {pushbuttonSW1Config, sw1In}, 
    {pushbuttonSW2Config, sw2In}, 
};

int pushbutton_init(void * minor_num){
    int fd = (int) (uintptr_t) minor_num; 
    pushbuttons[fd].init(); 
    return 0;  
} 

int pushbutton_read(void * minor_num){
    int fd = (int) (uintptr_t) minor_num; 
    int ch = pushbuttons[fd].read(); 
    return ch;
}
