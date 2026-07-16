<h1 align="center">E04 - Mapa de Memoria y Salida de Programa</h1>

> [!TLDR]
> Las operaciones crean una lista circular `A→C→B→A` con valores `info`: A=2, C=1, B=3. La salida por pantalla es: `2 3 1`.

## Enunciado

Para las siguientes instrucciones, haga un mapa de memoria que muestre qué ocurre en ella, y cuál es la salida del programa.

```cpp
struct node {
    int info;
    node *next;
};

int main() {
    node *p, *r, *s;
    p = new node();
    s = new node();
    r = new node();
    (*p).next = r;
    (*r).next = s;
    s->next = p;
    s->info = 3;
    p->next->next->next->info = 2;
    *(s->next).next->info = 1;
    p = s->next;
    std::cout << *(p).info << " " << s->info << " " << *(r).info << std::endl;
    return 0;
}
```

## Análisis Paso a Paso de la Traza

### 1. Inicialización de Variables y Reserva en Heap:

```cpp
node *p, *r, *s;
p = new node(); // Reserva Nodo A (supongamos dir 0x100)
s = new node(); // Reserva Nodo B (supongamos dir 0x200)
r = new node(); // Reserva Nodo C (supongamos dir 0x300)
```

- `p` almacena la dirección `0x100`.
- `s` almacena la dirección `0x200`.
- `r` almacena la dirección `0x300`.

### 2. Configuración de Enlaces:

```cpp
(*p).next = r;  // p->next apunta a r (0x100->next = 0x300)
(*r).next = s;  // r->next apunta a s (0x300->next = 0x200)
s->next = p;    // s->next apunta a p (0x200->next = 0x100)
```

Se ha establecido una **lista enlazada circular**:

$$\text{Nodo A (p: 0x100)} \to \text{Nodo C (r: 0x300)} \to \text{Nodo B (s: 0x200)} \to \text{Nodo A (p: 0x100)}$$

### 3. Asignación de Valores:

```cpp
s->info = 3; // El campo info de Nodo B (0x200) se asigna en 3.
```

```cpp
p->next->next->next->info = 2;
```

Navegamos la cadena:

- `p` es `0x100`.
- `p->next` es `0x300`.
- `p->next->next` es `0x200`.
- `p->next->next->next` es `0x100`.
- Por lo tanto, la asignación es: `(0x100)->info = 2`.

```cpp
*(s->next).next->info = 1;
```

Por precedencia de operadores:

- `s->next` es el puntero `p` (`0x100`).
- `*(s->next)` desreferencia al objeto en `0x100`.
- `*(s->next).next` accede al campo `next` del objeto en `0x100`, el cual es el puntero `r` (`0x300`).
- `*(s->next).next->info` accede al campo `info` del objeto en `0x300`.
- Por lo tanto, la asignación es: `(0x300)->info = 1`.

### 4. Reasignación de Puntero:

```cpp
p = s->next; // s->next es 0x100, por lo que p sigue apuntando a 0x100.
```

## Mapa de Memoria Final

### Stack (Pila de llamadas local)

```text
+----------+---------------+
| Variable | Valor (Dir)   |
+----------+---------------+
| p        | 0x100         |
| r        | 0x300         |
| s        | 0x200         |
+----------+---------------+
```

### Heap (Memoria dinámica)

```text
Dirección: 0x100 (Nodo A)
+---------------+---------+
| info          | 2       |
| next          | 0x300   | ---> Apunta a Nodo C (0x300)
+---------------+---------+

Dirección: 0x200 (Nodo B)
+---------------+---------+
| info          | 3       |
| next          | 0x100   | ---> Apunta a Nodo A (0x100)
+---------------+---------+

Dirección: 0x300 (Nodo C)
+---------------+---------+
| info          | 1       |
| next          | 0x200   | ---> Apunta a Nodo B (0x200)
+---------------+---------+
```

## Salida por Pantalla del Programa

La línea de impresión es:

```cpp
std::cout << *(p).info << " " << s->info << " " << *(r).info << std::endl;
```

- `*(p).info` accede a `(0x100)->info` = `2`
- `s->info` accede a `(0x200)->info` = `3`
- `*(r).info` accede a `(0x300)->info` = `1`

**Salida:**

```text
2 3 1
```
