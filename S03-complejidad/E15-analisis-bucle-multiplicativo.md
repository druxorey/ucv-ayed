<h1 align="center">E15 - Análisis de Complejidad del Bucle Multiplicativo</h1>

> [!TLDR]
> Si $N$ es constante la complejidad es $O(1)$. Si $N$ es la entrada del programa, el bucle se ejecuta $\lceil \log_b N \rceil$ veces, por lo que la complejidad es $O(\log N)$.

## Enunciado

Calcule la complejidad del siguiente algoritmo:

```cpp
int j = 1;
while (j < N) {
    j = j * b;
}
```

Donde b es una constante, dado que:

- a) N también es un valor constante
- b) N es la entrada de datos del programa

## Respuesta

```cpp
int j = 1;
while (j < N) {
    j = j * b;
}
```

Donde $b > 1$ es una constante entera. El valor de $j$ en cada iteración del bucle se calcula como una potencia de la base multiplicativa $b$:

- Iteración 0: $j = 1$
- Iteración 1: $j = b$
- Iteración 2: $j = b^2$
- Iteración 3: $j = b^3$
- ...
- Iteración $k$: $j = b^k$

El bucle termina cuando la condición de permanencia $j < N$ se vuelve falsa, es decir:

$$b^k \ge N$$

Aplicando logaritmo en base $b$ en ambos lados:

$$\log_b(b^k) \ge \log_b(N) \implies k \ge \log_b(N)$$

El número de iteraciones requeridas para terminar el bucle es $k = \lceil \log_b(N) \rceil$.

### **Caso a) $N$ es también un valor constante**

- **Análisis:** Si $N$ es una constante del programa (por ejemplo, definido como `#define N 1000` o `const int N = 1000`), el valor $\log_b(N)$ es un número fijo que no cambia bajo ninguna circunstancia durante la ejecución.

- El número de operaciones de multiplicación es siempre el mismo e independiente de cualquier entrada dinámica del usuario.

- **Complejidad:** $$T(N) = O(1) \quad (\text{Tiempo Constante})$$

### **Caso b) $N$ es la entrada de datos del programa**

- **Análisis:** Si $N$ es el parámetro de entrada variable que el usuario ingresa, la cantidad de iteraciones aumentará conforme el valor de $N$ crezca.

- El crecimiento de la cantidad de operaciones asintóticas sigue una curva logarítmica.

- **Complejidad:** $$T(N) = O(\log N) \quad (\text{Tiempo Logarítmico})$$
