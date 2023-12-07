/*
 * API_Uart.c
 *
 *  Created on: Dec 3, 2023
 *      Author: Royer Sanabria
 */
#include "main.h"
#include "API_UART.h"
#include "API_debounce.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define TIME_MAX_DELAY 10
#define BUFFER_SIZE 3
#define Null_Int 0


/*
 * Definición de variables para interacción con la UART
 */
static char mensaje_lectura_datos[]={"Indique la temperatura de seteo: \r\n"};
static char mensaje_confirmacion_datos[]={"Confirme la temperatura de seteo: \r\n"};
static char mensaje_error_datos[]={"Datos incompatible \r\n"};
static char mensaje_correcto_datos[]={"Datos almacenado \r\n"};
static char mensaje_reseteo_datos[]={"Reinicio de seteo \r\n"};
static char mensaje_alerta_hight[]={"Sobre paso la temperaturea de seteo \r\n"};
static char interlineado[]={"\r\n"};
static char Lectura_Sensor[]={"Temperatura actual  \r\n"};


static enum Flag_Program flag_program=write_message_temperature;
static Status_Program_Control status_program_control;


static uint8_t rx_buffer[BUFFER_SIZE]; // Buffer que almacena los datos recibidos por la UART por interrupción
static uint16_t UART_Date;
volatile uint8_t rx_data_ready = 0;
volatile bool_t program_ready;
static UARTRead_t set_temperature;
static UARTRead_t set_temperature_confirmation;
static delay_t Delay_sendDateBMP280;



UART_HandleTypeDef huart2;


/*UART_Init(void)
 * Funcion de inicializacion de parametros de la UART y reset de variables
 * de comparación.
 */
void UART_Init(void){
MX_USART2_UART_Init();
HAL_UART_Receive_IT(&huart2, (uint8_t *)rx_buffer, BUFFER_SIZE);
set_temperature.estado=false;
set_temperature_confirmation.estado=false;
debounceFSM_init();
}

/*UART_Read():
 * - Lectura ingreso de datos desde la UART a la F401RE.
 * - Se usa interrupción y se establece una bandera rx_data_ready
 *   cuando se realiza la interrupción, el valor digitado por la UART es almacenada
 *   en la variable local UartRead y se inicializa la interrupción.
 */
UARTRead_t UART_Read(){
UARTRead_t UartRead;
	if (rx_data_ready) {
		rx_data_ready = 0;
	    UartRead.dato=UART_Date;
	    UartRead.estado=true;
		HAL_UART_Receive_IT(&huart2, rx_buffer, BUFFER_SIZE);
		}
	else{
	    UartRead.dato=Null_Int;
	    UartRead.estado=false;
	}
return UartRead;
}


/*UART_Mef():
 * - Se establece una MEF para la confirmación del dato recibido a través de la UART.
 * - La MEF tiene 4 estados:
 *   	* Estado 1 (Write_message_temperature): En este estado se envía un mensaje a través de
 *   	  Uart y se espera la activación de la interrupción para pasar al Estado 2:
 *   	* Estado 2 (read_set_temperature): Se espera el dato de 3 bytes acompañado de un true proporcionado
 *   	  por la función UARTRead(). Se guarda el dato y se pasa al Estado 3.
 *   	* Estado 3 (write_message_confirmation) En este estado se envía un mensaje a través de
 *   	  Uart y se espera la activación de la interrupción para pasar al Estado 4:
 *   	* Estado 4 (read_confirmation_set_temperature) Se espera el dato de 3 bytes acompañado de un true
 *   	  proporcionado por la función UARTRead(). Se evalua si los datos ingresados son los mismos y se
 *   	  retorna el dato acompañado de un True.
 */
UARTRead_t UART_Mef(){
	UARTRead_t temperature_real;
	switch (flag_program){
	case(write_message_temperature):
		HAL_UART_Transmit(&huart2,(uint8_t *)mensaje_lectura_datos, strlen(mensaje_lectura_datos), HAL_MAX_DELAY);
			flag_program=read_set_temperature;
			break;

	case (read_set_temperature):
		set_temperature=UART_Read();
			if(true==set_temperature.estado){
				flag_program=write_message_confirmation;
				    }
			break;

	case (write_message_confirmation):
		HAL_UART_Transmit(&huart2,(uint8_t *)mensaje_confirmacion_datos, strlen(mensaje_confirmacion_datos), HAL_MAX_DELAY);
	flag_program=read_confirmation_set_temperature;
	break;

	case (read_confirmation_set_temperature):
			set_temperature_confirmation=UART_Read();
		if (true==set_temperature_confirmation.estado){
			if(set_temperature.dato==set_temperature_confirmation.dato){
				HAL_UART_Transmit(&huart2,(uint8_t *)mensaje_correcto_datos, strlen(mensaje_correcto_datos), HAL_MAX_DELAY);
				temperature_real.dato=set_temperature.dato;
				temperature_real.estado=true;
				return temperature_real;

		}
			else {
				HAL_UART_Transmit(&huart2,(uint8_t *)mensaje_error_datos, strlen(mensaje_error_datos), HAL_MAX_DELAY);
				flag_program=write_message_temperature;
				temperature_real.estado=false;
				}
			}
break;

	default:
		flag_program=write_message_temperature;
		temperature_real.estado=false;
		break;
	}
	return temperature_real;
}


/*void HAL_UART_RxCpltCallback:
 * Función que indica que hubo un ingreso de datos  y lo guarda en una variable static y transmite el
 * valor ingresado por la uart.
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

			UART_Date= atoi((char *)rx_buffer);
		 	HAL_UART_Transmit(&huart2,(uint8_t *)rx_buffer,sizeof(rx_buffer), HAL_MAX_DELAY);
			HAL_UART_Transmit(&huart2,(uint8_t *)interlineado, strlen(interlineado), HAL_MAX_DELAY);
			rx_data_ready = 1;
}



/*UART_Status_button(void)
 * Funcion para re iniciar la MEF.
 */
void UART_Status_button(void){
if (readKey()){
		HAL_UART_Transmit(&huart2,(uint8_t *)mensaje_reseteo_datos, strlen(mensaje_reseteo_datos), HAL_MAX_DELAY);
		flag_program=write_message_temperature;
		set_temperature.estado=false;
		set_temperature_confirmation.estado=false;
		}
}




void MX_USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}

void UARTTrasmit(uint16_t temp_set,uint16_t temp_sensor,bool_t Stat){

	if(Stat==true){
//	HAL_UART_Transmit(&huart2,(uint8_t *)Lectura_Sensor, strlen(Lectura_Sensor), HAL_MAX_DELAY);

	HAL_UART_Transmit(&huart2,(char *)temp_sensor, sizeof(temp_sensor), HAL_MAX_DELAY);
	}
	if(temp_set<temp_sensor){
		HAL_UART_Transmit(&huart2,(uint8_t *)mensaje_alerta_hight, strlen(mensaje_alerta_hight), HAL_MAX_DELAY);
		Emergency();
	}
	}

/*
 * Func
 */
void Emergency(){

HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
HAL_Delay(5000);
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
}
