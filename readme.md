# 📝 Printf

## Descripción 

Este proyecto consiste en replicar el funcionamiento de la función original de printf. 
Se deben implementar solo las siguientes conversiones:

| Conversión  | Descripción														 			|
|-------|-----------------------------------------------------------------------------------|
| **%c** | Imprime un solo carácter.       													|
| **%s** | Imprime una string (como se define por defecto en C).											|
| **%p** | El puntero void * dado como argumento se imprime en formato hexadecimal.								|
| **%d** | Imprime un número decimal (base 10).																	|
| **%i** | Imprime un entero en base 10.               											|
| **%u** | Imprime un número decimal (base 10) sin signo.               									|
| **%x** | Imprime un número hexadecimal (base 16) en minúsculas.                				|
| **%X** | Imprime un número hexadecimal (base 16) en mayúsculas.                				|
| **%%** | Imprime el símbolo del porcentaje.                 											|

◦ La función printf retorna el número de caracteres impresos, o un valor negativo si ocurre un error.
◦ No se debe implementar la gestión del buffer del original.

## Funciones autorizadas 

| Función  | Descripción														 			|
|-------|-----------------------------------------------------------------------------------|
| malloc | Solicitar un bloque de memoria del tamaño suministrado como parámetro.     													|
| free | Desasigna un bloque de memoria que se había asignado previamente mediante una llamada. 											|
| write | Hace que los bytes que indiques del buffer sean escritos en el file descriptor seleccionado.								|
| va_start | Permite el acceso a los argumentos de la función variada.														|
| va_arg | Accede al siguiente argumento de la función variada.               											|
| va_copy | Hace una copia de los argumentos de la función variádica.               									|
| va_end | Finaliza el recorrido de los argumentos de la función variada.                				|