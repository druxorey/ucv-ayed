# E03 - Esquemas en Backtracking

> **TLDR**: Backtracking resuelve tres tipos de problemas: **Decisión** «¿hay al menos una salida del laberinto?» donde se detiene al encontrar la primera. **Optimización** «¿cuál es la salida con el tesoro más grande?» donde explora todo para encontrar la mejor. Y **Enumeración** «¿cuáles son todas las salidas posibles?» donde sigue buscando para listarlas todas.

---

## Principales Esquemas de Solución en Backtracking

Los algoritmos de backtracking son como un detective que explora una escena del crimen. Dependiendo de lo que busca el detective su estrategia cambia. Estos son los tres esquemas principales:

### 1. Problemas de Decisión «¿Existe una solución?»

Este es el esquema más simple. El objetivo es determinar si existe **al menos una solución** válida. El algoritmo explora los caminos y tan pronto como encuentra la primera solución completa que satisface todas las condiciones se detiene y retorna una respuesta afirmativa «generalmente `true`».

Si explora todos los caminos posibles y no encuentra ninguna solución válida entonces retorna una respuesta negativa «`false`». No le importa cuál es la solución o si hay más de una solo le importa si el problema tiene solución.

* **Ejemplo**: Resolver un Sudoku. Solo necesitas encontrar una configuración válida para decir que el Sudoku tiene solución.

### 2. Problemas de Optimización «¿Cuál es la mejor solución?»

Aquí el objetivo no es solo encontrar una solución sino encontrar **la mejor solución posible** según un criterio específico «el camino más corto el valor máximo el coste mínimo etc.».

El algoritmo necesita una variable global o un parámetro extra para llevar un registro de la «mejor solución encontrada hasta ahora». Cada vez que encuentra una solución válida la compara con la mejor que tiene guardada. Si la nueva es mejor la reemplaza. A diferencia del esquema de decisión el algoritmo no puede detenerse al encontrar la primera solución. Debe explorar **todas las ramas viables** del espacio de búsqueda para garantizar que el resultado final sea realmente el óptimo.

* **Ejemplo**: El problema de la mochila (*Knapsack Problem*) donde buscas la combinación de objetos que maximiza el valor total sin exceder un peso límite.

### 3. Problemas de Enumeración «Encuentra todas las soluciones»

En este esquema el objetivo es encontrar y registrar **todas las soluciones válidas** que existen para un problema.

El algoritmo es similar al de decisión pero no se detiene después de encontrar la primera solución. En lugar de eso la guarda en una lista o contenedor y continúa la búsqueda. El proceso solo termina cuando se han explorado por completo todas las ramas del árbol de búsqueda. Al final el resultado es una colección con todas las soluciones posibles.

* **Ejemplo**: El problema de las N-Reinas donde debes encontrar todas las maneras posibles de colocar N reinas en un tablero de N×N sin que se ataquen entre sí.
