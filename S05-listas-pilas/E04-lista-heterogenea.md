<h1 align="center">E04 - Homogeneidad y Posibilidad de Listas Heterogéneas</h1>

> [!TLDR]
> No es totalmente cierto que las listas sean homogéneas. En C++ pueden ser heterogéneas usando **polimorfismo** (clase base + herencia virtual), **punteros `void*`** con etiqueta de tipo, o **uniones/`std::variant`**.

## Enunciado

Las listas enlazadas son por definición estructuras de datos homogéneas (es decir, todos sus nodos almacenan elementos del mismo tipo y estructura). ¿Es esto totalmente cierto?, es decir, ¿Sería posible tener una lista que almacenara elementos diferentes en cada uno de sus nodos (tanto en tipo como en estructura)? Justifique su respuesta.

## Respuesta

**No es totalmente cierto.** Físicamente, sí es posible implementar listas **heterogéneas** en C++ que almacenen elementos de diferente tipo y estructura en cada uno de sus nodos.

Para diseñar una lista heterogénea, se utilizan tres enfoques clásicos de la computación:

### 1. Polimorfismo y Herencia (Enfoque Orientado a Objetos)

Es el método más seguro y elegante en C++.

- Se define una clase base común (ej. `ElementoBase`) con destructores virtuales.
- Se derivan múltiples clases que representan los tipos concretos (ej. `Entero`, `Texto`, `Fecha`, `Matriz`).
- La lista enlazada almacena punteros de tipo base (`ElementoBase*`).
- Gracias al polimorfismo, cada nodo apunta en realidad a un objeto hijo de estructura y tamaño completamente diferentes.

```cpp
class ElementoBase {
public:
    virtual void mostrar() = 0;
    virtual ~ElementoBase() {}
};

class Nodo {
public:
    ElementoBase* info; // Apunta a cualquier subclase derivada
    Nodo* prox;
};
```

### 2. Punteros Genéricos (`void*`) y Etiquetas de Tipo

- Cada nodo almacena un puntero a `void*` (que puede apuntar a cualquier dirección de memoria física sin importar su tipo).

- Se debe almacenar adicionalmente una variable enumerada (`TipoDato`) en el nodo que actúe como una "etiqueta" para que el programa sepa a qué tipo de dato castear el puntero `void*` al leer el nodo.

### 3. Uniones (`union` / `std::variant`)

- Se define una unión o un tipo variante que reserve el espacio máximo necesario para contener cualquiera de los tipos deseados. Cada nodo almacena esta unión en su campo de información.
