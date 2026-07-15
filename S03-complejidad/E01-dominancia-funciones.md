<h1 align="center">E01 - Dominancia de Funciones</h1>

> [!TLDR]
> $f(n) = O(g(n))$ significa que $g$ **domina** a $f$: existe una constante $c$ tal que $f(n) \le c \cdot g(n)$ para todo $n$ suficientemente grande. Gráficamente, la curva de $g$ queda por encima de $f$ a partir de cierto punto $n_0$.

## Enunciado

Explique el concepto de dominancia de funciones (gráfica y formalmente). Explique cuál es su fin, es decir, ¿para qué es utilizada?

## Concepto de Dominancia

Formalmente, se dice que una función $f(n)$ es dominada por una función $g(n)$ (o que $f(n) = O(g(n))$) si existen constantes positivas $c > 0$ y $n_0 \ge 1$ tales que:

$$0 \le f(n) \le c \cdot g(n) \quad \forall n \ge n_0$$

Gráficamente, si trazamos las curvas de $f(n)$ y $c \cdot g(n)$ en un plano cartesiano donde el eje $X$ representa el tamaño de entrada $n$ y el eje $Y$ representa el número de operaciones/tiempo, la curva de $c \cdot g(n)$ estará estrictamente por encima de la curva de $f(n)$ para todo punto a la derecha de la línea vertical $n = n_0$.

```text
 Tiempo / Operaciones (Y)
    ^
    |          / c * g(n)
    |         /
    |        /  / f(n)
    |       /  /
    |      /  /
    |     /  /
    |    /  /
    |   /  /
    |  /  /
    | /| /
    |--|-----------------> Tamaño de entrada n (X)
      n0
```

## Propósito y Utilidad

El fin de la dominancia de funciones en las ciencias de la computación es clasificar los algoritmos de acuerdo con su comportamiento de crecimiento asintótico. Nos permite:

1. **Independencia del Hardware**: Comparar algoritmos sin importar la velocidad de la CPU o la memoria de la máquina donde corran, enfocándonos en la eficiencia inherente del algoritmo.
2. **Análisis en el Peor de los Casos**: Establecer una cota superior segura del tiempo de ejecución para entradas muy grandes ($n \to \infty$).
