/*
 * MEF.h
 *
 *  Created on: Dec 14, 2023
 *      Author: Royer Sanabria
 */

#ifndef API_INC_MEF_H_
#define API_INC_MEF_H_
extern UART_HandleTypeDef huart2;
enum EstadoMef {
    Inicio,
	Altura_Seteo,
	Alerta_Abajo,
	Altura_Alcanzada,
	Alerta_Arriba,
	Control_Alerta
};

typedef enum EstadoMef EstadoAlerta_t;


void MEF();
EstadoAlerta_t ControlAlerta();
void MEF_Init();
#endif /* API_INC_MEF_H_ */
