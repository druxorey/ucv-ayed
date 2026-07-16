<h1 align="center">E01 - Concepto de Apuntador o Referencia</h1>

> [!TLDR]
> Un **apuntador** almacena una **dirección de memoria física**. Permite acceso indirecto a datos (desreferenciación con `*`), gestión dinámica de memoria en el Heap (`new`) e indirección en múltiples niveles.

## Enunciado

¿Qué es el tipo de dato referencia o apuntador?

Un **apuntador** (o puntero) es una variable cuyo valor no es un dato directo (como un entero o un carácter), sino una **dirección de memoria física**. Esta dirección indica dónde se encuentra almacenada otra variable u objeto en la memoria del computador.

## Respuesta

1. **Direccionamiento Indirecto:** Permite acceder y modificar el contenido de una variable indirectamente a través de su dirección.

2. **Gestión Dinámica de Memoria:** Es fundamental para reservar memoria en tiempo de ejecución (en el *Heap*) mediante el operador `new` en C++.

3. **Niveles de Direccionamiento:**
    - **Directo:** Acceder al valor de una variable a través de su nombre (ej. `x`).
    - **Indirecto:** Acceder al valor apuntado por un puntero (ej. `*ptr`).
