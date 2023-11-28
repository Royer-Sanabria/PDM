/*
 * API_delay.h
 *
 *  Created on: Nov 26, 2023
 *      Author: Royer Sanabria
 */

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_
#include <stdint.h>
#include <stdbool.h>


typedef uint32_t tick_t;
typedef bool bool_t;

typedef struct{
		tick_t startTime;
		tick_t duration;
		bool_t running;
	}delay_t;



	void delayInit (delay_t*delay, tick_t duration);
	/*void delayInit (delay_t*delay, tick_t duration);
	Función:Inicializa la función de retardo. duración retardo por defecto=0.
	Entrada de función:No requiere entradas.
	Salidas de función: No envía salidas.
	*/


	void delayWrite(delay_t*delay, tick_t duration);
	/*void delayWrite(delay_t*delay, tick_t duration);
	Función:Registra el tiempo de retardo requerido por el usuario.
	Entrada de función: (tick_t duration) Tiempo de retardo en ms.
	Salidas de función: No envía salidas.
	*/

	bool_t delayRead(delay_t*delay);
	/*bool_t delayRead(delay_t*delay);
	Función:indicar si el tiempo ingresado en la función delayWrite fue cumplido.
	Entrada de función: No requiere entredas.
	Salidas de función:
		* true: Tiempo retardo cumplido.
		* false: Tiempo de retardo no cumplido.
		*/


#endif /* API_INC_API_DELAY_H_ */
