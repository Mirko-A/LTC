/* 
 * File:   timer.h
 * Author: 
 *
 * Created on November 8, 2017, 10:48 PM
 */

/* USER LIBRARIES */
#include "timer.h"

/* LOCAL VARIABLES */
static volatile uint32_t ms_tick = 0;

/* GLOBAL FUNCTIONS */
/********************************************************************
*    Function Name:  CloseTimer1                                    *
*    Description:    This routine disables the Timer1 and its       *
*                    interrupt enable and flag bits.                *
*    Parameters:     None                                           *
*    Return Value:   None                                           *
********************************************************************/

void CloseTimer1(void)
{
    _T1IE = 0;      /* Disable the Timer1 interrupt */
    T1CONbits.TON = 0;      /* Disable timer1 */
    _T1IF = 0;      /* Clear Timer interrupt flag */
}


/*******************************************************************
*    Function Name: ConfigIntTimer1                                *
*    Description:   This function configures interrupt and sets    *
*                   Interrupt Priority                             *
*    Return Value:  None                                           *
*******************************************************************/

void ConfigIntTimer1(unsigned int config)
{
    _T1IF = 0;                   /* clear IF bit */
    _T1IP = (config &0x0007);    /* assigning Interrupt Priority */
    _T1IE = (config &0x0008)>>3; /* Interrupt Enable /Disable */
}



/********************************************************************
*    Function Name:  OpenTimer1                                     *
*    Description:    This routine configures the timer control      *
*                    register and timer period register.            *
*    Parameters:     config: bit definitions to configure Timer1    *
*                    period: Value to be loaded to PR reg           *
*    Return Value:   None                                           *
********************************************************************/

void OpenTimer1(unsigned int config,unsigned int period)
{
    TMR1  = 0;          /* Reset Timer1 to 0x0000 */
    PR1   = period;     /* assigning Period to Timer period register */
    T1CON = config;     /* Configure timer control reg */
}

/********************************************************************
*    Function Name:  ReadTimer1                                     *
*    Description:    This routine reads the 16-bit value from       *
*                    Timer Register.                                *
*    Parameters:     None                                           *
*    Return Value:   unsigned int: Timer  16-bit value              *
********************************************************************/

unsigned int ReadTimer1(void)
{
    return (TMR1);      /* Return the Timer1 register */
}


/********************************************************************
*    Function Name:  WriteTimer1                                    *
*    Description:    This routine writes a 16-bit value to Timer1   *
*    Parameters:     unsigned int: value to write to Timer          *
*    Return Value:   None                                           *
********************************************************************/

void WriteTimer1(unsigned int timer)
{
    TMR1 = timer;     /* assign timer value to Timer1 Register */
}

/* LOCAL FUNCTIONS */

/** 
 * @brief Inicijalizuje Timer1 za 
 * @param void
 * @return void
 */
static void initTimer1(void)
{

}

/** 
 * @brief Inicijalizuje Timer2. Sluzi da generise PWM signal za servo motor.
 * @param void
 * @return void
 */
static void initTimer2(void)
{
	TMR2 = 0;          /* Resetuj vrednost tajmera 2  */
	PR2  = UINT16_MAX;  /* Podesi period tajmera 2     */
    
	T2CONbits.TCS = 0;   /* 0 = Internal clock (FOSC/4) */
    // IPC1bits.T2IP = 3 /* T2 interrupt pririty (0-7)      */
	// SRbits.IPL = 3;   /* CPU interrupt priority is 3(11) */
	T2CONbits.TCKPS = 0b11; /* Prescaler 1:256 */
    
    IFS0bits.T2IF = 0; /* Resetuj interrupt flag tajmera 2 */
	IEC0bits.T2IE = 1; /* Dozvoli interrupt tajmera 2      */

	T2CONbits.TON = 1; /* T2 on */ 
}

/** 
 * @brief Inicijalizuje Timer3 sa periodom jedna milisekunda. Sluzi da uvecava ms_tick svake milisekunde.
 * @param void
 * @return void
 */
static void initTimer3(void)
{
	TMR3 = 0;              /* Resetuj vrednost tajmera 3  */
	PR3  = ONE_MS_PERIOD;  /* Podesi period tajmera 3     */
	
	T3CONbits.TCS = 0;   /* 0 = Internal clock (FOSC/4) */
    // IPC1bits.T3IP = 3 /* T3 interrupt pririty (0-7)      */
	// SRbits.IPL = 3;   /* CPU interrupt priority is 3(11) */
	
    IFS0bits.T3IF = 0; /* Resetuj interrupt flag tajmera 3 */
	IEC0bits.T3IE = 1; /* Dozvoli interrupt tajmera 3      */

	T3CONbits.TON = 1; /* T3 on */ 
}

/** 
 * @brief Inicijalizuje Timer4. Sluzi da generise PWM signal za buzzer.
 * @param void
 * @return void
 */
static void initTimer4(void)
{
	TMR4 = 0;          /* Resetuj vrednost tajmera 4  */
	PR4  = UINT16_MAX;  /* Podesi period tajmera 4     */
    
	T4CONbits.TCS = 0;   /* 0 = Internal clock (FOSC/4) */
    // IPC1bits.T2IP = 3 /* T4 interrupt pririty (0-7)      */
	// SRbits.IPL = 3;   /* CPU interrupt priority is 3(11) */
	T4CONbits.TCKPS = 0b11; /* Prescaler 1:256 */
    
    IFS1bits.T4IF = 0; /* Resetuj interrupt flag tajmera 4 */
	IEC1bits.T4IE = 1; /* Dozvoli interrupt tajmera 4      */

	// T4CONbits.TON = 1; /* T4 on, ne radimo ovde nego u funkcijama vezanim za alarm u door_system.c */ 
}

/* GLOBAL FUNCTIONS */

void initTimers(void)
{
    initTimer1();
    initTimer2();
    initTimer3();
    initTimer4();
}

void startTimer2(uint16_t period_tenth_of_ms)
{
    /* Resetuj vrednost tajmera 2 */
	TMR2 = 0;
    /* Podesi period tajmera 2 */
	PR2  = period_tenth_of_ms * TENTH_OF_MS_FACTOR;
}

void startTimer4(uint16_t period_tenth_of_ms)
{
    /* Resetuj vrednost tajmera 4 */
	TMR4 = 0;
	/* Podesi period tajmera 4 */
    PR4  = period_tenth_of_ms * TENTH_OF_MS_FACTOR;
}

uint32_t getTickMs(void)
{
    return ms_tick;
}

/* INTERRUPT SERVICE ROUTINES */
void __attribute__((__interrupt__)) __attribute__ ((__auto_psv__)) _T1Interrupt(void)
{    
   	TMR1 = 0;
    IFS0bits.T1IF = 0;
}

/* Increment ms_tick every millisecond */
void __attribute__((__interrupt__)) __attribute__ ((__auto_psv__)) _T3Interrupt(void)
{    
    ms_tick = ms_tick + 1;
    
   	TMR3 = 0;
    IFS0bits.T3IF = 0;
}

