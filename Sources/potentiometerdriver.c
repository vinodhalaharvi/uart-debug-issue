#include "derivative.h"
#include <stdio.h>
#include <stdlib.h>
#include "potentiometerdriver.h"

void potentiometer_driver_init(void) {
   SIM_SCGC3 |= SIM_SCGC3_ADC1_MASK;
   ADC1_CFG1 = ADC_CFG1_MODE(ADC_CFG1_MODE_12_13_BIT);
   ADC1_SC3 = ADC_SC3_AVGE_MASK | ADC_SC3_AVGS(ADC_SC3_AVGS_32_SAMPLES);
}

unsigned int potentiometer_driver_read() {
   //ADC1_SC1A = channel;
   ADC1_SC1A = ADC_CHANNEL_POTENTIOMETER;
   // ADC_CHANNEL_TEMPERATURE_SENSOR 
   while(!(ADC1_SC1A & ADC_SC1_COCO_MASK)) {
   }
   return ADC1_RA;
}
