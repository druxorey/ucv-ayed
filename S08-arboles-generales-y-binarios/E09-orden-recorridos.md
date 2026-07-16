<h1 align="center">E09 - Generalización de Estructuras por Recorridos Idénticos</h1>

> [!TLDR]
> Preorden ≡ Inorden: árbol sin hijos izquierdos (lista hacia la derecha). Postorden ≡ Inorden: árbol sin hijos derechos (lista hacia la izquierda). Preorden ≡ Postorden: solo posible con un único nodo ($N = 1$).

## Enunciado

Generalice la forma de los árboles binarios cuyos nodos aparecen exactamente en el mismo orden en los recorridos de:

- a. Preorden y Simétrico.
- b. Postorden y Simétrico.
- c. Preorden y Postorden.

## Respuesta

Determinamos la forma estructural que deben tener los árboles binarios para que sus recorridos generen secuencias de nodos idénticas:

### **Caso a) Recorrido Preorden e Inorden (Simétrico) Idénticos**

- **Estructura General:** El árbol binario debe ser una cadena lineal degenerada donde **ningún nodo posee hijo izquierdo**.

- **Justificación:**
    - Preorden visita: $\text{Raíz} \to \text{Subárbol Izquierdo} \to \text{Subárbol Derecho}$.
    - Inorden visita: $\text{Subárbol Izquierdo} \to \text{Raíz} \to \text{Subárbol Derecho}$.
    - Para que ambos coincidan, el subárbol izquierdo de cada nodo debe estar vacío. Así, ambos recorridos se reducen a: $\text{Raíz} \to \text{Subárbol Derecho}$.
    - Físicamente representa una **lista lineal enlazada simple orientada hacia la derecha** (punteros `right` activos, `left = nullptr`).

### **Caso b) Recorrido Postorden e Inorden (Simétrico) Idénticos**

- **Estructura General:** El árbol binario debe ser una cadena lineal degenerada donde **ningún nodo posee hijo derecho**.

- **Justificación:**
    - Postorden visita: $\text{Subárbol Izquierdo} \to \text{Subárbol Derecho} \to \text{Raíz}$.
    - Inorden visita: $\text{Subárbol Izquierdo} \to \text{Raíz} \to \text{Subárbol Derecho}$.
    - Para que ambos coincidan, el subárbol derecho de cada nodo debe estar vacío. Ambos recorridos se reducen a: $\text{Subárbol Izquierdo} \to \text{Raíz}$.
    - Físicamente representa una **lista lineal enlazada hacia la izquierda** (punteros `left` activos, `right = nullptr`).

### **Caso c) Recorrido Preorden y Postorden Idénticos**

- **Estructura General:** El árbol binario debe constar de **exactamente un único nodo** (la raíz sola, $N = 1$).

- **Justificación:**
    - Si el árbol tiene $N > 1$ elementos, la raíz del árbol siempre será el **primer** elemento visitado en el recorrido Preorden, mientras que será obligatoriamente el **último** elemento visitado en el recorrido Postorden.
    - Por ende, al estar la raíz en extremos opuestos del orden resultante, es matemáticamente imposible que las secuencias coincidan para cualquier $N > 1$.
    - El único caso en el que coinciden es cuando $N = 1$, donde ambos recorridos devuelven la secuencia de un solo nodo: `[Raíz]`.
