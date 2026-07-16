<h1 align="center">E09 - Traza de Matriz Dinámica y Detección de Fallo de Segmentación</h1>

> [!TLDR]
> El bucle externo itera `i < N-1`, dejando `arr[2]` y `mat[2]` sin inicializar. Al intentar `delete[] mat[2]` sobre un puntero basura, se produce un **Segmentation Fault** inmediato.

## Enunciado

Haga la traza del siguiente algoritmo y explique qué sucede en cada instrucción.

```cpp
int main() {
    int i, j, n;
    int *arr;
    int **mat;
    std::cin >> n;
    arr = new int[n];
    mat = new int*[n];
    for (i = 0; i < n - 1; i++) {
        arr[i] = i;
        mat[i] = new int[n];
        for (j = 0; j < n - 1; j++) {
            mat[i][j] = i + j;
        }
    }
    i = n - 1;
    while (i >= 0) {
        std::cout << arr[i] << std::endl;
        delete[] mat[i];
        i = i - 1;
    }
    delete[] arr;
    delete[] mat;
    // en este momento, ¿a quién apunta arr?. ¿Podría acceder arr[1]?
    return 0;
}
```

## Análisis de la Traza (Supongamos $N = 3$)

### 1. Inicialización y Asignación de Memoria:

```cpp
arr = new int[3];  // Arreglo de 3 enteros en Heap
mat = new int*[3]; // Arreglo de 3 punteros a enteros en Heap (las filas de la matriz)
```

### 2. Primer Bucle `for` (Inicialización de datos):

El bucle corre para $i < N - 1$ ($i$ va de $0$ a $1$):

- **Iteración $i = 0$:**
    - `arr[0] = 0;`
    - `mat[0] = new int[3];` (Reserva memoria para la fila 0)
    - Bucle interno para $j$ de $0$ a $1$:
        - `mat[0][0] = 0 + 0 = 0;`
        - `mat[0][1] = 0 + 1 = 1;`
        - `mat[0][2]` queda sin inicializar (contiene basura).

- **Iteración $i = 1$:**
    - `arr[1] = 1;`
    - `mat[1] = new int[3];` (Reserva memoria para la fila 1)
    - Bucle interno para $j$ de $0$ a $1$:
        - `mat[1][0] = 1 + 0 = 1;`
        - `mat[1][1] = 1 + 1 = 2;`
        - `mat[1][2]` queda sin inicializar.

*Nota:* Dado que el bucle externo termina cuando $i = 2$ ($2 < 2$ es falso):

- `arr[2]` **nunca** se inicializa (contiene basura).
- `mat[2]` **nunca** se inicializa (es un puntero basura o salvaje que apunta a una dirección de memoria aleatoria).

### 3. Segundo Bucle `while` (Impresión y Liberación):

Inicia en $i = N - 1 = 2$.

- **Iteración $i = 2$:**
    - `std::cout << arr[2];` $\to$ Imprime el valor basura almacenado en `arr[2]`.
    - `delete[] mat[2];` $\to$ **CRASH / FALLO DE SEGMENTACIÓN (Segmentation Fault).**

Se intenta liberar la memoria apuntada por el puntero `mat[2]`. Dado que `mat[2]` nunca se inicializó, apunta a una dirección de memoria aleatoria no gestionada por nuestro Heap. Liberar un puntero salvaje corrompe la tabla de asignación de memoria del sistema y hace colapsar el programa inmediatamente.

### ¿A quién apunta `arr` en este momento?

Después de ejecutar `delete[] arr;`, el puntero `arr` sigue almacenando la dirección física de la memoria del Heap que acaba de ser liberada. No se convierte en `NULL` automáticamente. Esto se conoce en ingeniería de software como un **puntero colgante (dangling pointer)**.

### ¿Podría acceder a `arr[1]`?

- **Físicamente:** Sí, el compilador permitirá escribir `arr[1]` y compilará sin errores sintácticos.

- **Lógicamente/Seguridad:** **No se debe hacer.** Acceder a memoria liberada produce un **Comportamiento Indefinido (Undefined Behavior)**. Dado que esa memoria ya fue devuelta al sistema operativo, su valor puede haber sido modificado por otro proceso, o el intento de acceso podría disparar un error de violación de protección de memoria en tiempo de ejecución.
