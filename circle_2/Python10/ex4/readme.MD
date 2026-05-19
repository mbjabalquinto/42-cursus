# Ejercicio 04: Master's Tower (Decoradores Avanzados)

Este último nivel del proyecto explora la creación de decoradores sofisticados, incluyendo factorías de decoradores (decoradores con parámetros) y su integración con clases.

## Conceptos Clave y Lecciones Aprendidas

### 1. Factorías de Decoradores (Los 3 Niveles)
Cuando un decorador necesita recibir parámetros (como `min_power` o `max_attempts`), ya no basta con dos funciones. Necesitamos una estructura de **tres niveles**:
1.  **Nivel 1 (Factoría)**: Recibe los parámetros de configuración.
2.  **Nivel 2 (Decorador)**: Recibe la función original (`func`).
3.  **Nivel 3 (Wrapper)**: Es la función que realmente se ejecuta en lugar de la original y recibe los argumentos (`*args`, `**kwargs`).

### 2. El Desafío del Primer Argumento (`self`)
Uno de los puntos donde más dudamos fue cómo encontrar el argumento `power`. El subject decía que era el primero, pero en la clase `MageGuild` era el tercero (después de `self` y `spell_name`).
*   **Decisión Técnica**: En lugar de usar el módulo `inspect` (que era complejo de defender), aplicamos una **heurística inteligente**:
    *   Buscamos primero en `kwargs` por el nombre `"power"`.
    *   Si no está, miramos si el primer argumento es un entero (`args[0]`).
    *   Si hay muchos argumentos (caso de la clase), miramos en `args[2]`.
Esta solución es robusta y fácil de explicar en la evaluación.

### 3. Gestión de Errores con `retry_spell`
Aprendimos que para que un decorador pueda reintentar una acción, la función original debe **lanzar una excepción** (`raise Exception`).
*   **Lógica de Reintentos**: Usamos un bucle `for` y un bloque `try-except`. Si el intento falla, el `except` captura el error y decide si volver a intentar o devolver el mensaje final de fallo.
*   **Concatenación de Strings**: Recordamos que para que `flake8` no se queje por líneas largas, debemos usar paréntesis `( ... )` al unir strings multilínea, asegurando que Python no ignore la segunda parte del mensaje.

### 4. Métodos Estáticos (`@staticmethod`)
Implementamos `validate_mage_name` usando esta técnica, lo que permite llamar a la función sin necesidad de instanciar la clase, manteniendo la lógica organizada dentro del contexto de `MageGuild`.

---

## Preguntas de Reflexión

### ¿Cómo permiten los decoradores la separación de intereses?
Permiten añadir funcionalidades (como tiempo, validación o reintentos) sin modificar el código interno de la función original. Esto mantiene las funciones "puras" y enfocadas en su tarea principal, delegando la lógica de control a los decoradores.

### ¿Cuál es la diferencia entre `@staticmethod` y métodos de instancia?
*   **Método de Instancia**: Recibe `self` y puede acceder/modificar el estado del objeto.
*   **`@staticmethod`**: No recibe `self` ni `cls`. Es básicamente una función normal que vive dentro de la clase por organización lógica.
