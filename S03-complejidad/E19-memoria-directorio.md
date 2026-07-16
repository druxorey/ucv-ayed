<h1 align="center">E19 - Análisis de Memoria de EntradaDeDirectorio</h1>

> [!TLDR]
> `Fecha` ocupa 12 bytes. `EntradaDeDirectorio` ocupa $256 + 12 + 4 + 1 = 273$ bytes en total.

## Enunciado

Para el siguiente bloque de programa:

```cpp
struct Fecha {
    int Dia;
    char Mes[4];
    int Año;
};
struct EntradaDeDirectorio {
    char Nombre[256];
    Fecha Creacion;
    int NumeroDeArchivos;
    bool EstaCompartido;
};
```

Calcule la cantidad de memoria requerida para la estructura del objeto `EntradaDeDirectorio`.

## Respuesta

### 1. Tamaño del sub-objeto `Fecha`

Sumamos el tamaño de sus campos:

- `Dia`: $4 \text{ bytes}$
- `Mes`: $4 \times \text{size}(char) = 4 \text{ bytes}$
- `Año`: $4 \text{ bytes}$

$$\text{Tamaño de Fecha} = 4 + 4 + 4 = 12 \text{ bytes}$$

### 2. Tamaño de `EntradaDeDirectorio`

Sumamos el tamaño de cada campo, incluyendo la estructura anidada `Fecha`:

- `Nombre`: $256 \times \text{size}(char) = 256 \text{ bytes}$
- `Creacion`: $\text{size}(Fecha) = 12 \text{ bytes}$
- `NumeroDeArchivos`: $\text{size}(int) = 4 \text{ bytes}$
- `EstaCompartido`: $\text{size}(bool) = 1 \text{ byte}$

$$\text{Tamaño de EntradaDeDirectorio} = 256 + 12 + 4 + 1 = 273 \text{ bytes}$$

En bytes netos:

$$\text{Memoria total del struct} = 273 \text{ bytes}$$
