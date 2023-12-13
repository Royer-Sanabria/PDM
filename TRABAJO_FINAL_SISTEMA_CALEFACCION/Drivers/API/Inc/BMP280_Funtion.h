/*
 * BMP280_Funtion.h
 *
 *  Created on: Dec 12, 2023
 *      Author: Royer Sanabria
 */

#ifndef API_INC_BMP280_FUNTION_H_
#define API_INC_BMP280_FUNTION_H_

typedef struct ReadSensor {
    float Temperatura;
    float Presion;
    float altura;
    float Point0;
} ReadSensor;

ReadSensor BMP_280_Read(I2C_HandleTypeDef hi2c1);
void BMP_280_Init2(I2C_HandleTypeDef hi2c1);
ReadSensor BMP_280_ConfigP0(I2C_HandleTypeDef hi2c1);

#endif /* API_INC_BMP280_FUNTION_H_ */
