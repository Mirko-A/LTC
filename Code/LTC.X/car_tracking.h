/* 
 * File:   door_system.h
 * Author: 
 *
 * Created on December 25, 2022, 2:55 PM
 */

#ifndef CAR_TRACKING_H_
#define	CAR_TRACKING_H_

/* STANDARD LIBRARIES */
#include <stdint.h>

/* CTRL LIBRARIES */
#include <p30fxxxx.h>

/* USER LIBRARIES */
#include "timer.h"
#include "adc.h"
#include "uart.h"
#include "utils.h"

/* MACRO CONSTANTS */
/* GPIO pin related macros */
#define PHOTO_RES_FRONT_PIN   PORT_B, ?
#define PHOTO_RES_FRONT_GET   PORTBbits.RB?
#define PHOTO_RES_FRONT_SET   LATBbits.LATB?

#define PHOTO_RES_LEFT_PIN   PORT_B, ?
#define PHOTO_RES_LEFT_GET   PORTBbits.RB?
#define PHOTO_RES_LEFT_SET   LATBbits.LATB?

#define PHOTO_RES_RIGHT_PIN   PORT_B, ?
#define PHOTO_RES_RIGHT_GET   PORTBbits.RB?
#define PHOTO_RES_RIGHT_SET   LATBbits.LATB?

#define PHOTO_RES_BACK_PIN   PORT_B, ?
#define PHOTO_RES_BACK_GET   PORTBbits.RB?
#define PHOTO_RES_BACK_SET   LATBbits.LATB?

#define DISTANCE_FRONT_PIN   PORT_B, ?
#define DISTANCE_FRONT_GET   PORTBbits.RB?
#define DISTANCE_FRONT_SET   LATBbits.LATB?

#define DISTANCE_BACK_PIN   PORT_B, ?
#define DISTANCE_BACK_GET   PORTBbits.RB?
#define DISTANCE_BACK_SET   LATBbits.LATB?

/* OTHER CONSTANTS*/

#define START_COMMAND_LEN (5u)
#define STOP_COMMAND_LEN (4u)
#define CRITICAL_LIGHT (50u)
#define CRITICAL_DISTANCE (25u)

/* TYPE DEFINITIONS */
typedef enum 
{
    CAR_OFF,
    CAR_ON
} CarState;

typedef enum 
{
    CAR_LEFT,
    CAR_RIGHT,
	CAR_BACK,
	CAR_FORWARD,
	CAR_IDLE
} CarAction;

typedef struct
{
    uint16_t  front;
    uint16_t  back;
    uint16_t  left;
    uint16_t  right;
} EnvLightLevel;

typedef struct
{
    uint16_t  front;
    uint16_t  back;
} ObstacleDistance;

/* GLOBAL FUNCTIONS */

/**
 * @brief This function initializes all components of the system. These include: 
 * - GPIO pins
 * - Timers
 * - UART module
 * - A/D converter
 * .
 * @param void
 * @return void
 */
void carTrackingInit(void);

/**
 * @brief This function executes core functionalities of the system sequentially. These include: 
 * - Checking input signals and raising corresponding flags
 * - Starting necessary actions based on flags from input signals
 * - Stopping started actions when necessary (when time limits are reached).
 * .
 * @param void
 * @return void
 */
void carTrackingRun(void);

#endif	/* CAR_TRACKING_H_ */