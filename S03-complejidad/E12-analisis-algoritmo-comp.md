<h1 align="center">E12 - Análisis de Complejidad del Algoritmo comp</h1>

> [!TLDR]
> La función es $O(n)$. El `while` interno consume $n$ iteraciones en su única ejecución, elevando `i` a `n`. Esto hace que la condición del `for` externo falle de inmediato, y el `if` interno nunca se ejecuta porque `j == n` siempre.

## Enunciado

Calcule la complejidad en tiempo del siguiente algoritmo:

```cpp
void comp(int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = 0;
        while (i < n) {
            j = j + 1;
            i = i + 1;
        }
        if (j < n) {
            for (int k = 1; k < n; k++) {
                for (int k2 = 1; k2 < n; k2++) {
                    i = k * k2;
                }
            }
        }
    }
}
```

## Respuesta

```cpp
void comp(int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = 0;
        while (i < n) {
            j = j + 1;
            i = i + 1;
        }
        if (j < n) {
            for (int k = 1; k < n; k++) {
                for (int k2 = 1; k2 < n; k2++) {
                    i = k * k2;
                }
            }
        }
    }
}
```

Analicemos paso a paso el comportamiento del algoritmo:

1. **Inicio del Bucle Externo:** La variable `i` comienza en `0` (`i = 0`). La condición de permanencia es `i < n - 1`.

2. **Bucle Interno `while (i < n)`:**
    - `j` inicia en `0`.
    - Este ciclo incrementa `i` y `j` simultáneamente de uno en uno hasta que `i` alcanza `n`.
    - Dado que `i` inicia en `0`, el ciclo `while` se ejecuta exactamente **$n$ veces**.
    - Al finalizar el `while`, el valor final de las variables es:
        - `i = n`
        - `j = n`

3. **Condición `if (j < n)`:** Se evalúa la condición del `if` con el valor actual de `j`:

$$\text{¿} j < n \text{?} \implies \text{¿} n < n \text{?}$$

Esta condición es siempre **falsa**. Por lo tanto, el cuerpo del `if` (los dos bucles anidados con variable `k` y `k2`) **nunca se ejecuta**.

4. **Actualización del Bucle Externo:** Tras terminar el cuerpo del bucle `for`, se aplica el paso de actualización de la variable de control: `i++`. Como `i` tenía el valor `n` (al salir del `while`), ahora toma el valor `n + 1`.

5. **Verificación de Parada del Bucle Externo:** Se evalúa la condición de permanencia del `for`:

    $$\text{¿} i < n - 1 \text{?} \implies \text{¿} n + 1 < n - 1 \text{?}$$

Esta condición es **falsa** para todo valor no negativo de $n$. Por ende, el bucle `for` externo termina su ejecución inmediatamente y la función retorna.

El bucle externo se ejecuta **exactamente una vez**. Durante esa única ejecución, el bucle interno `while` realiza exactamente $n$ operaciones elementales de incremento.

Por lo tanto, la función complejidad $T(n)$ es lineal:

$$T(n) = O(n)$$
