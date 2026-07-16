<h1 align="center">E10 - Traza de Apuntadores Dobles y Errores</h1>

> [!TLDR]
> El código tiene 3 errores: `q→info` produce **Segmentation Fault** (puntero no inicializado), `s→prox` es un **error de compilación** (`s` es `Nodo**`), y `(*s)→prox→info` produce otro **Segmentation Fault** (puntero basura).

## Enunciado

Realice la traza del siguiente algoritmo. En cada línea, muestre el estado de las estructuras de datos gráficamente, y en caso de que la instrucción sea incorrecta, indicar el tipo de error.

```cpp
struct Nodo {
    int Info;
    Nodo *prox;
};

Nodo **p, **s, *q, *r;
p = &q;
q->info = 30;
q->prox = NULL;
r = new Nodo();
r->info = 2;
s = &r;
delete q;
q = new Nodo();
q->info = 31;
s->prox = q; // ¿Es válida esta instrucción?
(*p)->info = q->info + (*s)->prox->info;
```

## Respuesta

El fragmento de código contiene varios errores graves, tanto en tiempo de compilación (sintaxis) como en tiempo de ejecución (semántica):

### 1. Error de Ejecución Crítico en Línea 3 (`q->info = 30;`)

- **Causa:** El puntero simple `q` se declara en la pila, pero **nunca es inicializado** (no apunta a ninguna dirección válida de memoria asignada con `new`). Es un puntero salvaje.

- **Consecuencia:** Intentar desreferenciarlo en `q->info` produce un **Fallo de Segmentación (Segmentation Fault)** inmediato, colapsando el programa antes de llegar a las líneas siguientes.

### 2. Error de Compilación en Línea 11 (`s->prox = q;`)

- **Pregunta del enunciado:** ¿Es válida esta instrucción?

- **Respuesta:** **No, es completamente inválida.**

- **Causa:** `s` está declarado como un puntero doble: `Nodo **s`. Al aplicar el operador de acceso de miembro con flecha (`s->`), el compilador intenta buscar el campo `prox` directamente en el tipo `Nodo*` (puntero simple), lo cual es ilegal porque `s` no apunta a un objeto `Nodo` de forma directa, sino a un puntero `r`.

- **Error del Compilador:**

```text
error: request for member 'prox' in 's', which is of non-class type 'Nodo**'
```

- **Corrección Correcta:** Para acceder al miembro `prox` del nodo apuntado por `r` a través de `s`, se debe desreferenciar el puntero doble primero:

```cpp
(*s)->prox = q;
```

### 3. Error de Ejecución en Línea 12 (`(*s)->prox->info`)

- **Causa:** Incluso si corregimos la compilación de la línea anterior, el puntero `r->prox` (que es `(*s)->prox`) nunca fue inicializado con un enlace válido (contiene basura o `NULL`). Intentar leer `(*s)->prox->info` desreferencia un puntero nulo/basura.

- **Consecuencia:** Otro **Fallo de Segmentación** en tiempo de ejecución.
