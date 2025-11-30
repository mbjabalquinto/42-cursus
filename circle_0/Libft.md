# 📚 Libft - Resumen de Funciones

Este documento sirve como guía rápida de referencia para las funciones de la librería **Libft**. Está dividido en las secciones correspondientes al *Subject* de 42.

> **Nota:** `size_t` es un tipo entero sin signo (generalmente usado para longitudes). `void *` es un puntero genérico.

<details>
<summary><h3>🛠️ Parte 1 - Funciones de la Libft</h2></summary>

Estas funciones replican el comportamiento de las originales de la librería estándar de C (`string.h`, `ctype.h`, `stdlib.h`).

### 🔤 Verificación y Conversión (ctype)

| Función | Descripción Resumida | Parámetros | Retorno |
| :--- | :--- | :--- | :--- |
| `ft_isalpha` | Comprueba si es una letra (A-Z o a-z). | `int c`: carácter a evaluar. | `1` si es letra, `0` si no. |
| `ft_isdigit` | Comprueba si es un dígito (0-9). | `int c`: carácter a evaluar. | `1` si es dígito, `0` si no. |
| `ft_isalnum` | Comprueba si es alfanumérico (letra o dígito). | `int c`: carácter a evaluar. | `1` si es alfanumérico, `0` si no. |
| `ft_isascii` | Comprueba si pertenece a la tabla ASCII (0-127). | `int c`: carácter a evaluar. | `1` si es ASCII, `0` si no. |
| `ft_isprint` | Comprueba si es un carácter imprimible (incluyendo espacio). | `int c`: carácter a evaluar. | `1` si es imprimible, `0` si no. |
| `ft_toupper` | Convierte un carácter a mayúscula si es minúscula. | `int c`: carácter a convertir. | El carácter en mayúscula (o el mismo si no aplica). |
| `ft_tolower` | Convierte un carácter a minúscula si es mayúscula. | `int c`: carácter a convertir. | El carácter en minúscula (o el mismo si no aplica). |

### 🧵 Strings (string.h)

| Función | Descripción Resumida | Parámetros | Retorno |
| :--- | :--- | :--- | :--- |
| `ft_strlen` | Calcula la longitud de una cadena. | `const char *s`: la cadena. | `size_t`: número de caracteres hasta el `\0`. |
| `ft_strlcpy` | Copia strings con seguridad de tamaño (garantiza terminación `\0`). | `dst` (destino), `src` (origen), `size` (tamaño buffer dst). | `size_t`: longitud de la cadena que *intentó* crear (len de `src`). |
| `ft_strlcat` | Concatena strings con seguridad de tamaño. | `dst`, `src`, `size` (tamaño total buffer dst). | `size_t`: len inicial de `dst` + len de `src`. |
| `ft_strchr` | Busca la primera aparición de un carácter en un string. | `const char *s`: string, `int c`: carácter. | Puntero a la primera coincidencia o `NULL`. |
| `ft_strrchr` | Busca la última aparición de un carácter en un string. | `const char *s`: string, `int c`: carácter. | Puntero a la última coincidencia o `NULL`. |
| `ft_strncmp` | Compara dos strings hasta `n` caracteres. | `s1`, `s2`, `size_t n`. | `0` si iguales, diferencia (`s1[i] - s2[i]`) si distintos. |
| `ft_strnstr` | Busca un substring dentro de un string (hasta `len` caracteres). | `big` (donde buscar), `little` (qué buscar), `len`. | Puntero al inicio de `little` dentro de `big` o `NULL`. |
| `ft_strdup` | **(MALLOC)** Duplica un string reservando memoria nueva. | `const char *s1`: string a duplicar. | Puntero al nuevo string duplicado. |
| `ft_atoi` | Convierte un string a un entero (`int`). | `const char *str`: string con el número. | El valor entero convertido. |

### 💾 Memoria (string.h / stdlib.h)

| Función | Descripción Resumida | Parámetros | Retorno |
| :--- | :--- | :--- | :--- |
| `ft_memset` | Rellena un bloque de memoria con un byte constante. | `void *b`: destino, `int c`: byte, `size_t len`: cantidad. | Puntero a `b`. |
| `ft_bzero` | Pone a cero (bytes nulos) un área de memoria. | `void *s`: puntero, `size_t n`: cantidad. | `void` (Nada). |
| `ft_memcpy` | Copia área de memoria (no maneja solapamiento/overlap). | `dst`, `src`, `size_t n`. | Puntero a `dst`. |
| `ft_memmove` | Copia área de memoria (sí maneja solapamiento de forma segura). | `dst`, `src`, `size_t len`. | Puntero a `dst`. |
| `ft_memchr` | Busca un byte específico en un bloque de memoria. | `const void *s`, `int c`, `size_t n`. | Puntero al byte encontrado o `NULL`. |
| `ft_memcmp` | Compara dos bloques de memoria. | `s1`, `s2`, `size_t n`. | `0` si iguales, diferencia del primer byte distinto. |
| `ft_calloc` | **(MALLOC)** Reserva memoria para un array y la inicializa a 0. | `count` (num elementos), `size` (tamaño c/u). | Puntero a la memoria reservada. |

</details>

<details>
<summary><h3>✨ Parte 2 - Funciones Adicionales</h2></summary>

Estas funciones no están en la Libc estándar o tienen una forma distinta. Son utilidades muy potentes para manejar strings y file descriptors.

### ✂️ Manipulación de Strings (con Malloc)

| Función | Descripción Resumida | Parámetros | Retorno |
| :--- | :--- | :--- | :--- |
| `ft_substr` | Crea un substring desde un string original. | `s` (origen), `start` (índice inicio), `len` (longitud máx). | El nuevo substring. |
| `ft_strjoin` | Concatena dos strings en uno nuevo. | `s1` (prefijo), `s2` (sufijo). | El nuevo string (`s1` + `s2`). |
| `ft_strtrim` | Elimina caracteres específicos del principio y final de un string. | `s1` (string), `set` (caracteres a quitar). | El string recortado. |
| `ft_split` | Trocea un string en partes usando un delimitador. | `s` (string), `c` (carácter delimitador). | Array de strings (`char **`) terminado en NULL. |
| `ft_itoa` | Convierte un número entero a string (inverso a `atoi`). | `int n`: el número. | String representando el número. |
| `ft_strmapi` | Aplica una función a cada carácter creando un nuevo string. | `s` (string), `f` (función `(unsigned int, char)`). | El nuevo string modificado. |
| `ft_striteri` | Aplica una función a cada carácter modificando el original. | `s` (string), `f` (función `(unsigned int, char*)`). | `void` (Nada). |

### 📤 File Descriptors (fd)

| Función | Descripción Resumida | Parámetros | Retorno |
| :--- | :--- | :--- | :--- |
| `ft_putchar_fd`| Escribe un carácter en un file descriptor dado. | `char c`, `int fd`. | `void`. |
| `ft_putstr_fd` | Escribe un string en un file descriptor dado. | `char *s`, `int fd`. | `void`. |
| `ft_putendl_fd`| Escribe un string seguido de un salto de línea (`\n`). | `char *s`, `int fd`. | `void`. |
| `ft_putnbr_fd` | Escribe un número entero en un file descriptor dado. | `int n`, `int fd`. | `void`. |

</details>

<details>
<summary><h3>🎁 Parte Bonus - Listas Enlazadas</h2></summary>

Funciones para manipular la estructura `t_list`. Fundamental para aprender estructuras de datos dinámicas.

> **Estructura:**
> ```c
> typedef struct s_list
> {
>     void          *content;
>     struct s_list *next;
> } t_list;
> ```

| Función | Descripción Resumida | Parámetros | Retorno |
| :--- | :--- | :--- | :--- |
| `ft_lstnew` | Crea un nuevo nodo. | `content`: contenido del nodo. | Puntero al nuevo nodo. |
| `ft_lstadd_front`| Añade un nodo al principio de la lista. | `**lst` (dirección puntero cabeza), `*new` (nodo a añadir). | `void`. |
| `ft_lstsize` | Cuenta el número de nodos en la lista. | `*lst`: inicio de la lista. | `int`: tamaño de la lista. |
| `ft_lstlast` | Devuelve el último nodo de la lista. | `*lst`: inicio de la lista. | Puntero al último nodo. |
| `ft_lstadd_back` | Añade un nodo al final de la lista. | `**lst` (dirección puntero cabeza), `*new` (nodo a añadir). | `void`. |
| `ft_lstdelone` | Libera la memoria de UN nodo (usando `del` y `free`). | `*lst` (nodo), `del` (función para borrar contenido). | `void`. |
| `ft_lstclear` | Libera una lista entera y pone el puntero inicial a NULL. | `**lst`, `del`. | `void`. |
| `ft_lstiter` | Aplica una función al contenido de cada nodo. | `*lst` (lista), `f` (función `(void *)`). | `void`. |
| `ft_lstmap` | Crea una **nueva** lista aplicando una función a la original. | `*lst`, `f` (transformar), `del` (borrar si error). | La nueva lista o `NULL` si falla. |

</details>
