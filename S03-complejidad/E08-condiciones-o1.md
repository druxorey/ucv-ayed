<h1 align="center">E08 - Condiciones para Complejidad $O(1)$</h1>

> [!TLDR]
> Un algoritmo es $O(1)$ cuando su tiempo de ejecución es **independiente de la entrada**: sin bucles que dependan de $n$, solo operaciones elementales y estructuras de tamaño constante.

## Enunciado

¿Bajo qué condiciones es un algoritmo de $O(1)$?

## Respuesta

Un algoritmo tiene una complejidad temporal de $O(1)$ (tiempo constante) cuando su tiempo de ejecución es independiente del tamaño de la entrada de datos ($n$).

1. **Sin Bucles Dependientes de la Entrada**: El algoritmo no debe contener ciclos (`for`, `while`, `do-while`) o recursión cuyo número de iteraciones dependa directa o indirectamente del tamaño de la entrada $n$. *Nota:* Un bucle que se ejecuta un número fijo y constante de veces (ej. `for (int i = 0; i < 100; i++)`) sigue siendo $O(1)$.

2. **Operaciones Básicas**: Consiste únicamente en operaciones elementales que toman tiempo constante en hardware:
    - Operaciones aritméticas elementales (suma, resta, multiplicación, división con tipos primitivos).
    - Operaciones lógicas y de bits (AND, OR, desplazamientos).
    - Asignaciones y accesos a variables individuales.
    - Lecturas y escrituras en arreglos mediante direccionamiento directo (siempre que el cálculo del índice sea $O(1)$).

3. **Tamaño de Estructuras Acotado**: Si realiza operaciones en estructuras dinámicas, estas deben estar acotadas a un tamaño constante máximo que no dependa de la entrada.
