*Este proyecto ha sido creado como parte del currículo de 42 por mjabalqu.*

# Codexion

## Descripción
**Codexion** es un proyecto de programación concurrente desarrollado en C que simula un entorno de trabajo colaborativo. En esta simulación, un grupo de programadores se sienta en una mesa circular y compite por un número limitado de recursos compartidos: los **dongles USB**.

El objetivo principal es orquestar múltiples hilos de ejecución (programadores) y sincronizar su acceso a los recursos mediante primitivas de **POSIX threads**, evitando problemas clásicos de la computación paralela como interbloqueos (deadlocks), inanición (starvation) y carreras de datos (race conditions).

## Instrucciones de Uso

### Compilación
El proyecto incluye un `Makefile` compatible con la Norma de 42. Para compilar el programa ejecutable:

```bash
make
```

### Ejecución
El programa recibe 8 argumentos obligatorios:
```bash
./codexion [number_of_coders] [time_to_burnout] [time_to_compile] [time_to_debug] [time_to_refactor] [number_of_compiles_required] [dongle_cooldown] [scheduler]
```

**Ejemplo:**
```bash
./codexion 5 800 200 200 200 10 10 fifo
```

*   `number_of_coders`: Número de programadores y dongles.
*   `time_to_burnout`: Tiempo (ms) que un programador puede estar sin empezar a compilar antes de agotarse.
*   `time_to_compile`: Tiempo (ms) que dura la compilación (requiere 2 dongles).
*   `time_to_debug`: Tiempo (ms) dedicado a la depuración.
*   `time_to_refactor`: Tiempo (ms) dedicado a la refactorización.
*   `number_of_compiles_required`: (Opcional) Número de veces que cada uno debe compilar para finalizar la simulación.
*   `dongle_cooldown`: Tiempo (ms) de enfriamiento de un dongle tras ser liberado.
*   `scheduler`: Política de arbitraje (`fifo` o `edf`).

## Recursos
Para el desarrollo de este proyecto se han utilizado:
- **Hilos (pthreads):** Para representar a cada programador y al monitor de salud.
- **Mutexes:** Para la protección de recursos compartidos (dongles) y la serialización de la salida por terminal.
- **Variables de Condición:** Para gestionar la cola de espera de forma eficiente sin espera activa (*busy-waiting*).
- **Cola de Prioridad (Min-Heap):** Implementación manual para el soporte de planificadores FIFO y EDF.

## Blocking cases handled

### Prevención de Interbloqueos (Deadlocks)
- **Orden de Recursos:** Se ha implementado una jerarquía en la adquisición de dongles para evitar esperas circulares.
- **Caso N=1:** El sistema detecta automáticamente cuando solo hay un programador. En este escenario, el programador toma el único dongle disponible y, al no poder adquirir el segundo necesario para compilar, espera pacíficamente hasta el agotamiento, evitando intentar bloquear dos veces el mismo mutex.

### Prevención de Inanición (Starvation)
- El uso de una **Cola de Prioridad** garantiza que las solicitudes se atiendan de forma justa según el scheduler elegido. Ningún programador queda relegado indefinidamente, ya que su prioridad (tiempo de llegada en FIFO o fecha límite en EDF) le asegura un turno de acceso a los dongles.

### Gestión del Cooldown
- Cada dongle posee un sello de tiempo de último uso. Los programadores verifican este tiempo antes de intentar tomar el recurso, asegurando que se respete el periodo de enfriamiento indicado por los parámetros de entrada.

### Serialización del Log
- Todas las impresiones por pantalla están protegidas por un **mutex de log global**. Esto garantiza que los mensajes de diferentes hilos no se mezclen en la misma línea y que el log sea legible y cronológicamente coherente.

## Thread synchronization mechanisms

La arquitectura de sincronización de Codexion se basa en tres pilares:

1.  **Protección de Estados (`pthread_mutex_t`):** Cada dongle tiene su propio mutex. Además, cada programador cuenta con un mutex de monitoreo para que el hilo monitor pueda consultar su estado de salud de forma segura (thread-safe).
2.  **Sincronización por Eventos (`pthread_cond_t`):** Los programadores no consultan constantemente si los dongles están libres. En su lugar, se bloquean en una variable de condición y son despertados (`broadcast`) solo cuando un recurso se libera o el estado de la cola cambia.
3.  **Monitor de Salud Separado:** Un hilo independiente supervisa constantemente los tiempos de vida de los programadores. Si detecta un agotamiento, activa una bandera global de fin de simulación y despierta a todos los hilos para una finalización limpia y ordenada de la memoria.
