/* 
 * File:   main.c
 * Author: 
 *
 * Created on December 25, 2022, 11:48 AM
 */

/* STANDARD LIBRARIES */
#include <stdlib.h>
#include <stdint.h>

/* USER LIBRARIES */
#include "car_tracking.h"

/* CFG */
_FOSC(CSW_ON_FSCM_OFF & HS2_PLL4); //Kristal 10MHz -> Instrukcioni takt = Kristal/4 => HS/x smanjuje x puta
_FWDT(WDT_OFF);
_FGS(CODE_PROT_OFF);


/* ENTRY POINT */
int main(int argc, char** argv)
{
    // INIT
    carTrackingInit();
    
    // LOOP
    while (TRUE)
    {
        carTrackingRun();
    }

    return (EXIT_SUCCESS);
}

