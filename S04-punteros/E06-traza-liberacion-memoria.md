<h1 align="center">E06 - Traza e Identificación de Fugas de Memoria</h1>

> [!TLDR]
> El programa crea 3 nodos enlazados (valores 30, 40, 80) y acumula su suma en `*E = 150`. Al final, los 3 nodos, el entero `E` y el puntero dinámico `F` nunca se liberan, produciendo **5 objetos con fuga de memoria**.

## Enunciado

Dada la siguiente secuencia de instrucciones indique qué es lo que ocurre en cada línea. Indique si queda algún espacio de memoria por liberar.

```cpp
class Nodo {
public:
    int Info;
    Nodo *prox;
};

Nodo *P, *Q;
int *E;
int I;
int **F;

int main() {
    P = new Nodo();
    E = new int();
    *E = 0;
    F = &E;
    P->prox = new Nodo();
    Q = &(*P);
    P = P->prox; 
    Q->Info = 30;
    (*P).Info = Q->Info + 10;
    P->prox = new Nodo();
    P->prox->Info = Q->Info + P->Info + 10;
    P = (*P).prox;
    P->prox = NULL;
    while (Q != NULL) {
        *E = *F + Q->Info;
        Q = Q->prox;
    }
    F = new int*();
    *F = new int();
    **F = 1;
    delete *F;
    *F = &I;
    I = 5;
    std::cout << **F << std::endl;
    return 0;
}
```

## Resultado

1. **`P = new Nodo();`** Reserva un objeto `Nodo` (Nodo A en `0x100`) en el Heap. `P` apunta a `0x100`.

2. **`E = new int();`** Reserva un entero (Entero A en `0x200`) en el Heap. `E` apunta a `0x200`.

3. **`*E = 0;`** Inicializa el valor del Entero A (`0x200`) en `0`.

4. **`F = &E;`** `F` (puntero doble) almacena la dirección de la variable local de pila `E`.

5. **`P->prox = new Nodo();`** Reserva un segundo `Nodo` (Nodo B en `0x300`) en el Heap y enlaza Nodo A con Nodo B (`0x100->prox = 0x300`).

6. **`Q = &(*P);`** `Q` apunta al Nodo A (`0x100`).

7. **`P = P->prox;`** `P` avanza al Nodo B (`0x300`).

8. **`Q->Info = 30;`** Asigna `30` en el campo `Info` de Nodo A (`0x100`).

9. **`(*P).Info = Q->Info + 10;`** Asigna `30 + 10 = 40` en el campo `Info` de Nodo B (`0x300`).

10. **`P->prox = new Nodo();`** Reserva un tercer `Nodo` (Nodo C en `0x400`) y enlaza Nodo B con Nodo C (`0x300->prox = 0x400`).

11. **`P->prox->Info = Q->Info + P->Info + 10;`** Asigna `30 + 40 + 10 = 80` en el campo `Info` de Nodo C (`0x400`).

12. **`P = (*P).prox;`** `P` avanza al Nodo C (`0x400`).

13. **`P->prox = NULL;`** Asegura el final de la lista enlazada: `0x400->prox = nullptr`. La lista completa queda como:

$$\text{Q} \to \text{[30|0x300]} \to \text{[40|0x400]} \to \text{[80|nullptr]}$$

14. **Bucle `while (Q != NULL)`:**
    - *Iteración 1:* `*E = *E + Q->Info` $\implies 0 + 30 = 30$. `Q` avanza a `0x300`.
    - *Iteración 2:* `*E = 30 + 40 = 70$. `Q` avanza a `0x400`.
    - *Iteración 3:* `*E = 70 + 80 = 150$. `Q` avanza a `nullptr`.
    - Al terminar el bucle, la variable acumuladora `*E` vale `150`.

15. **`F = new int*();`** Reserva memoria dinámica para un puntero de enteros (Puntero B en `0x500`) en el Heap.

16. **`*F = new int();`** Reserva un entero (Entero B en `0x600`) en el Heap. `*F` (dirección `0x500`) apunta a `0x600`.

17. **`**F = 1;`** El Entero B (`0x600`) toma el valor `1`.

18. **`delete *F;`** Libera correctamente el Entero B (`0x600`) de la memoria.

19. **`*F = &I;`** El puntero en `0x500` apunta ahora a la variable de pila local `I`.

20. **`I = 5;`** `I` toma el valor `5`.

21. **`std::cout << **F << std::endl;`** Imprime `5` (el valor de `I` a través de la indirección doble de `F`).

Al finalizar la función `main()`, los siguientes elementos que fueron reservados en el Heap con `new` **nunca se liberaron con `delete`**, provocando fugas de memoria:

1. **Los Nodos de la Lista Enlazada:** Nodo A (`0x100`), Nodo B (`0x300`) y Nodo C (`0x400`) siguen existiendo en el Heap. Fuga de $3 \times \text{size}(Nodo) \text{ bytes}$.

2. **El Entero A (`E`):** El entero dinámico que almacena el acumulado `150` (`0x200`) no fue liberado. Fuga de $4 \text{ bytes}$.

3. **El Puntero Dinámico `F` (`*F`):** La dirección `0x500` (el puntero reservado con `new int*()`) quedó huérfana en el Heap al terminar el programa sin un `delete F`. Fuga de $4/8 \text{ bytes}$ (dependiendo de la arquitectura).
