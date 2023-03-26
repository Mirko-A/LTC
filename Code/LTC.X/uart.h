/* 
 * File:   uart_driver.h
 * Author: 
 *
 * Created on November 3, 2022, 10:33 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

/* STANDARD LIBRARIES */
#include <stdlib.h>
#include <stdint.h>
    
/* CTRL LIBRARIES */
#include <p30fxxxx.h>

/* USER LIBRARIES */
#include "utils.h"
    
#define MAX_BUFFER_SIZE 64u

/* Prijemni FIFO bafer */
extern byte rx_buffer[MAX_BUFFER_SIZE];
/* Pozicija sa koje ce se procitati sledeci karakter */
extern volatile byte buffer_first;
/* Pozicija na koju ce se upisati sledeci karakter */
extern volatile byte buffer_last;
/* Trenutni broj karaktera u baferu */
extern volatile byte buffer_size;    
    
/* Funckija inicijalizuje UART kanal */
void uartInit(void);

/* Funckija koja vraca trenutni broj karaktera u FIFO baferu 
   Ako je prazan vraca 0
 */ 
byte uartAvailable();

/* Funckija cisti FIFO bafer */ 
void uartFlush();

/* Funckija cita jedan karakter iz FIFO bafera */
byte uartReadChar();

/* Funckija cita sve karaktere u FIFO baferu */
byte uartReadString(byte *str_to_read);

/* Funckija upisuje jedan karakter u FIFO bafer */
void uartWriteChar(byte p_byte);

/* Funckija upisuje niz karaktera u FIFO bafer */
void uartWriteString(byte *p_str);

/* Funckija upisuje broj u obliku stringa u FIFO bafer */
void uartWriteNumber(uint16_t num);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

