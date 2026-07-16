<h1 align="center">E18 - Análisis de Memoria de la Estructura Vivienda</h1>

> [!TLDR]
> Una `Vivienda` ocupa 1,041 bytes. El arreglo `Urb[15]` ocupa en total $15 \times 1041 = 15,615$ bytes (~15.25 KB).

## Enunciado

Para el siguiente bloque de programa:

```cpp
struct Vivienda {
    float Costo;
    char Direccion[1024];
    int Pisos;
    bool TieneVigilancia;
    int Metros;
    int Altura;
};
Vivienda Urb[15];
```

Calcule la cantidad de memoria requerida para la estructura del objeto `Urb`.

## Respuesta

Sumamos el tamaño de cada campo individual en bytes:

- `Costo`: $\text{size}(float) = 4 \text{ bytes}$
- `Direccion`: $1024 \times \text{size}(char) = 1024 \text{ bytes}$
- `Pisos`: $\text{size}(int) = 4 \text{ bytes}$
- `TieneVigilancia`: $\text{size}(bool) = 1 \text{ byte}$
- `Metros`: $\text{size}(int) = 4 \text{ bytes}$
- `Altura`: $\text{size}(int) = 4 \text{ bytes}$

$$\text{Tamaño de una Vivienda} = 4 + 1024 + 4 + 1 + 4 + 4 = 1041 \text{ bytes}$$

El arreglo `Urb` tiene una longitud fija de 15 elementos:

$$\text{Memoria total del arreglo Urb} = 15 \times 1041 \text{ bytes} = 15,615 \text{ bytes}$$

En kilobytes:

$$\text{Memoria total} \approx 15.25 \text{ KB}$$
