################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_Delay.c \
../Drivers/API/Src/API_Uart.c \
../Drivers/API/Src/API_debounce.c \
../Drivers/API/Src/BMP280.c 

OBJS += \
./Drivers/API/Src/API_Delay.o \
./Drivers/API/Src/API_Uart.o \
./Drivers/API/Src/API_debounce.o \
./Drivers/API/Src/BMP280.o 

C_DEPS += \
./Drivers/API/Src/API_Delay.d \
./Drivers/API/Src/API_Uart.d \
./Drivers/API/Src/API_debounce.d \
./Drivers/API/Src/BMP280.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/USUARIO/Desktop/PDM/PDM/PROYECTO_FINAL/Drivers/API" -I"C:/Users/USUARIO/Desktop/PDM/PDM/PROYECTO_FINAL/Drivers/API/Inc" -I"C:/Users/USUARIO/Desktop/PDM/PDM/PROYECTO_FINAL/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_Delay.cyclo ./Drivers/API/Src/API_Delay.d ./Drivers/API/Src/API_Delay.o ./Drivers/API/Src/API_Delay.su ./Drivers/API/Src/API_Uart.cyclo ./Drivers/API/Src/API_Uart.d ./Drivers/API/Src/API_Uart.o ./Drivers/API/Src/API_Uart.su ./Drivers/API/Src/API_debounce.cyclo ./Drivers/API/Src/API_debounce.d ./Drivers/API/Src/API_debounce.o ./Drivers/API/Src/API_debounce.su ./Drivers/API/Src/BMP280.cyclo ./Drivers/API/Src/BMP280.d ./Drivers/API/Src/BMP280.o ./Drivers/API/Src/BMP280.su

.PHONY: clean-Drivers-2f-API-2f-Src

