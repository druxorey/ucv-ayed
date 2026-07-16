<h1 align="center">E14 - Análisis de Complejidad del Bucle con Condicional de Salto</h1>

> [!TLDR]
> La complejidad es $O(n^2)$. El primer bucle interno (`j`) incrementa `i` hasta $n/2$ en la primera iteración, y los bucles de `k1`/`k2` generan trabajo cuadrático. El bucle externo solo se ejecuta 2 veces.

## Enunciado

Para el siguiente algoritmo indique su complejidad en tiempo. Explique detalladamente qué ocurre:

```cpp
for (int i = 1; i < n; i++) {
    int j, k1, k2;
    for (j = 1; j < n - 1; j++) {
        i = i + 1;
        j = j + 1;
    }
    for (k1 = i; k1 < n; k1++) {
        for (k2 = k1; k2 < n; k2++) {
            k1 = k1 + 1;
            k2 = k2 + 1;
        }
    }
}
```


## Respuesta

```cpp
for (int i = 1; i < n; i++) {
    int j, k1, k2;
    for (j = 1; j < n - 1; j++) {
        i = i + 1;
        j = j + 1;
    }
    for (k1 = i; k1 < n; k1++) {
        for (k2 = k1; k2 < n; k2++) {
            k1 = k1 + 1;
            k2 = k2 + 1;
        }
    }
}
```

Analizaremos la ejecución a partir de la primera iteración del bucle externo ($i = 1$):

### 1. Bucle de `j` (Intermedio):

```cpp
for (j = 1; j < n - 1; j++) {
    i = i + 1;
    j = j + 1;
}
```

- `j` se incrementa en `1` dentro del cuerpo (`j = j + 1`) y en `1` en la cabecera del ciclo (`j++`). Por ende, `j` se incrementa de **2 en 2** en cada iteración: $1, 3, 5, 7, \dots$.
- Este bucle se ejecutará aproximadamente $\frac{n}{2}$ veces.
- En cada iteración de `j`, la variable del bucle externo `i` se incrementa en `1` (`i = i + 1`).
- Al finalizar el bucle de `j`, `i` habrá aumentado en $\frac{n}{2}$. Como su valor inicial era $1$, el valor de `i` al salir de este ciclo es:

$$i \approx \frac{n}{2}$$

### 2. Bucles de `k1` y `k2` (Internos):

```cpp
for (k1 = i; k1 < n; k1++) {
    for (k2 = k1; k2 < n; k2++) {
        k1 = k1 + 1;
        k2 = k2 + 1;
    }
}
```

- `k1` inicia en el valor actual de `i` ($\approx \frac{n}{2}$).

- En el bucle de `k2`, `k1` se incrementa en `1` en el cuerpo del ciclo (`k1 = k1 + 1`). Dado que este incremento ocurre dentro del bucle de `k2`, el comportamiento de `k1` depende de cuántas veces se ejecute el ciclo interno. Sin embargo, para fines de cota asintótica:
    - Ambos contadores `k1` y `k2` tienen pasos de incremento doble.
    - El bucle de `k2` realiza aproximadamente $\frac{n - k1}{2}$ iteraciones.
    - La sumatoria de las operaciones de estos bucles anidados desde $k1 = \frac{n}{2}$ hasta $n$ se comporta cuadráticamente:

$$T_{interno}(n) = \sum_{k1=n/2}^{n} \sum_{k2=k1}^{n} O(1) \approx O(n^2)$$

### 3. Siguiente iteración del Bucle Externo:

Al terminar los bucles internos en la primera iteración:

- La variable `i` (que valía $\approx \frac{n}{2}$) recibe la actualización del `for` externo: `i++`, por lo que pasa a ser $\frac{n}{2} + 1$.

- En la segunda iteración del bucle externo, se vuelve a ejecutar el bucle de `j`, lo que vuelve a sumar $\frac{n}{2}$ a la variable `i`. Esto provoca que `i` sea mayor o igual a `n` de inmediato, provocando la terminación del bucle externo.

- El bucle externo se ejecuta como máximo 2 veces.

El tiempo total de ejecución está dominado por la sumatoria cuadrática de los bucles internos de `k1` y `k2` durante la primera iteración del bucle externo:

$$T(n) = O(n^2)$$

La complejidad del algoritmo es **cuadrática**.
