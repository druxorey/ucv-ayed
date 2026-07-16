<h1 align="center">E01 - Necesidad de Apuntadores en la Implementación de Listas</h1>

## Enunciado

¿Es estrictamente necesario el uso de apuntadores para implementar listas?

## Respuesta

**No, no es estrictamente necesario.** Aunque los apuntadores (variables de dirección física) son la herramienta más natural en lenguajes modernos como C++ para gestionar memoria dinámica, existen representaciones alternativas que no los utilizan.

En lenguajes de programación antiguos que no poseían el tipo de dato apuntador (como FORTRAN clásico o las primeras versiones de BASIC), las listas enlazadas se implementaban utilizando **arreglos estáticos indexados**.

### Funcionamiento:

Se define un arreglo de estructuras (o múltiples arreglos paralelos) donde cada elemento representa un "nodo":

1. **Arreglo de Datos (`info`):** Almacena el valor real.
2. **Arreglo de Enlaces (`next`):** En lugar de contener una dirección de memoria física (como `0x7ff`), contiene el **índice numérico entero (0-indexed)** del siguiente nodo dentro del mismo arreglo.

### Ejemplo de Representación en Memoria:

Asumamos un arreglo que contiene una lista enlazada lógica con los caracteres `'B' -> 'A' -> 'C'`:

- **Cabecera de lista:** `inicio = 1` (Indica que el primer elemento lógico está en la posición 1 del arreglo).

```text
Índice:     0       1       2       3
Info:     ['C']   ['B']   ['A']   [   ]
Next:     [-1]    [ 2 ]   [ 0 ]   [   ]
```

- **Navegación Lógica:**
    - Leemos el inicio: Índice 1 $\to$ Contiene `'B'`. Su `next` es 2.
    - Vamos al índice 2 $\to$ Contiene `'A'`. Su `next` es 0.
    - Vamos al índice 0 $\to$ Contiene `'C'`. Su `next` es -1 (representa `NULL`, fin de la lista).
