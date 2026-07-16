<h1 align="center">E08 - Traza de la Función LOL()</h1>

> [!TLDR]
> La función construye la lista `10→13→23` en el Heap y la imprime. Al terminar, ningún nodo se libera con `delete`, provocando una fuga de memoria de los 3 nodos.

## Enunciado

Dada la siguiente secuencia de instrucciones indique qué ocurre en cada línea. Indique además si queda algún elemento por liberar de memoria al terminar `LOL()`.

```cpp
class Nodo {
public:
    int Info;
    Nodo *prox;
};
Nodo *P, *Q;

void LOL() {
    P = new Nodo();
    P->Info = 10;
    P->prox = P;
    Q = new Nodo();
    P->prox = Q;
    Q->Info = P->Info + 3;
    Q->prox = P;
    Q->prox = NULL;
    Q = new Nodo();
    Q->Info = P->Info + P->prox->Info;
    P->prox->prox = Q;
    Q->prox = NULL;
    Q = P;
    while (Q != NULL) {
        std::cout << Q->Info << std::endl;
        Q = Q->prox;
    }
}
```

## Respuesta

1. **`P = new Nodo();`** Reserva Nodo A en Heap (`0x100`). `P` apunta a `0x100`.

2. **`P->Info = 10;`** Asigna `10` al campo `Info` de Nodo A (`0x100`).

3. **`P->prox = P;`** El puntero `prox` de Nodo A apunta a sí mismo (`0x100->prox = 0x100`), creando un ciclo de un solo elemento.

4. **`Q = new Nodo();`** Reserva Nodo B en Heap (`0x200`). `Q` apunta a `0x200`.

5. **`P->prox = Q;`** Nodo A apunta a Nodo B (`0x100->prox = 0x200`). Se rompe el bucle sobre sí mismo.

6. **`Q->Info = P->Info + 3;`** Asigna `10 + 3 = 13` al campo `Info` de Nodo B (`0x200`).

7. **`Q->prox = P;`** Nodo B apunta a Nodo A (`0x200->prox = 0x100`), creando una lista circular de dos elementos: `A -> B -> A`.

8. **`Q->prox = NULL;`** El puntero `prox` de Nodo B se asigna a `NULL` (`0x200->prox = nullptr`). Esto interrumpe la circularidad, quedando:

$$\text{P} \to \text{[10|0x200]} \to \text{[13|nullptr]}$$

9. **`Q = new Nodo();`** Reserva un tercer Nodo C en el Heap (`0x300`). `Q` apunta a `0x300`.

10. **`Q->Info = P->Info + P->prox->Info;`**
    - `P->Info` = 10
    - `P->prox->Info` = `(0x200)->Info` = 13
    - `Q->Info` = $10 + 13 = 23$.

11. **`P->prox->prox = Q;`** `P->prox` es Nodo B (`0x200`). `P->prox->prox` (el puntero `prox` de Nodo B) ahora apunta a Nodo C (`0x300`).

12. **`Q->prox = NULL;`** Nodo C apunta a `NULL`. La lista enlazada final es lineal y tiene 3 elementos:

$$\text{P} \to \text{[10|0x200]} \to \text{[13|0x300]} \to \text{[23|nullptr]}$$

13. **`Q = P;`** `Q` apunta a la cabeza de la lista (Nodo A, `0x100`).

14. **Bucle `while (Q != NULL)`:** Recorre la lista imprimiendo el valor del campo `Info` de cada nodo:
    - *Paso 1 (0x100):* Imprime `10`. `Q` avanza a `0x200`.
    - *Paso 2 (0x200):* Imprime `13`. `Q` avanza a `0x300`.
    - *Paso 3 (0x300):* Imprime `23`. `Q` avanza a `nullptr`.

Salida del Programa (Pantalla)

```text
10
13
23
```

Al finalizar la función `LOL()`:

- Aunque los punteros globales `P` y `Q` quedan con referencias, **no se ejecuta ningún delete**.
- Los 3 nodos reservados dinámicamente en el Heap (Nodo A en `0x100`, Nodo B en `0x200`, Nodo C en `0x300`) **nunca se liberan**.
- Toda la memoria dinámica ocupada por la lista enlazada queda con **fuga de memoria**.
