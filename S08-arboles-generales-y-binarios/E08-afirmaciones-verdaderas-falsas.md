<h1 align="center">E08 - Discusión sobre Afirmaciones de Árboles</h1>

> [!TLDR]
> Las tres afirmaciones son **falsas**: (a) la altura es el camino **más largo** a cualquier hoja, no “a la hoja”; (b) la fórmula altura_nodo = altura_árbol − nivel solo vale en árboles perfectamente completos; (c) en árboles degenerados solo-derecho, preorden e inorden producen la misma secuencia.

## Enunciado

Indique cuáles de las afirmaciones dadas en el enunciado son verdaderas o falsas y justifique su respuesta con argumentos y contraejemplos.

## Respuesta

### **Afirmación a: "La altura del nodo de un árbol es la longitud del camino que va desde el nodo a la hoja."**

El dictamen es que se considera falsa o imprecisa. La altura de un nodo $N$ se define formalmente como la longitud del camino **más largo** desde $N$ hasta una de sus hojas descendientes. Decir "a la hoja" (en singular) es ambiguo e incorrecto, ya que un nodo puede tener múltiples hojas descendientes a diferentes niveles. La definición correcta exige que sea el camino de **longitud máxima**.

### **Afirmación b: "La altura del nodo de un árbol viene dada por la altura del árbol menos el nivel del nodo."**

Esta afirmación es falsa. Esta igualdad solo se cumple en árboles perfectamente balanceados o completos donde todas las hojas residen exactamente en el mismo nivel más profundo. En árboles desbalanceados no se cumple.

- *Contraejemplo:* Considere un árbol de altura 3 con raíz $A$ (nivel 0). Su hijo izquierdo $B$ (nivel 1) es una hoja (altura de $B$ = 0). Su hijo derecho $C$ (nivel 1) tiene un hijo $D$ (nivel 2) y este a su vez tiene a $E$ (nivel 3).

- Si aplicamos la fórmula para el nodo $B$:

$$\text{Altura}(B) = \text{Altura}(Árbol) - \text{Nivel}(B) = 3 - 1 = 2$$

Sin embargo, la altura real del nodo $B$ es $0$ (ya que es una hoja). La fórmula falla.

### **Afirmación c: "Para cualquier árbol binario la secuencia que se produce al recorrerlo en preorden es diferente a la producida en simétrico (inorden)."**

Se considera falsa. Existen árboles binarios para los cuales ambos recorridos producen exactamente la misma secuencia de elementos. Esto ocurre en árboles degenerados tipo "lista" donde **todos los nodos hijos son hijos derechos** (no existen subárboles izquierdos).

- *Ejemplo:* Considere el árbol con estructura: `1 -> [derecho] -> 2 -> [derecho] -> 3`.
- **Recorrido Preorden (Raíz, Izq, Der):** `[1, 2, 3]`
- **Recorrido Simétrico/Inorden (Izq, Raíz, Der):** `[1, 2, 3]`
- Ambos recorridos producen la misma secuencia, lo que demuestra que la afirmación no se cumple para "cualquier" árbol binario.
