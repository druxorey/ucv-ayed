<h1 align="center">E13 - Análisis y Optimización del Algoritmo alfa</h1>

> [!TLDR]
> El algoritmo original es $O(2^N)$ por su bucle de $2^N$ iteraciones. Se optimiza a $O(1)$ calculando los valores finales de $X$, $Y$ y $Z$ mediante **fórmulas de sumatoria cerradas**.

## Enunciado

Dado el siguiente algoritmo:

```cpp
void alfa() {
    int N, X, Y, Z, M;
    X = 0; Y = 0; Z = 0;
    cin >> N;
    M = pow(2, N);
    for (int I = 1; I < M; I++) {
        Z = (4 * I) + 8 + Z;
        Y = Y + (2 * I);
        X = X + 1;
    }
}
```

- a) Calcule la función T(n) del algoritmo e indique su orden de complejidad en tiempo.
- b) Reescriba este algoritmo para que su orden de complejidad sea de $O(1)$. Recuerde que el nuevo algoritmo debe tener los mismos resultados que el original.

## **Parte a) Cálculo de T(n) y Orden de Complejidad**

```cpp
void alfa() {
    int N, X, Y, Z, M;
    X = 0; Y = 0; Z = 0;
    cin >> N;
    M = pow(2, N);
    for (int I = 1; I < M; I++) {
        Z = (4 * I) + 8 + Z;
        Y = Y + (2 * I);
        X = X + 1;
    }
}
```

1. **Cálculo de M:** La variable $M$ toma el valor $2^N$.
2. **Iteraciones del Bucle:** El bucle `for` se ejecuta desde $I = 1$ hasta $M - 1$ con incrementos unitarios. El número total de iteraciones es:

$$\text{Iteraciones} = M - 1 = 2^N - 1$$

3. **Operaciones en el Bucle:** Cada iteración ejecuta tres operaciones aritméticas elementales de asignación y suma, las cuales toman tiempo constante $O(1)$.

Por tanto, el tiempo de ejecución $T(N)$ es proporcional al número de iteraciones:

$$T(N) = c \cdot (2^N - 1) = O(2^N)$$

La complejidad temporal del algoritmo original es **exponencial**: $O(2^N)$.

## **Parte b) Rediseño en Tiempo Constante $O(1)$**

Para eliminar el bucle, podemos modelar los valores finales de las variables acumuladoras $X$, $Y$ y $Z$ mediante fórmulas matemáticas cerradas de sumatoria:

### 1. Valor final de $X$:

En cada iteración $X$ se incrementa en $1$. Al iniciar en $0$, su valor final es exactamente el número total de iteraciones:

$$X = \sum_{I=1}^{M-1} 1 = M - 1 = 2^N - 1$$

### 2. Valor final de $Y$:

En cada iteración se suma $2 \cdot I$ a $Y$. Al iniciar en $0$, su valor final es la suma de los primeros $M-1$ números pares:

$$Y = \sum_{I=1}^{M-1} 2I = 2 \sum_{I=1}^{M-1} I = 2 \cdot \frac{(M - 1)M}{2} = (M - 1)M = (2^N - 1)2^N$$

### 3. Valor final de $Z$:

En cada iteración se suma $4 \cdot I + 8$ a $Z$. Al iniciar en $0$, su valor final es:

$$Z = \sum_{I=1}^{M-1} (4I + 8) = 4 \sum_{I=1}^{M-1} I + 8 \sum_{I=1}^{M-1} 1 = 4 \cdot \frac{(M - 1)M}{2} + 8(M - 1)$$

$$Z = 2(M - 1)M + 8(M - 1) = 2(2^N - 1)2^N + 8(2^N - 1)$$

### Algoritmo Optimizado en $O(1)$:

Usando estas fórmulas cerradas, podemos reescribir la función eliminando por completo el bucle `for` y logrando una complejidad constante de $O(1)$:

```cpp
void alfa_optimo() {
    int N;
    std::cin >> N;

    // Usamos el operador de desplazamiento de bits (1 << N) para calcular 2^N rápidamente
    long long M = 1LL << N; 

    long long X = M - 1;
    long long Y = (M - 1) * M;
    long long Z = 2 * (M - 1) * M + 8 * (M - 1);

    // Imprimir los resultados
    std::cout << "X: " << X << ", Y: " << Y << ", Z: " << Z << std::endl;
}
```

- **Complejidad del nuevo algoritmo:** $O(1)$ en tiempo y $O(1)$ en espacio.
