"""
Resumen del ejercicio "Matrix data analysis" (numpy, pandas, matplotlib)

1. Generación de datos con numpy
--------------------------------
- np.linspace(inicio, fin, n):
    Genera valores ordenados (ej: tiempo). No es aleatorio.
    Ejemplo: 1000 puntos entre 0 y 10.

- np.random.randn(n):
    Genera ruido aleatorio (distribución normal).
    Valores sin patrón → comportamiento caótico.

2. Diferencia clave
-------------------
- linspace → estructura (orden, progresión)
- randn → ruido (aleatoriedad)

3. Construcción de datos realistas
----------------------------------
En análisis de datos es común combinar:

    señal + ruido

Ejemplo:
    y = np.sin(x) + np.random.randn(n) * 0.2

- np.sin(x):
    Genera un patrón tipo onda (comportamiento cíclico).
    Representa la "señal real".

- np.random.randn(...) * 0.2:
    Añade pequeñas variaciones (ruido controlado).

4. Por qué multiplicar el ruido
-------------------------------
- Controla su intensidad (escala).
- 0.2 equivale a dividir entre 5.
- Permite que el patrón (señal) siga siendo visible.

5. Interpretación de variables
------------------------------
- x:
    Eje horizontal (tiempo o índice).
    Siempre ordenado.

- y:
    Valores medidos (actividad).

6. Raw vs Smooth (concepto importante)
--------------------------------------
- raw:
    Datos con mucho ruido (simulan mediciones reales sin procesar).

- smooth:
    Datos con menos ruido (más claros, más interpretables).

Ejemplo:
    y_raw = np.sin(x) + np.random.randn(n)
    y_smooth = np.sin(x) + np.random.randn(n) * 0.2

7. Visualización
----------------
- Una línea → suficiente para el ejercicio.
- Dos líneas → permite comparar (más completo, pero no obligatorio).

8. Sobre el enunciado
---------------------
- No exige múltiples líneas.
- No exige normalización.
- Sí exige:
    * uso de numpy (generar datos)
    * pandas (DataFrame)
    * matplotlib (gráfico)

9. Conclusión
-------------
- El objetivo es simular datos "realistas".
- Datos reales = estructura + ruido.
- Añadir ruido controlado mejora la calidad del análisis.
"""