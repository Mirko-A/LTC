/* 
 * File:   uart_driver.h
 * Author: 
 *
 * Created on November 3, 2022, 10:33 PM
 */

#include "uart.h"

/* Prijemni FIFO bafer */
byte rx_buffer[MAX_BUFFER_SIZE] = { 0 };
/* Pozicija sa koje ce se procitati sledeci karakter */
volatile byte buffer_first = 0;
/* Pozicija na koju ce se upisati sledeci karakter */
volatile byte buffer_last  = 0;
/* Trenutni broj karaktera u baferu */
volatile byte buffer_size  = 0;

void uartInit(void)
{
    U1BRG=0x10; //ovim odredjujemo baudrate (0x10 -> 4800)

    U1MODEbits.ALTIO=0; //biramo koje pinove koristimo za komunikaciju osnovne ili alternativne

    IEC0bits.U1RXIE=1; //omogucavamo rx1 interupt

    U1STA&=0xfffc;

    U1MODEbits.UARTEN=1; // ukljucujemo ovaj modul

    U1STAbits.UTXEN=1; // ukljucujemo predaju
}

byte uartAvailable()
{
    return buffer_size;
}

void uartFlush()
{
    buffer_size = 0;
    buffer_first = 0;
    buffer_last = 0;
}

byte uartReadChar()
{
    byte byte_to_return;
    
    if (buffer_size == 0)
    { 
        return -1;
    }
    
    byte_to_return = rx_buffer[buffer_first++];
    buffer_first &= MAX_BUFFER_SIZE - 1;
    
    buffer_size--;
    
    return byte_to_return;
}

byte uartReadString(byte str_to_read[])
{
    byte length = 0u;
    
    while (buffer_size > 0)
    {
        str_to_read[length++] = uartReadChar();
    }
    
    return length;
}

void uartWriteChar(byte p_byte)
{
	while(!U1STAbits.TRMT);

    if(U1MODEbits.PDSEL == 3)
        U1TXREG = p_byte;
    else
        U1TXREG = p_byte & 0xFF;
}

void uartWriteString(byte *p_str)
{
	while ((*p_str) != 0)
    {
        uartWriteChar(*p_str);
        p_str++;
    }
}

void uartWriteNumber(uint16_t num)
{
    byte digits[5] = { 0 };
    byte len = 0;
    
    do
    {
        digits[len] = (byte) ((num % 10) + '0');
        len = len + 1;
        
        num = num / 10;
    } 
    while (num != 0);
    
    byte it = 0;
    
    for ( ; it < len; it++)
    {
        uartWriteChar(digits[len-it-1]);
    }
}

void __attribute__((__interrupt__)) __attribute__ ((__auto_psv__)) _U1RXInterrupt(void) 
{
    IFS0bits.U1RXIF = 0;
    
    rx_buffer[buffer_last++]=U1RXREG;
    buffer_last &= MAX_BUFFER_SIZE - 1;
    
    if (buffer_size < MAX_BUFFER_SIZE)
    {
        buffer_size++;
    }
} 