/* 
 * File:   uart_driver.h
 * Author: 
 *
 * Created on November 3, 2022, 10:33 PM
 */

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

/* STANDARD LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
    
/* Funckija poredi dva stringa */
boolean stringCompare(uint8_t *string1, uint8_t *string2);

#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

