<h1 align="center">E04 - Orden Teórico vs. Rendimiento Práctico</h1>

> [!TLDR]
> No. Dos algoritmos con el mismo orden asintótico (ej. ambos $O(n^2)$) pueden diferir drásticamente en la práctica por sus **constantes ocultas**, el uso de **caché de CPU** y el **costo real de sus operaciones**.

## Enunciado

Si dos algoritmos tienen el mismo orden teórico en tiempo de ejecución, entonces ¿ambos tardarán el mismo tiempo en ejecutarse en la práctica? Suponga que ambos se ejecutan en plataformas totalmente iguales. Explique su respuesta.

## Respuesta

**No necesariamente.** Dos algoritmos con el mismo orden de crecimiento asintótico (por ejemplo, ambos son $O(n^2)$) pueden tener tiempos de ejecución reales muy diferentes en la práctica.

**1. Constantes Multiplicativas y Términos de Menor Orden**

La notación asintótica descarta las constantes y términos menos significativos. Si el tiempo de ejecución real del Algoritmo A es $T_A(n) = 2n^2 + 5n$ y el del Algoritmo B es $T_B(n) = 100n^2 + 2000n$:

- Ambos pertenecen a la clase de complejidad $O(n^2)$.
- En la práctica, el Algoritmo B tardará aproximadamente 50 veces más que el Algoritmo A para valores grandes de $n$.

**2. Localidad de Datos y Caché de CPU**

La eficiencia práctica depende críticamente de cómo interactúa el algoritmo con la memoria:

* Un algoritmo que accede a memoria de forma secuencial aprovecha la **caché de la CPU** (localidad espacial y temporal), siendo sumamente rápido.
* Otro algoritmo que realiza saltos aleatorios en memoria sufrirá constantes fallos de caché (*cache misses*), ralentizando su ejecución drásticamente, a pesar de tener la misma cantidad teórica de operaciones.

**3. Costo Real de las Operaciones**

No todas las operaciones de CPU consumen los mismos ciclos:

- Las sumas y operaciones de bits son extremadamente rápidas (1 ciclo).
- Las multiplicaciones, divisiones u operaciones de punto flotante consumen significativamente más ciclos.
Un algoritmo con un alto número de divisiones tardará más que uno con el mismo orden que solo use sumas.
