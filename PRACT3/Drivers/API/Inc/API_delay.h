/*
 * API_delay.h
 *
 *  Created on: Nov 26, 2023
 *      Author: Royer Sanabria
 */

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>


#endif /* API_INC_API_DELAY_H_ */



typedef uint32_t tick_t;
typedef bool bool_t;
typedef struct{ // defino la estructura de los datos
	tick_t startTime;
	tick_t duration;
	bool_t running;
}delay_t;

void delayInit (delay_t*delay, tick_t duration); //defino solamente la función
bool_t delayRead(delay_t*delay);
void delayWrite(delay_t*delay, tick_t duration);

