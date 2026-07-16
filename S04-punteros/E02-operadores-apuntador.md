<h1 align="center">E02 - Operadores & y *</h1>

> [!TLDR]
> `&` obtiene la **dirección** de una variable. `*` accede al **valor** en la dirección apuntada. Juntos permiten referenciar y desreferenciar memoria dinámica.

## Enunciado

Describa el uso que se le da en este contexto a los operadores `&` y `*`.

En C++, los apuntadores se controlan mediante dos operadores unarios fundamentales:

## 1. Operador de Dirección (`&` - Referenciación)

- **Función:** Obtiene la dirección de memoria de una variable existente.
- **Lectura:** "Dirección de..."
- **Ejemplo:**

```cpp
int x = 42;
int* ptr = &x; // Asigna a 'ptr' la dirección física de 'x'
```

Si `x` reside en la dirección `0x7ffee3b`, entonces el valor almacenado en `ptr` será `0x7ffee3b`.

## 2. Operador de Indirección (`*` - Desreferenciación)

- **Función:** Accede al valor almacenado en la dirección de memoria a la que apunta un puntero. Permite tanto leer como modificar dicho valor.
- **Lectura:** "El valor apuntado por..."
- **Ejemplo:**

```cpp
int x = 42;
int* ptr = &x;
std::cout << *ptr; // Imprime 42 (lee el valor de x a través de ptr)
*ptr = 99;         // Modifica el valor de x a 99 indirectamente
```
