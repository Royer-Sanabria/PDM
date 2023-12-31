/*
 * API_debounce.c
 *
 *  Created on: Nov 26, 2023
 *      Author: Royer Sanabria
 */

#include "API_debounce.h"

static uint32_t delay_control=40;
static debounceState_t status_mef;
static delay_t Retardo;
static bool real_status_button;

/*
 * función de inicio de debounceFSM
 */
void debounceFSM_init(void){
	delayInit(&Retardo,delay_control);
	status_mef=buttonUp;
}

/*
 * Actualizacion de la MEF de estado del botón.
 *
 */
void debounceFSM_update(){
	switch (status_mef){
		case buttonUp:

			if(RESET==HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){
				status_mef=buttonFalling;
			}
		    break;
		case buttonFalling:
			if(delayRead(&Retardo)){
				if(SET==HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){
					status_mef=buttonUp;
					real_status_button=true;
				}
				else {
				status_mef=buttonDown;
				}
			}
			break;

		case buttonDown:
			if (SET==HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){
				status_mef=buttonRising;
			}
			break;

		case buttonRising:
			if(delayRead(&Retardo)){
			if(RESET==HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){
				status_mef=buttonUp;
				real_status_button=true;
			}
			else {
				status_mef=buttonDown;
			}
			}
			break;
		default:

	}
}

/*
 * Funcion que devuelve un true en caso que haya se haya presionado el botón
 */
bool_t readKey(){
	debounceFSM_update();
	if(real_status_button){
		real_status_button=false;
				return true;
	}
	else{
	return false;
	}
}

