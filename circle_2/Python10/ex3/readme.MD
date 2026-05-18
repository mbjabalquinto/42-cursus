## Esquema función recursiva fibonacci:
```mermaid
graph TD
%% Definición de estilos para los colores
classDef basecase fill:#e1f5fe,stroke:#01579b,stroke-width:2px,color:#333;
classDef cachehit fill:#e8f5e9,stroke:#1b5e20,stroke-width:2px,color:#333;
classDef normalcall fill:#fff,stroke:#333,stroke-width:1px,color:#333;

%% --- Título/Ecuación principal ---
A("
return <code>fib(n-1) + fib(n-2)</code> => 5
"):::normalcall

%% --- Estructura del árbol replicando la pizarra ---

%% Nivel superior
EqTop("
<code><b>fib(4)</b> + fib(3)</code>
<br/>Sum: 3 + 2 = <b>5</b>
"):::normalcall
A --> EqTop

%% Rama izquierda (Recursividad bajando)
Eq4("
<code><b>fib(3)</b> + fib(2)</code>
<br/>Sum: 2 + 1 = <b>3</b>
"):::normalcall
EqTop -->|Llamada| Eq4

Eq3("
<code><b>fib(2)</b> + fib(1)</code>
<br/>Sum: 1 + 1 = <b>2</b>
"):::normalcall
Eq4 -->|Llamada| Eq3

Eq2("
<code>fib(1) + fib(0)</code>
<br/>Sum: 1 + 0 = <b>1</b>
"):::normalcall
Eq3 -->|Llamada| Eq2

%% Casos base (Hojas finales)
BC_Eq2_L("
<b>Caso base:</b>
<br/>return 1
"):::basecase
BC_Eq2_R("
<b>Caso base:</b>
<br/>return 0
"):::basecase
Eq2 -->|izq| BC_Eq2_L
Eq2 -->|der| BC_Eq2_R

%% El fib(1) a la derecha de fib(3)
BC_Eq3_R("
<b>Caso base:</b>
<br/>return 1
"):::basecase
Eq3 -->|der| BC_Eq3_R

%% --- El poder del Caché (Ramas no expandidas) ---

%% fib(2) a la derecha de fib(4)
Cache_fib2("
<code><b>fib(2)</b></code>
<br/><b>CACHÉ HIT!</b>
<br/>Result: 1
"):::cachehit
Eq4 -.->|Recuperado| Cache_fib2

%% fib(3) a la derecha de fib(5)
Cache_fib3("
<code><b>fib(3)</b></code>
<br/><b>CACHÉ HIT!</b>
<br/>Result: 2
"):::cachehit
EqTop -.->|Recuperado| Cache_fib3
```
## Esquema en formato ASCII:
```text
Llamada inicial: fib(5)
│
├── [Baja por la izquierda]
│   fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1) ---> (Caso base: retorna 1)
│   │   │   └── fib(0) ---> (Caso base: retorna 0)
│   │   │
│   │   └── fib(1) ---> [¡CACHÉ HIT! Recupera 1 instantáneamente]
│   │
│   └── fib(2) -------> [¡CACHÉ HIT! Recupera 1 instantáneamente]
│
└── [Sube y mira a la derecha]
    fib(3) -----------> [¡CACHÉ HIT! Recupera 2 instantáneamente]


* Resultado final: 5
```
## Esquema original en pizarra:
![Mi pizarra de Fibonacci](./images/pizarra.jpeg)
