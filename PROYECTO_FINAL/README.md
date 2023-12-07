El sistema utiliza la interfaz UART para solicitar un valor de temperatura de referencia, el cual se 
compara con la lectura actual del sensor BMP280. El sistema solicita confirmación del valor de temperatura
 antes de realizar cambios. Cuando la lectura del sensor se aproxima al valor de temperatura establecido, 
 el sistema activa un parpadeo en el LED de la placa. En caso de que la lectura del sensor supere el umbral 
 de temperatura, se ejecutará una rutina bloqueante, indicada por la iluminación continua del LED de la placa
durante 5 segundos. Tanto la interacción con la UART, el sensado y el parpadeo del Led trabaja con rutina no bloqueante.
 
Además, el sistema cuenta con un botón de reinicio que permite restablecer el valor de temperatura de referencia,
facilitando así la configuración de nuevos puntos de control térmico.

Autor Royer Sanabria