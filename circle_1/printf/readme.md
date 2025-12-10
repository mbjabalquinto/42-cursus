# ft_printf

_Este proyecto ha sido creado como parte del currículo de 42 por mjabalqu_

Proyecto de la escuela 42 que consiste en recrear la función `printf` de la librería estándar de C.  
El objetivo es profundizar en el manejo de **variadic functions**, formateo de cadenas y gestión de memoria.

## 📌 Descripción

La función `ft_printf` debe comportarse de manera similar a `printf`, aceptando una cadena de formato y un número variable de argumentos.  
Se implementan diferentes especificadores de formato y se garantiza un comportamiento consistente con la versión estándar.

## 🚀 Funcionalidades

- **Caracteres**: `%c`
- **Cadenas**: `%s`
- **Números enteros**: `%d`, `%i`
- **Números sin signo**: `%u`
- **Hexadecimal**: `%x`, `%X`
- **Punteros**: `%p`
- **Porcentaje literal**: `%%`

## 📂 Estructura del proyecto

ft_printf/ <br>
├── Makefile <br>
├── ft_printf.c  <br>
├── ft_printf.h <br>
├── ft_putchar.c <br>
├── ft_putnbr_base.c <br>
├── ft_putnbr.c <br>
├── ft_putstr.c <br>
└── Makefile


Code

## ⚙️ Compilación

Compilar la librería con:
make

Esto generará el archivo libftprintf.a que puede enlazarse en otros proyectos.

🧪 Uso
Ejemplo básico:

c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola %s, el número es %d y en hex es %x\n", "mundo", 42, 42);
    return (0);
}
✅ Normas y requisitos
Cumplir con la Norminette.

No usar funciones prohibidas (ej. printf, malloc fuera de lo permitido).

Gestionar correctamente la memoria.

El código debe ser claro, modular y reutilizable.

🧩 Tests recomendados
Comparar salida con printf estándar.

Probar casos límite: NULL, enteros máximos/mínimos, punteros nulos.

Validar formatos combinados y cadenas largas.

📖 Recursos útiles
Variadic functions en C

Especificadores de formato

Norminette y estilo de código

