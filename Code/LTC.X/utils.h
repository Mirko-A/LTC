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
#include <stdint.h>
#include <string.h>
    
/* MACRO CONSTANTS */
#define PORT_A (0u)
#define PORT_B (1u)
#define PORT_C (2u)
#define PORT_D (3u)
#define PORT_F (4u)

#define PIN_LOW   (0u)
#define PIN_HIGH  (1u)

#define INPUT_PIN  (1u)
#define OUTPUT_PIN (0u)

#define FALSE   (0u)
#define TRUE    (1u)
    
/* TYPE DEFINITIONS */
typedef uint8_t boolean;
typedef uint8_t byte;
/**
 * @Brief Function compares two strings.
 * @param byte *string1 
 * @param byte *string2
 * @return boolean -> TRUE if strings are same, FALSE if strings are different
 */
boolean stringCompare(byte string1[], byte string2[]);

#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

