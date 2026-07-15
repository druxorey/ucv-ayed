<h1 align="center">E09 - Cálculo de Complejidad de Bucles Anidados</h1>

> [!TLDR]
> El **Algoritmo 1** con tres bucles dependientes acumula $O(N^3)$ operaciones mediante sumatoria triple. El **Algoritmo 2** con división a la mitad en cada paso ejecuta $O(\log N)$ iteraciones.

## Enunciado

Supongamos que el tiempo de ejecución de un procedimiento A es una constante M. Calcular el orden de magnitud de la función complejidad T(n) que mide el tiempo de ejecución de los siguientes algoritmos, donde n es el tamaño de la entrada, y demuestre formalmente mediante el concepto de dominancia de funciones cuál es su complejidad.

### Algoritmo 1:

```cpp
int I = 1;
do {
    int J = 1;
    do {
        int K = 1;
        do {
            A();
            K = K + 1;
        } while (K != J);
        J = J + 1;
    } while (J != I);
    I = I + 1;
} while (I != N);
```

### Algoritmo 2:

```cpp
int J = N;
while (J > 1) {
    A();
    J = J/2;
}
```

## **Algoritmo 1**

```cpp
int I = 1;
do {
    int J = 1;
    do {
        int K = 1;
        do {
            A();
            K = K + 1;
        } while (K != J);
        J = J + 1;
    } while (J != I);
    I = I + 1;
} while (I != N);
```

El algoritmo consta de 3 bucles anidados controlados por contadores lineales:

1. El bucle externo se ejecuta para $I$ desde $1$ hasta $N$ (incremento unitario).
2. El bucle intermedio se ejecuta para $J$ desde $1$ hasta $I$ (incremento unitario).
3. El bucle interno se ejecuta para $K$ desde $1$ hasta $J$ (incremento unitario). En este nivel se llama a la función constante $A()$.

Por tanto, el número total de llamadas a $A()$, representado por $T(N)$, viene dado por la siguiente sumatoria triple:

$$T(N) = \sum_{I=1}^{N} \sum_{J=1}^{I} \sum_{K=1}^{J} 1 = \sum_{I=1}^{N} \sum_{J=1}^{I} J$$

Aplicando la fórmula de la suma aritmética en la sumatoria intermedia ($\sum_{j=1}^{i} j = \frac{i(i+1)}{2}$):

$$T(N) = \sum_{I=1}^{N} \frac{I(I+1)}{2} = \frac{1}{2} \sum_{I=1}^{N} (I^2 + I) = \frac{1}{2} \left( \sum_{I=1}^{N} I^2 + \sum_{I=1}^{N} I \right)$$

Utilizando las fórmulas de sumas de potencias:

- $\sum_{i=1}^{n} i^2 = \frac{n(n+1)(2n+1)}{6} \approx \frac{n^3}{3}$
- $\sum_{i=1}^{n} i = \frac{n(n+1)}{2} \approx \frac{n^2}{2}$

Sustituyendo y buscando el término de mayor crecimiento asintótico:

$$T(N) = \frac{1}{2} \left( \frac{2N^3 + 3N^2 + N}{6} + \frac{N^2 + N}{2} \right) = \frac{N^3}{6} + O(N^2)$$

El término dominante es $N^3$.

$$T(N) = O(N^3)$$

## **Algoritmo 2**

```cpp
int J = N;
while (J > 1) {
    A();
    J = J/2;
}
```

La variable de control $J$ inicia en $N$ y en cada iteración del bucle se divide a la mitad:

$$J_0 = N, \quad J_1 = \frac{N}{2}, \quad J_2 = \frac{N}{4}, \quad \dots \quad J_k = \frac{N}{2^k}$$

El bucle termina cuando $J_k \le 1$.

$$\frac{N}{2^k} \le 1 \implies N \le 2^k \implies k \ge \log_2 N$$

El número de iteraciones (y llamadas a $A()$) es proporcional al logaritmo en base 2 de $N$.

$$T(N) = O(\log N)$$
