# FuncMage: Dominando la Programación Funcional en Python

Este repositorio contiene la resolución del Proyecto 10 (Python10) de 42. El objetivo es dominar las herramientas del paradigma funcional para restaurar el orden en el reino digital.

## Estructura del Proyecto

### [ex0: Lambda Sanctum](./ex0/lambda_spells.py)
*   **Enfoque**: Funciones anónimas (`lambda`).
*   **Lección**: Usar `map`, `filter` y `sorted` con lambdas. Aprendimos a usar `TypedDict` para dar seguridad a los diccionarios, aunque finalmente optamos por `dict[str, Any]` para cumplir estrictamente con las firmas del subject sin que `mypy` protestara.

### [ex1: Higher Realm](./ex1/higher_magic.py)
*   **Enfoque**: Funciones de orden superior (H.O.F).
*   **Lección**: Funciones que crean otras funciones. Fue crucial entender el **Contrato de Hechizos** (argumentos `target, power`) para que todas las piezas encajaran. Corregimos el uso de `Callable` importándolo desde `collections.abc` por normativa del PDF.

### [ex2: Memory Depths](./ex2/scope_mysteries.py)
*   **Enfoque**: Ámbito léxico y clausuras (`closures`).
*   **Lección**: Uso de la palabra clave `nonlocal` para mantener estados privados. Aprendimos que el método `.get(key, default)` de los diccionarios es la forma más "Pythonic" de manejar valores faltantes sin que el programa explote.

### [ex3: Ancient Library](./ex3/functools_artifacts.py)
*   **Enfoque**: Módulo `functools`.
*   **Lección**: Reducción de datos (`reduce`), aplicaciones parciales (`partial`), memorización (`lru_cache`) y despacho polimórfico (`singledispatch`). Implementamos un **mapeo de operaciones** con un diccionario para evitar estructuras `if-elif` sucias.
*   [Ver Documentación Detallada (Recursividad y Fibonacci)](./ex3/readme.MD)

### [ex4: Master's Tower](./ex4/decorator_mastery.py)
*   **Enfoque**: Decoradores avanzados.
*   **Lección**: Creación de factorías de decoradores y manejo de argumentos dinámicos (`*args`, `**kwargs`). Resolvimos el problema de encontrar argumentos en diferentes posiciones mediante heurísticas de tipos.
*   [Ver Documentación Detallada](./ex4/readme.MD)

---

## Bitácora de Aprendizaje y Decisiones de Diseño

### Gestión de Git
Tuvimos un incidente de "divergencia" al subir un archivo por la web de GitHub. Aprendimos a usar `git pull --rebase` para sincronizar los historiales local y remoto sin crear commits de mezcla innecesarios y sin perder el trabajo local.

### El Dilema del Tipado
En Python 3.10+, las firmas genéricas como `dict` o `Callable` deben ser explícitas. Aunque el PDF sugería firmas simples, usamos `Any` y firmas completas de `Callable` para que el linter fuera feliz y el código fuera profesional.

### Heurísticas vs Introspección
En el ejercicio de los decoradores, en lugar de usar el módulo `inspect` (muy complejo para una evaluación rápida), decidimos usar una lógica de comprobación de tipos y posiciones. Esto demuestra que entendemos cómo Python empaqueta los argumentos en tuplas (`args`) y diccionarios (`kwargs`).

---
**FuncMage v3.1** - *Mastering the Ancient Arts of Functional Programming*
