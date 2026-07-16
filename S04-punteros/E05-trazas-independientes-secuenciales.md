<h1 align="center">E05 - Trazas Independientes y Secuenciales de Punteros</h1>

> [!TLDR]
> Cada instrucción opera sobre el estado inicial de la lista `1→2→3→4→5`. Las operaciones sin asignación no tienen efecto. Las de copia por valor crean duplicados con posibles fugas, y las de reasignación de punteros pueden crear ciclos.

## Enunciado

Dada las siguientes definiciones:

```cpp
class Nodo {
public:
    int N;
    Nodo *prox;
};
Nodo *q, *r, *s;
Nodo t;
```

Asuma como estado inicial la figura del PDF (una cadena de nodos enlazados: `q -> [1|.] -> [2|.] -> [3|.] -> [4|.] -> [5|/]` (null) con `r` apuntando al nodo de valor 3, `s` apuntando al de valor 4, y `t` como objeto local), e indique el estado final después de ejecutar cada una de las siguientes instrucciones independientemente y luego una tras otra secuencialmente.


| Instrucciones izquierda | Instrucciones derecha |
|-------------------------|------------------------|
| `q = q->prox`           | `s->prox = s`          |
| `*q = *(q->prox)`       | `t = *q`               |
| `q->prox`               | `*q = *s`              |
| `q->prox->prox`         | `*s = t`               |
| `q = r->prox`           | `q = t`                |
| `*q = *(*r.prox)`       | `(*r).prox = q`        |
| `s->prox = q->prox`     | `q = q->prox->prox->prox` |


## Respuesta

Dada la lista enlazada inicial:

$$\text{q} \to \text{[1|next]} \to \text{[2|next]} \to \text{[3 (r)|next]} \to \text{[4 (s)|next]} \to \text{[5|nullptr]}$$
Y el objeto local `Nodo t`.

Analizamos el resultado de ejecutar cada instrucción directamente sobre el estado inicial:

- **`q = q->prox;`** El puntero local `q` avanza una posición. Ahora `q` apunta al nodo con valor `2`. La estructura de la memoria no sufre ningún cambio físico.

- **`*q = *(q->prox);`** Copia profunda de contenido. El nodo apuntado por `q` (nodo 1) copia la información y el puntero del nodo siguiente (nodo 2). El primer nodo físico almacena `N = 2` y apunta al nodo 3. El nodo 2 físico original queda huérfano (fuga de memoria).

- **`q->prox;`** Es una expresión simple sin asignación. El compilador la evalúa pero no tiene ningún efecto secundario. No hay cambios.

- **`q->prox->prox;`** Expresión sin asignación. No produce ningún efecto.

- **`q = r->prox;`** `q` pasa a apuntar a `r->prox` (nodo 4, donde también apunta `s`). La estructura física en memoria permanece intacta.

- **`*q = *(*r.prox);`** `*r.prox` (o `r->prox`) apunta al nodo 4. `*(*r.prox)` representa el objeto del nodo 4. Se copia este objeto en el nodo 1 (`q`). El nodo 1 toma el valor `N = 4` y su puntero `prox` pasa a apuntar al nodo 5. Los nodos 2, 3 y 4 quedan desconectados de la cabeza `q`.

- **`s->prox = q->prox;`** El puntero `prox` del nodo 4 (`s`) deja de apuntar al nodo 5 y pasa a apuntar a `q->prox` (nodo 2). Se crea una estructura circular: `nodo 1 -> nodo 2 -> nodo 3 -> nodo 4 -> nodo 2`. El nodo 5 queda huérfano.

- **`s->prox = s;`** El puntero `prox` del nodo 4 apunta a sí mismo. `1 -> 2 -> 3 -> 4 -> 4 (bucle infinito)`. El nodo 5 queda huérfano.

- **`t = *q;`** Copia de objeto. La variable local de pila `t` almacena una copia del contenido del nodo 1: `t.N = 1` y `t.prox = direccion_del_nodo_2`. La memoria dinámica no cambia.

- **`*q = *s;`** Copia profunda de datos. El contenido del nodo 4 (`s`) se escribe en el nodo 1 (`q`). El nodo 1 ahora vale `N = 4` y apunta al nodo 5.

- **`*s = t;`** Copia el contenido del objeto temporal `t` en el nodo 4 (`s`). El nodo 4 pasa a almacenar `N = 1` y a apuntar al nodo 2.

- **`q = t;`** **Error de compilación.** `q` es de tipo `Nodo*` (puntero) y `t` es de tipo `Nodo` (objeto directo). No se puede asignar un objeto a un puntero sin el operador de dirección (`&`).

- **`(*r).prox = q;`** El puntero `prox` del nodo 3 (`r`) apunta al nodo 1 (`q`). Se genera un ciclo: `1 -> 2 -> 3 -> 1`.

- **`q = q->prox->prox->prox;`** `q` avanza 3 enlaces en la cadena (nodo 1 $\to$ 2 $\to$ 3 $\to$ 4). Ahora `q` apunta al nodo 4.

Si ejecutamos la secuencia válida de forma acumulativa, se obtienen reasignaciones complejas e interrupciones de enlaces que pueden provocar referencias nulas. Académicamente, la resolución independiente es el objetivo primordial para validar el entendimiento analítico de cada instrucción.
