<h1 align="center">E16 - Complejidad en Tiempo de Varios Fragmentos</h1>

> [!TLDR]
> F1: $O(n)$ (incremento lineal), F2: $O(\log n)$ (multiplicación por 3), F3: $O(n \log n)$ (exterior lineal × interior logarítmico), F4: $O(n^3)$ (tres bucles independientes), F5: $O(n^3)$ (tres bucles dependientes con sumatoria cúbica).

## Enunciado

Calcule la complejidad en tiempo para los siguientes fragmentos de código:

1.
```cpp
int I = 1;
int X = 0;
while (I <= n) {
    x++;
    I += 3;
}
```

2.
```cpp
int I = 1;
int X = 0;
while (I <= n) {
    X += 3;
    I *= 3;
}
```

3.
```cpp
for (int i = 1; i <= n; i++) {
    int j = 1;
    while (j <= i) {
        j *= 2;
        x += 2;
    }
}
```

4.
```cpp
int X = 0;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            X += 2;
        }
    }
}
```

5.
```cpp
int X = 0;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        for (int k = 1; k <= j; k++) {
            X += 2;
        }
    }
}
```


## Análisis de los Fragmentos

### **Fragmento 1**

```cpp
int I = 1;
int X = 0;
while (I <= n) {
    x++;
    I += 3;
}
```

- **Análisis:**
    - La variable de control $I$ se incrementa linealmente sumando una constante: $1, 4, 7, 10, \dots, (3k + 1)$.
    - Termina cuando $3k + 1 > n \implies k \approx \frac{n}{3}$.

- **Complejidad:** $$T(n) = O(n)$$

### **Fragmento 2**

```cpp
int I = 1;
int X = 0;
while (I <= n) {
    X += 3;
    I *= 3;
}
```

- **Análisis:**
    - La variable de control $I$ se multiplica por 3 en cada iteración: $1, 3, 9, 27, \dots, 3^k$.
    - Termina cuando $3^k > n \implies k \approx \log_3 n$.

- **Complejidad:** $$T(n) = O(\log n)$$

### **Fragmento 3**

```cpp
for (int i = 1; i <= n; i++) {
    int j = 1;
    while (j <= i) {
        j *= 2;
        x += 2;
    }
}
```

- **Análisis:**
    - El bucle externo se ejecuta $n$ veces.
    - El bucle interno se ejecuta $\log_2 i$ veces para cada iteración de $i$.
    - La sumatoria total del número de iteraciones es: $$T(n) = \sum_{i=1}^{n} \log_2 i = \log_2(1 \cdot 2 \cdot 3 \cdots n) = \log_2(n!)$$
    - Utilizando la aproximación de Stirling ($\log(n!) \approx n \log n - n \log e$), el término de mayor crecimiento es $n \log n$.

- **Complejidad:** $$T(n) = O(n \log n)$$

### **Fragmento 4**

```cpp
int X = 0;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            X += 2;
        }
    }
}
```

- **Análisis:**
    - Hay 3 bucles anidados independientes, cada uno iterando de $1$ a $n$ linealmente.
    - El número total de operaciones elementales es: $T(n) = n \cdot n \cdot n = n^3$.

- **Complejidad:** $$T(n) = O(n^3)$$

### **Fragmento 5**

```cpp
int X = 0;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        for (int k = 1; k <= j; k++) {
            X += 2;
        }
    }
}
```

- **Análisis:**
    - Hay 3 bucles anidados cuyos límites dependen de la variable del bucle padre:
        - El bucle interno de $k$ se ejecuta $j$ veces.
        - La sumatoria del bucle de $j$ da: $\sum_{j=1}^{i} j = \frac{i(i+1)}{2}$.
        - La sumatoria externa es:

$$T(n) = \sum_{i=1}^{n} \frac{i(i+1)}{2} = \frac{1}{2} \left( \sum_{i=1}^{n} i^2 + \sum_{i=1}^{n} i \right) \approx \frac{1}{2} \left( \frac{n^3}{3} \right) = \frac{n^3}{6}$$

    - El término dominante asintótico es $n^3$.

- **Complejidad:** $$T(n) = O(n^3)$$
