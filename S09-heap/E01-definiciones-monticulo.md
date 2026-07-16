<h1 align="center">E01 - Definiciones de Árboles y su Importancia en Montículos</h1>

> [!TLDR]
> Un heap es un **árbol binario completo**. Esta propiedad permite almacenarlo en un **arreglo sin punteros** (hijo izq. en $2i+1$, der. en $2i+2$, padre en $\lfloor(i-1)/2\rfloor$) y garantiza altura $O(\log N)$, acotando las operaciones de flotar/hundir.

## Enunciado

Defina árbol binario completo y lleno e indique su importancia en la implementación del concepto de Montículo (Heap).

## Definiciones Fundamentales

- **Árbol Binario Lleno (Full Binary Tree):** Es un árbol binario en el que cada nodo tiene exactamente cero (0) o dos (2) hijos. Ningún nodo interno tiene un único hijo.
- **Árbol Binario Completo (Complete Binary Tree):** Es un árbol binario en el que todos los niveles están completamente llenos de nodos, a excepción posiblemente del último nivel, el cual debe estar lleno de izquierda a derecha.

## Importancia en la Implementación de Montículos (Heaps)

Un montículo binario se define estructuralmente como un **árbol binario completo**. Esta propiedad de completitud es fundamental por las siguientes razones:

### a) Almacenamiento Contiguo Eficiente en Arreglos (Sin Punteros)

Dado que un árbol binario completo se llena estrictamente de izquierda a derecha y de arriba a abajo, podemos mapear lógicamente todos sus nodos en un **arreglo de memoria contiguo** sin desperdiciar celdas y sin necesidad de almacenar punteros físicos (`left`, `right`).

Si la raíz reside en el índice $0$, para cualquier nodo en el índice $i$:

- Su **hijo izquierdo** se encuentra exactamente en: $2i + 1$
- Su **hijo derecho** se encuentra exactamente en: $2i + 2$
- Su **padre** se encuentra exactamente en: $\lfloor (i - 1) / 2 \rfloor$

```text
       [10] (0)
      /    \
   [8] (1)  [7] (2)     ===> Arreglo: [ 10, 8, 7, 5, 6 ]
   /   \
[5](3) [6](4)
```

### b) Garantía de Altura Logarítmica $O(\log N)$

Al mantenerse completo, la altura $h$ de un montículo de $N$ elementos siempre estará acotada superiormente por:

$$h = \lfloor \log_2 N \rfloor$$

Esto garantiza que las operaciones críticas de reordenamiento como **flotar** y **hundir** (las cuales se desplazan verticalmente por las ramas del árbol) tomen a lo sumo un tiempo logarítmico estrictamente acotado de $O(\log N)$ en el peor caso.
