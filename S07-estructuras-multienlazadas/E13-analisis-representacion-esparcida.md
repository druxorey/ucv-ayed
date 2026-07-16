<h1 align="center">E13 - Matriz Esparcida Doblemente Enlazada vs. Simplemente Enlazada</h1>

> [!TLDR]
> El doble enlace permite eliminación en $O(1)$ y navegación bidireccional, pero añade 8 bytes extra por nodo (40% más) y duplica los punteros a mantener en cada inserción/eliminación.

## Enunciado

¿Qué ventajas y desventajas tiene utilizar una estructura doblemente enlazada para los elementos de una matriz esparcida (proxFila, prevFila, proxCol, prevCol) con respecto a punteros simples? ¿Qué operaciones se benefician?

## Parte a) Ventajas y Desventajas

### Ventajas:

1. **Eliminación en Tiempo Constante $O(1)$:** En una matriz esparcida simplemente enlazada, para eliminar un nodo celda de la estructura, es necesario recorrer la fila y la columna desde el encabezado para encontrar los nodos anteriores y poder desvincular el nodo objetivo. Con doble enlace (`prevFila` y `prevCol`), el nodo conoce a sus antecesores inmediatos, permitiendo reconectar a los vecinos y liberar la memoria en $O(1)$ sin realizar búsquedas.

2. **Navegación Bidireccional:** Permite recorrer la matriz en cualquier dirección (de izquierda a derecha, de derecha a izquierda, de arriba a abajo y de abajo a arriba). Esto facilita algoritmos numéricos bidireccionales y recorridos inversos.

3. **Inserción antes de una posición conocida en $O(1)$:** Se puede insertar un nodo inmediatamente antes de una celda de referencia sin tener que buscarla.

### Desventajas:

1. **Mayor Consumo de Memoria:** Cada celda de la matriz debe almacenar dos punteros adicionales (`prevFila` y `prevCol`). En una arquitectura de 32 bits, esto añade $8 \text{ bytes}$ por celda (incrementando el tamaño del nodo de $20 \text{ bytes}$ a $28 \text{ bytes}$). En matrices con miles de elementos no nulos, esto representa una penalización de espacio considerable de un **$40\%$** en el Heap por nodo celda.

2. **Complejidad en la Programación (Mantenimiento de Punteros):** Cada inserción o desvinculación requiere actualizar el doble de punteros (hasta 8 punteros en las celdas vecinas). Esto incrementa la posibilidad de introducir bugs de punteros huérfanos y añade una pequeña sobrecarga de procesamiento constante de CPU.

## Parte b) Operaciones Beneficiadas

1. **Eliminaciones Frecuentes de Elementos (Asignación de Ceros):** Cuando un elemento con valor activo en la matriz cambia a cero ($0$), el nodo correspondiente debe ser removido físicamente de la estructura para conservar espacio. Esta eliminación es de $O(1)$ constante.

2. **Algoritmos de Álgebra Lineal que usan Pivoteo (ej. Eliminación Gaussiana):** Operaciones que requieren intercambio de filas y columnas o modificaciones interactivas de celdas en posiciones adyacentes.

3. **Recorridos en Sentido Inverso:** Procesamiento de datos o impresión de la matriz en orden reverso en tiempo lineal sin necesidad de estructuras auxiliares como pilas.

4. **Búsqueda Localizada:** Navegar hacia atrás a partir de una celda para evaluar vecindades locales en problemas de modelado de celdas.
