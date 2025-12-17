*Este proyecto ha sido creado como parte del currículo de 42 por mjabalqu*

# get next line

# DESCRIPCIÓN
El proyecto get_next_line tiene como objetivo implementar una función en C capaz de leer una línea completa desde un descriptor de archivo, independientemente de su longitud. 
La función debe devolver la línea leída cada vez que se invoque, gestionando correctamente la memoria y permitiendo múltiples llamadas consecutivas hasta alcanzar el final del archivo. 

Este ejercicio busca desarrollar habilidades en:
- Manejo de memoria dinámica.
- Uso de la función read().
- Gestión de buffers y concatenación de cadenas.
- Robustez frente a distintos valores de BUFFER_SIZE.

## Instrucciones

### Compilación
Para compilar el proyecto, utiliza el siguiente comando en la raíz del repositorio especificando el tamañode buffer deseado. Si no se especifica, por defecto tomará el valor 42:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o gnl

### Ejecución
Ejecuta el programa indicando el archivo que deseas leer:

./gnl archivo.txt

Puedes variar el valor de BUFFER_SIZE en la compilación para comprobar el comportamiento de la función:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 ...
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 ...

## Recursos
Documentación oficial de read().

Tutoriales de gestión de memoria dinámica en C.

Artículos sobre buffers y manejo de cadenas en C.

Peer to peer.

Artículos sobre variables constantes.

Uso de I.A. como apoyo para lograr comprimir alguna función por debajo de 25 líneas para poder cumplir con la norma. Ejemplo: me ha enseñado a hacer un return usando el operador ",": return(free(variable), NULL); Este return ejecuta el primer parámetro pero ignora el resultado y ejecuta el segundo parámetro. Cosigues ahorrar una línea.

Uso de Francinette y valgrind para test adicionales y comprobación de leaks de memoria.


## Algoritmo seleccionado

He empleado un buffer con un tamaño definido en la librería pero que también se puede definir en la compliación, y un array de punteros a char de tipo constante para almacenar lo que sobra de lo leído del fichero una vez se ha extraído la línea, cosa que sucede cuando se encuentra un salto de línea. Una vez encontrado se extrae la línea, se guarda lo leído de más y se devuelve la línea.

He usado el mismo para la parte de bonus ya que es el mismo ejercicio pero con el array de punteros a char se pueden manejar todas las llamadas con los disintos ficheros hasta un máximo definido de 1024.

### Esquema del algoritmo:
```
       [ INICIO ]
           |
           v
   [ BUSCO EN BACKUP ] <-----------------------+
           |                                   |
      ¿Hay '\n'?                               |
     /          \                              |
   NO            SÍ                            |
   |              |                            |
   v              v                            |
[ LEO FICHERO ] [ EXTRAER LÍNEA ]              |
   |              |                            |
 ¿EOF?            v                            |
 /   \          [ DEVOLVER LÍNEA ]             |
SÍ    NO                    |                  |
|      \                    |                  |
|       `---- [ GUARDO EN BACKUP ] ------------+
|			    			|	
v			    			|
¿Queda algo en Backup?      |
   /            \	    	|
  SÍ             NO	    	|	
  |              |	    	|	
  v              v	    	|
[ LO DEVUELVO ] [ NULL ]    |	
  \              /	    	|	
   \            /	    	|
    v          v	    	|	
      ( FIN ) <-------------+
```
### Descripción del proceso: 
Primero comprobamos si tenemos algo en la variable constante, si hay algo buscamos el salto de línea. Si lo encontramos entonces extrameos la línea, guardamos lo que sobra en la constante y devolvemos la línea. Si no tenemos nada entonces es cuando leemos del fichero al buffer y a continuación guardamos el contenido del buffer en la constante. A continuación buscamos el salto de línea en la constante. Si lo encontramos repetimos el proceso anterior para devolver la línea. Si no lo encontramos volvemos a comprobar y a leer del fichero hasta que lleguemos a EOF. Cuando obtenemos EOF entonces devolvemos el contenido de la constante.

El algoritmo garantiza que funciona con cualquier tamaño de BUFFER_SIZE, desde 1 hasta valores muy grandes, siempre que el sistema disponga de memoria suficiente.

La elección de este algoritmo se justifica porque:

Permite manejar líneas de longitud arbitraria.

Es eficiente en memoria, ya que solo guarda lo necesario.

Se adapta a distintos entornos y valores de BUFFER_SIZE.

### Ejemplo de uso
Archivo texto.txt:

Hola mundo
42 Málaga

Ejecución:

./gnl texto.txt
Salida:

Hola mundo
42 Málaga

### Ejemplo de main:

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("prueba.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}

