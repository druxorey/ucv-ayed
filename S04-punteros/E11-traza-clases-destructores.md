<h1 align="center">E11 - Destructores de Clases y Error de Doble Liberación</h1>

> [!TLDR]
> `delete r` dispara el destructor de `Rect` que intenta liberar `p1` (ya liberado por `delete a`), causando un **Double Free** y crash. Al salir del `main`, `otro` intenta liberar los mismos punteros por tercera vez.

## Enunciado

Haga la traza del siguiente algoritmo y explique qué sucede en cada instrucción.

```cpp
class Point {
public:
    float x, y;
    Point() {
        x = 0; 
        y = 0;
    }
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }
};

class Rect {
public:
    Point *p1, *p2;
    Rect() { p1 = p2 = NULL; }
    Rect(Point *p1, Point *p2) {
        this->p1 = p1;
        this->p2 = p2;
    }
    ~Rect() {
        if (p1 != NULL) delete p1;
        if (p2 != NULL) delete p2;
    }
};

int main() {
    Point *a, *b;
    a = new Point();
    b = new Point(1, 1);
    Rect *r = new Rect(a, b);
    delete a;
    delete r; // ¿Qué error ocurre aquí?
    Rect otro(a, b);
    return 0;
} // ¿Qué sucede al llamar al destructor de otro?
```

## Respuesta

1. **`a = new Point();`** Reserva un objeto `Point` (Point A: $(0,0)$ en `0x100`) en el Heap.

2. **`b = new Point(1, 1);`** Reserva un segundo `Point` (Point B: $(1,1)$ en `0x200`) en el Heap.

3. **`Rect *r = new Rect(a, b);`** Reserva un objeto `Rect` en el Heap. Los miembros internos de este rectángulo apuntan a las direcciones compartidas:
    - `r->p1` = `0x100` (Point A)
    - `r->p2` = `0x200` (Point B)

4. **`delete a;`** Libera manualmente el Point A (`0x100`) de la memoria. La dirección queda disponible en el sistema. El puntero `a` y el miembro `r->p1` ahora son **punteros colgantes** que apuntan a memoria inválida.

### ¿Qué error ocurre al ejecutar `delete r;`?

Se produce un error crítico de **Doble Liberación de Memoria (Double Free Error)**, lo que causa la terminación abrupta del programa.

- **Razón:** Al llamar a `delete r;`, el compilador ejecuta el destructor de `Rect`:

```cpp
~Rect() {
	if (p1 != NULL) delete p1; // Paso 1
	if (p2 != NULL) delete p2; // Paso 2
}
```

En el *Paso 1*, intenta liberar la memoria apuntada por `p1` (`0x100`). Como esa dirección ya fue liberada anteriormente por `delete a;`, el gestor de memoria detecta que se intenta liberar la misma memoria por segunda vez, disparando un error de corrupción de Heap:

```text
free(): double free or corruption
Aborted (core dumped)
```

### ¿Qué sucede al llamar al destructor de `otro`?

Si asumiéramos que el programa continuara tras el error anterior, al finalizar la función `main()` el objeto `otro` (declarado en el Stack) sale de su ámbito local de visibilidad, lo que invoca automáticamente su destructor `~Rect()`.

Esto provocaría un **segundo y tercer fallo de Double Free**:

1. Intentaría liberar `otro.p1` (`0x100`), la cual ya fue liberada dos veces.

2. Intentaría liberar `otro.p2` (`0x200`). La dirección `0x200` (Point B) ya fue liberada previamente durante la ejecución de `delete r;` (Paso 2 de su destructor). Intentar liberarlo nuevamente a través de `otro` constituye otro Double Free.

### Lección de Diseño:

Para evitar este tipo de errores, si una clase no es la propietaria exclusiva de los punteros que recibe, su destructor **no debe liberar la memoria de esos punteros**, o bien se debe implementar una política de punteros inteligentes compartidos (`std::shared_ptr`).
