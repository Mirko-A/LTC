/* 
 * File:   adc.h
 * Author: 
 *
 * Created on 27. septembar 2017., 16.09
 */

#ifndef ADC_H_
#define	ADC_H_

/* STANDARD LIBRARIES */
#include <stdint.h>

/* CTRL LIBRARIES */
#include <p30fxxxx.h>

/* GLOBAL VARIABLES */
extern uint16_t  photores_front_raw;
extern uint16_t  photores_back_raw;
extern uint16_t  photores_left_raw;
extern uint16_t  photores_right_raw;
extern uint16_t  distance_front_raw;
extern uint16_t  distance_back_raw;

/* GLOBAL FUNCTIONS */
void initADC(void);

#endif	/* ADC_H_*/

