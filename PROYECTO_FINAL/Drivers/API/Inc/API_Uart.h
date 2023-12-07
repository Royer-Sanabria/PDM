/*
 * API_UART.h
 *
 *  Created on: Dec 3, 2023
 *      Author: Royer Sanabria ARIZA
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_
#endif /* API_INC_API_UART_H_ */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "API_Delay.h"
#include "API_debounce.h"
#include "stm32f4xx_hal.h"
#include <BMP280.h>


typedef bool bool_t;
typedef uint16_t tick_m;

/*Flag_Program:
 *  - Estados que puede tomar la MEF de la función UART_Mef(); *
 */
enum  Flag_Program{
	 read_set_temperature,
	 read_confirmation_set_temperature,
	 write_message_temperature,
	 write_message_confirmation
};
enum status_program_control{
	High_Alert,
	Ideal_Condition
};


typedef struct {
bool_t Status_Temperature;
uint16_t Temperature;
}Temperature_read;

typedef struct {
	enum status_program_control;
	uint16_t Temperature;
}Status_Program_Control;

/*UARTRead
 *  - Estructura de datos para guardar la información transmitida por la UART,
 *    se acompaña de un bool para tener el control de la lectura de datos por
 *    interrupcion.
 */
typedef struct{
	bool estado;
	uint16_t dato;
}UARTRead_t;


void UART_Init(void); //Inicializa los parametros de la Uart;

UARTRead_t UART_Read(); //La función se encarga de leer los datos enviados a través de UART y devuelve true tan pronto como ha recibido la totalidad de los datos.

UARTRead_t UART_Mef(); //Inicializa parametros de la MEF de guardado de temperatura.

void UART_Status_button(void); // Revisa si hay una pulsación del boton asignado para el reseteo de dato.

void UARTTrasmit(uint16_t temp_set,uint16_t temp_sensor,bool_t Stat); // Envia el valor sensado por la UART.

void MX_USART2_UART_Init(void);
void Emergency(); // Rutina de emergencia bloqueante. Enciende led de placa.
