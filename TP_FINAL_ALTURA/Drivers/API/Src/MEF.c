/*
 * MEF.c
 *
 *  Created on: Dec 14, 2023
 *      Author: Royer Sanabria
 */
#include "main.h"
#include "BMP280_Funtion.h"
#include "API_Delay.h"
#include "API_UART.h"
#include "MEF.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Tolerancia 10 // tolerancia 10%
#define rango 2 // limites inferior y superior de alarmas

static enum EstadoMef FlagMEF=Inicio;
static char mensaje;
static uint8_t Set_Altura;
delay_t MyDelay;
static float Limites[]={0.85, 1.20};
extern UART_HandleTypeDef huart2;
extern I2C_HandleTypeDef hi2c1;


void MEF(){
	ReadSensor Dato;
	switch (FlagMEF){

	case Inicio:
char mensaje[]="Indique la altura de seteo: \r\n";
UART_TrasmitMessage(mensaje);
FlagMEF=Altura_Seteo;
break;

	case Altura_Seteo:
		UARTRead_t AlturaSeteo=UART_Read();
		if(AlturaSeteo.estado){
		    BMP_280_ConfigP0(hi2c1);
		    BMP_280_SetPoint(AlturaSeteo.dato);
		     Dato= BMP_280_Read();
		    UART_TrasmitSensor(Dato);
		    FlagMEF=Control_Alerta;
		}
		break;

	case Control_Alerta:
		FlagMEF=ControlAlerta();
		break;

	case Alerta_Abajo:
	     Dato= BMP_280_Read();
	    UART_TrasmitSensor(Dato);
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		HAL_Delay(500);
		FlagMEF= Control_Alerta;
		break;

	case Altura_Alcanzada:
	     Dato= BMP_280_Read();
	    UART_TrasmitSensor(Dato);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
		FlagMEF= Control_Alerta;
		break;

	case Alerta_Arriba:
	     Dato= BMP_280_Read();
	    UART_TrasmitSensor(Dato);
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		HAL_Delay(100);
		FlagMEF= Control_Alerta;
		break;
	default:
	FlagMEF=Inicio;
	}
}

EstadoAlerta_t ControlAlerta(){
	enum EstadoMef Control;
	ReadSensor Dat=BMP_280_Read();
if (Dat.AlturaSet/Dat.altura<Limites[0]){
	Control=Alerta_Abajo;
	}
else if(Dat.AlturaSet/Dat.altura>Limites[0] && Dat.AlturaSet/Dat.altura>Limites[1] ) {
	Control=Altura_Alcanzada;
}
else {
	Control=Alerta_Arriba;
}
return Control;
}
