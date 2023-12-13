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

/*
 * Estados de la MEF que determina si el botón fue presionado.
 */
typedef enum {
buttonUp,
buttonDown,
buttonRising,
buttonFalling}debounceState_t;


void debounceFSM_update(); // Función que contiene la MEF que determina sii el botón fue presionado.
void debounceFSM_init(); // Función de inicialización
bool_t readKey(); // función que indica que indica si el botón fue presionado. devuelve un true en caso que haya sido presionado.


#endif /* API_INC_API_DEBOUNCE_H_ */
