<h1 align="center">E07 - Representación Estática de Árboles en Postorden</h1>

> [!TLDR]
> El enfoque estático tiene tres desventajas: modificaciones $O(N)$ (hay que desplazar el arreglo), navegación costosa (requiere simular el recorrido) y rigidez de tamaño predefinido. Las primitivas se implementan con una **pila auxiliar** de reconstrucción.

## Enunciado

Considere la representación estática de árboles consistente en almacenar el recorrido en postorden definido en un arreglo (además de tener el grado de cada nodo). ¿Qué desventajas podría tener este enfoque de almacenamiento estático? Basado en esta representación defina las primitivas de `Primer_Hijo`, `Hermano_Der` y `Padre`.

## Representación en Postorden en un Arreglo Estático

Almacenar un árbol general de forma contigua mediante su recorrido en postorden y un arreglo de grados presenta las siguientes desventajas críticas:

1. **Costo de Modificación Estructural Excesivo ($O(N)$):** Cualquier inserción de un nuevo nodo o eliminación de un subárbol completo rompe el orden del recorrido. Requiere reconstruir y desplazar físicamente los elementos en el arreglo, lo que toma tiempo lineal $O(N)$ en comparación con el tiempo constante $O(1)$ de reconexión de punteros dinámicos.

2. **Complejidad de Navegación Temporal:** Las operaciones básicas de navegación como obtener el `Padre` o el `Hermano_Der` no son directas. Requieren simular el recorrido completo utilizando estructuras auxiliares en tiempo lineal $O(N)$, eliminando la eficiencia de acceso directo.

3. **Desperdicio o Rigidez en el Tamaño de Memoria:** Por ser una estructura estática (arreglo), debe predefinirse una capacidad física máxima, lo que puede provocar desbordamiento o desperdicio si el árbol real es pequeño.

## Definición de Primitivas usando una Pila Auxiliar

El recorrido en postorden visita primero a todos los descendientes de un nodo antes de procesar la raíz. Para un nodo con grado $g$ (número de hijos), sus $g$ hijos aparecen inmediatamente antes que él en el arreglo de postorden.

### Algoritmo de Reconstrucción Lógica con Pila:

Para determinar las relaciones jerárquicas, recorremos el arreglo de postorden de izquierda a derecha. Usamos una pila auxiliar que almacena los nodos procesados:

Para cada elemento $i$ en el arreglo con valor $val$ y grado $g$:

- Si $g == 0$ (es una hoja): Apilamos el nodo.
- Si $g > 0$ (tiene hijos):
	- Desapilamos $g$ elementos de la pila.
	- Dado el orden de postorden, los elementos se desapilan de derecha a izquierda:
		- El **primer** elemento desapilado es el hijo más a la derecha.
		- El **último ($g$-ésimo)** elemento desapilado es el hijo más a la izquierda, el cual corresponde a la primitiva **`Primer_Hijo(i)`**.
		- Para cualquier hijo desapilado $H_k$, el elemento desapilado inmediatamente antes que él es su **`Hermano_Der(H_k)`**.
		- Para todos los $g$ elementos desapilados, el nodo actual $i$ es asignado como su **`Padre`**.
	- Apilamos el nodo actual $i$ (que ahora representa la raíz de su subárbol completo).

### Definición Formal de las Primitivas:

- **`Primer_Hijo(nodo)`:** Si `grado(nodo) > 0`, al simular con la pila, es el último elemento desapilado de los $g$ hijos asignados a `nodo`.

- **`Hermano_Der(nodo)`:** Durante la simulación, es el elemento desapilado inmediatamente antes que `nodo` de la misma lista de hijos del mismo padre. Si fue el primer elemento desapilado (hijo más a la derecha), retorna `NULL`.

- **`Padre(nodo)`:** Es el nodo que desapila a `nodo` de la pila durante la reconstrucción del recorrido.
