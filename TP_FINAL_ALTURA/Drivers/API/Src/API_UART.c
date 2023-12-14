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
#define BUFFER_SIZE 3
UART_HandleTypeDef huart2;

static uint8_t Data[256]; // tamaño de cadena de caracteres para transmitir.
static uint8_t rx_buffer[BUFFER_SIZE]; // Buffer que almacena los datos recibidos por la UART por interrupción
static uint16_t UART_Date;
volatile uint8_t rx_data_ready;
static UARTRead_t BUFFER_READ;

void UART_TrasmitSensor(ReadSensor Dato){
	uint16_t size;
	sprintf((char *)Data,"Presion: %.2f Pa, Temperatura: %.2f, Altura: %.2f, SetPoint: %.2f \r\n",Dato.Presion, Dato.Temperatura, Dato.altura, Dato.AlturaSet);
	HAL_UART_Transmit(&huart2,Data, strlen(Data), Delay_Max_UART);
}

void UART_TrasmitMessage(const char *Message){
	HAL_UART_Transmit(&huart2, (uint8_t *)Message, strlen(Message),Delay_Max_UART);
}

void UART_Init2 (){
	HAL_UART_Receive_IT(&huart2, (uint8_t *)rx_buffer, BUFFER_SIZE);
}


UARTRead_t UART_Read(){
	if (rx_data_ready) {
		rx_data_ready = 0;
		BUFFER_READ.estado = true;
		BUFFER_READ.dato=UART_Date;
		HAL_UART_Receive_IT(&huart2, rx_buffer, BUFFER_SIZE);
	}
	else{
	    BUFFER_READ.estado=false;
	}
return BUFFER_READ;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	        // Convertir el buffer a un número entero
	        UART_Date = atoi((char *)rx_buffer);
	        // Reiniciar la recepción
	        HAL_UART_Receive_IT(&huart2, rx_buffer, BUFFER_SIZE);
	        // Transmitir el número recibido (opcional, para depuración)
	        HAL_UART_Transmit(&huart2, (uint8_t *)rx_buffer, sizeof(rx_buffer), Delay_Max_UART);
	    	rx_data_ready = 1;
}



