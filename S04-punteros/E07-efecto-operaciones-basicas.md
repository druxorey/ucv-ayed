<h1 align="center">E07 - Efecto de Operaciones Básicas con Punteros</h1>

> [!TLDR]
> `X=Y` reasigna el puntero causando una **fuga** del entero original de `X`. `Z=W` y `(W==Z)` producen **errores de compilación** por tipos incompatibles (`int*` vs `char*`). `delete Y` libera correctamente.

## Enunciado

Considere las siguientes declaraciones:

```cpp
int *X, *Y, *Z;
char *W;
int A;
char B;
bool C;
```

Indique el efecto de las siguientes operaciones:

- `X = new int();`
- `Y = new int();`
- `W = new char();`
- `X = Y;`
- `B = *W;`
- `Z = new int();`
- `Z = W;`
- `C = W == Z;`
- `X = new int();`
- `*X = 1;`
- `*W = 'G';`
- `A = *X + *Y;`
- `C = (*W == A);`
- `*Z = A;`
- `Z = X;`
- `delete Y;`

## Respuesta

Dadas las declaraciones:

```cpp
int *X, *Y, *Z;
char *W;
int A;
char B;
bool C;
```

Analizamos secuencialmente el impacto lógico y de compilación de cada instrucción:

- **`X = new int();`** Reserva un espacio para un entero en el Heap. `X` almacena su dirección física.

- **`Y = new int();`** Reserva un segundo entero en el Heap. `Y` almacena su dirección física.

- **`W = new char();`** Reserva un carácter en el Heap. `W` almacena su dirección.

- **`X = Y;`** Reasignación de puntero. `X` copia la dirección de `Y`. Ambos apuntan al segundo entero. El primer entero (el de `X` original) queda inaccesible en memoria, generando un **leak (fuga)**.

- **`B = *W;`** Lee el valor del carácter apuntado por `W` (sin inicializar en este punto) y lo asigna a la variable local `B`.

- **`Z = new int();`** Reserva un tercer entero en el Heap. `Z` almacena su dirección.

- **`Z = W;`** **Error de compilación.** Intentar asignar un puntero a carácter (`char*`) a un puntero a entero (`int*`) sin una conversión explícita (`reinterpret_cast`) es una violación de tipo en C++.

- **`C = (W == Z);`** **Error de compilación.** Comparación no permitida entre punteros de tipos de datos incompatibles (`char*` e `int*`).

- **`X = new int();`** Reserva un cuarto entero en el Heap y asigna su dirección a `X`.

- **`*X = 1;`** Inicializa el entero apuntado por `X` con el valor `1`.

- **`*W = 'G';`** Inicializa el carácter apuntado por `W` con la constante `'G'`.

- **`A = *X + *Y;`** Suma el contenido de `*X` ($1$) y `*Y` (basura de inicialización) y almacena el resultado en la variable local `A`.

- **`C = (*W == A);`** Compara la codificación numérica ASCII del carácter en `*W` (`'G'` = 71) con el valor numérico de `A`. El booleano se almacena en `C`.

- **`*Z = A;`** Asigna el valor de `A` al entero apuntado por `Z`.

- **`Z = X;`** Reasignación. `Z` apunta ahora a la misma dirección que `X`. El entero que antes apuntaba `Z` queda inaccesible, provocando un **leak (fuga)**.

- **`delete Y;`** Libera correctamente del Heap el entero al que apunta `Y`.
