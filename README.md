# Mastermind

Mastermind es un juego de lógica deductiva.

El punto es que el código se creo inspirado en seguir la lógica del juego.

La "CPU" genera un código aleatorio, y vos como usuario tiene que tratar de adivinarlo
dentro del numero de intentos.

El código esta escrito en "c", todo contenido dentro de una función principal.

## Librerias importadas:
- **stdio.h**: Para la lectura de datos y la salida estandar de datos, en este caso cuando el usuario procede a la seleccion de los colores del código. 
- **time.h**: Sera utulizada para ajustar la semilla de la funcion que genera el código de manera aleatoria.
- **stdlib.h**: Para tomar la función rand();

## Secciones del código 

La función principal se divide en 3 fragmentos principales:

-  **la generacion del código**
- **El bucle principal**
- **Los resultados**
