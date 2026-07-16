<h1 align="center">E20 - Complejidad en Espacio de la Variable E</h1>

> [!TLDR]
> `E[20]` ocupa $20 \times 808 = 16,160$ bytes (~15.78 KB). Su complejidad en espacio es $O(1)$ porque su tamaño es fijo y no depende de ninguna entrada dinámica.

## Enunciado

Dada la siguiente estructura de datos:

```cpp
struct XG {
    int Elemento[10][10]; // Representado como [10] [1..10] en el PDF
};
struct YG {
    int x, y;
    XG Milista;
};
struct K {
    YG x;
    XG y;
};
K E[20];
```

Calcule la complejidad en espacio de la variable `E`.

## Respuesta

### 1. Estructura `XG`

El campo `Elemento` es una matriz bidimensional estática de $10 \times 10$ enteros (`int`):

$$\text{Tamaño de XG} = 10 \times 10 \times \text{size}(int) = 100 \times 4 \text{ bytes} = 400 \text{ bytes}$$

### 2. Estructura `YG`

- Variables enteras `x`, `y`: $2 \times 4 \text{ bytes} = 8 \text{ bytes}$
- Variable `Milista` de tipo `XG`: $400 \text{ bytes}$

$$\text{Tamaño de YG} = 8 + 400 = 408 \text{ bytes}$$

### 3. Estructura `K`

- Variable `x` de tipo `YG`: $408 \text{ bytes}$
- Variable `y` de tipo `XG`: $400 \text{ bytes}$

$$\text{Tamaño de K} = 408 + 400 = 808 \text{ bytes}$$

La variable `E` es un arreglo estático de 20 elementos de tipo `K`:

$$\text{Memoria total de E} = 20 \times \text{size}(K) = 20 \times 808 \text{ bytes} = 16,160 \text{ bytes}$$

En kilobytes:

$$\text{Memoria total} \approx 15.78 \text{ KB}$$

La complejidad en espacio de la variable `E` es **constante** $O(1)$ con respecto al tiempo de ejecución del programa, puesto que su tamaño está predefinido estáticamente y no depende de ninguna variable de entrada dinámica.
