/*
 * API_Delay.c
 *
 *  Created on: Dec 3, 2023
 *      Author: Royer Sanabria
 */

#include "API_Delay.h"

void delayInit(delay_t*delay, tick_t duration)
{
	delay->running = false;
	delayWrite(delay, duration);

}

bool_t delayRead(delay_t*delay)
{
	if(delay->running)
	{
	if((HAL_GetTick()- delay->startTime)>= delay->duration)
		{
		delay->running=false;
		return true;
		}
	}
	else
	{
		delay->startTime=HAL_GetTick();
		delay->running=true;
	}
	return false;
}

void delayWrite(delay_t*delay, tick_t duration)
{
	delay->duration=duration;
}

