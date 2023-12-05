/*
 * API_debounce.h
 *
 *  Created on: Nov 26, 2023
 *      Author: Royer Sanabria
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include "stm32f4xx_hal.h"
#include "API_delay.h"
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t status_t;
typedef uint32_t control_t;

typedef enum {
buttonUp,
buttonDown,
buttonRising,
buttonFalling}debounceState_t;


void buttonPressed();
void buttonReleased();
void debounceFSM_update();
void debounceFSM_init();
bool_t readKey();


#endif /* API_INC_API_DEBOUNCE_H_ */
