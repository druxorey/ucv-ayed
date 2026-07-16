<h1 align="center">E10 - Análisis de Fragmentos de Código</h1>

> [!TLDR]
> F1: $O(n^3)$, F2: $O(\log n)$, F3 y F4 son **bucles infinitos** por errores de incremento cruzado, F5: $O(\log n)$ porque el bucle externo se ejecuta a lo sumo 2 veces.

## Enunciado

Analice el tiempo de ejecución T(n) de los siguientes fragmentos de programa y calcule su orden de complejidad:

1.
```cpp
int sum = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n*n; j++) {
        sum = sum + 1;
    }
}
```

2.
```cpp
int i = 1;
int x = 0;
while (i <= n) {
    x = x + 3;
    i = i * 2;
}
```

3.
```cpp
int x = 0;
for (int i = 0; i < n; n++) {
    for (int j = 0; j < i*i; i++) {
        for (int k = 0; k < j; j++) {
            x = x + 2;
        }
    }
}
```

4.
```cpp
int sum = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; i++) {
        sum = sum + 1;
    }
}
```

5.
```cpp
int i = 1;
int x = 0;
do {
    int j = 1;
    while (j <= n) {
        x = x + 1;
        j = j * 2;
    }
    i = i + 1;
} while (i == n);
```

## Análisis de los Fragmentos

### Fragmento 1

```cpp
int sum = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n*n; j++) {
        sum = sum + 1;
    }
}
```

- **Análisis:**
    - El bucle externo se ejecuta exactamente $n$ veces.
    - El bucle interno se ejecuta $n^2$ veces por cada iteración del bucle externo.
    - La operación interna de suma es elemental y constante ($O(1)$).
    - Número total de sumas: $T(n) = n \cdot n^2 = n^3$.

- **Complejidad:** $$T(n) = O(n^3)$$

### Fragmento 2

```cpp
int i = 1;
int x = 0;
while (i <= n) {
    x = x + 3;
    i = i * 2;
}
```

- **Análisis:**
    - La variable de control $i$ se duplica en cada iteración: $1, 2, 4, 8, \dots, 2^k$.
    - El ciclo se detiene cuando $i > n$, es decir, cuando $2^k > n$.
    - Despejando el número de iteraciones $k$: $k \approx \log_2 n$.

- **Complejidad:** $$T(n) = O(\log n)$$

### Fragmento 3

```cpp
int x = 0;
for (int i = 0; i < n; n++) {
    for (int j = 0; j < i*i; i++) {
        for (int k = 0; k < j; j++) {
            x = x + 2;
        }
    }
}
```

- **Análisis:**
    - **Bucle Externo:** La condición de actualización es `n++` en lugar de `i++`. Dado que se incrementa el límite `n` en cada paso, la variable `i` jamás alcanzará a `n` (asumiendo $n > 0$).
    - **Bucle Intermedio:** La condición de actualización es `i++` en lugar de `j++`. Al incrementar `i` en lugar del contador `j`, la cota `i*i` crece mucho más rápido en cada paso, impidiendo que `j` la alcance.
    - **Conclusión:** Este fragmento de código contiene múltiples bugs de incremento cruzado que causan un **bucle infinito divergente**. No termina en tiempo finito.

- **Complejidad:** $$T(n) = \text{Divergente} \quad (\infty)$$

### Fragmento 4

```cpp
int sum = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; i++) {
        sum = sum + 1;
    }
}
```

- **Análisis:**
    - **Bucle Interno:** La condición de actualización es `i++` en lugar de `j++`. La variable `j` permanece en $0$, mientras que `i` se incrementa infinitamente en el bucle interno, haciendo que la condición de entrada `j < i` se mantenga siempre verdadera.
    - **Conclusión:** Provoca un **bucle infinito**.

- **Complejidad:** $$T(n) = \text{Divergente} \quad (\infty)$$

### **Fragmento 5**

```cpp
int i = 1;
int x = 0;
do {
    int j = 1;
    while (j <= n) {
        x = x + 1;
        j = j * 2;
    }
    i = i + 1;
} while (i == n);
```

- **Análisis:**
    - **Bucle Interno:** `while (j <= n)` multiplica `j` por 2 en cada paso, ejecutándose $O(\log n)$ veces.
    - **Bucle Externo:** Se ejecuta de la siguiente forma:
        - **Iteración 1:** `i = 1`. Al final, `i` se incrementa a 2. La condición de permanencia es `i == n`.
        - Si $n = 2$, la condición `2 == 2` es verdadera, por lo que entra a la **Iteración 2**. Al final de la segunda iteración, `i` se incrementa a 3. La condición `3 == 2` es falsa y el bucle termina (se ejecutó 2 veces).
        - Si $n \neq 2$, la condición `2 == n` es falsa y el bucle termina inmediatamente tras **1 iteración**.
    - Por lo tanto, el bucle externo se ejecuta a lo sumo un número constante de veces (1 o 2).

- **Complejidad:** $$T(n) = \text{constante} \cdot O(\log n) = O(\log n)$$
