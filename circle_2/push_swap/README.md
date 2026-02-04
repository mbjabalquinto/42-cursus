# PUSH_SWAP

*Este proyecto ha sido creado como parte del currículo de 42 Málaga por mjabalqu.* <br><br>
<img width="326" height="279" alt="image" src="https://github.com/user-attachments/assets/8eeffc19-4f12-4106-bdee-dcceb37f0116" />

*Score obtenido: 125/100 (Outstanding Project)*

## 📋 DESCRIPCIÓN

El proyecto **push_swap** es un desafío algorítmico simple y muy efectivo: tienes que ordenar datos. Tienes a tu disposición un conjunto de números enteros, dos pilas (Stacks A y B) y un conjunto de instrucciones para manipular ambas pilas.

¿El objetivo? Escribir un programa en C llamado `push_swap` que calcule y muestre en la salida estándar el programa de instrucciones más pequeño posible que ordena los números enteros recibidos como argumentos.

Este ejercicio busca desarrollar habilidades críticas en:
* **Complejidad Algorítmica:** Entender la diferencia entre $O(n^2)$ y $O(n \log n)$.
* **Estructuras de Datos:** Manejo avanzado de listas doblemente enlazadas y pilas.
* **Optimización:** Búsqueda de la solución más eficiente (menos movimientos).
* **Gestión de Memoria:** Riguroso control de leaks y punteros.

---

## 🛠️ INSTRUCCIONES

### Compilación

El proyecto cuenta con un **Makefile** que gestiona la compilación tanto de la parte obligatoria como del bonus.

Para compilar el programa principal (`push_swap`):
```bash
make
```
Para compilar el verificador (checker), que incluye la validación propia de los movimientos:
```bash
make bonus
```
Ejecución
1. Programa principal: Ejecuta el programa pasando una lista de números como argumentos:
```bash
./push_swap 2 1 3 6 5 8
```
Salida: Lista de movimientos (sa, pb, ra...) necesarios para ordenar la lista.

2. Verificador (Bonus): Puedes usar el pipe | para verificar si la salida de tu programa ordena correctamente la lista:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
Salida: OK (si está ordenado) o KO (si falla).

## 📚 RECURSOS Y APRENDIZAJE
Para completar este proyecto con la máxima puntuación, he profundizado en:

Algoritmos de ordenación: Quick Sort, Radix Sort y algoritmos Greedy basados en costes.

Listas doblemente enlazadas: Implementación de estructuras t_stack_node para navegar en ambas direcciones.

Precedencia de operadores en C: Vital para manejar punteros dobles correctamente (ej: (*stack)->nbr).

Arquitectura de Software: Diseño modular donde el Mandatory y el Bonus comparten la lógica de movimientos (swap.c, push.c, etc.) mediante una librería común, evitando duplicidad de código.

## 🧠 ALGORITMO SELECCIONADO (Turk Algorithm)
He implementado un algoritmo Greedy basado en costes mecánicos (conocido popularmente en 42 como "The Turk").

Créditos para A. Yigit Ogun: https://medium.com/@ayogun/push-swap-c1f5d2d41e97

A diferencia de Radix (que trabaja con bits) o QuickSort puro, este algoritmo calcula en cada paso cuál es el nodo más "barato" de mover de una pila a la otra para que quede en su posición correcta.

Lógica del Algoritmo:
Push a B: Enviamos nodos de A a B (excepto 3) manteniéndolos parcialmente ordenados de forma descendente o buscando "target nodes" simples.

Cálculo de Costes: Para cada nodo en A (o B), calculamos cuántos movimientos (ra, rb, rr, rra, etc.) cuesta ponerlo encima de su "Target" en la otra pila.

Movimiento Óptimo: Seleccionamos el nodo con el coste total más bajo y ejecutamos los movimientos (optimizando rotaciones dobles rr o rrr).

Retorno a A: Una vez todo está en B (ordenado), devolvemos a A ajustando la posición.

Ajuste Final: Rotamos A hasta que el número menor esté en la cima.

Esquema del Algoritmo:
```bash
       [ INICIO: STACK A LLENO ]
                 |
                 v
      [ PRE-SORTING / PUSH A STACK B ]
(Dejamos solo 3 nodos en A, el resto a B)
                 |
                 v
       [ ORDENAR LOS 3 DE STACK A ]
                 |
                 v
   +---> [ CALCULAR TARGETS Y COSTES ] <---+
   | (Para cada nodo en B, ¿dónde va en A?)|
   |             |                         |
   |             v                         |
   |    [ SELECCIONAR NODO MÁS BARATO ]    |
   |             |                         |
   |             v                         |
   |    [ EJECUTAR MOVIMIENTOS ]           |
   |   (Usar rr/rrr para optimizar)        |
   |             |                         |
   |             v                         |
   |         [ PUSH PA (B -> A) ]          |
   |             |                         |
   |             v                         |
   +------ ¿QUEDA ALGO EN B? (NO/SÍ) ------+
                 |
                 v
         [ ROTACIÓN FINAL EN A ]
   (Poner el número menor al principio)
                 |
                 v
            [ FIN: ORDENADO ]
```
### Justificación:
La elección de este algoritmo se justifica porque:

Eficiencia: Consigue ordenar 100 números en menos de 600 movimientos y 500 números en menos de 5000 (rango de 5 estrellas).

Adaptabilidad: Funciona bien tanto con listas pequeñas como grandes.

Lógica Real: No depende de trucos binarios, sino de cálculo de costes reales de operación.

## 💎 BONUS: EL CHECKER
Para la parte del bonus, en lugar de copiar y pegar código, diseñé una arquitectura de archivos compartidos.

El checker utiliza las mismas funciones de movimiento (pa, ra, etc.) que el programa principal.

Se implementó un "interruptor" (flag booleano/entero) en las funciones de movimiento para silenciar la salida (print = 0) cuando las ejecuta el checker, y mostrarla (print = 1) cuando lo hace el push_swap.

Incluye una versión robusta de get_next_line para leer las instrucciones.

Gestiona errores de entrada (no numéricos, duplicados) y verifica estrictamente que Stack A esté ordenado Y Stack B esté vacío.

Ejemplo de main (simplificado):
```bash
C
int main(int argc, char **argv)
{
    // 1. Inicialización y Parsing
    init_stack(&stack_a, argv + 1);

    // 2. Lectura de instrucciones (GNL)
    while ((line = get_next_line(0)))
    {
        // Ejecuta movimiento en silencio (0)
        if (!exec_instruction(line, &stack_a, &stack_b)) 
            error_exit();
        free(line);
    }

    // 3. Verificación Final
    if (stack_sorted(stack_a) && !stack_b)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
        
    // 4. Limpieza de memoria
    free_all(stack_a, stack_b);
    return (0);
}
```
