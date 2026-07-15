<h1 align="center">E07 - Análisis de Complejidad de un Condicional Simple</h1>

> [!TLDR]
> Sí, el código es $O(1)$. La evaluación de `Cond` y la ejecución de cualquiera de las dos ramas son operaciones de costo fijo que no dependen del tamaño de la entrada.

## Enunciado

¿Es cierto que el siguiente código:

```cpp
if (Cond) {
    X = X + 1;
} else {
    X = X - 1;
}
```

es de $O(1)$? (justifique en detalle su respuesta)

## Respuesta

**Sí, es correcto.** Este código tiene una complejidad temporal de $O(1)$ (tiempo constante).

1. **Evaluación de la Condición:** Evaluar la condición lógica `Cond` es una operación básica e indivisible de la CPU que toma un tiempo constante $t_{cond}$.

2. **Rama Then (`if`):** Si `Cond` es verdadera, se ejecuta la operación `X = X + 1`, la cual consta de una suma y una asignación en memoria. Toma un tiempo constante $t_{then}$.

3. **Rama Else (`else`):** Si `Cond` es falsa, se ejecuta la operación `X = X - 1`, la cual consta de una resta y una asignación. Toma un tiempo constante $t_{else}$.

4. **Análisis del Peor Caso:** El tiempo total de ejecución $T(n)$ será:

    $$T(n) = t_{cond} + \max(t_{then}, t_{else})$$

Dado que $t_{cond}$, $t_{then}$ y $t_{else}$ son constantes fijas que **no dependen en absoluto de ningún tamaño de entrada** $n$, la cantidad total de operaciones de este bloque siempre estará acotada superiormente por una constante fija $M = t_{cond} + \max(t_{then}, t_{else})$.

Por definición de Big-O:

$$T(n) \le 1 \cdot M \quad \forall n \ge 1 \implies T(n) = O(1)$$
