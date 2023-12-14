Trabajo Práctico final PMD
Autor: Royer Yesid Sanabria Ariza

Descripción del proyecto:Utilizando la fórmula barométrica junto con la presión atmosférica y la 
temperatura obtenidas por el sensor BMP280, se calcula la altura actual. El sistema responde con 
señales luminosas distintivas para notificar al usuario si se encuentra por debajo de la altura 
deseada (parpadeo led placa durante 200 ms), ha alcanzado la altura deseada (LED placa encendido) o ha superado 
dicha altura (parpadeo led placa rápido durante 50 ms). Una vez que el usuario ingresa la altura deseada, 
el sensor se comunica con la placa STMF401RE a través de I2C para transmitir información sobre la
presión atmosférica y la temperatura. A su vez, la placa se comunica con la PC mediante UART, 
proporcionando en todo momento datos como la presión atmosférica, la temperatura, la altura actual
y la altura deseada. 

El sistema tiene la opcion de resetearse y volver a introducir el valor de seteo con el boton de la placa. 

Recursos empleados: 
Sensor BMP280.
Tarjeta STM32F401RE 
PC

Comunicación entre dispositivos: 

PC<--UART-->STM32F401RE
PC<--I2C--> BMP280

Modulos de Software:

- API_debounce
- API_Delay
- API_UART
- BMP280_Funtion
- BMP280
- MEF

Perisfericos utilizados

- GPIO
- UART
- I2C

 

