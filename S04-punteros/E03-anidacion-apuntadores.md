<h1 align="center">E03 - Anidación de Apuntadores</h1>

> [!TLDR]
> Sí. Cada nivel de indirección se indica con un `*` adicional: `int**` es un puntero a puntero. En la práctica raramente se superan 3 niveles (matrices dinámicas 3D o paso por referencia de estructuras enlazadas).

## Enunciado

¿Es posible tener apuntadores de apuntadores y anidarlos cuantas veces sea necesario?

## Respuesta

**Sí, es totalmente posible y válido en C++.** Esto se conoce como direccionalidad múltiple o indirección múltiple.

Un apuntador es una variable que reside en memoria, lo que significa que **tiene su propia dirección de memoria física**. Por lo tanto, podemos crear otro apuntador que almacene la dirección del primer apuntador.

### Sintaxis en C++:

Cada nivel de anidación o indirección se representa añadiendo un asterisco (`*`) adicional al tipo de dato:

- `int x = 10;` (Variable entera de nivel 0).
- `int* p = &x;` (Apuntador a entero: nivel 1 de indirección).
- `int** pp = &p;` (Apuntador a apuntador a entero: nivel 2 de indirección).
- `int*** ppp = &pp;` (Apuntador a apuntador a apuntador a entero: nivel 3).

### Mapa de Memoria Conceptual:

```text
Variable:      x               p               pp              ppp
Dirección:    0x100           0x200           0x300           0x400
Valor:        [ 10 ]  <----  [ 0x100 ] <---  [ 0x200 ] <---  [ 0x300 ]
```

- `*p` nos da el valor de `x` ($10$).
- `**pp` nos da el valor de `x` ($10$) pasando por `p`.
- `***ppp` nos da el valor de `x` ($10$) navegando por tres niveles de direcciones.

Aunque la teoría permite infinitos niveles de anidación, en el desarrollo práctico de software raramente se superan los 3 niveles (apuntadores triples, usualmente para matrices dinámicas tridimensionales o paso de parámetros por referencia de estructuras enlazadas dinámicas).
