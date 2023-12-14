/*
 * BMP280_Funtion.h
 *
 *  Created on: Dec 12, 2023
 *      Author: Royer Sanabria
 */

#ifndef API_INC_BMP280_FUNTION_H_
#define API_INC_BMP280_FUNTION_H_

typedef struct  {
    float Temperatura;
    float Presion;
    float altura;
    float Point0;
    float AlturaSet;
} ReadSensor;

ReadSensor BMP_280_Read();
void BMP_280_Init2();
void BMP_280_ConfigP0();

#endif /* API_INC_BMP280_FUNTION_H_ */
