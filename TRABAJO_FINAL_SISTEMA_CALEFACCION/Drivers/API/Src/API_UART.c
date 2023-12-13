/*
 * API_UART.c
 *
 *  Created on: Dec 12, 2023
 *      Author: Royer Sanabria
 */
#include "main.h"
#include "BMP280_Funtion.h"
#include "API_Delay.h"
#include "API_UART.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Delay_Max_UART 100
#define BUFFER_SIZE 2


static uint8_t Data[256]; // tamaño de cadena de caracteres para transmitir.
static uint8_t rx_buffer[BUFFER_SIZE]; // Buffer que almacena los datos recibidos por la UART por interrupción
static uint16_t UART_Date;
volatile uint8_t rx_data_ready = 0;
static UARTRead_t BUFFER_READ;

void UART_TrasmitSensor(UART_HandleTypeDef *huart, ReadSensor Dato){
	sprintf((char *)Data,"Presion: %.2f Pa, Temperatura: %.2f, Altura: %.2f \r\n",Dato.Presion, Dato.Temperatura, Dato.altura);
	HAL_UART_Transmit(&huart2, Data, strlen(Data), Delay_Max_UART);
}
/*
void UART_Set_Altura(){

}*/
/*
UARTRead_t UART_Read(UART_HandleTypeDef*huart){

	if (rx_data_ready) {
		rx_data_ready = 0;
		BUFFER_READ.dato=UART_Date;
	    BUFFER_READ.estado=true;
		HAL_UART_Receive_IT(huart, rx_buffer, BUFFER_SIZE);

	}
	else{
	    BUFFER_READ.estado=false;
	}
return BUFFER_READ;
}
*/

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	while (1){
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
				HAL_Delay(100);
			}
			UART_Date= atoi((char *)rx_buffer);
		 	HAL_UART_Transmit(&huart2,(uint8_t *)rx_buffer,sizeof(rx_buffer), Delay_Max_UART);
			rx_data_ready = 1;
}

