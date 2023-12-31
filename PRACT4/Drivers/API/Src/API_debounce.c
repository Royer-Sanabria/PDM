/*
 * API_debounce.c
 *
 *  Created on: Nov 26, 2023
 *      Author: Royer Sanabria
 */

#include "API_debounce.h"
#include "API_delay.h"
static uint32_t delay_control=40;
debounceState_t status_mef;
static delay_t Retardo;
static bool real_status_button;

void debounceFSM_init(void){
	delayInit(&Retardo,delay_control);
	status_mef=buttonUp;
}

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
					//buttonPressed();
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
				//buttonReleased();
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


void buttonPressed(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
}
void buttonReleased(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
}
