# Montículos

## **E01-definiciones-monticulo**

Defina árbol binario completo y lleno e indique su importancia en la implementación del concepto de Montículo (Heap).

**Respuesta: [E01-definiciones-monticulo.md](../S09-heap/E01-definiciones-monticulo.md)**

## **E02-implementacion-monticulo**

Implemente las primitivas `Hundir` y `Flotar` para un montículo máximo. Haciendo uso de estas, implemente las operaciones `Insertar` y `Remover`.

**Ejemplos:**
| Operación (Entrada) | Estado Interno del Heap (Salida) |
| :--- | :--- |
| `Insertar(15)`, `Insertar(8)`, `Insertar(20)`, `Insertar(5)`, `Insertar(30)` | `[ 30 20 15 5 8 ]` (Estructura de Max-Heap) |
| `Remover()` | Retorna `30` (el elemento máximo) |


**Respuesta: [E02-implementacion-monticulo.cpp](../S09-heap/E02-implementacion-monticulo.cpp)**

## **E03-mezclar-monticulos**

Para la clase `Monticulo` definida anteriormente agregue un método que permita mezclar dos heaps con y sin claves repetidas, haciendo uso de primitivas.

**Ejemplos:**
| Montículo 1 | Montículo 2 | Salida de Mezcla (Sin Repetidos) |
| :--- | :--- | :--- |
| `[ 15 10 5 ]` | `[ 20 10 ]` | `[ 20 15 5 10 ]` (Fusión sin claves duplicadas) |


**Respuesta: [E03-mezclar-monticulos.cpp](../S09-heap/E03-mezclar-monticulos.cpp)**

## **E04-monticulo-apuntadores**

Implemente un montículo utilizando apuntadores físicos en el Heap (nodos con enlaces a hijos y padre) en lugar de un arreglo. Compare la complejidad en tiempo y en espacio de ambas implementaciones.

**Ejemplos:**
| Operación | Salida / Estado |
| :--- | :--- |
| `Insertar(50)`, `Insertar(30)`, `Insertar(80)` | Árbol binario enlazado con raíz `80` (hijos `30` y `50`) |
| `Remover()` | Retorna `80` (raíz enlazada) |


**Respuesta: [E04-monticulo-apuntadores.cpp](../S09-heap/E04-monticulo-apuntadores.cpp)**

## **E05-propiedad-monticulo**

Dado el nodo raíz de un árbol binario, implemente una función eficiente que verifique si el árbol cumple la propiedad de montículo máximo (que sea completo y que cumpla la relación padre >= hijos).

**Ejemplos:**
| Estructura del Árbol (Entrada) | Salida (¿Es Max-Heap?) |
| :--- | :--- |
| `100` con izq `(19->(17,3))` y der `(36)` | `true` |
| `10` con izq `(50)` y der `(15)` | `false` (Violación de orden: 50 > 10) |
| `100` con izq `(19->(17,null))` y der `(36->(25,null))` | `false` (No es un árbol completo) |


**Respuesta: [E05-propiedad-monticulo.cpp](../S09-heap/E05-propiedad-monticulo.cpp)**
