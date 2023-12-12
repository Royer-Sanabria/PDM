################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/BMP280_Funtion.c \
../Drivers/API/Src/bmp280.c 

OBJS += \
./Drivers/API/Src/BMP280_Funtion.o \
./Drivers/API/Src/bmp280.o 

C_DEPS += \
./Drivers/API/Src/BMP280_Funtion.d \
./Drivers/API/Src/bmp280.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/USUARIO/Desktop/Royer/universidad/PDM1/TRABAJO_FINAL_SISTEMA_CALEFACCION/Drivers/API/Inc" -I"C:/Users/USUARIO/Desktop/Royer/universidad/PDM1/TRABAJO_FINAL_SISTEMA_CALEFACCION/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/BMP280_Funtion.cyclo ./Drivers/API/Src/BMP280_Funtion.d ./Drivers/API/Src/BMP280_Funtion.o ./Drivers/API/Src/BMP280_Funtion.su ./Drivers/API/Src/bmp280.cyclo ./Drivers/API/Src/bmp280.d ./Drivers/API/Src/bmp280.o ./Drivers/API/Src/bmp280.su

.PHONY: clean-Drivers-2f-API-2f-Src

