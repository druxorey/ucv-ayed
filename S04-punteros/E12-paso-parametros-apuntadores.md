<h1 align="center">E12 - Paso de Parámetros por Valor, Referencia y Puntero Doble</h1>

> [!TLDR]
> `X` (referencia a puntero) y `Y` (puntero doble) modifican `p` externamente. `Z` y `W` usan paso por valor: `Z` genera un **leak** al no actualizar `p→prox→prox`, mientras `W` sí modifica el contenido del nodo.

## Enunciado

Indique el estado final, y responda las preguntas comentadas en `Any()`.

```cpp
struct node {
    int info;
    node *prox;
};

void X(node *&q, int value) {
    q = new node();
    q->info = value;
    q->prox = NULL;
}

void Y(node **q, int value) {
    *q = new node();
    (*q)->info = value;
    (*q)->prox = NULL;
}

void W(node *q, int value) {
    q->info = value;
}

void Z(node *q, int value) {
    q = new node();
    q->info = value;
    q->prox = NULL;
}

void Any() {
    node *p;
    X(p, 1);
    Y(&(p->prox), 2);
    Z(p->prox->prox, 3);
    W(p, 4);
}
```

- a) ¿Cuál es el estado de la memoria en este momento?
- b) ¿Es posible liberar todos los elementos creados con New? ¿De qué forma?

## Análisis de las Llamadas de Función en `Any()`

### 1. Llamada `X(p, 1);`

- **Firma:** `void X(node *&q, int value)`
- **Tipo de Paso:** Paso por **referencia a puntero** (`node *&`). Modificar `q` altera de forma directa el puntero original `p`.
- **Efecto:** Reserva Nodo A (dirección `0x100`) en Heap.
- **Estado:** `p` apunta a `0x100` (`[1|nullptr]`).

### 2. Llamada `Y(&(p->prox), 2);`

- **Firma:** `void Y(node **q, int value)`
- **Tipo de Paso:** Paso por **puntero doble** (`node **`). Pasar la dirección física de `p->prox` permite que `Y` modifique dicho puntero mediante desreferenciación (`*q`).
- **Efecto:** Reserva Nodo B (dirección `0x200`) y lo asigna a `p->prox`.
- **Estado:** `p` $\to$ `[1|0x200]` $\to$ `[2|nullptr]`.

### 3. Llamada `Z(p->prox->prox, 3);`

- **Firma:** `void Z(node *q, int value)`
- **Tipo de Paso:** Paso por **valor** (`node *`). El valor del puntero `p->prox->prox` (`nullptr`) se copia en el parámetro local `q`.
- **Efecto:** Dentro de `Z`, se ejecuta `q = new node()`, haciendo que `q` apunte a un nuevo Nodo C (`0x300`) con valor `3`. Sin embargo, al ser un parámetro local por valor, modificar `q` **no altera** a `p->prox->prox`.
- **Estado:** Al salir de `Z`, la dirección `0x300` se pierde, generando un **leak (fuga de memoria)**. `p->prox->prox` permanece en `nullptr`.

### 4. Llamada `W(p, 4);`

- **Firma:** `void W(node *q, int value)`
- **Tipo de Paso:** Paso por **valor** (`node *`).
- **Efecto:** Aunque el puntero `p` se copia, desreferencia al objeto original `q->info = 4`. Modifica el campo `info` del Nodo A.
- **Estado final de la lista:** `p` $\to$ `[4|0x200]` $\to$ `[2|nullptr]`.

## Respuestas Específicas

### **a) ¿Cuál es el estado de la memoria en este momento?**

- **Stack:** La variable local `p` almacena la dirección `0x100`.
- **Heap:**
    - Nodo A (`0x100`): `info = 4`, `prox = 0x200`.
    - Nodo B (`0x200`): `info = 2`, `prox = nullptr`.
    - Nodo C (`0x300`): `info = 3`, `prox = nullptr` (**Fuga de memoria: inaccesible**).

### **b) ¿Es posible liberar todos los elementos creados con `new`? ¿De qué forma?**

- **No por completo.**
- **Elementos que SÍ se pueden liberar:** La lista enlazada a la que apunta `p` (Nodo A y Nodo B) se puede liberar recorriendo y borrando secuencialmente:

```cpp
node* temp;
while (p != NULL) {
	temp = p->prox;
	delete p;
	p = temp;
}
```

- **Elementos que NO se pueden liberar:** El Nodo C (`0x300`) creado dentro de `Z()` se fugó. Al no existir ningún puntero en el programa que almacene su dirección física, es imposible invocar `delete` sobre él. Permanecerá ocupando memoria en el Heap hasta que finalice el proceso.
