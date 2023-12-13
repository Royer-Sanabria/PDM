/*
 * API_UART.h
 *
 *  Created on: Dec 12, 2023
 *      Author: Royer Sanabria
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

typedef struct{
	bool_t estado;
	uint8_t dato;
}UARTRead_t;




void UART_TrasmitSensor(ReadSensor Dato);
void UART_Init2 ();
UARTRead_t UART_Read();

#endif /* API_INC_API_UART_H_ */
