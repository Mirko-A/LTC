#include "car_tracking.h"

/* LOCAL VARIABLES */

/* Car command data */
static const byte start_command[START_COMMAND_LEN]  = "START";
static const byte stop_command[STOP_COMMAND_LEN]    = "STOP";

/* Action flags */

static CarState  car_state;
static CarAction car_action;
static boolean   safe_to_move;

static void processUartRX(void)
{
	if(!uartAvailable())
	{
		byte entered_word[MAX_BUFFER_SIZE] = {0};
		uartReadString(entered_word);
		
		if(stringCompare(entered_word, (byte*) start_command) == TRUE)
		{
			car_state = CAR_ON;
		}
		else if(stringCompare(entered_word, (byte*) stop_command) == TRUE)
		{
			car_state = CAR_OFF;
		}
		else 
		{
			uartWriteString((byte*) "Wrong command\n");
		}
			
	}
}

static void displayCarState(void)
{
    uartWriteString((byte*) "Car: ");
    if (car_state == CAR_ON)
    {
        uartWriteString((byte*) "CAR ON \n");
    }
    else if (car_state == CAR_OFF)
    {
        uartWriteString((byte*) "CAR OFF \n");
    }
    uartWriteString((byte*) "\n\r");
}

/* TODO: dovrsiti */
static EnvLightLevel getEnvLightLevel(void)
{
    EnvLightLevel env_light_level;

    env_light_level.front = photores_front_raw;
    env_light_level.back  = photores_back_raw;
    env_light_level.left  = photores_left_raw;
    env_light_level.right = photores_right_raw;
	
	return env_light_level;
}

static ObstacleDistance getObstacleDistances(void)
{
    ObstacleDistance obstacle_distances;
	
	obstacle_distances.front = distance_front_raw;
	obstacle_distances.back  = distance_back_raw;
	
	return obstacle_distances;
}

static void checkInputs(void)
{
	ObstacleDistance obstacle_distances = getObstacleDistances();
	
	if(car_state == CAR_ON)
	{
		if(obstacle_distances.front < CRITICAL_DISTANCE)
		{
			car_action = CAR_IDLE;
			safe_to_move = FALSE;
		}
		else if(obstacle_distances.back < CRITICAL_DISTANCE)
		{
			car_action = CAR_IDLE;
			safe_to_move = FALSE;
		}
		else
		{
			safe_to_move = TRUE;
		}
	}
}

/* Funkcija koja na osnovu nivoa osvetljenosti vraca polozaj gde je osvetljenost preko kriticne */
static CarAction getGetCarAction(void)
{
    CarAction car_action;
	EnvLightLevel env_light_level = getEnvLightLevel();
	
	/* TODO: porazmisliti o prioritetu */
	if(env_light_level.front > CRITICAL_LIGHT)
	{
		car_action = CAR_FORWARD;
	}
	else if(env_light_level.left > CRITICAL_LIGHT)
	{
		car_action = CAR_LEFT;
	}
	else if(env_light_level.right > CRITICAL_LIGHT)
	{
		car_action = CAR_RIGHT;
	}
	else if(env_light_level.back > CRITICAL_LIGHT)
	{
		car_action = CAR_BACK;
	}
	else
	{
		car_action = CAR_IDLE;
	}
    
    return car_action;
}

/*Funkcija gde pomeramo auto */
void performAction(void)
{
	if(safe_to_move == TRUE)
	{
		/* TODO: dovrsiti */
	}
}

void carTrackingInit(void)
{
	
}

void carTrackingRun(void)
{
	
}